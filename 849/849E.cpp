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

int n,m;
int a[Maxn];
set<int> t[1<<18];
vector<int> pos[Maxn];
set<int> ap;

void update(int i,int x){
	pos[x].push_back(i);
	sort(pos[x].begin(),pos[x].end());
	i+=(1<<17)-2;
	for(auto v:t[i]){
		for(int j=0;j<pos[v].size();j++){
			if(pos[v][j]==i+2-(1<<17)){
				pos[v].erase(pos[v].begin()+j);
				sort(pos[v].begin(),pos[v].end());
				break;
			}
		}
	}
	t[i].clear();
	t[i].insert(x);
	while(i){
		i/=2;
		t[i].clear();
		for(auto v1:t[2*i+1]) t[i].insert(v1);
		for(auto v2:t[2*i+2]) t[i].insert(v2);
	}
}

void query(int l,int r,int i,int a,int b){
	if(l<=a&&r>=b){
		for(auto v:t[i]) ap.insert(v);
		return;
	}
	if(b<l||a>r) return;
	else{
		query(l,r,2*i+1,a,(a+b)/2);
		query(l,r,2*i+2,(a+b+1)/2,b);
	}
}

int count(int l,int r){
	int sum=0;
	for(auto v:ap){
		int k1=lower_bound(pos[v].begin(),pos[v].end(),l)-pos[v].begin();
		int k2=upper_bound(pos[v].begin(),pos[v].end(),r)-pos[v].begin()-1;
		sum+=pos[v][k2]-pos[v][k1]; 
	}
return sum;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		pos[a[i]].push_back(i);
		t[i+(1<<17)-2].insert(a[i]);
	}
	for(int i=1;i<=n;i++) sort(pos[i].begin(),pos[i].end());
	for(int i=(1<<17)-2;i>=0;i--){
		for(auto v1:t[2*i+1]) t[i].insert(v1);
		for(auto v2:t[2*i+2]) t[i].insert(v2);
	}
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==1) update(b,c);
		if(a==2){
			ap.clear();
			query(b,c,0,1,1<<17);
			int s=count(b,c);
			printf("%d\n",s);
		}
	}
return 0;
}
