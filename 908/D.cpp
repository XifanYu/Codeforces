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

const ll md=1e9+7;

ll k,a,b;

ll powm(ll x,ll y){
	if(!y) return 1;
	ll rez=powm(x,y>>1);
	rez=(rez*rez)%md;
	if(y&1) rez=(rez*x)%md;
	return rez;
}

ll inv(ll x){
	return powm(x,md-2);
}

ll dp[1005][1005]; //number of a's, and number of subsquences

int main(){
	scanf("%I64d%I64d%I64d",&k,&a,&b);
	ll pa,pb,pk;
	pa=a*inv(a+b)%md;
	pb=b*inv(a+b)%md;
	pk=inv(b)%md;
	for(int i=k;i>=0;i--){
		for(int j=k;j>=0;j--){
			if(i+j>=k) dp[i][j]=(i+j+a*pk)%md;
			else dp[i][j]=(pa*dp[i+1][j]+pb*dp[i][i+j])%md;
		}
	}
	ll ans=dp[1][0];
	printf("%I64d\n",ans);
return 0;
}
