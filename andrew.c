#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include "andrew.h"

asmlinkage long sys_andrew(void)
{
	struct task_struct * proces;
	for_each_process (proces){
		if (proces->parent){
			printk(
				"Parent process: %s, \
				PID_Numer: %ld\n \
				Process State: %ld\n \
				Priority: %ld\n \
				RT_Priority: %ld\n \
				Static Priority: %ld\n \
				Normal Priority: %ld\n", \
				proces->parent->comm, \
				(long)task_pid_nr(proces->parent, \
				(long)proces->parent->state, \
				(long)proces->parent->prio, \
				(long)proces->parent->rt_priority, \
				(long)proces->parent->static_prio, \
				(long)proces->parent->normal_prio \
			);
			printk("\n");
		}
	}
	return 0;
}
