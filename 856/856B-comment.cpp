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

const ll mul=37,md=32416187567;//hash的乘数和模数// 
const int Maxt=1000005;//最大test组数量//

//分析：如果两个prefix是similar的，那么称较短的prefix到较长的prefix有一条边，//
//那么所有的prefix被分为若干连通子图，我们只需在每个子图取最大不相邻的点的集合//

int t,n;
unordered_set<ll> node[Maxt];//每一个test中存放的代表prefix的node//
unordered_map<ll,set<ll> > edge[Maxt];//每一个test中边的情况，edge[test][当前prefix]是一个集合，当前prefix到集合中每个node有一条边// 
unordered_map<ll,bool> notroot[Maxt];//如果有一个prefix没有边指向它，我们就可以从它dfs，否则存入notroot//
unordered_map<ll,int> df[Maxt];//记忆化搜索数组，每个df[当前test][当前node]表示这个node的dfs的结果//

int dfs(ll x){//复杂度O(节点的数量)//
	if(df[t][x]) return df[t][x];//计算过就return// 
	int ans1=0,ans2=1;//ans1不取当前节点，ans2取当前节点// 
	for(auto nn:edge[t][x]){
		ans1+=dfs(nn);
		for(auto nnn:edge[t][nn])ans2+=dfs(nnn);
	}
return df[t][x]=max(ans1,ans2);
}

int main(){
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		getchar();
		
		while(n--){
			ll val1=0,val2=0;
			string s="";
			char c;
			while('a'<=(c=getchar())) s+=c;
			int id=0;
			while(id<s.length()){
				ll x=0,y=0;
				x=(val1*mul+s[id])%md;
				if(id!=0) y=(val2*mul+s[id])%md;
				edge[t][y].insert(x);//y向x有一条边// 
				val1=x;
				val2=y; 
				node[t].insert(val1);
				id++;
			}
		}
		
		for(auto v:node[t]){
			for(auto u:edge[t][v]){
				notroot[t][u]=1;//有边指向的不是root//
			}
		}
		
		unordered_set<ll>::iterator it=node[t].begin();
		int ans=0;
		while(it!=node[t].end()){
			if(!notroot[t][*it]) {
				ans+=dfs(*it);//是root就开始dfs//
			}
			it++;
		}
		
		printf("%d\n",ans);
	}
return 0;
}
