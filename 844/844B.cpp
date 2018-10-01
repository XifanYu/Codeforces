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

long long calc(int i){
	long long s=1;
	int l=i;
	while(l){
		s*=2;
		l--;
	}
return s-1-i;
}

int main(){
	int n,m;
	int a[55][55];
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	long long ans=m*n;
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=m;j++){
			if(a[i][j]) cnt++;
		}
		ans+=calc(cnt);
		ans+=calc(m-cnt);
	}
	for(int i=1;i<=m;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j][i]) cnt++;
		}
		ans+=calc(cnt);
		ans+=calc(n-cnt);
	}
	printf("%I64d\n",ans);
return 0;
}
