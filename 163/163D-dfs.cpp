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

int n,q[20];

ll p[20],v,a,b,c,ans,A,B,C,MA,MB;

void cal(ll now,int id){
	if(now>MB) return;
	if(id>n){
		b=now;
		c=((v/a)/b);
		if(a>b) return;
		if(ans>2*(a*b+b*c+c*a)){
			ans=2*(a*b+b*c+c*a);
			A=a,B=b,C=c;
		}
		return;
	}
	if(q[id]){
		q[id]--;
		cal(now*p[id],id);
		q[id]++;
	}
	cal(now,id+1);
}

void dfs(ll now,int id){
	if(now>MA) return;
	if(id>n){
		a=now;
		if(2*(2*a*sqrt(v/a)+(v/a))>ans)return;
		MB=sqrt(v/a);
		cal(1,1);
		return;
	}
	if(q[id]){
		q[id]--;
		dfs(now*p[id],id);
		q[id]++;
	}
	dfs(now,id+1);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		v=1;
		for(int i=1;i<=n;i++){
			scanf("%I64d%d",&p[i],&q[i]);
			for(int j=1;j<=q[i];j++) v*=p[i];
		}
		ans=4*1e18+5;
		MA=pow(v,double(1)/3)+0.5;
		dfs(1,1);
		printf("%I64d %I64d %I64d %I64d\n",ans,A,B,C);
	}
return 0;
}
