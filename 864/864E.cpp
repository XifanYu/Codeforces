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

const int Maxn=105,Maxt=2005;

int n;

struct node
{
    int t,d,p,id;
}a[Maxn];

bool cmp(node a,node b)
{
    return a.d<b.d;
}


int dp[Maxn][Maxt],pr[Maxn][Maxt];
bool used[Maxn];
int ans=0,ans1=-1,ans2;
vector<int> seq;



int main(){
	scanf("%d",&n);
	memset(pr,-1,sizeof pr);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].t,&a[i].d,&a[i].p);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=0;j<Maxt;j++){
			if(j>=a[i].d) break;
			if(j<a[i].t) continue;
			if(j==a[i].t){
				dp[i][j]=a[i].p;
			}
			for(int k=1;k<i;k++){
				int tmp=dp[k][j-a[i].t]+a[i].p;
				if(tmp>dp[i][j]){
					dp[i][j]=tmp;
					pr[i][j]=k;
				}
			}
			if(dp[i][j]>ans){
				ans=dp[i][j];
				ans1=i;
				ans2=j;
			}
		}
	}
	while(true){
		if(ans1==-1) break;
		seq.push_back(a[ans1].id);
		int tmp=pr[ans1][ans2];
		ans2-=a[ans1].t;
		ans1=tmp;
	}
	printf("%d\n",ans);
	printf("%d\n",seq.size());
	for(int i=seq.size()-1;i>=0;i--){
		printf("%d",seq[i]);
		if(i!=0) printf(" ");
		else printf("\n");
	}
return 0;
}
