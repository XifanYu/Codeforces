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

int n;
vector<int> adj[100005];

double len(int s,int prv=-1){
	double ret=0;
	int siz=adj[s].size();
	for(int i=0;i<adj[s].size();i++){
		if(adj[s][i]!=prv) ret+=double(1+len(adj[s][i],s))/(prv==-1?siz:(siz-1));
	}
return ret;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	printf("%lf\n",len(1));
return 0;
}
