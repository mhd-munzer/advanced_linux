#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

pid_t get_pid_proc()
{
char target[32];
int pid;

readlink("/proc/self", target, sizeof(target));
sscanf(target, "%d", &pid);
return (pid_t) pid;


}

int main()
{
printf("Proc is reporting %d as pid\n", (int) get_pid_proc());
printf("getpid reports %d", (int)getpid());
return 0;
}
