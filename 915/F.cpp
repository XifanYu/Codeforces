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

const int Maxn=1e6+5;

int n,x,y;
vector<int> adj[Maxn];
pi a[Maxn];
int f[Maxn];
int sz[Maxn];
ll maxt=0,mint=0;

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void init(){
	for(int i=1;i<=n;i++){
		f[i]=i;
		sz[i]=0;
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].FS);
		a[i].SC=i;
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	sort(a+1,a+n+1);
	init();
	for(int i=1;i<=n;i++){
		ll sum=0,square=0;
		sz[a[i].SC]=1;
		for(auto v:adj[a[i].SC]){
			find(v);
			sum+=sz[f[v]];
			square+=(ll)sz[f[v]]*sz[f[v]];
			if(sz[f[v]]!=0){
				sz[a[i].SC]+=sz[f[v]];
				f[f[v]]=a[i].SC;
			}
		}
		maxt+=(sum+1)*a[i].FS;
		maxt+=(sum*sum-square)*a[i].FS/2;
	}
	init();
	for(int i=n;i>=1;i--){
		ll sum=0,square=0;
		sz[a[i].SC]=1;
		for(auto v:adj[a[i].SC]){
			find(v);
			sum+=sz[f[v]];
			square+=(ll)sz[f[v]]*sz[f[v]];
			if(sz[f[v]]!=0){
				sz[a[i].SC]+=sz[f[v]];
				f[f[v]]=a[i].SC;
			}
		}
		mint+=(sum+1)*a[i].FS;
		mint+=(sum*sum-square)*a[i].FS/2;
	}
	printf("%I64d\n",maxt-mint);
return 0;
}
