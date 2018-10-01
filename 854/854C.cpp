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

typedef pair<int,int> pi;
typedef long long ll;

const int Maxn=3*1e5+5;

int n,k;
int c[Maxn];
int ans[Maxn];
ll cost;
priority_queue<pi,vector<pi>,less<pi> > pq;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
	}
	for(int i=1;i<=k;i++) pq.push(pi(c[i],i));
	for(int i=1;i<=n;i++){
		if(i+k<=n) pq.push(pi(c[i+k],i+k));
		pi nex=pq.top();
		int ct=nex.first,id=nex.second;
		pq.pop();
		ans[id]=i+k;
		cost+=(ll)(i+k-id)*ct;
	}
	printf("%I64d\n",cost);
	for(int i=1;i<=n;i++){
		if(i>1) printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	


	
	
	
	
return 0;
}
