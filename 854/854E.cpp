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

typedef vector<int> vi;
typedef long long ll;

const int Maxn=2*1e5+5;

int n,q,MN;
int pos[Maxn];//column i with row pos[i]//
vi tree[Maxn*4];

void init(){
	for(int i=MN-1;i;i--){
		int id1=0,id2=0,x=2*i,y=2*i+1;
		while(id1<tree[x].size()&&id2<tree[y].size()){
			if(tree[x][id1]<tree[y][id2]) tree[i].push_back(tree[x][id1++]);
			else tree[i].push_back(tree[y][id2++]);
		}
		while(id1<tree[x].size()) tree[i].push_back(tree[x][id1++]);
		while(id2<tree[y].size()) tree[i].push_back(tree[y][id2++]);
	}
}

int cnt(int k,int d,int u){
	int ub,lb;
	lb=lower_bound(tree[k].begin(),tree[k].end(),d)-tree[k].end();
	ub=upper_bound(tree[k].begin(),tree[k].end(),u)-tree[k].end()-1;
return ub-lb+1>0?ub-lb+1:0;
}

int query(int l,int d,int r,int u,int k,int l1,int r1){
	if(l<=l1&&r>=r1) return cnt(k,d,u);
	if(l1>r||r1<l) return 0;
	else{
		return query(l,d,r,u,2*k,l1,(l1+r1)/2)+query(l,d,r,u,2*k+1,(l1+r1+1)/2,r1);
	}
}

int main(){
	scanf("%d%d",&n,&q);
	MN=1;
	while(MN<n) MN*=2;
	for(int i=1;i<=n;i++){
		scanf("%d",pos+i);
		tree[i+MN-1].push_back(pos[i]);
	}
	init();
	while(q--){
		int l,d,r,u;
		scanf("%d%d%d%d",&l,&d,&r,&u);
		ll ans=(ll)n*(n-1)/2;
		ll del1=(ll)(l-1)*(l-2)/2,del2=(ll)(n-r)*(n-r-1)/2,del3=(ll)(d-1)*(d-2)/2,del4=(ll)(n-u)*(n-u-1)/2;
		ans-=del1+del2+del3+del4;
		int k1,k2,k3,k4;
		k1=query(1,1,(l-1),(d-1),1,1,MN);
		k2=query(1,(u+1),(l-1),n,1,1,MN);
		k3=query((r+1),1,n,(d-1),1,1,MN);
		k4=query((r+1),(u+1),n,n,1,1,MN);
		ans+=(ll)k1*(k1-1)/2+(ll)k2*(k2-1)/2+(ll)k3*(k3-1)/2+(ll)k4*(k4-1)/2;
		printf("%I64d\n",ans);
	}
return 0;
}
