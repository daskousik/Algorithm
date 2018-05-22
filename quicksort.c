#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void qsor(long long int *array,long long int size);
void print(long long int *array,long long int i,long long int j)
{
	while(i<=j)
	printf("%lld ",array[i++]);
	printf("\n");
}
int main()
{
	while(1)
	{
	 long long  int n,i=0;
	long long unsigned int total_time;
	struct timespec start,end;
	 printf("Enter size ");
	 scanf("%lld",&n);
	long long int *array;
	array=(long long int *)malloc(sizeof(long long int)*n);
	if(array==NULL)
	{
		printf("Memory not allocate");
		continue;
	}
	for(i=0;i<n;i++)
	array[i]=i%119+i%145+i%17;
	long long int size=n;
	clock_gettime(CLOCK_REALTIME,&start);
	qsor(array,size-1);
	clock_gettime(CLOCK_REALTIME,&end);
	total_time=end.tv_nsec-start.tv_nsec;
	printf("%lld\n",total_time);
	//print(array,0,size-1);
	}
}
void swap(long long int *a,long long int *b)
{
	long long int tmp=*a;
	*a=*b;
	*b=tmp;
	return;
	
}
long long int piviot(long long int *array,long long int start,long long int end)
{
	long long int i=start+1,j=end;
	long long int ele=array[start];
	while(i<=j)
	{
		if(array[i]<=ele)
		i++;
		else
		{
			if(ele<array[j])
			j--;
			else
			{
				swap(&array[i],&array[j]);
				i++;
			}
		}
	}
	swap(&array[start],&array[i-1]);
	return i-1;
}
void push(long long int *stack,long long int *top,long long int a,long long int b)
{
	stack[++(*top)]=a;
	stack[++(*top)]=b;
	return;
}
long long int pop(long long int *stack,long long int *top)
{
	return (stack[(*top)--]);
}
void qsor(long long int *array,long long int size)
{	
	
	long long int i,j,k,l,start,end,piv;
	long long int *stack,top=-1;
	stack=(long long int *)malloc(sizeof(long long int)*10000000);
	if(stack==NULL)
	{
		printf("Stack over flow\n");
		return;
	}
	push(stack,&top,0,size);
	while(top!=-1)
	{
		
		end=pop(stack,&top);
		start=pop(stack,&top);
		if(end-start>0)
		{
			piv=piviot(array,start,end);
			push(stack,&top,piv+1,end);
			push(stack,&top,start,piv-1);
		}
	
	}
}

