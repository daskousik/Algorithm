#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 321321
typedef long long ll;

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

ll mini(ll x,ll y) {
	if(x<y) return x;
	return y;
}

int fibsrch(int n,ll x) {
	ll f2=0,f1=1,f=f1+f2;
	while(f<n) {
		f2=f1;
		f1=f;
		f=f1+f2;
	}
	ll limit=-1;
	while(f>1) {
		ll i=mini(limit+f2,n-1);
		if(a[i].key<x) {
			f=f1;
			f1=f2;
			f2=f-f1;
			limit=i;
		}
		else if(a[i].key>x) {
			f=f2;
			f1-=f2;
			f2=f-f1;
		}
		else return i;
	}
	if(f1 && a[limit+1].key==x) return limit+1;
	return -1;
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
    FILE *fp3 =fopen("fibo_search.txt","w");
	FILE *fp4=fopen("b_srch against fibo.txt","w");
	for(i=10;i<MAX;i+=100) {
		init(i);
        int idx=i+rand();
		clock_gettime(CLOCK_REALTIME,&tps);
		fibsrch(i,idx);
		clock_gettime(CLOCK_REALTIME,&tpe);
		fprintf(fp3,"%d %lu\n",i,tpe.tv_nsec-tps.tv_nsec);
		clock_gettime(CLOCK_REALTIME,&tps);
		bsrch(idx,i);
		clock_gettime(CLOCK_REALTIME,&tpe);
		//double val=(11.000)*log((double)i)/log(2.000000000);
		fprintf(fp4,"%d %lu\n",i,tpe.tv_nsec-tps.tv_nsec);
		//fprintf(fp4,"%d %lf\n",i,val);
	}
	return 0;
}
