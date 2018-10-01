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
	int n,k;
	int have=0,give=0;
	int ans=105;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		have+=x;
		if(give<k){
			int d=min(8,have);
			have-=d;
			give+=d;
		}
		if(give>=k) ans=min(ans,i);
	}
	if(give<k) ans=-1;
	printf("%d\n",ans);
return 0;
}
