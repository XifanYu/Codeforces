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

int n,m;
int a[40];
set<int> st1[20],st2[40];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		a[i]%=m;
	}
	if(n<=18){
		st1[0].insert(0);
		for(int i=1;i<=n;i++){
			for(auto v:st1[i-1]){
				st1[i].insert(v);
				st1[i].insert((v+a[i])%m);
			}
		}
		int ans=*(--st1[n].end());
		printf("%d\n",ans);
	}
	else{
		st1[0].insert(0);
		for(int i=1;i<=18;i++){
			for(auto v:st1[i-1]){
				st1[i].insert(v);
				st1[i].insert((v+a[i])%m);
			}
		}
		st2[18].insert(0);
		for(int i=19;i<=n;i++){
			for(auto v:st2[i-1]){
				st2[i].insert(v);
				st2[i].insert((v+a[i])%m);
			}
		}
		int ans=0;
		int it=0;
		for(auto it:st1[18])
    	{
    		auto it2=st2[n].lower_bound(m-it);
    		if(it2==st2[n].begin()) continue;
    		it2--;
    		ans=max(ans, (it+*it2)%m);
    	}
		printf("%d\n",ans);
	}
return 0;
}
