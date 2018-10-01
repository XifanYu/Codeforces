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

int n;
int dp[2][55];
int s[55];
int sum[55];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",s+i);
	for(int i=n;i>=1;i--) sum[i]=s[i]+sum[i+1];
	for(int i=n;i>=1;i--){
		dp[0][i]=max(dp[0][i+1],s[i]+sum[i+1]-dp[1][i+1]);
		dp[1][i]=max(dp[1][i+1],s[i]+sum[i+1]-dp[0][i+1]);
	}
	printf("%d %d\n",sum[1]-dp[0][1],dp[0][1]);
return 0;
}
