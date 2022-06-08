#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
sem_t sem;
sem_t sem1;
int sells= 0;
int products=0;
void* PROCESSA()
{
	while(1)
	{
		sem_wait(&sem);	
		sells++;
		printf("sells = %d\n", sells);
		sem_post(&sem1);
		sleep(1);
	}
}
void* PROCESSB()
{
	while(1)
	{
		sem_wait(&sem1);
		products++;
		printf("products = %d\n", products);
		sem_post(&sem);
		//sleep(1);
		
	}
}
void main()
{
	sem_init(&sem,0,0);
	sem_init(&sem1,0,10);
	pthread_t th1, th2;
	pthread_create(&th1, NULL, &PROCESSA, NULL);
	pthread_create(&th2, NULL, &PROCESSB, NULL);
	while(1);
}
