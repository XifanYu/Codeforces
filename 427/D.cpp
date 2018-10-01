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

const int Maxn=5005; 

string s1,s2; 
int len1,len2;

int pre[2][Maxn];
int dp[3][Maxn][Maxn];
int ans=Maxn;

int main(){
	getline(cin,s1);
	getline(cin,s2);
	len1=s1.length();
	len2=s2.length();
	memset(dp,0,sizeof dp);
	for(int i=1;i<=len1;i++){
		pre[0][i]=i;
		for(int j=1;j<=len1;j++){
			int x=i-1,y=j-1;
			if(x==y) continue;
			if(s1[x]==s1[y]){
				dp[0][i][j]=dp[0][i-1][j-1]+1;
				pre[0][i]=min(pre[0][i],i-dp[0][i][j]);
			}
		}
	}
	for(int i=1;i<=len2;i++){
		pre[1][i]=i;
		for(int j=1;j<=len2;j++){
			int x=i-1,y=j-1;
			if(x==y) continue;
			if(s2[x]==s2[y]){
				dp[1][i][j]=dp[1][i-1][j-1]+1;
				pre[1][i]=min(pre[1][i],i-dp[1][i][j]);
			}	
		}
	}
	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			int x=i-1,y=j-1;
			if(s1[x]==s2[y]){
				dp[2][i][j]=dp[2][i-1][j-1]+1;
				int a=i+1-pre[0][i],b=j+1-pre[1][j];
				int m=max(a,b);
				if(dp[2][i][j]<m) continue;
				if(m<ans) ans=m;
			}
		}
	}
	if(ans==Maxn) printf("-1\n");
	else printf("%d\n",ans);
return 0;
}
