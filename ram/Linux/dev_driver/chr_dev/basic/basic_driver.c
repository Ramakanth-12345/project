/* Manually creating the device file */

#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#include<linux/device.h>

dev_t dev=0;
static struct class *dev_class;
static struct cdev etx_cdev;

static int __init init_device(void);
static void __exit exit_device(void);
static int ext_open(struct inode *inode,struct file *file);
static int ext_release(struct inode *inode,struct file *file);
static ssize_t ext_read(struct file *filep,char __user *buf,size_t len,loff_t *off);
static ssize_t ext_write(struct file *filep,const char __user *buf,size_t len,loff_t *off);

struct file_operations fops =
{
	.owner   = THIS_MODULE, 
	.open    = ext_open,
	.read    = ext_read,
	.write   = ext_write,
	.release = ext_release,
};

static int ext_open(struct inode *inode,struct file *file)
{
	pr_info("Driver is opened sucessfully\n");
	return 0;
}
static int ext_release(struct inode *inode,struct file *file)
{
	pr_info("Driver is closed sucessfully\n");
	return 0;
}
static ssize_t ext_read(struct file *filep,char __user *buf,size_t len,loff_t *off)
{
	pr_info("Driver is available for reading\n");
	return 0;
}
static ssize_t ext_write(struct file *filep,const char __user *buf,size_t len,loff_t *off)
{
	pr_info("Driver is available for writing\n");
	return len;
}

static int __init init_device(void)
{
	if((alloc_chrdev_region(&dev,0,1,"simple_device"))<0)
	{
		pr_err("unable create device file\n");
		return -1;
	}
	pr_info("Device created sucessfully Major=%d Minor=%d\n",MAJOR(dev),MINOR(dev));

	cdev_init(&etx_cdev,&fops);
	        if((cdev_add(&etx_cdev,dev,1)) < 0){
            pr_err("Cannot add the device to the system\n");
            goto r_class;
        }

	dev_class=class_create(THIS_MODULE,"simple_device");
	if(IS_ERR(dev_class))
	{
		pr_err("cannot create struct class for device\n");
		goto r_class;
	}
	if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"simple_device")))
	{
		pr_err("cannot create device\n");
		goto r_device;
	}
	pr_info("Module inserted sucessfully\n");
	pr_warn("Created properly or not\n");
	return 0;
r_device:
	class_destroy(dev_class);
r_class:
	unregister_chrdev_region(dev,1);
	return -1;
}
static void __exit exit_device(void)
{
	device_destroy(dev_class,dev);	
	class_destroy(dev_class);
	cdev_del(&etx_cdev);
	unregister_chrdev_region(dev,1);
	pr_info("Removed Sucessfully\n");
}	
module_init(init_device);
module_exit(exit_device);

MODULE_AUTHOR("RAMAKANTH");
MODULE_DESCRIPTION("SIMPLE DEVICE FILE ALLOCATION");
MODULE_VERSION("1.0");
MODULE_LICENSE("GPL");
