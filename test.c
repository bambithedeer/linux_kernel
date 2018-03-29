#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

int main(){
	printf("Invoking andrew sys call");
	long int ret_status = syscall(333);
	if (ret_status == 0){
		printf("syscall andrew executed correctly.");
	}
	else{
		printf("syscall failed");
	}
	return 0;
}
