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

const int INF=1e9+5;
const pi S=pi(0,0);
const pi T=pi(21,21);

int n,t;
char s1[12][12],s2[12][12];
bool infect[12][12];
bool dp[61][12][12][12][12];
queue<pi> q[12][12],nuc,temp;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
vector<pi> adj[22][22];//x,y for scientists, 10+x,10+y for capsules
int capa[22][22][22][22];
int dist[22][22];
int ans=0;

void precalc(){
	memset(dp,false,sizeof dp);
	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			if(s1[x][y]!='Y'&&s1[x][y]!='Z'){
				dp[0][x][y][x][y]=true;
				q[x][y].push(pi(x,y));
			}
			else if(s1[x][y]=='Z'){
				infect[x][y]=true;
				nuc.push(pi(x,y));
			}
		}
	}
	for(int i=1;i<=t;i++){
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				while(!q[x][y].empty()){
					temp.push(q[x][y].front());
					q[x][y].pop();
				}
				while(!temp.empty()){
					int a=(temp.front()).FS,b=(temp.front()).SC;
					temp.pop();
					for(int k=0;k<4;k++){
						int nx=a+dx[k],ny=b+dy[k];
						if(s1[nx][ny]=='Y'||infect[a][b]||infect[nx][ny]) continue;
						if(!dp[i][x][y][nx][ny]){
							dp[i][x][y][nx][ny]=true;
							q[x][y].push(pi(nx,ny));
						}
					}
				}
			}
		}
		while(!nuc.empty()){
			temp.push(nuc.front());
			nuc.pop();
		}
		while(!temp.empty()){
			int a=(temp.front()).FS,b=(temp.front()).SC;
			temp.pop();
			for(int k=0;k<4;k++){
				int nx=a+dx[k],ny=b+dy[k];
				if(s1[nx][ny]=='Y'||infect[nx][ny]) continue;
				infect[nx][ny]=true;
				nuc.push(pi(nx,ny));
			}
		}
	}
}

bool able(int x1,int y1,int x2,int y2){
	for(int i=0;i<=t;i++) if(dp[i][x1][y1][x2][y2]) return true;
	return false;
}

void build(){
	memset(capa,0,sizeof capa);
	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			if('0'<=s1[x][y]&&s1[x][y]<='9'){
				adj[0][0].PB(pi(x,y));
				adj[x][y].PB(S);
				capa[0][0][x][y]=s1[x][y]-'0';
			}
			if('0'<=s2[x][y]&&s2[x][y]<='9'){
				adj[10+x][10+y].PB(T);
				adj[21][21].PB(pi(10+x,10+y));
				capa[10+x][10+y][21][21]=s2[x][y]-'0';
			}
		}
	}
	for(int x1=1;x1<=n;x1++){
		for(int y1=1;y1<=n;y1++){
			for(int x2=1;x2<=n;x2++){
				for(int y2=1;y2<=n;y2++){
					if(able(x1,y1,x2,y2)){
						adj[x1][y1].PB(pi(10+x2,10+y2));
						adj[10+x2][10+y2].PB(pi(x1,y1));
						capa[x1][y1][10+x2][10+y2]=INF;
					}
				}
			}
		}
	}
}

bool bfs(){
	memset(dist,-1,sizeof dist);
	int x1,y1,x2,y2;
	queue<pi> q;
	q.push(S);
	dist[0][0]=0;
	while(!q.empty()){
		x1=(q.front()).FS;
		y1=(q.front()).SC;
		q.pop();
		for(auto v:adj[x1][y1]){
			x2=v.FS;
			y2=v.SC;
			if(dist[x2][y2]==-1&&capa[x1][y1][x2][y2]>0){
				q.push(pi(x2,y2));
				dist[x2][y2]=dist[x1][y1]+1;
			}
		}
	}
	return dist[21][21]>0;
}

int dfs(pi now,int f){
	if(now==T) return f;
	int x1=now.FS,y1=now.SC,x2,y2,w=0;
	for(auto v:adj[x1][y1]){
		x2=v.FS;
		y2=v.SC;
		if(dist[x2][y2]==dist[x1][y1]+1&&capa[x1][y1][x2][y2]>0){
			w=dfs(v,min(f,capa[x1][y1][x2][y2]));
			if(w>0){
				capa[x1][y1][x2][y2]-=w;
				capa[x2][y2][x1][y1]+=w;
				return w;
			}
		}
	}
	return 0;
}

void dinic(){
	while(bfs())ans+=dfs(S,INF);
}

int main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++){
		scanf("%s",s1[i]+1);
		s1[i][0]=s1[i][n+1]=s1[0][i]=s1[n+1][i]='Y';
	}
	for(int i=1;i<=n;i++){
		scanf("%s",s2[i]+1);
		s2[i][0]=s2[i][n+1]=s2[0][i]=s2[n+1][i]='Y';
	}
	precalc();
	build();
	dinic();
	printf("%d\n",ans);
return 0;
}
