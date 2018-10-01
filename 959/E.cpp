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
#define FF first
#define SS second
#define LB lower_bound
#define PB push_back
#define lc p*2+1
#define rc p*2+2
#define rep(n) for(int i=1;i<=n;i++)
#define rep0(n) for(int i=0;i<n;i++)
#define rrep(n) for(int i=n;i;i--)
#define rrep0(n) for(int i=n-1;i>=0;i--)
#define forw(v) (v).begin(),(v).end()

typedef long long ll;
typedef pair<int,int> pi; 

/*
 * high precision: cout<<fixed<<setprecision(10)<<;
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

ll n;
ll c[50];
ll ans=0;
ll d;

int main(){
	scanf("%I64d",&n);
	c[0]=0;
	d=n&(-n);
	for(ll i=0,x=1;n;i++,x<<=1){
		if(n&x){
			n^=x;
			ans+=c[i];
			ans+=x;
		}
		c[i+1]=(c[i]<<1)+x;
	}
	ans-=d;
	printf("%I64d\n",ans);
return 0;
}
