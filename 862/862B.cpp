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

const int Maxn=100005;

vector<int> adj[Maxn];
bool a1[Maxn];
int n0;

void dfs(int now,int prv=-1){
	for(auto next:adj[now]){
		if(next!=prv){
			a1[next]=(!a1[now]);
			dfs(next,now);
		}
	}
	if(a1[now]) n0--;
}

int main(){
	int n;
	cin>>n;
	n0=n;
	for(int i=0;i<n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(a1[i]){
			ans+=(long long)n0-(long long)adj[i].size();
		}
	}
	printf("%I64d\n",ans);
return 0;
}
