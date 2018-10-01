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
typedef pair<int,int> pi;

#define lc p*2+1
#define rc p*2+2

const int Maxn=35005;

int n,k,MN=1;
int a[Maxn];
int t1[Maxn<<2],t2[Maxn<<2];
int dp[55][Maxn];
map<int,int> pre;
int pos[Maxn];

inline void pushup(int p){
	t1[p]=max(t1[lc],t1[rc]);
}

void pushdown(int p){
	if(t2[p]){
		t1[lc]+=t2[p];
		t1[rc]+=t2[p];
		t2[lc]+=t2[p];
		t2[rc]+=t2[p];
		t2[p]=0;
	}
}

void update(int a,int b,int p=0,int l=1,int r=MN){
	if(a<=l&&b>=r){
		t1[p]++;
		t2[p]++;
		return;
	}
	if(a>r||b<l) return;
	pushdown(p);
	update(a,b,lc,l,(l+r)>>1);
	update(a,b,rc,(l+r+1)>>1,r);
	pushup(p);
}

int query(int a,int b,int p=0,int l=1,int r=MN){
	if(a<=l&&b>=r){
		return t1[p];
	}
	if(a>r||b<l) return -Maxn;
	pushdown(p);
	int ans=max(query(a,b,lc,l,(l+r)>>1),query(a,b,rc,(l+r+1)>>1,r));
	pushup(p);
	return ans;
}

void build(int i,int p=0,int l=1,int r=MN){
	if(l==r){
		t1[p]=dp[i-1][l-1];
		return;
	}
	build(i,lc,l,(l+r)>>1);
	build(i,rc,(l+r+1)>>1,r);
	pushup(p);
}



int main(){
	scanf("%d%d",&n,&k);
	while(MN<n) MN*=2;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		pos[i]=pre[a[i]];
		pre[a[i]]=i;
	}
	for(int i=1;i<=k;i++){
		memset(t2,0,sizeof t2);
		build(i);
		for(int j=1;j<=n;j++){
			update(pos[j]+1,j);
			dp[i][j]=query(1,j);
		}
	}
	printf("%d\n",dp[k][n]);
return 0;
}
