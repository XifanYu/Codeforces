#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <memory.h>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int n,fb,pr;//n,feedback,previous feedback//
char q[1005];
int pos0=0,pos1=0,tar;
int l,r,nl,nr,remain=0,num;

void query(){
	pr=fb;
	printf("? ");
	for(int i=1;i<=n;i++) putchar(q[i]);
	printf("\n");
	fflush(stdout);
	scanf("%d",&fb);
}

void calc(int k1,int k2){
	k2-=remain;
	nl=(k1-k2+(r-l+1)/2)/2;
	nr=(k1+k2-(r-l+1)/2)/2;
}

int main(){
	scanf("%d",&n);
	fill(q,q+1005,'0');
	query();
	q[1]='1';
	query();
	if(fb==pr+1) {
		pos0=1;
		tar=1;
		q[1]='0';
	}
	else {
		pos1=1;
		tar=0;
		q[1]='1';
		for(int i=2;i<=n;i++) q[i]='1';
	}
	l=2,r=n;
	query();
	num=fb;
	while(l<r){
		for(int i=l;i<=(l+r-1)/2;i++) tar==0?q[i]='0':q[i]='1';
		query();
		calc(num,fb);
		for(int i=l;i<=r;i++) tar==0?q[i]='1':q[i]='0';
		if(nl>0){
			remain+=nr;
			r=(l+r-1)/2;
			num=nl;
		}
		else{
			num=nr;
			l=(l+r+1)/2;
		}
		fflush(stdout);
	}
	if(tar==1) pos1=l;
	else pos0=l;
	printf("! %d %d\n",pos0,pos1);
	fflush(stdout);
}
