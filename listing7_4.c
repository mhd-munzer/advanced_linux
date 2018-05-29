#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

void print_process_env(pid_t pid)
{
char filename[24];
int fd;
char* next_var;
char env[8192];
size_t length;

snprintf(filename, sizeof(filename), "/proc/%d/environ", (int)pid);
fd = open(filename, O_RDONLY);
length = read(fd, env, sizeof(env));
close(fd);
env[length] = '\0';

next_var = env;

while (next_var < env + length){
printf("%s\n", next_var);
next_var += strlen(next_var) + 1;

}
}

int main(int args, char* argv[])
{
pid_t pid = (pid_t) atoi(argv[1]);
print_process_env(pid);
return 0;
}
