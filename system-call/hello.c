#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/uaccess.h>

SYSCALL_DEFINE1(hello, struct myTask *, tasksList)
{
	int i = 0;
	struct task_struct *task;
	for_each_process(task)
	{
		task->comm;
		task->pid;

		copy_to_user(tasksList[i].name, task->comm, sizeof(task->comm));
		copy_to_user(&tasksList[i].pid, &task->pid, sizeof(task->pid));

		i = i + 1;
	}

	printk("Hello From Kernel\n");
	return i;
}

SYSCALL_DEFINE2(hello2, int, number, int, number2)
{
	printk("Hello From Kernel 2\n");
	return number*number2;
}
