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
const ll Maxk=2e12+5;
const ll INF=2e18;

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

set<line> ss;
int n;
int a[Maxn];
ll s1[Maxn],s2[Maxn];
ll ans=0,temp;

bool check(line l1,line l2,line l3){
	double d=1.0*(l3.k-l1.k)*(l2.b-l1.b)-1.0*(l2.k-l1.k)*(l3.b-l1.b);
	if(d<=0) return true;
	return false;
}

void insert(line o){
	if(ss.size()<2){
		ss.insert(o);
		return;
	}
	set<line>::iterator r=ss.LB(o),l=r,t;
	if(l!=ss.begin()){
		l--;
		if(check(*l,o,*r))return;
		ss.insert(o);
		while(l!=ss.begin()){
			t=l--;
			if(check(*l,*t,o)) ss.erase(t);
			else break;
		}
	}
	if(r!=ss.end()){
		t=r++;
		while(r!=ss.end()){
			if(check(o,*t,*r)) ss.erase(t);
			else break;
			t=r++;
		}
	}
}

ll gety(line o,int x){
	return o.k*x+o.b;
}

ll calc(int x){
	set<line>::iterator it;
	ll lb=-Maxk,ub=Maxk,mi;
	while(ub-lb>1){
		mi=(ub+lb)>>1;
		it=ss.LB(line{mi,INF}); 
		if(gety(*prev(it),x)>gety(*it,x)) ub=mi;
		else lb=mi;
	}
	it=ss.LB(line{lb,INF});
	return gety(*it,x);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		s1[i]=s1[i-1]+a[i];
		s2[i]=s2[i-1]+(ll)i*a[i];
	}
	ss.insert(line{-Maxk,-INF});
	ss.insert(line{Maxk,-INF});
	for(int i=n-1;i>=0;i--){
		temp=(ll)i*s1[i]-s2[i];
		insert(line{-s1[i+1],s2[i+1]});
		ans=max(ans,temp+calc(i));
	}
	printf("%I64d\n",ans);
return 0;
}
