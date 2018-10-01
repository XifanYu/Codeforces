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

ll t1[Maxn<<2][5];
int t2[Maxn<<2];
int n,x,e,MN=1;
int rk[Maxn],sz=0;
pi q[Maxn];
map<int,int> mp;
char s[5];

void pushup(int p){
	if(p==0) return;
	p=(p-1)/2;
	for(int i=0;i<5;i++) t1[p][i]=t1[lc][i]+t1[rc][(i+t2[lc])%5];
	pushup(p);
}

void add(int x,int v,int p=0,int l=0,int r=MN-1){
	t2[p]++;
	if(l==r){
		t1[p][2]=v;
		pushup(p);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) add(x,v,lc,l,mid);
	else add(x,v,rc,mid+1,r);
}

void del(int x,int p=0,int l=0,int r=MN-1){
	t2[p]--;
	if(l==r){
		t1[p][2]=0;
		pushup(p);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) del(x,lc,l,mid);
	else del(x,rc,mid+1,r);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		if(s[0]=='a'){
			scanf("%d",&e);
			rk[sz++]=e;
			q[i]=pi(1,e);
		}
		else if(s[0]=='d'){
			scanf("%d",&e);
			q[i]=pi(2,e);
		}
		else{
			q[i]=pi(0,0);
		}
	}
	while(MN<sz) MN=MN<<1;
	sort(rk,rk+sz);
	for(int i=0;i<sz;i++) mp[rk[i]]=i;
	for(int i=0;i<n;i++){
		x=q[i].FS;
		if(x==1){
			e=q[i].SC;
			add(mp[e],e);
		}
		else if(x==2){
			e=q[i].SC;
			del(mp[e]);
		}
		else{
			printf("%I64d\n",t1[0][0]);
		}
	}
return 0;
}
