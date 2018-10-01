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


const int Maxn=200005;

int n;
short a[Maxn];
short t[1<<19][101]; 
int q;
int MN=1;

void build(){
	while(MN<n) MN*=2;
	for(int i=1;i<=2*MN-1;i++){
		for(int j=1;j<=100;j++) t[i][j]=j;
	}
}

void pushdown(int k){
	for(int i=1;i<=100;i++){
		t[k*2][i]=t[k][t[k*2][i]];
		t[k*2+1][i]=t[k][t[k*2+1][i]];
	}
	for(int i=1;i<=100;i++) t[k][i]=i;
}

void change(int a,int b,int x,int y,int k,int l,int r){
	if(a>r||b<l) return;
	if(a<=l&&b>=r){
		for(int i=1;i<=100;i++){
			if(t[k][i]==x) {
				t[k][i]=y;
			}
		}
		return;
	}
	pushdown(k);
	change(a,b,x,y,k*2,l,(l+r)>>1);
	change(a,b,x,y,k*2+1,(l+r+1)>>1,r);
	return;
}

int main(){
	scanf("%d",&n);
	build();
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int l,r,x,y;
		scanf("%d%d%d%d",&l,&r,&x,&y);
		change(l,r,x,y,1,1,MN);
	}
	for(int i=1;i<MN;i++) pushdown(i);
	for(int i=1;i<=n;i++){
		printf("%d ",t[MN+i-1][a[i]]);
	}
return 0;
}
