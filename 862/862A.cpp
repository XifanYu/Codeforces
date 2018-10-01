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

int main(){
	int n,x;
	bool ex[105];
	memset(ex,0,sizeof ex);
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		int y;
		scanf("%d",&y);
		ex[y]=1;
	}
	int ans=0;
	for(int i=0;i<x;i++){
		if(!ex[i]) ans++;
	}
	if(ex[x]) ans++;
	cout<<ans<<"\n";
return 0;
}
