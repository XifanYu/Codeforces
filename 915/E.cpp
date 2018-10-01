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


int n,q,l,r,k,x,y;
set<pi> ss;
int work=0;

int main(){
	scanf("%d%d",&n,&q);
	ss.emplace(pi(1,n+1));
	work+=n;
	while(q--){
		scanf("%d%d%d",&l,&r,&k);
		auto it=ss.lower_bound(pi(l,1));
		if(it!=ss.begin()){
			it--;
			if(it->second>l){
				x=it->first,y=it->second;
				ss.erase(it);
				ss.emplace(pi(x,l));
				it=ss.emplace(pi(l,y)).first;
			}
			else it++;
		}
		while(it!=ss.end()&&it->second<=r+1){
			work-=it->second-it->first;
			auto nxt=next(it);
			ss.erase(it);
			it=nxt;
		}
		while(it!=ss.end()&&it->first<=r){
			work-=r+1-it->first;
			auto nxt=next(it);
			ss.emplace(pi(r+1,it->second));
			ss.erase(it);
			it=nxt;
		}
		if(k==2){
			work+=r+1-l;
			ss.emplace(pi(l,r+1));
		}
		printf("%d\n",work);
	}
return 0;
}
