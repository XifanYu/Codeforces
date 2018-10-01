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

const int Maxn=5*1e5+5;
const int Maxa=1e6+5;

int n;
ll x,y;
ll a[Maxn];
ll sum[Maxn];
ll d;
int lb[2*Maxa];



int main(){
	scanf("%d%I64d%I64d",&n,&x,&y);
	d=x/y;
	for(int i=1;i<=n;i++){
		scanf("%I64d",a+i);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
	}
	ll mincost=1e18;
	for(int i=0;i<Maxa;i++) lb[i]=lower_bound(a+1,a+n+1,i)-a-1;
	for(int i=Maxa;i<2*Maxa;i++) lb[i]=n;
	for(int i=2;i<Maxa-2;i++){
		ll cost=0;
		for(int j=i;j-i<Maxa-1;j+=i){
			int l,r,m;
			l=lb[j-i+1];
			r=lb[j+1];
			if(i>d) m=lb[j-d];
			else m=l;
			cost+=(ll)(m-l)*x+((ll)j*(r-m)-(sum[r]-sum[m]))*y;
		}
		if(cost<mincost){
			mincost=cost;
		}
	}
	printf("%I64d\n",mincost);
return 0;
}
