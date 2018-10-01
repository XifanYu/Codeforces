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

typedef pair<int,pair<int,int> > pip;
typedef pair<int,int> pi;
typedef long long ll;

const int Maxn=505,Maxq=250005;

int n,m,k,q; 
int a[Maxn][Maxn];
pip p[Maxq];

bool check(int x){
	memset(a,0,sizeof a);
	int t=p[x].first;
	for(int i=0;i<q;i++){
		pip v=p[i];
		if(v.first<=t){
			a[v.second.first][v.second.second]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]) a[i][j]+=a[i-1][j];
		}
	}
	for(int i=1;i<=n;i++){
		int l=1,r=1;
		while(r<=m&&l<=m){
			while(l<=m&&a[i][l]<k) l++;
			r=l;
			while(r<=m&&a[i][r]>=k) r++;
			if(r-l>=k) return true;
			l=r;
		}
	}
return false;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	cin>>n>>m>>k>>q;
	for(int i=0;i<q;i++){
		int x,y,t;
		cin>>x>>y>>t;
		p[i]=pip(t,pi(x,y));
	}
	sort(p,p+q);
	int lb=-1,ub=q;
	while(ub-lb>1){
		int mi=(ub+lb)/2;
		if(check(mi)) ub=mi;
		else lb=mi;
	}
	if(ub==q) cout<<-1<<"\n";
	else cout<<p[ub].first<<"\n";
return 0;
}

