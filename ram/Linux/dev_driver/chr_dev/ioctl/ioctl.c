#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/slab.h>
//#include<linux/init.h>
#include<linux/ioctl.h>
#include<linux/err.h>
#include<linux/uaccess.h>
#include<asm/uaccess.h>

#define WR_VALUE _IOW('a','a',int32_t*)
#define RD_VALUE _IOR('a','b',int32_t*)

int32_t value=0;

dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;

static int __init init_ioctl(void);
static void __exit exit_ioctl(void);
static int open_dev(struct inode *inode,struct file *file);
static int release_dev(struct  inode *inode,struct file *file);
static ssize_t read_dev(struct file *file,char __user *buf,size_t len,loff_t *loff);
static ssize_t write_dev(struct file *file,const char __user *buf,size_t len,loff_t *loff);
static long ioctl_dev(struct  file *file,unsigned int cmd,unsigned long arg);

struct file_operations fops={
	.owner=THIS_MODULE,
	.open=open_dev,
	.release=release_dev,
	.read=read_dev,
	.write=write_dev,
	.unlocked_ioctl=ioctl_dev,
};

static int open_dev(struct inode *inode,struct file *file)
{
	pr_info("device is opened for operations\n");
	return 0;
}
static int release_dev(struct  inode *inode,struct file *file)
{
	pr_info("Device is closed\n");
	return 0;
}
static ssize_t read_dev(struct file *filep,char __user *buf,size_t len,loff_t *loff)
{
	//py_from_user();
	pr_info("Device is ready for reading\n");
	return 0;
}
static ssize_t write_dev(struct file *filep,const char __user *buf,size_t len,loff_t *loff)
{
	pr_info("Writing to the device file\n");
	return len;
}
static long ioctl_dev(struct file *file,unsigned int cmd,unsigned long arg)
{
	switch(cmd)
	{
		case WR_VALUE:
			if(copy_from_user(&value,(int32_t *)arg,sizeof(value)))
			{
				pr_err("Data is ERR\n");
			}
			pr_info("Value=%d\n",value);
			break;
		case RD_VALUE:
			if(copy_to_user((int32_t *)arg,&value,sizeof(value)))
			{
				pr_err("Data read:ERR..\n");
			}
			break;
		default:pr_info("Default....\n");
			break;
	}
	return 0;
}

static int __init init_ioctl(void)
{
	if((alloc_chrdev_region(&dev,0,1,"ioctl_dev"))<0)
	{
		pr_info("Unable to allocate memory\n");
		return -1;
	}
	pr_info("Major=%d, Minor=%d\n",MAJOR(dev),MINOR(dev));
	cdev_init(&etx_cdev,&fops);
	
	if((cdev_add(&etx_cdev,dev,1))<0)
	{
		pr_info("Cannot add the system to the device\n");
		goto r_class;
	}
	if(IS_ERR(dev_class=class_create(THIS_MODULE,"ioctl_dev")))
	{
		pr_err("Cannot class for this device\n");
		goto r_class;
	}
	if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"ioctl_dev")))
	{
		pr_err("Device is not created.........\n");
		goto r_device;
	}
r_class:
	class_destroy(dev_class);
r_device:
	unregister_chrdev_region(dev,1);
	return -1;
}
static void __exit exit_ioctl(void)
{
		device_destroy(dev_class,dev);
		class_destroy(dev_class);
		cdev_del(&etx_cdev);
		unregister_chrdev_region(dev,1);
		pr_info("Driver is removed from the device list..\n");
}
module_init(init_ioctl);
module_exit(exit_ioctl);

MODULE_AUTHOR("RAMAKANTH");
MODULE_DESCRIPTION("IOCTL DRIVER DEVELOPMENT");
MODULE_VERSION("1.0.6");
MODULE_LICENSE("GPL");

