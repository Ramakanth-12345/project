#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/semaphore.h>
#include<linux/cdev.h>
#include<asm/uaccess.h>
#include<linux/uaccess.h>

struct fake_device
{
	char data[100];  //data to  be store
	struct semaphore sem;  // semaphore 
}virtual_dev;

struct cdev *mcdev;   //m is my device
int major_num;        //major num to be 
int ret;              // to store return value
dev_t dev_num;        // to store major number which is given by kernel 

#define DEVICE_NAME  "soliddevice" //to name it as device name 

int device_open(struct inode *inod,struct file *fil)
{
	if(down_interruptible(&virtual_dev.sem)!=0)
	{
		printk(KERN_ALERT"solid:could not lock device during open\n");
		return -1;
	}
	printk(KERN_INFO"solid:opened device file\n");
	return 0;
}

ssize_t device_read(struct file *fil, char* bufStoreData,size_t bufcount,loff_t* curOffset)
{
	printk(KERN_INFO"solid: Reading from device\n");
	ret=copy_to_user(bufStoreData,virtual_dev.data,bufcount);
	return ret;
}

ssize_t device_write(struct file *fil,const char* bufStoreData,size_t bufcount,loff_t* curOffset)
{
	printk(KERN_INFO"solid: Reading from device\n");
	ret=copy_from_user(virtual_dev.data,bufStoreData,bufcount);
	return ret;
}

int device_close(struct inode *inod,struct file *fil)
{
	up(&virtual_dev.sem);
	printk(KERN_INFO"solid:closed device file\n");
	return 0;
}

struct file_operations fops= {
	.owner=THIS_MODULE,
	.open=device_open,
	.release=device_close,
	.write=device_write,
	.read=device_read
};

static int driver_entry(void)
{
	ret=alloc_chrdev_region(&dev_num,0,1,DEVICE_NAME);
	if(ret<0) // at time kernel function returns negatives, there is an error 
	{
		printk(KERN_ALERT "soliddev: failed allocate major number\n");
		return ret;
	}
	major_num=MAJOR(dev_num);
	printk(KERN_INFO "solid dev: major num is %d",major_num);
	printk(KERN_INFO "\tuse \"mknod /dev/%s c %d 0\" for device file\n",DEVICE_NAME,major_num);

	mcdev = cdev_alloc();
	mcdev->ops = &fops;
	mcdev->owner = THIS_MODULE;

	ret = cdev_add(mcdev,dev_num,1);
	if(ret<0)
	{
		printk(KERN_ALERT "soliddev: unable add cdev to kernel\n");
		return ret;
	}
	sema_init(&virtual_dev.sem,1);
	return 0;
}

static void driver_exit(void)
{
	cdev_del(mcdev);
	unregister_chrdev_region(dev_num,1);
	printk(KERN_ALERT"soliddev:unloading module\n");
}

module_init(driver_entry);
module_exit(driver_exit);
