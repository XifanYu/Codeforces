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

const ll md=1000000007;
const int Maxn=100005;

int n,m,k,x;
vector<int> adj[Maxn];
ll dp[Maxn][3][15];
ll ans=0;


void dfs(int u,int pr=0){
	for(auto v:adj[u]) if(v!=pr) dfs(v,u);
	if(adj[u].size()==1&&u!=0){
		dp[u][0][0]=k-1;
		dp[u][1][1]=1;
		dp[u][2][0]=m-k;
		return;
	}
	ll sum1[15],sum2[15];
	bool fir=true;
	fill(sum1,sum1+15,0);
	for(auto v:adj[u]){
		if(v==pr) continue;
		if(fir){
			for(int i=0;i<=x;i++) sum2[i]=(dp[v][0][i]+dp[v][1][i]+dp[v][2][i])%md;
			fir=false;
			continue;
		}
		for(int i=0;i<=x;i++) {
			sum1[i]=sum2[i];
			sum2[i]=0;
		}
		for(int i=0;i<=x;i++){
			for(int j=0;j<=x;j++){
				if(i+j<=x) sum2[i+j]=(sum2[i+j]+sum1[i]*(dp[v][0][j]+dp[v][1][j]+dp[v][2][j]))%md;
			}
		}
	}
	for(int i=0;i<=x;i++) dp[u][0][i]=((ll)(k-1)*sum2[i])%md;
	fill(sum1,sum1+15,0);
	fir=true;
	for(auto v:adj[u]){
		if(v==pr) continue;
		if(fir){
			for(int i=0;i<=x;i++) sum2[i]=(dp[v][0][i])%md;
			fir=false;
			continue;
		}
		for(int i=0;i<=x;i++) {
			sum1[i]=sum2[i];
			sum2[i]=0;
		}
		for(int i=0;i<=x;i++){
			for(int j=0;j<=x;j++){
				if(i+j<=x)sum2[i+j]=(sum2[i+j]+sum1[i]*(dp[v][0][j]))%md;
			}
		}
	}
	for(int i=1;i<=x;i++) dp[u][1][i]=sum2[i-1];
	fill(sum1,sum1+15,0);
	fir=true;
	for(auto v:adj[u]){
		if(v==pr) continue;
		if(fir){
			for(int i=0;i<=x;i++) sum2[i]=(dp[v][0][i]+dp[v][2][i])%md;
			fir=false;
			continue;
		}
		for(int i=0;i<=x;i++) {
			sum1[i]=sum2[i];
			sum2[i]=0;
		}
		for(int i=0;i<=x;i++){
			for(int j=0;j<=x;j++){
				if(i+j<=x) sum2[i+j]=(sum2[i+j]+sum1[i]*(dp[v][0][j]+dp[v][2][j]))%md;
			}
		}
	}
	for(int i=0;i<=x;i++) dp[u][2][i]=((ll)(m-k)*sum2[i])%md;
}



int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	adj[0].push_back(1);
	adj[1].push_back(0);
	scanf("%d%d",&k,&x);
	dfs(0);
	for(int i=0;i<=x;i++){
		for(int j=0;j<3;j++){
			ans=(ans+dp[1][j][i])%md;
		}
	}
	printf("%I64d\n",ans);
return 0;
}
