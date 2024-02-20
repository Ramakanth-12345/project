#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/slab.h>
#include<linux/kdev_t.h>
#include<linux/interrupt.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<asm/io.h>
#include<linux/sysfs.h>
#include<linux/kobject.h>
#include<linux/workqueue.h>
#include<linux/err.h>
#include<linux/uaccess.h>

#define IRQ_NO 11

void workqueue_fn(struct work_struct *work);

DECLARE_WORK(workqueue,workqueue_fn);

void workqueue_fn(struct work_struct *work)
{
	pr_info("Executing workqueue : Function\n");
}

static irqreturn_t irq_handler(int irq,void *dev_id)
{
	pr_info("SHARED IRQ :Interrupt occured\n");
	schedule_work(&workqueue);
	return IRQ_HANDLED;
}

volatile int etx_value = 0;

dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;
struct kobject *kobj_ref;

static int __init dev_init(void);
static void __exit dev_exit(void);

static int dev_open(struct inode *inode,struct file *file);
static int dev_close(struct inode *inode,struct file *file);
static ssize_t dev_read(struct file *filp,char __user *buf,size_t len,loff_t *off);
static ssize_t dev_write(struct file *file,const char __user *buf,size_t len,loff_t *off);

static ssize_t sys_show(struct kobject *kobj,struct kobj_attribute *attr,char *buf);
static ssize_t sys_store(struct kobject *kobj,struct kobj_attribute *attr,const char *buf,size_t count);

struct kobj_attribute etx_attr=__ATTR(etx_value,0660,sys_show,sys_store);

static struct file_operations fops=
{
	.owner=THIS_MODULE,
	.open=dev_open,
	.release=dev_close,
	.read=dev_read,
	.write=dev_write,
};

static ssize_t sys_show(struct kobject *kobj,struct kobj_attribute *attr,char *buf)
{
	pr_info("sysfs ----> READ function\n");
	return sprintf(buf,"%d",etx_value);
}
static ssize_t sys_store(struct kobject *kobj,struct kobj_attribute *attr,const char *buf,size_t count)
{
	pr_info("sysfs-----> Write Function\n");
	sscanf(buf,"%d",&etx_value);
	return count;
}

static int dev_open(struct inode *inode,struct file *file)
{
	pr_info("dev_file is opened\n");
	return 0;
}
static int dev_close(struct inode *inode,struct file *file)
{
	pr_info("dev_file is closed\n");
	return 0;
}
static ssize_t dev_read(struct file *filp,char __user *buf,size_t len,loff_t *off)
{
	pr_info("REady for reading the file\n");
	asm("int $0x3B");
	return 0;
}
static ssize_t dev_write(struct file *file,const char __user *buf,size_t len,loff_t *off)
{
	pr_info("Ready for writing the file\n");
	return len;
}

static int __init dev_init(void)
{
	if((alloc_chrdev_region(&dev,0,1,"workqueue_static"))<0)
	{
		pr_info("canot alloc memory----\n");
		return -1;
	}
	pr_info("MAJOR=%d,MINOR=%d\n",MAJOR(dev),MINOR(dev));

	cdev_init(&etx_cdev,&fops);

	if((cdev_add(&etx_cdev,dev,1))<0)
	{
		pr_info("cannot add device to the system\n");
		goto r_class;
	}
	if(IS_ERR(dev_class=class_create(THIS_MODULE,"etx_class")))
	{
		pr_info("cannot create the dev_class\n");
		goto r_class;
	}
	if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"etx_device")))
	{
		pr_info("device class not created\n");
		goto r_device;
	}

	kobj_ref=kobject_create_and_add("etx_sysfs",kernel_kobj);

	if(sysfs_create_file(kobj_ref,&etx_attr.attr))
	{
		printk(KERN_INFO"cannot create sysfs\n");
		goto r_sysfs;
	}
	if(request_irq(IRQ_NO,irq_handler,IRQF_SHARED,"etx_device",(void*)(irq_handler)))
	{
		pr_info("device cannot register as irq\n");
		goto irq;
	}
	pr_info("Device registered Sucessfully\n");
	return 0;

r_sysfs:
	kobject_put(kobj_ref);
	sysfs_remove_file(kernel_kobj,&etx_attr.attr);
r_class:
	unregister_chrdev_region(dev,1);
	cdev_del(&etx_cdev);
	//return -1;
r_device:
	class_destroy(dev_class);
irq:
	free_irq(IRQ_NO,(void*)(irq_handler));
	return -1;
}	

static void __exit dev_exit(void)
{
	free_irq(IRQ_NO,(void*)(irq_handler));
	sysfs_remove_file(kernel_kobj,&etx_attr.attr);
	unregister_chrdev_region(dev,1);
	cdev_del(&etx_cdev);
	device_destroy(dev_class,dev);
	class_destroy(dev_class);
	kobject_put(kobj_ref);
	pr_info("Device is removed sucessfully\n");		
}

module_init(dev_init);
module_exit(dev_exit);

MODULE_DESCRIPTION("Work Queue Static");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("RAMAKANTH");
