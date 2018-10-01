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

int a[100005];
int lm[100005],rm[100005];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	int maxt=-1e9-1;
	for(int i=1;i<=n;i++){
		maxt=max(maxt,a[i]);
	}
	lm[0]=1e9+1,rm[n+1]=1e9+1;
	for(int i=1;i<=n;i++){
		lm[i]=min(lm[i-1],a[i]);
	}
	for(int i=n;i;i--){
		rm[i]=min(rm[i+1],a[i]);
	}
	if(k==1){
		cout<<lm[n]<<"\n";
	}
	else if(k==2){
		int ans=-1e9-1;
		for(int i=1;i<n;i++){
			ans=max(ans,max(lm[i],rm[i+1]));
		}
		cout<<ans<<"\n";
	}
	else{
		cout<<maxt<<"\n";
	}
return 0;
}
