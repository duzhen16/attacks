#include <stdio.h>
#include <unistd.h>
#include <sched.h>
int main()
{
	unsigned long mask = 1; /* processor 0 */
	if (sched_setaffinity(0,sizeof(mask),&mask) < 0) {
		printf("set cpu affinity failed\n");
		return 0;
	}

	printf("set cpu affinity succeed,now loop on processor 0\n");
	while(1) {
	}
	return 0;
}
