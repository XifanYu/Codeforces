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

const int Maxn=10005;


int n,ans=0;
int p[Maxn],c[Maxn],f[Maxn],used[Maxn];
vector<int> adj[Maxn];

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void join(int a,int b){
	f[find(a)]=find(b);
}

int main(){ 
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d",p+i);
		adj[i].push_back(p[i]);
		adj[p[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
		f[i]=i;
	}
	for(int i=1;i<=n;i++){
		for(auto v:adj[i]){
			if(c[i]==c[v]){
				if(find(i)!=find(v)) join(i,v);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!used[find(i)]){
			used[find(i)]=1;
			ans++;
		}
	}
	printf("%d\n",ans);
return 0;
}
