#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/string.h>
#include<asm/uaccess.h>
#include<linux/uaccess.h>
#include<sys/ioctl.h>

MODULE_LICENSE("GPL");

static char ker_buf[100];

static int a;

static long my_ioctl(struct file *f,unsigned int cmd,unsigned long arc)
{
	switch(cmd)
	{
		case QUERY_GET_VALUE:
			copy_to_user((int*)arg,&a,sizeof(int));
			break;
		case QUERY_SET_VALUE:
			copy_from_user(&a,(int*)arg,sizeof(int));
			break;
		case QUERY_CLEAR_VALUE:
			break;
	}
	return 0;
}

static struct file_operations fops=
{
	.open=dev_open,
	.write=dev_write,
	.read=dev_read,
	.release=dev_close,
	.unlocked_ioctl=my_ioctl
};
static int hello_init(void)   //init function to be called at the time of insmod
{
	int t=register_chrdev(90,"mydev",&fops);
	if(t<0)
		printk(KERN_ALERT "device registration failed.");
	else
		printk(KERN_ALERT "device registred\n");
	return 0;
}
static void hello_exit(void) //exit function to be called at the time of rmmod
{
	unregister_chrdev(90,"mydev");
	printk(KERN_ALERT "exit");
}
static int dev_open(struct inode *inod, struct file *fil)
{
	printk("KERN_ALERT device opened");
	return 0;
}
static ssize_t dev_read(struct file *filep,char *buf,size_t len,loff_t *off)
{
	copy_to_user(buf,ker_buf,len);
	return len;
}
static ssize_t dev_write(struct file *flip,const char *buf,size_t len,loff_t *off)
{
	copy_from_user(ker_buf,buf,len);
	ker_buf[len]=0;
	return len;
}
static int dev_release(struct inode *inod,struct file *fil)
{
	printk("KERN_ALERT device closed\n");
	return 0;
}
	module_init(hello_init);
	module_exit(hello_exit);
