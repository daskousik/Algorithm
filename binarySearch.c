#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define MAX 321321

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

int bsrch(int idx,int n) {
    int i=0,j=n-1;
    while(i<=j) {
        int m=i+(j-i)/2;
        if(a[m].key==idx) return m;
        if(a[m].key>idx) j=m-1;
        else i=m+1;
    }
    return -1;
}

int main() {
	init(MAX);
    	time_t t;
	srand((unsigned)time(&t));
	int i;
	struct timespec tps,tpe;
    //printf(" TOTAL NUMBER OF RECORDS        |       WORST CASE RUNNING TIME\n");
    FILE *fp3 =fopen("b_search.txt","w");
	FILE *fp4=fopen("b_srch against log_2.txt","w");
	for(i=10;i<MAX;i+=100) {
		init(i);
        	int idx=i+rand();
		clock_gettime(CLOCK_REALTIME,&tps);
		bsrch(idx,i);
		clock_gettime(CLOCK_REALTIME,&tpe);
		double val=(10.500)*log((double)i)/log(2.000000000);
		fprintf(fp3,"%d %lu\n",i,tpe.tv_nsec-tps.tv_nsec);
		fprintf(fp4,"%d %lf\n",i,val);
	}
	return 0;
}
