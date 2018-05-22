#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 200010

typedef struct friend_info {
	int key;
	float amount;
}wallet;

wallet a[MAX];

void init(int n) {
	int i;
	time_t t;
	srand((unsigned)time(&t));
	for(i=0;i<n;i++) {
		a[i].key=i+1;
		a[i].amount=i%120+rand()%1000;
	}
}

void solve1(int idx,int n) {
	int i;
	for(i=0;i<n;i++) {
		if(a[i].key==idx)  return ;
	}
}

int main() {
	init(MAX);
    time_t t;
	srand((unsigned)time(&t));
	int i;
	clock_t s,e;
	//printf(" TOTAL NUMBER OF RECORDS        |       WORST CASE RUNNING TIME\n");
	FILE *fp1 =fopen("l_search.txt","w");
	for(i=10;i<MAX;i+=100) {
		init(i);
        int idx=i+rand();
		s=clock();
		solve1(idx,i);
		e=clock();
		double diff1=(double)(e-s)/CLOCKS_PER_SEC;
		fprintf(fp1,"%d %f\n",i,diff1);
	}
	return 0;
}
