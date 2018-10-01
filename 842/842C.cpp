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

int n;
int a[Maxn];
vector<int> adj[Maxn];
int maxt[Maxn];
int dp[Maxn];
set<int> p[Maxn];

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

void dfs(int s,int prv=-1){
	for(auto g:p[s]) maxt[s]=max(maxt[s],g);
	for(int i=0;i<adj[s].size();i++){
		int ns=adj[s][i];
		if(ns!=prv){
			dp[ns]=gcd(dp[s],a[ns]);
			for(auto v:p[s]){
				int x=gcd(v,a[ns]);
				p[ns].insert(x);
			}
			p[ns].insert(dp[s]);
			dfs(ns,s);
		}
	}
}


int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dp[1]=a[1];
	p[1].insert(a[1]);
	p[1].insert(0);
	dfs(1);
	for(int i=1;i<=n;i++){
		if(i>1) printf(" ");
		printf("%d",maxt[i]);
	}
	printf("\n");
return 0;
}
