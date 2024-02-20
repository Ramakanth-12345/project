#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#include<asm/uaccess.h>
#include<linux/module.h>
#include<linux/wait.h>
#include<linux/slab.h>
#include<linux/err.h>
#include<linux/kthread.h>
#include<linux/device.h>

unsigned int read_count = 0;
static struct task_struct *wait_thread;

//DECLARE_WAIT_QUEUE_HEAD(wait_queues);

dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;
wait_queue_head_t wait_queues;
int wait_queue_flags=0;

static int __init init_fun(void);
static void __exit exit_fun(void);

static int open_fun(struct inode *inode,struct file *file);
static ssize_t read_fun(struct file *filp,char __user *buf,size_t len,loff_t *off);
static ssize_t write_fun(struct file *filp,const char __user *buf,size_t len,loff_t *off);
static int release_fun(struct inode *inode,struct file *file);

static struct file_operations fops=
{
	.owner   = THIS_MODULE,
	.open    = open_fun,
	.read    = read_fun,
	.write   = write_fun,
	//.unlocked_ioctl = ioctl_fun,
	.release = release_fun,
};
static int wait_fun(void *unused)
{
	while(1)
	{
		pr_info("waiting for event\n");
		wait_event_interruptible(wait_queues,wait_queue_flags!=0);
		if(wait_queue_flags==2){
			pr_info("EVENT CAME OUT OF EXIT FUNCTION\n");
			return 0;
		}
		pr_info("EVENT CAME FROM OF READ FUNCTION : %d\n",++read_count);
		wait_queue_flags = 0;

	}
	do_exit(0);
	return 0;
}

static int open_fun(struct inode *inode,struct file *file)
{
	pr_info("opened for the fun\n");
	return 0;
}

static ssize_t read_fun(struct file *filp,char __user *buf,size_t len,loff_t *off)
{
	pr_info("READ fun is REady\n");
	wait_queue_flags =1;
	wake_up_interruptible(&wait_queues);
	return 0;
}

static ssize_t write_fun(struct file *filp,const char __user *buf,size_t len,loff_t *off)
{
	pr_info("Write is ready for writing\n");
	return len;
}

static int release_fun(struct inode *inode,struct file *file)
{
	pr_info("Device is closed\n");
	return 0;
}
static int __init init_fun(void)
{
	if((alloc_chrdev_region(&dev,0,1,"waitqueue_stat"))<0)
	{
		pr_err("unable to allocate memory\n");
		return -1;
	}
	pr_info("MAjor = %d MInor = %d\n",MAJOR(dev),MINOR(dev));

	cdev_init(&etx_cdev,&fops);
	etx_cdev.owner=THIS_MODULE;
	etx_cdev.ops=&fops;

	if((cdev_add(&etx_cdev,dev,1))<0)
	{
		pr_info("cannot add device\n");
		goto r_class;
	}

	if(IS_ERR(dev_class=class_create(THIS_MODULE,"waitqueue_stat")))
	{
		pr_info("cannot create the class\n");
		goto  r_class;
	}

	if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"waitqueue_stat_device")))
	{
		pr_info("device is not created\n");
		goto r_device;
	}

	wait_thread=kthread_create(wait_fun,NULL,"waitthread");

	if(wait_thread)
	{
		pr_info("Thread created sucessfully\n");
		wake_up_process(wait_thread);
	}
	else
		pr_info("Thread Creation failed\n");

	pr_info("Driver is Successfully INserted\n");
	return 0;
r_class:
	class_destroy(dev_class);
r_device:
	unregister_chrdev_region(dev,1);
	return -1;
}
static void __exit exit_fun(void)
{
	wait_queue_flags= 2;
	wake_up_interruptible(&wait_queues);
	device_destroy(dev_class,dev);
	class_destroy(dev_class);
	cdev_del(&etx_cdev);
	unregister_chrdev_region(dev,1);
	pr_info("Device Removed SUCESSFULLY\n");

}

module_init(init_fun);
module_exit(exit_fun);

MODULE_AUTHOR("RAMAKANTH");
MODULE_DESCRIPTION("WAITQUEUE_STATIC");
MODULE_VERSION("1.2.0");
MODULE_LICENSE("GPL");
