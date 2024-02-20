#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/slab.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/uaccess.h>
#include<asm/uaccess.h>
#include<linux/ioctl.h>
#include<linux/proc_fs.h>
#include<linux/err.h>

#define WR_VALUE _IOW('a','a',int32_t*)
#define RD_VALUE _IOR('a','b',int32_t*)

int32_t value = 0;
char array[30]="procfs FileSystems";
static int len = 1;

dev_t dev =0;
static struct class *dev_class;
static struct cdev etx_cdev;
static struct proc_dir_entry *parent;

static int __init init_fun(void);
static void __exit exit_fun(void);

static int open_fun(struct inode *inode,struct file *file);
static int release_fun(struct inode *inode,struct file *file);
static ssize_t read_fun(struct file *filep,char __user *buf,size_t len,loff_t *off);
static ssize_t write_fun(struct file *filep,const char __user *buf,size_t len,loff_t *off);
static long ioctl_fun(struct file *file,unsigned int cmd,unsigned long arg);

static int open_proc(struct inode *inode,struct file *file);
static int release_proc(struct inode *inode,struct file *file);
static ssize_t read_proc(struct file *filep,char __user *buffer,size_t length,loff_t *off);
static ssize_t write_proc(struct file *filep,const char __user *buffer,size_t len,loff_t *off);

static struct file_operations fops=
{
	.owner=THIS_MODULE,
	.open=open_fun,
	.read=read_fun,
	.write=write_fun,
	.unlocked_ioctl = ioctl_fun,
	.release=release_fun,
};

static struct file_operations fops_proc=
{
	.open=open_proc,
	.read=read_proc,
	.write=write_proc,
	.release=release_proc,
};

static int open_proc(struct inode *inode,struct file *file)
{
	pr_info("proc file is opened\n");
	return 0;
}
static int release_proc(struct inode *inode,struct file *file)
{
	pr_info("proc file closed\n");
	return 0;
}
static ssize_t read_proc(struct file *filep,char __user *buffer,size_t length,loff_t *off)
{
	pr_info("Read_proc file is ready\n");
	if(len)
	{
		len=0;
	}
	else
	{
		len=1;
		return 0;
	}
	if(copy_to_user(buffer,array,30))
	{
		pr_err("Data send : ERR..\n");
	}
	return length;
}
static ssize_t write_proc(struct file *filep,const char __user *buffer,size_t len,loff_t *off)
{
	pr_info("proc write file function...\n");
	if(copy_from_user(array,buffer,20))
	{
		pr_err("len of write_proc...\n");
	}
	return len;
}

static int open_fun(struct inode *inode,struct file *file)
{
	pr_info("Device file is opened for struct function...\n");
	return 0;
}
static int release_fun(struct inode *inode,struct file *file)
{
	pr_info("Device file is closed for file_operations");
	return 0;
}
static ssize_t read_fun(struct file *filep,char __user *buf,size_t len,loff_t *off)
{
	pr_info("Device file for Reading\n");
	return 0;
}
static ssize_t write_fun(struct file *filep,const char __user *buf,size_t len,loff_t *off)
{
	pr_info("Device file is writing\n");
	return len;
}
static long ioctl_fun(struct file *file,unsigned int cmd,unsigned long arg)
{
	switch(cmd)
	{
		case WR_VALUE:
			if(copy_from_user(&value,(int32_t*)arg,sizeof(value)))
			{
				pr_err("data write:ERR....\n");
			}
			pr_info("value = %d\n",value);
			break;
		case RD_VALUE:
			if(copy_to_user((int32_t*)arg,&value,sizeof(value)))
			{
				pr_err("Data Read:ERR...\n");
			}
			break;
		default:pr_info("Default...\n");
			break;
	}
	return 0;
}

static int __init init_fun(void)
{
	if((alloc_chrdev_region(&dev,0,1,"procfs_device"))<0)
	{
		pr_info("memory is not allocated for device\n");
	}
	pr_info("Major=%d Minor=%d",MAJOR(dev),MINOR(dev));

	cdev_init(&etx_cdev,&fops);

	if((cdev_add(&etx_cdev,dev,1))<0)
	{
		pr_info("Cannot add the device\n");
		goto r_class;
	}

	if(IS_ERR(dev_class=class_create(THIS_MODULE,"procfs_device")))
	{
		pr_info("Cannor create the class\n");
		goto r_class;
	}

	if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"procfs_device")))
	{
		pr_info("Cannot create the device\n");
		goto r_device;
	}

	parent=proc_mkdir("procfs_dev",NULL);

	if(parent==NULL)
	{
		pr_info("Unable to create to create Directory\n");
		goto r_device;
	}
	proc_create("pro_etx",0666,parent,&fops_proc);

	pr_info("Driver insertyed sucessfully\n");
	return 0;
	
r_class:
	class_destroy(dev_class);
r_device:
	unregister_chrdev_region(dev,1);
	return -1;
}
static void __exit exit_fun(void)
{
	proc_remove(parent);
	device_destroy(dev_class,dev);
	class_destroy(dev_class);
	unregister_chrdev_region(dev,1);
	pr_info("Device is sucessfully EJECTED\n");
}

module_init(init_fun);
module_exit(exit_fun);

MODULE_AUTHOR("RAMAKANTH");
MODULE_DESCRIPTION("PROCFS FILESYSTEM CREATION");
MODULE_AUTHOR("gopaganiramakanth@gmail.com");
MODULE_LICENSE("GPL");
MODULE_VERSION("5.1.2");

