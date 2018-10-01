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

const int Maxn=100005;

typedef pair<int,int> pi;

int n,q;
int a[Maxn],b[Maxn],l[Maxn],r[Maxn],w[Maxn];//a,b,l输入edge,r,w输入query//
vector<int> adj[Maxn],d[Maxn];//adj邻接表，d[i][j]记录以adj[i][j]为起点i为前驱跑dfs能遍历的点的数量// 
pi e[Maxn];//记录边的顶点// 
double p[Maxn];//记录边被一个随机三元组包含的可能//
map<pi,int> mp;//记录（a,b）b是a邻接表中第几个邻居// 


int dfs(int s,int prv,int id){
	int ret=1;
	if(d[s][mp[pi(s,prv)]]) return d[prv][id]=n-d[s][mp[pi(s,prv)]];
	for(int i=0;i<adj[s].size();i++){
		if(adj[s][i]!=prv) {
			if(d[s][i]==0) {
				ret+=dfs(adj[s][i],s,i);
			}
			else ret+=d[s][i];
		}
	}
return d[prv][id]=ret;
}


int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d %d",a+i,b+i,l+i);
		e[i]=pi(a[i],b[i]);
		mp[pi(a[i],b[i])]=adj[a[i]].size(); 
		adj[a[i]].push_back(b[i]);
		d[a[i]].push_back(0);//最初将d[i][j]都赋为0，后面dfs经过时将其赋值// 
		mp[pi(b[i],a[i])]=adj[b[i]].size();
		adj[b[i]].push_back(a[i]);
		d[b[i]].push_back(0);
		
	}
	double ans=0;
	for(int i=1;i<n;i++){
		pi en=e[i];
		int n1=en.first,n2=en.second;
		if(adj[n1].size()>adj[n2].size()) swap(n1,n2);
		int id1=mp[pi(n1,n2)],id2=mp[pi(n2,n1)];
		int x=(d[n2][id2]?d[n2][id2]:dfs(n1,n2,id2));
		int y=(d[n1][id1]?d[n1][id1]:dfs(n2,n1,id1));
		p[i]=(double(6*x)/n)*(double(y)/(n-1));
		ans+=l[i]*p[i];
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d %d",r+i,w+i);
		int x=r[i],y=w[i];
		ans-=p[x]*(l[x]-w[i]);
		l[x]=w[i];
		printf("%lf\n",ans);
	}
	
return 0;
}
