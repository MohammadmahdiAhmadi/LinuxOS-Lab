#include <linux/init.h> // For module init and exit
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h> // For fops
#include <linux/uaccess.h>
#include <linux/kthread.h> // kernel threads
#include <linux/string.h> // for strings :)))
#include <linux/slab.h>
#include <linux/semaphore.h>

#define INIT_BALANCE 2000000
#define ACCOUNT_COUNT 100
#define DEVICE_NAME "bankmodule"

MODULE_LICENSE("GPL");
static int iut_open(struct inode*, struct file*);
static int iut_release(struct inode*, struct file*);
static ssize_t iut_read(struct file*, char*, size_t, loff_t*);
static ssize_t device_write(struct file *, const char  *, size_t, loff_t *); 
char* retacc(void);

static struct file_operations fops = {
   .open = iut_open,
   .read = iut_read,
   .release = iut_release,
   .write = device_write,
};

static int major; // device major number. driver reacts to this major number.

struct bank {
	int acc[ACCOUNT_COUNT]; 	
};
static struct bank bal;


int atoi(char* data){
	printk(KERN_ALERT "atoi working...\n");
	printk(KERN_ALERT "atoi input: %s\n", data);	
	int sum, i;
	sum = 0;
	for (i=0; data[i] >= '0' && data[i] <= '9' ; i++){
		sum *= 10;
		sum += (data[i] - '0');
	}
	printk(KERN_ALERT "atoi result: %d\n", sum);
	return sum;
}
int int_len(int data){
	int len = 0;
	if (!data) len++; // In case of data=0
	while(data){
		len++;
		data/=10;
	}
	return len;	
}
void decode_input(char* data, int* out){ // out: from, to, amount (-1 if '-')
	int temp;

	// from
	if (data[2] == '-') temp = -1;
	else temp = atoi(&(data[2]));
	out[0] = temp;
	printk(KERN_ALERT "out[0] set to %d and its len is %d.\n", out[0],int_len(out[0]));
	// to
	if (data[2+int_len(out[0])+1] == '-') temp = -1;
	else temp = atoi(&(data[2+int_len(out[0])+1]));
	out[1] = temp;
	printk(KERN_ALERT "out[1] set to %d and its len is %d.\n", out[1],int_len(out[1]));
	// amount
	temp = atoi(&(data[2+int_len(out[0])+1+int_len(out[1])+1]));
	out[2] = temp;
	printk(KERN_ALERT "out[2] set to %d and its len is %d.\n", out[2],int_len(out[2]));
	printk(KERN_ALERT "decoded input: %d,%d,%d\n", out[0],out[1],out[2]);

	printk(KERN_ALERT,data[0]);
	if(data[0]=='t')
	{
		printk("here 1");


		if(bal.acc[out[0]]<out[2])
		{
			printk("Eror happend,you dont have enough money");
		}
		else
		{
			bal.acc[out[0]]-=out[2];
			bal.acc[out[1]]+=out[2];
			printk("%d unit decreased from account %d  to account %d",out[3],out[1],out[2]);

		}

	}
	else if(data[0]=='w')
	{
		printk("here 1");

		if(bal.acc[out[0]]<out[2])
		{
			printk("Eror happend,you dont have enough money");
		}
		else
		{
			bal.acc[out[0]]-=out[2];
			printk("%d unit decreased from account %d ",out[3],out[1]);


		}



	}
	else if(data[0]=='d')
	{
		printk("here 1");


		bal.acc[out[1]]+=out[2];


	}
	else{

		printk("Eror");
	}
}


static int __init iut_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops); // 0: auto major ||| name is displayed in /proc/devices ||| fops.
    if (major < 0) {
        printk(KERN_ALERT "Device001 load failed!\n");
        return major;
    }
    
    // Set balance to all wallets
    int i;
    for(i=0;i<100;i++){
	bal.acc[i]=2000000;
    }

    printk(KERN_INFO "iut device module has been loaded: %d\n", major);
    return 0;
}


static void __exit iut_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO " iut device module has been unloaded.\n");
}

static int iut_open(struct inode *inodep, struct file *filep) {
   printk(KERN_INFO " iut  device opened.\n");
   return 0;
}

static int iut_release(struct inode *inodep, struct file *filep) {
   printk(KERN_INFO "iut  device closed.\n");
   return 0;
}



char* retacc(void){
    int j;
    char* ans;
    ans = kmalloc(5000, GFP_KERNEL);
    for(j=0; j<100; j++){
        char t[50];
        sprintf(t, "%d,", bal.acc[j]);
        strcat(ans, t);
    }

    return ans;
}

static ssize_t iut_read(struct file *filep, char *buffer, size_t len, loff_t *offset) {
	int errors = 0;

	char *message=retacc();
	errors = copy_to_user(buffer, message, strlen(message));

	printk(KERN_INFO "iut device read.\n");

	return errors == 0 ? strlen(message) : -EFAULT;
}


static ssize_t device_write(struct file *filp, const char  *buffer, size_t len, loff_t *off) {
    int out[3];

    char* input = NULL;
    input = kmalloc(len + 1, GFP_KERNEL);
    memset(input, 0, len+1);

    if(copy_from_user(input, buffer, len)) {
        printk(KERN_ERR "There is some errors\n");
        return -EFAULT;
    }

    decode_input(input,out);

    return 0;
} 

module_init(iut_init);
module_exit(iut_exit);

