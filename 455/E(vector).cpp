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

const int Maxn=1e5+5; 
const ll INF=1e15+5;

int n,m,x,y,MN=1;
int a[Maxn],s[Maxn];

class line{
	public:
		ll k,b;
		bool operator<(const line &o)const{
			return k<o.k||(k==o.k&&b<o.b);
		}
		bool operator==(const line &o)const{
			return k==o.k&&b==o.b;
		}
};

vector<line> hull[Maxn<<2];

bool check(line l1,line l2,line l3){
	double d=1.0*(l3.k-l1.k)*(l2.b-l1.b)-1.0*(l2.k-l1.k)*(l3.b-l1.b);
	if(d>=0) return true;
	return false;
}

void insert(line o,int id){
	if(hull[id].size()==0){
		hull[id].PB(o);
		return;
	}
	if(hull[id].size()==1){
		if(hull[id][0].k==o.k&&hull[id][0].b<=o.b) return;
		hull[id].PB(o);return;
	}
	int m=hull[id].size()-1,l=m-1;
	while(l>=0&&check(hull[id][l],hull[id][m],o)){
		hull[id].pop_back();
		m=l--;
	}
	hull[id].PB(o);
}

void build(){
	while(MN<n) MN*=2;
	for(int p=n;p>0;p--){
		insert(line{a[p],p*a[p]-s[p]},p+MN-2);
	}
	for(int p=MN-2;p>=0;p--){
		int id1=0,id2=0;
		while(id1<hull[lc].size()&&id2<hull[rc].size()){
			if(hull[lc][id1]<hull[rc][id2]){
				insert(hull[lc][id1++],p);
			}
			else insert(hull[rc][id2++],p);
		}
		while(id1<hull[lc].size()) insert(hull[lc][id1++],p);
		while(id2<hull[rc].size()) insert(hull[rc][id2++],p);
	}
}

ll val(line o,int x,int y){
	return (ll)(x-y)*o.k+o.b;
}
ll calc(int id,int x,int y){
	if(hull[id].size()==0) return INF;
	int ub=hull[id].size(),lb=0,mi;
	while(ub-lb>1){
		mi=(ub+lb)>>1;
		if(mi!=0&&val(hull[id][mi-1],x,y)<val(hull[id][mi],x,y)) ub=mi;
		else lb=mi;
	}
	return val(hull[id][lb],x,y)+s[y]; 
}

ll query(int x,int y,int l,int r,int p=0,int l1=1,int r1=MN){
	if(l<=l1&&r>=r1) return calc(p,x,y);
	if(l>r1||r<l1) return INF;
	return min(query(x,y,l,r,lc,l1,(l1+r1)>>1),query(x,y,l,r,rc,(l1+r1+1)>>1,r1));
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		s[i]=s[i-1]+a[i];
	}
	build();
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		printf("%I64d\n",query(x,y,y-x+1,y));
	}
return 0;
}
