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

class line{
	public: 
		ll k,m;
		bool operator< (const line &o) const{
			return k<o.k||(k==o.k&&m<o.m);
		}
		bool operator== (const line &o) const{
		    return k==o.k&&m==o.m;
		}
};

const int Maxn=1e5+5;
const ll INF=1e18+5;

int n,u,v;
int a[Maxn],b[Maxn],pt[Maxn]; //pt[a] (pointer of 'a') is to store the cell in which the set of all current lines(linear functions) of the subtree of 'a' is stored.
vector<int> adj[Maxn];
ll dp[Maxn];
set<line> s[Maxn];

bool check(line l1,line l2,line l3){ //determine if l2 can be deleted from the set of lines
	double d=1.0*(l3.k-l1.k)*(l2.m-l1.m)-1.0*(l2.k-l1.k)*(l3.m-l1.m); //determine if the intersection of l3 and l1 lies left to the intersection of l2 and l1
	if(d>=0) return true; //if so, l2 can be deleted
	return false;
}

void insert(int id,line o){//insert line o into the set with an id
	if(s[id].size()<2){
		s[id].insert(o);
		return;
	}
	set<line>::iterator r=s[id].LB(o),l=r,t;
	if(r!=s[id].end()&&*r==o) return; //determine if line o already exists in the set 
	if(l!=s[id].begin()){
		l--;
		if(r!=s[id].end()&&check(*l,o,*r)) return; //determine if line o should be inserted
		s[id].insert(o);
		while(l!=s[id].begin()){
		    t=l--;
			if(check(*l,*t,o)){ //delete extra lines with slope less than line o
				s[id].erase(t);
			}
			else break;
		}
	}
	if(r!=s[id].end()){
	    t=r++;
		while(r!=s[id].end()){
			if(check(o,*t,*r)){ //delete extra lines with slope greater than line o
				s[id].erase(t);
				t=r++;
			}
			else break;
		}
	}
}

ll gety(line o,int x){ //get the value y=f(x) for linear function o
	return o.m+(ll)x*o.k;
}

ll calc(int id,int x){
	int lb=-Maxn,ub=Maxn+1,mi; //perform a binary search on slope
	set<line>::iterator it;
	while(ub-lb>1){
		mi=(ub+lb)>>1;
		it=s[id].LB(line{mi,INF});
		if(it!=s[id].begin()&&gety(*prev(it),x)<gety(*it,x)) ub=mi; //determine the direction of binary search
		else lb=mi;
	}
	it=s[id].LB(line{lb,INF}); //get the line where we can get the least value at pos=x
	return gety(*it,x);
}

void merge(int id1,int id2){
	for(auto v:s[id1]){
		insert(id2,v);
	}
}

void dfs(int now,int pre){
	int weight=0,big=now; //find a heavy children and merge all the light children's line set to the heavy children's line set
	for(auto nxt:adj[now]){
		if(nxt!=pre){
			dfs(nxt,now);
			if(s[pt[nxt]].size()>weight){
				weight=s[pt[nxt]].size();
				big=nxt;
			}
		}
	}
	pt[now]=pt[big];//set pointer of current node to the pointer of the heavy children, since we are going to merge the other light children to the set
	if(big==now){//the node is a leaf; initialize the leaf
		dp[now]=0;
		pt[now]=now;
		insert(now,line{-Maxn,INF});
		insert(now,line{Maxn,INF});
		insert(now,line{b[now],0});
		return;
	}
	for(auto nxt:adj[now]){
		if(nxt!=pre&&nxt!=big){
			merge(pt[nxt],pt[big]); //merge
		}
	}
	dp[now]=calc(pt[now],a[now]); //find the minimum value of all functions of subtrees at pos=a[now]
	insert(pt[now],line{b[now],dp[now]}); //insert the new line into the set
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)printf("%I64d ",dp[i]);printf("\n");
return 0;
}
