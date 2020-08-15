#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define LL_ADD(item,list) do{			\
	if(item != NULL)					\
	{									\
		item->next = list;				\
		if(list != NULL) list->pre = item;\
		list = item;					\
	}									\
}while(0)								

#define LL_REMOVE(item,list) do{							\
	if(item != NULL)										\
	{														\
		if(item == list)	list = item->next;				\
		if(item->pre != NULL) item->pre->next = item->next;	\
		if(item->next !=NULL) item->next->pre = item->pre;	\
		item->pre = NULL;									\
		item->next = NULL;									\
	}														\
}while(0)



struct NJOB{
	void (*job_func)(void * arg);
	void *arg;
	
	struct NJOB *pre;
	struct NJOB *next;

};

struct NWORK{

	pthread_t pid;
	int terminate;
	struct NMANAGER *pool;

	struct NWORK *pre;
	struct NWORK *next;

};


typedef struct NMANAGER{

	struct NJOB *job;
	struct NWORK *work;

	pthread_mutex_t mtx;
	pthread_cond_t	cond;

}nthreadpool;

void func(void * arg)
{
	int *i = (int *)arg;
	printf("%d\n",*i);
	sleep(1);
}


void threadpool_push(nthreadpool *pool,struct NJOB * job)
{
	printf("push job\n");
	pthread_mutex_lock(&pool->mtx);
	LL_ADD(job,pool->job);
	pthread_cond_signal(&pool->cond);
	pthread_mutex_unlock(&pool->mtx);
}

void threadpool_destory(nthreadpool *pool)
{
	if(pool == NULL)	return ;
	struct NWORK * work = NULL;
	printf("destroy\n\n");
	for(work = pool->work;work!=NULL;work = work->next)
	{
		work->terminate = 1;
	}

	pthread_mutex_lock(&pool->mtx);
	pthread_cond_broadcast(&pool->cond);
	pthread_mutex_unlock(&pool->mtx);
}


void * thread_cb(void * arg)
{
	printf("work is doing\n");
	struct NWORK * work = (struct NWORK *)arg;
	while(1)
	{

		pthread_mutex_lock(&work->pool->mtx);
		while(work->pool->job == NULL)
		{
			printf("----\n");
			if(work->terminate)	break;
			pthread_cond_wait(&work->pool->cond,&work->pool->mtx);
		}

		if(work->terminate)
		{
			pthread_mutex_unlock(&work->pool->mtx);
			break;
		}

		struct NJOB *job = work->pool->job;
		if(job != NULL)
		{
			printf("remove job\n");
			LL_REMOVE(job,work->pool->job);
		}

		pthread_mutex_unlock(&work->pool->mtx);
		job->job_func(job->arg);
	}
	free(work);
	pthread_exit(NULL);
}

int threadpool_create(nthreadpool * pool,int worknum)
{
	if(pool == NULL)	return -1;
	memset(pool,0,sizeof(nthreadpool));
	printf("create pool\n");
	
	if(worknum < 1)		return -1;

	pthread_mutex_t blank_mutex = PTHREAD_MUTEX_INITIALIZER;
	memcpy(&pool->mtx,&blank_mutex,sizeof(pthread_mutex_t));

	pthread_cond_t blank_cond  = PTHREAD_COND_INITIALIZER;
	memcpy(&pool->cond,&blank_cond,sizeof(pthread_cond_t));


	int i = 0;
	for(i= 0 ;i<worknum;i++)
	{
		struct NWORK *work = (struct NWORK *)malloc(sizeof(struct NWORK));
		#if 1 
		if(work == NULL)
		{
			printf("malloc work error");
			return -2;
		}

		memset(work,0,sizeof(struct NWORK));
		work->pool = pool;	
		int ret = pthread_create(&work->pid,NULL,thread_cb,work);
		if(ret == -1)
		{
			perror("pthread create error");
			free(work);
			return -3;
		}
		LL_ADD(work,pool->work);
		#endif
	}
	return 0;
}

int main()
{
	nthreadpool * pool = (nthreadpool *)malloc(sizeof(nthreadpool));;
	if(pool == NULL)
	{
		perror("malloc pool error");
		return -1;
	}

	//printf("%ld\n",sizeof(struct NWORK));

	threadpool_create(pool,2);
	sleep(1);
	#if 1
	for(int i = 0;i<10;i++)
	{
		struct NJOB *job  = (struct NJOB *)malloc(sizeof(struct NJOB));
		if(job == NULL)
		{
			perror("malloc job error");
			return -1;
		}
		memset(job,0,sizeof(struct NJOB));
		job->job_func = func;
		job->arg = &i;
		threadpool_push(pool,job);
		sleep(1);
	}
	#endif
	while(1);
	threadpool_destory(pool);

	return 0;
}
