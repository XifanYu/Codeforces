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

class line{
	public:
		ll k,b;
		bool operator<(const line &o)const{
			return k<o.k||(k==o.k&&b<o.b);
		}
};

int n;
int a[Maxn],b[Maxn];
ll dp[Maxn];
vector<line> hull;

bool check(line l1,line l2,line l3){
	double d=1.0*(l3.k-l1.k)*(l2.b-l1.b)-1.0*(l2.k-l1.k)*(l3.b-l1.b);
	return d<=0;
}

void insert(line o){
	if(hull.size()<2){
		hull.PB(o);
		return;
	}
	int m=hull.size()-1,l=m-1;
	while(m){
		if(check(hull[l],hull[m],o)){
			hull.pop_back();
			m--;l--;
		}
		else break;
	}
	hull.PB(o);
}

ll gety(int x,line o){
	return o.k*x+o.b;
}

ll calc(int x){
	int ub=hull.size(),lb=0,mi;
	while(ub-lb>1){
		mi=(ub+lb)>>1;
		if(mi!=0&&gety(x,hull[mi-1])<gety(x,hull[mi])) ub=mi;
		else lb=mi;
	}
	return gety(x,hull[lb]);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) scanf("%d",b+i);
	dp[1]=0;
	insert(line{b[1],0});
	for(int i=2;i<=n;i++){
		dp[i]=calc(a[i]);
		insert(line{b[i],dp[i]});
	}
	printf("%I64d\n",dp[n]);
return 0;
}
