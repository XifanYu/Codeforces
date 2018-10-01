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
vector<pi> range;

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		range.push_back(pi(x,y)); 
	}
	sort(range.begin(),range.end());
	int e1=-1,e2=-1;
	int id=0;
	while(id<n){
		if(e1>e2) swap(e1,e2);
		if(range[id].first>e1){
			e1=range[id].second;
			id++;
		}
		else{
			printf("NO\n");
			exit(0);
		}
	}
	printf("YES\n");
return 0;
}
