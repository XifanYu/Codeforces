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

const int Maxn=200005;
const ll INF=1e18;

struct edge{
	int u,v,w;
	
};

edge e1[Maxn],e2[Maxn];

vector<int> adj1[Maxn];
int adj2[Maxn];

int n,q;

int dfs1(int now,int pre=-1)
{
	int rez=0;
	for(auto v:adj1[now])
	{
		if(v!=pre)
		{
			dfs1(v,now);
		}
	}
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		e1[i]=edge{a,b,c};
		adj1[a].push_back(i);
	}
	for(int i=1;i<n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		e2[i]=edge{a,b,c};
		adj2[a]=i;
	}
	for(int i=1;i<=q;i++){
		int t;
		scanf("%d",&t);
		if(t==1){
			int i,w;
			scanf("%d%d",&i,&w);
			if(i<n)
			{
				
			}
			else
			{
				
			}
		}
		else{
			int u,v;
			scanf("%d%d",&u,&v);
			
		}
	}
return 0;
}
