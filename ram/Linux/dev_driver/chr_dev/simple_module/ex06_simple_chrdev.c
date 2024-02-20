#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("RAM");


int dev_open(struct inode *ino,struct file *fil)
{
	printk(KERN_ALERT"kernel function %s\n",__FUNCTION__);
	return 0;
}
ssize_t dev_read(struct file *file,char __user *buf,size_t len,loff_t *loff)
{
	printk(KERN_ALERT"kernel function %s\n",__FUNCTION__);
	return 0;
}
ssize_t dev_write(struct file *file,const char __user *buf,size_t len,loff_t *loff)
{
	printk(KERN_ALERT"kernel function %s\n",__FUNCTION__);
	return len;
}
int dev_release(struct inode *ino,struct file *fil)
{
	printk(KERN_ALERT"kernel function %s\n",__FUNCTION__);
	return 0;
}

struct file_operations fops =
{
	.owner=THIS_MODULE,
	.open=dev_open,
	.write=dev_write,
	.read=dev_read,
	.release=dev_release
};
static int simple_init(void)
{
	printk(KERN_ALERT"kernel start function %s\n",__FUNCTION__);
	register_chrdev(240,"simple_function",&fops);
	return 0;
}

void simple_exit(void)
{
	printk(KERN_ALERT"Kernal stop function %s\n",__FUNCTION__);
	unregister_chrdev(240,"simple_function");
}

module_init(simple_init);
module_exit(simple_exit);
