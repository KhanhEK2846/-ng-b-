#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>
#include<semaphore.h>
sem_t sem1, sem2;
int n;
int i = 0;
static int dem = 0;
int a[100000];
void* PROCESS1()
{
	while (1)
{
	sem_wait(&sem1);
	if (dem < n) 
	{
	a[i++] = rand() % (n - 1);
	dem++;
	printf("\nThread 1: So phan tu co trong a la %2d", dem);
	}
	sem_post(&sem1);
	sleep(2);
	
}

}

void* PROCESS2()
{
	int j, b;
	while (1)
	{
		sem_wait(&sem1);
		//if (dem <= n) {
		if (dem == 0)
		{
			printf("\nThread 2: Nothing in array a");
		}
		else
		{
			dem--;
			b = a[0];
			for (j = 0; j < dem; j++)
			{
				a[j] = a[j + 1];
			}		
		printf("\nThread 2: So phan tu co trong a la %2d", dem);
		}
		sem_post(&sem1);
		sleep(1);
	}

}

void main()
{
	sem_init(&sem1, 0, 1);
	//sem_init(&sem2, 0, 0);
	printf("\nEnter n: ");
	scanf("%d",&n);
	pthread_t th1, th2;
	pthread_create(&th1, NULL, PROCESS1, NULL);
	pthread_create(&th2, NULL, PROCESS2, NULL);
	while(1);

}
