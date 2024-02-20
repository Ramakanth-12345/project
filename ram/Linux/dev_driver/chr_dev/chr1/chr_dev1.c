#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/uaccess.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/slab.h>
#include<linux/kdev_t.h>
#include<linux/device.h>
#include<linux/ioctl.h>
#include<asm/uaccess.h>
#include<linux/proc_fs.h>
#include<linux/interrupt.h>
#include<asm/io.h>
#define mem_size 1024

#define IRQ_NO 1
unsigned int i=0;
void tasklet_fun(unsigned long);

struct tasklet_struct *tasklet;
/*Declation of tasklet static method*/

//DECLARE_TASKLET(tasklet,tasklet_fun,1);

/*Tasklet Function body declaration*/

void tasklet_fun(unsigned long data)
{
	printk(KERN_INFO"Executing the tasklet function : data=%ld\n",data);

}

//interrupr handler for IRQ 1.
static irqreturn_t irq_handler(int irq,void *dev_id)
{
	printk(KERN_INFO"Keyboard:occured %d\n",i);
	tasklet_schedule(tasklet);
	i++;
	return IRQ_HANDLED;
}
volatile int chr_value = 0;


char ch_arr[40]= "Welcome to Procfs ramakanth tutorial\n";
static int len = 1;
//IOCTL Macro
#define WR_DATA _IOW('a','a',int32_t*)
#define RD_DATA _IOR('a','b',int32_t*)

int32_t val = 0;

dev_t dev=0;
static struct class *dev_class;
static struct cdev my_cdev;
static struct proc_dir_entry *parent;
uint8_t *kernel_buffer;
struct kobject *kobj_ref;

static int __init chr_driver_init(void);
static void __exit chr_driver_exit(void);
static int my_open(struct inode *inode,struct file *file);
static ssize_t my_read(struct file *fil,char __user *buf,size_t len,loff_t *loff);
static ssize_t my_write(struct file *fil,const char __user *buf,size_t len,loff_t *loff);
static int my_release(struct inode *inode,struct file *file);
static long my_ioctl(struct file *file,unsigned int cmd,unsigned long arg);

static int open_proc(struct inode *inode,struct file *file);
static ssize_t read_proc(struct file *filp,char __user *buffer,size_t len,loff_t *off);
static ssize_t write_proc(struct file *filp,const char __user *buff,size_t len,loff_t *offset);
static int release_proc(struct inode *inode,struct file *file);

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open  = my_open,
	.read  = my_read,
	.write = my_write,
.unlocked_ioctl = my_ioctl,
	.release = my_release
};

static  struct file_operations proc_fops =
{
	.open	= open_proc,
	.write	= write_proc,
	.read	= read_proc,
	.release = release_proc
};

static int open_proc(struct inode *inode,struct file *file)
{
	printk(KERN_INFO"Procfs file is released\n");
	return 0;
}
static ssize_t read_proc(struct file *filp,char __user *buffer,size_t lenght,loff_t *off)
{
	printk(KERN_INFO"Procfs file is reading\n");
	if(len)
		len=0;
	else
	{
		len=1;
		return 0;
	}
	copy_to_user(buffer,ch_arr,40);
	return lenght;
}
static ssize_t write_proc(struct file *filp,const char __user *buff,size_t len,loff_t *offset)
{
	printk(KERN_INFO"Procfs file is writing\n");
	copy_from_user(ch_arr,buff,len);
	return len;
}
static int release_proc(struct inode *inode,struct file *file)
{
	printk(KERN_INFO"procfs file is opened\n");
	return 0;
}

static int my_open(struct inode *inode,struct file *file)
{
        /* creating Physical Memory*/
        if((kernel_buffer=kmalloc(mem_size,GFP_KERNEL))==0)
        {
                printk(KERN_INFO"cannot allocate the memory to the kernel\n");
                return -1;
        }
        printk(KERN_INFO"Device file OPENED\n");
        return 0;

}

static int my_release(struct inode *inode,struct file *file)
{
	kfree(kernel_buffer);
	printk(KERN_INFO"Device file closed\n");
	return 0;
}

static ssize_t my_read(struct file *fil,char __user *buf,size_t len,loff_t *loff)
{
	copy_to_user(buf,kernel_buffer,mem_size);
	printk(KERN_INFO"Data Read: DONE\n");
	return mem_size;
}

static ssize_t my_write(struct file *fil,const char __user *buf,size_t len,loff_t *loff)
{
	copy_from_user(kernel_buffer,buf,len);
	printk(KERN_INFO"Data is written sucessfully\n");
	return len;
}

static int __init chr_driver_init(void)
{
	/*Aloloctaing MAJOR num*/
	if((alloc_chrdev_region(&dev,0,1,"MY_DEV"))<0)
	{
		printk(KERN_INFO"Unable to allocate major number..\n");
		return -1;
	}

	printk(KERN_INFO"Major=%d\tMinor=%d",MAJOR(dev),MINOR(dev));

	/*Creating Cdev Structure*/

	cdev_init(&my_cdev,&fops);

	/*Adding character device to the system*/
		if((cdev_add(&my_cdev,dev,1))<0)
		{
			printk(KERN_INFO"cannot add the device\n");
			goto r_class;
		}

	/*creating struct class*/
		if((dev_class=class_create(THIS_MODULE,"my_class"))==NULL)
		{
			printk(KERN_INFO"cannot create the struct class");
			goto r_class;
		}
	/*creating device*/

		if((device_create(dev_class,NULL,dev,NULL,"my_device"))==NULL)
		{
			printk(KERN_INFO"cannot create the device");
			goto r_device;
		}
	/*creating directory*/

		parent =proc_mkdir("chr",NULL);
		if(parent == NULL)
		{
			pr_info("Error creating proc dir\n");
			goto r_device;
		}
	/*creating the proc entry*/
		proc_create("chr_proc",0666,NULL,&proc_fops);

	/*creating the interrupt request handler*/
		if(request_irq(IRQ_NO,irq_handler,IRQF_SHARED,"my_device",(void*)(irq_handler)))
			{
				printk(KERN_INFO"my_device:cannot register IRQ\n");
				goto irq;
			}
		tasklet = kmalloc(sizeof(struct tasklet_struct),GFP_KERNEL);
		if(tasklet==NULL)
		{
			printk(KERN_INFO"Cannot alloctae memory for Tasklet\n");
			goto irq;
		}


		tasklet_init(tasklet,tasklet_fun,0);//Dynamic method
		printk(KERN_INFO"Device is inserted properly\n");
		return 0;
irq:
		free_irq(IRQ_NO,(void*)(irq_handler));

r_device:
		class_destroy(dev_class);//if device is not crerated this destory the class


r_class:
		unregister_chrdev_region(dev,1);//register driver is unregistered 
		return -1;
}

static long my_ioctl(struct file *fil,unsigned int cmd,unsigned long arg)
{
	switch(cmd)
	{
		case WR_DATA:
			copy_from_user(&val,(int32_t*)arg,sizeof(val));
			printk(KERN_INFO"val=%d\n",val);
			break;
		case RD_DATA:
			copy_to_user((int32_t*)arg,&val,sizeof(val));
			break;
	}
	return 0;
}

void __exit chr_driver_exit(void)
{
	free_irq(IRQ_NO,(void*)(irq_handler));
	tasklet_kill(tasklet);
	proc_remove(parent);
	device_destroy(dev_class,dev);
	class_destroy(dev_class);
	cdev_del(&my_cdev);
	unregister_chrdev_region(dev,1);

	printk(KERN_INFO"Device driver is removed sucessfully\n");
}
module_init(chr_driver_init);
module_exit(chr_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("RAM123");
MODULE_DESCRIPTION("THE CHARACTER DRIVER");
MODULE_VERSION("1.6");

