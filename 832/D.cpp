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

typedef long long ll;
typedef pair<int,int> pi; 
const int Maxn=1e5+5;

int n,q; 
int p;
int a,b,c;
int ab,bc,ca;
int dep[Maxn];
int seq[Maxn<<1],id=0;
int fir[Maxn];
int t[Maxn<<3],MN=1;
vector<int> adj[Maxn];

void dfs(int now,int pre){
	fir[now]=id;
	for(auto v:adj[now]){
		if(v!=pre){
			seq[id++]=now;
			dep[v]=dep[now]+1;
			dfs(v,now);
		}
	}
	seq[id++]=now;
}

void build(){
	dep[0]=Maxn;
	while(MN<id) MN*=2;
	for(int i=id-1;i>=0;i--){
		t[i+MN-1]=seq[i];
	}
	for(int i=MN-2;i>=0;i--){
		int l=i*2+1,r=i*2+2;
		if(dep[t[l]]<=dep[t[r]]) t[i]=t[l];
		else t[i]=t[r];
	}
}

int query(int a,int b,int k,int l,int r){
	if(a<=l&&b>=r) return t[k];
	if(a>r||b<l) return 0;
	int mi=(l+r)>>1;
	int x=query(a,b,k*2+1,l,mi),y=query(a,b,k*2+2,mi+1,r);
	return (dep[x]<=dep[y]?x:y); 
}

void calc(int x1,int x2,int x3,int c1,int c2){
	int d1=dep[x1]-dep[c2]+dep[c1]-dep[c2];
	int d2=dep[x2]-dep[c1];
	int d3=dep[x3]-dep[c1];
	printf("%d\n",max(d1,max(d2,d3))+1);
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++){
		scanf("%d",&p);
		adj[i].push_back(p);
		adj[p].push_back(i);
	}
	dfs(1,0);
	build();
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&a,&b,&c);
		ab=query(min(fir[a],fir[b]),max(fir[a],fir[b]),0,0,MN-1);
		bc=query(min(fir[b],fir[c]),max(fir[b],fir[c]),0,0,MN-1);
		ca=query(min(fir[c],fir[a]),max(fir[c],fir[a]),0,0,MN-1);
		if(ab==bc){
			calc(b,c,a,ca,ab);
		}
		else if(bc==ca){
			calc(c,a,b,ab,bc);
		}
		else{
			calc(a,b,c,bc,ca);
		}
	}
return 0;
}
