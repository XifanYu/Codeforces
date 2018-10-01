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
using namespace std;

const int Maxn=200005;

int n,q;
int a[Maxn],b[Maxn];
vector<int> pos[Maxn],v[Maxn];//第i个人所有bid的位置，和每次bid的多少//
int last[Maxn],sortedlast[Maxn];//第i个人最后一次的bid，所有人最后一次的bid由大到小排序// 
map<int,int> rm;//每个bid是谁的// 
int range;//总共几个人参加过bid//

void query(){
	int k;
	scanf("%d",&k);
	int l[Maxn],bid[Maxn];
	fill(l,l+k+2,0);
	fill(bid,bid+k+2,0);
	for(int i=1;i<=k;i++){
		scanf("%d",l+i);
		bid[i]=last[l[i]];
	}
	sort(bid+1,bid+k+1);
	reverse(bid+1,bid+k+1);
	for(int i=1;i<=k;i++) l[i]=rm[bid[i]];
	int ub=min(range,k)+1,lb=0;
	while(ub-lb>1){
		int mi=(ub+lb)/2;
		if(sortedlast[mi]==bid[mi]) lb=mi;
		else ub=mi;
	}
	if(sortedlast[ub]==0) printf("0 0\n");
	else{
		int ans=rm[sortedlast[ub]];
		printf("%d ",ans);
		int id=ub+1;
		while(sortedlast[id]==bid[id-1]&&sortedlast[id]!=0) id++;
		if(sortedlast[id]==0) printf("%d\n",b[pos[ans][0]]);
		else{
			int k=upper_bound(v[ans].begin(),v[ans].end(),sortedlast[id])-v[ans].begin();
			printf("%d\n",b[pos[ans][k]]);
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d %d",a+i,b+i);
	memset(last,0,sizeof last);
	memset(sortedlast,0,sizeof sortedlast);
	for(int i=1;i<=n;i++){
		pos[a[i]].push_back(i);
		v[a[i]].push_back(b[i]);
		last[a[i]]=b[i];
		sortedlast[a[i]]=b[i];
		rm[b[i]]=a[i];
	}
	sort(sortedlast+1,sortedlast+Maxn);
	reverse(sortedlast+1,sortedlast+Maxn);
	int lb=1,ub=Maxn-3;
	while(ub-lb>1){
		int mi=(ub+lb)/2;
		if(sortedlast[mi]==0) ub=mi;
		else lb=mi;
	}
	range=lb;
	scanf("%d",&q);
	for(int i=1;i<=q;i++) query();
return 0;
}
