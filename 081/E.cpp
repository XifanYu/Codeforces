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

#define lc p*2+1
#define rc p*2+2

typedef long long ll;
typedef pair<int,int> pi; 

const int Maxn=1e5+5;

bool vis[Maxn],lp[Maxn];
int bf[Maxn],sx[Maxn],stk[Maxn];
vector<int> adj[Maxn];
vector<pi> ansp,cansp[2];
int dp1[Maxn][2];
int dp2[Maxn][2];
int ps[Maxn][2];
int croot,cans[2],cp[2],flag;
int ans,p;
int n;

void findloop(int now){
	stk[now]=1;
	for(auto v:adj[now]){
		if(stk[v]==1){
			lp[v]=true;
		}
		else findloop(v);
	}
	stk[now]=2;
}

void dfs1(int now){
	vis[now]=true;
	dp1[now][0]=dp1[now][1]=0;
	int rez=0;
	for(auto v:adj[now]){
		if(v!=croot){
			dfs1(v);
			dp1[now][0]+=max(dp1[v][0],dp1[v][1]);
		}
	}
	for(auto v:adj[now]){
		if(v!=croot){
			rez=max(rez,dp1[now][0]-max(dp1[v][0],dp1[v][1])+dp1[v][0]+1);
		}
	}
	dp1[now][1]=rez;
}

void dfs2(int now){
	dp2[now][0]=dp2[now][1]=0;
	int rez1=0,rez2=0;
	for(auto v:adj[now]){
		if(v!=croot){
			dfs2(v);
			if(dp1[v][0]>dp1[v][1]) dp2[now][0]+=dp2[v][0];
			else if(dp1[v][0]<dp1[v][1]) dp2[now][0]+=dp2[v][1];
			else dp2[now][0]+=max(dp2[v][0],dp2[v][1]);
		}
	}
	for(auto v:adj[now]){
		if(v!=croot){
			int x;
			if(dp1[v][0]>dp1[v][1]){
				rez1=dp1[now][0]+1;
				x=dp2[now][0]+(sx[now]==sx[v]?0:1);
			}
			else if(dp1[v][0]<dp1[v][1]){
				rez1=dp1[now][0]-dp1[v][1]+dp1[v][0]+1;
				x=dp2[now][0]-dp2[v][1]+dp2[v][0]+(sx[now]==sx[v]?0:1);
			}
			else{
				rez1=dp1[now][0]+1;
				x=dp2[now][0]-max(dp2[v][0],dp2[v][1])+dp2[v][0]+(sx[now]==sx[v]?0:1);
			}
			if(rez1==dp1[now][1]){
				if(rez2<=x){
					rez2=x;
					ps[now][flag]=v;
				}
			}
		}
	}
	dp2[now][1]=rez2;
}

void dfs3(int now){
	if(dp1[now][0]>dp1[now][1]){
		for(auto v:adj[now]){
			if(v!=croot)dfs3(v);
		}
	}
	else if(dp1[now][0]<dp1[now][1]){
		for(auto v:adj[now]){
			if(v!=croot){
				if(v==ps[now][flag]){
					cansp[flag].push_back(pi(now,v));
					for(auto u:adj[v]){
						if(u!=croot) dfs3(u);
					}
				}
				else dfs3(v);
			}
		}
	}
	else if(dp2[now][0]>dp2[now][1]){
		for(auto v:adj[now]){
			if(v!=croot)dfs3(v);
		}
	}
	else{
		for(auto v:adj[now]){
			if(v!=croot){
				if(v==ps[now][flag]){
					cansp[flag].push_back(pi(now,v));
					for(auto u:adj[v]){
						if(u!=croot) dfs3(u);
					}
				}
				else dfs3(v);
			}
		}
	}
	return;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",bf+i,sx+i);
		adj[bf[i]].push_back(i);
	}
	memset(vis,0,sizeof vis);
	memset(stk,0,sizeof stk);
	for(int i=1;i<=n;i++){
		if(!stk[i])findloop(i);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&lp[i]){
			flag=0;
			croot=i;
			dfs1(i);
			dfs2(i);
			dfs3(i);
			if(dp1[i][0]>dp1[i][1]){
				cans[flag]=dp1[i][0];
				cp[flag]=dp2[i][0];
			}
			else if(dp1[i][0]<dp1[i][1]){
				cans[flag]=dp1[i][1];
				cp[flag]=dp2[i][1];
			}
			else{
				cans[flag]=dp1[i][0];
				cp[flag]=max(dp2[i][0],dp2[i][1]);
			}
			flag=1;
			croot=bf[i];
			dfs1(bf[i]);
			dfs2(bf[i]);
			dfs3(bf[i]);
			if(dp1[bf[i]][0]>dp1[bf[i]][1]){
				cans[flag]=dp1[bf[i]][0];
				cp[flag]=dp2[bf[i]][0];
			}
			else if(dp1[bf[i]][0]<dp1[bf[i]][1]){
				cans[flag]=dp1[bf[i]][1];
				cp[flag]=dp2[bf[i]][1];
			}
			else{
				cans[flag]=dp1[bf[i]][0];
				cp[flag]=max(dp2[bf[i]][0],dp2[bf[i]][1]);
			}
			if(cans[0]>cans[1]){
				ans+=cans[0];
				p+=cp[0];
				for(auto v:cansp[0])ansp.push_back(v);
			}
			else if(cans[0]<cans[1]){
				ans+=cans[1];
				p+=cp[1];
				for(auto v:cansp[1])ansp.push_back(v);
				
			}
			else if(cp[0]>cp[1]){
				ans+=cans[0];
				p+=cp[0];
				for(auto v:cansp[0])ansp.push_back(v);				
			}
			else{
				ans+=cans[1];
				p+=cp[1];
				for(auto v:cansp[1])ansp.push_back(v);				
			}
			cansp[0].clear();
			cansp[1].clear();
		}
	}
	printf("%d %d\n",ans,p);
	for(auto v:ansp){
		printf("%d %d\n",v.first,v.second);
	}
return 0;
}
