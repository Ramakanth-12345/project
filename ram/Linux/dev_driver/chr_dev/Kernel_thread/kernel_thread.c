#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/slab.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/kthread.h>
#include<linux/sched.h>
#include<linux/uaccess.h>
#include<linux/delay.h>
#include<linux/err.h>

dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;

static int __init dev_init(void);
static void __exit dev_exit(void);

static struct task_struct *etx_thread;

static int dev_open(struct inode *inode,struct file *file);
static int dev_close(struct inode *inode,struct file *file);
static ssize_t dev_read(struct file *filep,char __user *buf,size_t len,loff_t *off);
static ssize_t dev_write(struct file *filep,const char __user *buf,size_t len,loff_t *off);

int thread_fun(void *pv);

int thread_fun(void *pv)
{
	int i=0;
	while(!kthread_should_stop())
	{
		pr_info("In Thread Function is %d\n",i++);
		msleep(1000);
	}
	return 0;
}

static struct file_operations fops=
{
	.owner=THIS_MODULE,
	.open=dev_open,
	.read=dev_read,
	.write=dev_write,
	.release=dev_close,
};

static int dev_open(struct inode *inode,struct file *file)
{
	pr_info("device file is opened under structure!!\n");
	return 0;
}
static int dev_close(struct inode *inode,struct file *file)
{
	pr_info("Device file is closed!!\n");
	return 0;
}
static ssize_t dev_read(struct file *filep,char __user *buf,size_t len,loff_t *off)
{
	pr_info("file is opened for reaading!!\n");
	return 0;
}
static ssize_t dev_write(struct file *filep,const char __user *buf,size_t len,loff_t *off)
{
	pr_info("file is closed for writing!!\n");
	return len;
}

static int __init dev_init(void)
{
	if((alloc_chrdev_region(&dev,0,1,"etx_device"))<0)
	{
		pr_err("Cannot allocate the memory\n");
		return -1;
	}
	pr_info("Major=%d MINOR=%d",MAJOR(dev),MINOR(dev));
	
	cdev_init(&etx_cdev,&fops);

	if((cdev_add(&etx_cdev,dev,1))<0)
	{
		pr_err("cannot add the device\n");
		goto r_class;
	}
	if(IS_ERR(dev_class=class_create(THIS_MODULE,"etx_class")))
	{
		pr_err("cannot create the class\n");
		goto r_class;
	}
	if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"etx_device")))
	{
		pr_err("Device cannot be created\n");
		goto r_device;
	}

	etx_thread = kthread_create(thread_fun,NULL,"eTx Thread");

        if(etx_thread) 
	{
            wake_up_process(etx_thread);
        } 
	else 
	{
            pr_err("Cannot create kthread\n");
            goto r_device;
        }

        /* You can use this method also to create and run the thread 
        etx_thread = kthread_run(thread_function,NULL,"eTx Thread");
        if(etx_thread)
       	{
            pr_info("Kthread Created Successfully...\n");
        }
       	else 
	{
            pr_err("Cannot create kthread\n");
             goto r_device;
        }*/

	pr_info("Device Driver is inserted!!\n");
	return 0;

r_device:

	class_destroy(dev_class);

r_class:
	unregister_chrdev_region(dev,1);
	cdev_del(&etx_cdev);
	return -1;
}
static void __exit dev_exit(void)
{
	kthread_stop(etx_thread);
	device_destroy(dev_class,dev);
	class_destroy(dev_class);
	cdev_del(&etx_cdev);
	unregister_chrdev_region(dev,1);
	pr_info("Device Driver is Removed!\n");
}

module_init(dev_init);
module_exit(dev_exit);

MODULE_LICENSE("GPL");
