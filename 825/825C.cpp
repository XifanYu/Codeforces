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

int main(){
	int n,k,a[1005];
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	sort(a,a+n);
	int ub=k, id=-1, ans=0;
	while(id<n-1){
		int pid=id;
		id=upper_bound(a,a+n,ub*2)-a-1;
		if(id==pid) {
			ub*=2;
			ans++;
		}
		else ub=max(ub,a[id]);
	}
	printf("%d\n",ans);
return 0;
}
