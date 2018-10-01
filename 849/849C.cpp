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
using namespace std;

typedef pair<int,int> pi;
typedef long long ll;

int p[10];
int dp[10];
int k;
int tim[26];

int main(){
	p[0]=1;
	memset(tim,0,sizeof tim);
	for(int i=1;i<10;i++) p[i]=p[i-1]<<1;
	for(int i=0;i<10;i++) dp[i]=p[i]*(p[i]-1)/2;
	int j=0,pos=9;
	scanf("%d",&k);
	if(k==0) {
		printf("ab\n");
		exit(0);
	}
	while(k){
		while(k>=dp[pos]){
			k-=dp[pos];
			tim[j]=p[pos];
			j++;
		}
		pos--;
	}
	string ans;
	for(int i=0;i<j;i++){
		while(tim[i]){
			ans+=char('a'+i);
			tim[i]--;
		}
	}
	cout<<ans<<endl;
return 0;
}
