#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
//sig_atomic_t;
/*typedef struct sigaction
{
int age;
char name[10];
float weight;
}*/
void sig_func(int signal)
{
  printf("signal account");
  exit(1);
}
void *thread_func()
{
 struct sigaction sa ;
memset (&sa,sizeof (sa),0);
sa.sa_handler=&sig_func;
sigaction(SIGINT,&sa,NULL);
printf("this thread is %ld \n ",pthread_self());
}
 int main()
{
int c;
pthread_t tid;
pthread_create(&tid,NULL,&thread_func,NULL);
pthread_join(tid,(void*)&c);
printf("\n %d ",c);
pthread_kill(tid,SIGINT);
pthread_cancel(tid);
return 0;
}

