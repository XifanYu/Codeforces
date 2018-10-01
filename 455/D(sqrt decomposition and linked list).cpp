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

#define MP make_pair
#define FS first
#define SC second
#define LB lower_bound
#define PB push_back
#define lc p*2+1
#define rc p*2+2

typedef long long ll;
typedef pair<int,int> pi; 

const int Maxn=1e5+5;
const int Maxp=320;

int n,q,t,pos;
int l,r,k,ans=0,v;
int a[Maxn];
int cnt[Maxp][Maxn];
int fir[Maxp],lst[Maxp],sz[Maxp];
int pre[Maxn],nxt[Maxn];

int numCount(int i,int val,int l,int r,int lb,int rb){
	if(l>rb||r<lb) return 0;
	if(l<=lb&&r>=rb) return cnt[i][val];
	int del=0;
	if(rb>r){
		int pos=lst[i],tim=rb-r;
		while(tim--){
			if(a[pos]==val) del++;
			pos=pre[pos];
		}
	}
	if(lb<l){
		int pos=fir[i],tim=l-lb;
		while(tim--){
			if(a[pos]==val) del++;
			pos=nxt[pos];
		}
	}
	return cnt[i][val]-del;
}

int find(int m){
	int i=0,lb=1;
	while(lb<m&&lb+sz[i]<=m){
		lb+=sz[i];
		i++;
	}
	return i;
}

void rightShift(int l,int r){
	int x=find(l),y=find(r);
	for(int i=0;i<x;i++){
		l-=sz[i];
		r-=sz[i];
	}
	for(int i=x;i<y;i++) r-=sz[i];
	int v,p;
	if(r==sz[y]){
		v=lst[y];
		lst[y]=pre[v];
	}
	else if(r==1){
		v=fir[y];
		fir[y]=nxt[v];
	}
	else{
		int pos=fir[y];
		while(r>1){
			r--;
			pos=nxt[pos];
		}
		v=pos;
	}
	nxt[pre[v]]=nxt[v];
	pre[nxt[v]]=pre[v];
	sz[y]--;
	cnt[y][a[v]]--;
	if(l==sz[x]){
		p=pre[lst[x]];
	}
	else if(l==1){
		p=pre[fir[x]];
		fir[x]=v;
	}
	else{
		int pos=fir[x];
		while(l>2){
			l--;
			pos=nxt[pos];
		}
		p=pos;
	}
	nxt[v]=nxt[p];
	pre[nxt[p]]=v;
	nxt[p]=v;
	pre[v]=p;
	sz[x]++;
	cnt[x][a[v]]++;
}

void build(int pos){
	int now=pos,id=0;
	while(now!=n+1){
		do{
			cnt[id][a[now]]--;
			now=nxt[now];
		}while(pre[now]!=lst[id]);
		id++;
	}
	memset(sz,0,sizeof sz);
	for(int i=0;pos<=n;i++){
		fir[i]=pos;
		cnt[i][a[pos]]++;
		sz[i]++;
		pos=nxt[pos];
		int k=Maxp;
		while(k--&&pos<=n){
			cnt[i][a[pos]]++;
			sz[i]++;
			pos=nxt[pos];
		}
		lst[i]=pre[pos];
	}
}

void print(int x){
	if(x>n)return;
	printf("%d ",a[x]);
	print(nxt[x]);
}

int main(){
	scanf("%d",&n);
	pre[0]=0;
	nxt[0]=1;
	pre[n+1]=n;
	nxt[n+1]=n+1;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		pre[i]=i-1;
		nxt[i]=i+1;
	}
	for(int i=0;pos<=n;i++){
		fir[i]=pos;
		cnt[i][a[pos]]++;
		sz[i]++;
		pos=nxt[pos];
		int k=Maxp;
		while(k--&&pos<=n){
			cnt[i][a[pos]]++;
			sz[i]++;
			pos=nxt[pos];
		}
		lst[i]=pre[pos];
	}
	scanf("%d",&q);
	for(int i=1,num=0;i<=q;i++){
		if(num==Maxp){
			build(nxt[0]);
			num=0;
		}
		scanf("%d",&t);
		if(t==1){
			num++;
			scanf("%d%d",&l,&r);
			l=((l+ans-1)%n)+1;
			r=((r+ans-1)%n)+1;
			if(l>r) swap(l,r);
			rightShift(l,r);
		}
		else{
			scanf("%d%d%d",&l,&r,&k);
			l=((l+ans-1)%n)+1;
			r=((r+ans-1)%n)+1;
			k=((k+ans-1)%n)+1;
			if(l>r) swap(l,r);
			ans=0;
			for(int i=0,lb=1,rb=sz[0];i<Maxp;lb=rb+1,i++,rb+=sz[i]) {
				ans+=numCount(i,k,l,r,lb,rb);
			}
			printf("%d\n",ans);
		}
	}
return 0;
}
