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

typedef pair<int,int> pi;
typedef long long ll;

const int Maxn=5005;
const int INF=1e9+5;

int n,m,t;
vector<pi> adj[Maxn];
int dp[Maxn][Maxn];
int pre[Maxn][Maxn];

int main(){
	scanf("%d%d%d",&n,&m,&t);
	for(int i=0;i<m;i++){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		adj[u].push_back(pi(v,c));
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=INF;
		}
	}
	dp[1][1]=0;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			for(auto v:adj[i]){
				int x=v.first,y=v.second;
				if(dp[i][j]+y<=INF&&dp[i][j]+y<dp[x][j+1]){
					dp[x][j+1]=dp[i][j]+y;
					pre[x][j+1]=i;
				}
			}
		}
	}
	int id=n;
	while(dp[n][id]>t) id--;
	printf("%d\n",id);
	stack<int> stk;
	int now=n;
	while(id){
		stk.push(now);
		now=pre[now][id--];
	}
	while(!stk.empty()){
		int p=stk.top();
		stk.pop();
		printf("%d ",p);
	}
return 0;
}
