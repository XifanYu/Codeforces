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

int n;
int a[2005];
int t[10005],MN=1; 
int best=1e9;

int gcd(int x,int y){
	if(y) return gcd(y,x%y);
	return x;
}

void update(int i,int k){
	i+=MN-1;
	t[i]=k;
	while(i){
		i=(i-1)/2;
		t[i]=gcd(t[i*2+1],t[i*2+2]);
	}
}

void process(){
	while(MN<n) MN*=2;
	for(int i=0;i<n;i++) {
		scanf("%d",a+i);
		update(i,a[i]);
	}
}

int query(int l,int r,int k,int a,int b){
	if(l<=a&&r>=b) return t[k];
	if(l>b||r<a) return 0;
	return gcd(query(l,r,k*2+1,a,(a+b-1)/2),query(l,r,k*2+2,(a+b+1)/2,b));
}

int main(){
	scanf("%d",&n);
	process();
	int l=0,r=0;
	int sum=0;
	for(int i=0;i<n;i++){
		if(a[i]==1) sum++;
	}
	if(sum!=0){
		printf("%d\n",n-sum);
		return 0;
	}
	if(t[0]!=1){
		printf("%d\n",-1);
		return 0;
	}
	while(r<n){
		while(r<n&&query(l,r,0,0,MN-1)!=1){
			r++;
		}
		while(query(l,r,0,0,MN-1)==1){
			l++;
		}
		best=min(best,min(r,n-1)-l+1);
	}
	printf("%d\n",n-1+best);
return 0;
}
