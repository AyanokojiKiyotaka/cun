#include<unistd.h>
#include<sys/syscall.h>
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int cnt;
    pid_t *pid=(pid_t*)malloc(sizeof(pid_t )*100);
    unsigned long *time=(unsigned long*)malloc(sizeof(unsigned long)*100);
    char **comm=(char**)malloc(sizeof(char*)*100);
    for(int i=0;i<100;++i)
    {
        comm[i]=(char*)malloc(sizeof(char )*64);
    }
        
    syscall(332,&cnt,pid,time,comm);
    printf("cnt:%d\n",cnt);
    printf("pid\t\ttime\t\tcomm\n");
    for(int i=0;i<cnt&&i<100;++i)
    {
        printf("%d\t\t%lu\t\t%s\n",pid[i],time[i],comm[i]);
    }
    return 0;
}
