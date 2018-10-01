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

const int Maxn=100005;
const ll md=1000000007;

int n,ans=1;
int siz[2*Maxn];
int par[2*Maxn];
bool used[2*Maxn];

int find(int x){
	if(par[x]==x) return x;
return par[x]=find(par[x]);
}

void unit(int x,int y){
	if(x==y) return;
	x=find(x);
	y=find(y);
	if(x==y){
		ans=(ans*2)%md;return;
	}
	siz[y]+=siz[x];
	par[x]=y;
}


int main(){
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++){
		par[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		used[u]=1;
		unit(u,v);
	}
	for(int i=1;i<=2*n;i++){
		if(!used[i]){
			ans=((ll)ans*siz[i])%md;
		}
	}
	printf("%d\n",ans);
return 0;
}
