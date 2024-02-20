#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/slab.h>
#include<asm/uaccess.h>
#include<linux/uaccess.h>
#include<linux/cdev.h>
#include<linux/kdev_t.h>
#include<linux/err.h>
#include<linux/device.h>
#include<linux/kobject.h>
#include<linux/sysfs.h>

volatile int ex_value=0;

dev_t dev=0;
static struct class *dev_class;
static struct cdev etx_cdev;
struct kobject *kobj_ref;

/* function prototypes */

static int   __init ex_driver_init(void);
static void  __exit ex_driver_exit(void);

/* driver function */

static int dr_open(struct inode *inode,struct file *file);
static int dr_close(struct inode *inode,struct file *file);
static ssize_t dr_read(struct  file *filp,char __user *buf,size_t len,loff_t *off);
static ssize_t dr_write(struct file *filp,const char __user *buf,size_t len,loff_t *off);

/* system fs functions */

static ssize_t sysfs_show(struct kobject *kobj,struct kobj_attribute *attr,char *buf);
static ssize_t sysfs_store(struct kobject *kobj,struct kobj_attribute *attr,const char *buf,size_t count);
struct kobj_attribute tx_attr=__ATTR(ex_value,0660,sysfs_show,sysfs_store);

/*file operations*/
static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = dr_open,
	.release = dr_close,
	.read = dr_read,
	.write = dr_write
};

static ssize_t sysfs_show(struct kobject *kobj,struct kobj_attribute *attr,char *buf)
{
	pr_info("sysfs file show -read !!-\n");
	return sprintf(buf,"%d",ex_value);
}
static ssize_t sysfs_store(struct kobject *kobj,struct kobj_attribute *attr,const char *buf,size_t count)
{
	pr_info("SYSFS file store - write !! - \n");
	sscanf(buf,"%d",&ex_value);
	return count;
}

static int dr_open(struct inode *inode,struct file *file)
{
	pr_info("driver is opened\n");
	return 0;
}
static int dr_close(struct inode *inode,struct file *file)
{
	pr_info("driver is closed\n");
	return 0;
}
static ssize_t dr_read(struct  file *filp,char __user *buf,size_t len,loff_t *off)
{
	pr_info("file is reading\n");
	return 0;
}
static ssize_t dr_write(struct file *filp,const char __user *buf,size_t len,loff_t *off)
{
	pr_info("file is write mode\n");
	return len;
}
static int   __init ex_driver_init(void)
{
	/*Major num allocation */
	if((alloc_chrdev_region(&dev,0,1,"etx_dev"))<0)
	{
		pr_info("cannot allocate memory\n");
		return -1;
	}
	pr_info("Major=%d  Minor=%d\n",MAJOR(dev),MINOR(dev));

	/*creating cdev structure*/
	cdev_init(&etx_cdev,&fops);

	/*Adding character driver to system*/
	if((cdev_add(&etx_cdev,dev,1))<0)
	{
		pr_info("cannot add device to system\n");
		goto r_class;
	}
	/*Creating Struct class*/
	if(IS_ERR(dev_class=class_create(THIS_MODULE,"etx_class")))
	{
		pr_info("cannot create struct class\n");
		goto r_class;
	}
	/*creating device class*/
	if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"etx_device")))
	{
		pr_info("cannot create the device\n");
		goto r_device;
	}
	
	/*create the directory /sys/kernel  */
	kobj_ref=kobject_create_and_add("ext_sysfs",kernel_kobj);

	/*creating sysfs file for ex_value*/
	if(sysfs_create_file(kobj_ref,&tx_attr.attr))
	{
		pr_err("cannot Create sysfs file  \n");
		goto r_sysfs;
	}
	pr_info("DEVICE DRIVER INSERT ....DONE !!!\n");
	return 0;

r_sysfs:
	kobject_put(kobj_ref);
	sysfs_remove_file(kernel_kobj,&tx_attr.attr);
r_device:
	class_destroy(dev_class);
r_class:
	unregister_chrdev_region(dev,1);
	cdev_del(&etx_cdev);
	return -1;
}
/* Module Exit Function */
static void  __exit ex_driver_exit(void)
{
	kobject_put(kobj_ref);
	sysfs_remove_file(kernel_kobj,&tx_attr.attr);
	device_destroy(dev_class,dev);
	class_destroy(dev_class);
	cdev_del(&etx_cdev);
	unregister_chrdev_region(dev,1);
	pr_info("Device driver removed\n");
}
module_init(ex_driver_init);
module_exit(ex_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ramakanth");
MODULE_DESCRIPTION("Sysfs File Creation");
MODULE_VERSION("1.6");
