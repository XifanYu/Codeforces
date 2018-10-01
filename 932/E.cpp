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

const int Maxk=5005;
const int md=1e9+7;

int n,k,m;
ll dp[Maxk][Maxk]; 

ll fpow(int num){
	ll rez=1;
	if(num==0) return rez;
	rez=fpow(num/2);
	rez=(rez*rez)%md;
	if(num&1) rez=(rez*2)%md;
	return rez;
}

int main(){
	scanf("%d%d",&n,&k);
	m=min(n,k);
	dp[0][m]=fpow(n-m);
	for(int j=m-1;j>=0;j--){
		dp[0][j]=(dp[0][j+1]*2)%md;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=m;j++){
			dp[i][j]=(j*dp[i-1][j]+(n-j)*dp[i-1][j+1])%md;
		}
	}
	printf("%d\n",dp[k][0]);
return 0;
}
