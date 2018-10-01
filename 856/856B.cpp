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
using namespace std;

typedef long long ll;

const ll mul=37,md=32416187567;
const int Maxt=1000005;

int t,n;
set<ll> node[Maxt];
map<ll,set<ll> > edge[Maxt];
map<ll,bool> notroot[Maxt];
ll pows[Maxt]; 
map<ll,int> df[Maxt];
map<ll,int> df1[Maxt];

int dfs(ll x){
	if(df[t][x]) return df[t][x];
	int ans1=0,ans2=1;
	for(auto nn:edge[t][x]){
		ans1+=dfs(nn);
		ans2+=df1[t][nn];
	}
	df1[t][x]=ans1;
return df[t][x]=max(ans1,ans2);
}

int main(){
	scanf("%d",&t);
	pows[0]=1;
	for(int i=1;i<1000005;i++) pows[i]=(pows[i-1]*mul)%md;
	while(t--){
		scanf("%d",&n);
		getchar();
		while(n--){
			ll val=0;
			string s="";
			char c;
			while('a'<=(c=getchar())) s+=c;
			int id=0;
			while(id<s.length()){
				ll x=(val*mul+s[id])%md;
				ll y=(x+md*1000-s[0]*pows[id])%md;
				edge[t][y].insert(x);
				val=x;
				node[t].insert(val);
				id++;
			}
		}
		for(auto v:node[t]){
			for(auto u:edge[t][v]){
				notroot[t][u]=1;
			}
		}
		set<ll>::iterator it=node[t].begin();
		int ans=0;
		while(it!=node[t].end()){
			if(!notroot[t].count(*it)) {
				ans+=dfs(*it);
			}
			it++;
		}
		printf("%d\n",ans);
	}
return 0;
}
