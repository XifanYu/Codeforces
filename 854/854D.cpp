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
using namespace std;

typedef pair<int,int> pi;
typedef long long ll;

const int Maxn=1e5+5;
const ll INF=1e12;

struct F{
	int d,f,t,c;
};

int n,m,k;
F f[Maxn];
ll front[Maxn],back[Maxn];
ll mincost=1e14;
ll cost[Maxn];
ll tcost;

bool cmp(F a,F b){
	return a.d<b.d;
} 

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&(f[i].d),&(f[i].f),&(f[i].t),&(f[i].c));
	}
	sort(f+1,f+m+1,cmp);
	tcost=(ll)n*INF;
	for(int i=0;i<=m+1;i++) {
		front[i]=tcost;
		back[i]=tcost;
	}
	fill(cost,cost+Maxn,INF);
	for(int i=1;i<=m;i++){
		front[i]=front[i-1];
		if(f[i].t==0){
			int city=f[i].f;
			if(f[i].c<cost[city]){
				front[i]+=(ll)f[i].c-cost[city];
				cost[city]=f[i].c;
			}
		}
	}
	fill(cost,cost+Maxn,INF);
	for(int i=m;i>=1;i--){
		back[i]=back[i+1];
		if(f[i].f==0){
			int city=f[i].t;
			if(f[i].c<cost[city]){
				back[i]+=(ll)f[i].c-cost[city];
				cost[city]=f[i].c;
			}
		}
	}
	int l=1,r=1;
	while(l<=m&&r<=m){
		if(f[l].t!=0) {
			l++;
			continue;
		}
		while(r<=m&&f[r].d-f[l].d<=k) r++;
		while(r<=m&&f[r].f!=0) r++;
		mincost=min(mincost,front[l]+back[r]);
		l++;
	}
	if(mincost<=1e12)printf("%I64d\n",mincost);
	else printf("-1\n");
	
	

return 0;
}

