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

const int Maxn=2e5+5;

int n;
int a[Maxn];
ll s1[Maxn],s2[Maxn];
ll ans=0;

class line{
	public:
		ll k,b;
		bool operator<(const line &o)const{
			return k<o.k||(k==o.k&&b<o.b);
		}
};

vector<line> v;

bool check(line l1,line l2,line l3){
	double d=1.0*(l3.k-l1.k)*(l2.b-l1.b)-1.0*(l2.k-l1.k)*(l3.b-l1.b);
	if(d<=0) return true;
	return false;
}

void insert(line o){
	if(v.size()<2){
		v.PB(o);return;
	}
	int i=v.size()-1;
	while(i){
		if(check(v[i-1],v[i],o)) v.pop_back();
		else break;
		i--;
	}
	v.PB(o);
}

ll gety(line o,ll x){
	return o.k*x+o.b;
}

ll calc(ll x){
	int ub=v.size(),lb=0,mi;
	while(ub-lb>1){
		mi=(ub+lb)>>1;
		if(mi!=0&&gety(v[mi],x)<gety(v[mi-1],x)) ub=mi;
		else lb=mi; 
	}
	return gety(v[lb],x);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		s1[i]=s1[i-1]+a[i];
		s2[i]=s2[i-1]+(ll)i*a[i];
	}
	for(int i=1;i<=n;i++){
		insert(line{i-1,(ll)(i-1)*s1[i-1]-s2[i-1]});
		ans=max(ans,calc(-s1[i])+s2[i]);
	}
	printf("%I64d\n",ans);
return 0;
}
