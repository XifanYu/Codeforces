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

const int Maxn=1e5+10;
const int Maxp=200;
const int Maxd=800;

int n,q,t,x;
int l,r,k,ans=0;
int sz[Maxn<<2];
int ch[Maxn<<2][2],par[Maxn<<2],cor[Maxn<<2];
int root[Maxn];
int cnt=1;

void splay(int node){
	
}

int getPos(int node){
	splay(node);
	return sz[ch[node][0]];
}

int getCount(int node){
	splay(node);
	return sz[ch[node][0]];
}

void insertLar(int pos,int id){
	int node=root[0],par=0,left=pos,flag=0;
	while(node){
		par=node;
		if(sz[ch[node][0]]>=left){
			node=ch[node][0];
			flag=0;
		}
		else{
			left-=sz[ch[node][0]]+1;
			node=ch[node][1];
			flag=1;
		}
	}
	sz[cnt]=1;
	if(par){
		ch[par][flag]=cnt;
		update(par);
		splay(cnt);	
	}
	else{
		root[0]=cnt;
	}
}

void insertSub(int pos,int id,int color){
	int node=root[color],par=0;
	while(node){
		
	}
	
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		insertCheck(i,cnt++,0);
		insertCheck(i,cnt++,x);
	}
	build();
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d%d",&t,&l,&r);
		l=(l+ans-1)%n;
		r=(r+ans-1)%n;
		if(l>r) swap(l,r);
		if(t==1){
			rightShift();
		}
		else{
			scanf("%d",&k);
			k=(k+ans-1)%n+1;
			ans=countVal();
			printf("%d\n",ans);
		}
	}
return 0;
}
