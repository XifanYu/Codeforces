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
typedef long long ll;

int main(){
	int n;
	ll y[1005];
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d",y+i);
	for(int i=2;i<=n;i++){
		bool vis[1005];
		memset(vis,0,sizeof vis);
		vis[1]=true;
		vis[i]=true;
		for(int j=2;j<=n;j++){
			if(j!=i){
				if(ll(y[j]-y[i])*ll(i-1)==ll(y[i]-y[1])*ll(j-i)) vis[j]=true;
			}
		}
		vector<int> sec;
		for(int j=1;j<=n;j++){
			if(!vis[j]) sec.push_back(j);
		}
		if(sec.size()==0) continue;
		if(sec.size()==1){
			printf("Yes\n");
			exit(0);
		}
		else{
			ll a=sec[0],b=y[a];
			ll c=sec[1],d=y[c];
			bool ok=true;
			if(ll(d-b)*ll(i-1)!=ll(y[i]-y[1])*ll(c-a)) ok=false;
			for(int j=2;j<sec.size();j++){
				ll e=sec[j],f=y[e];
				if(ll(f-d)*ll(c-a)!=ll(d-b)*ll(e-c)){
					ok=false;
					break;
				}
			}
			if(ok) {
				printf("Yes\n");
				exit(0);
			}
		}
	}
	ll y1=y[2],y2=y[3],x1=2,x2=3;
	bool flag=true;
	if(ll(y1-y[1])*ll(x2-x1)==ll(y2-y1)*ll(x1-1)) flag=false;
	for(int i=4;i<=n;i++){
		if(ll(y[i]-y2)*ll(x2-x1)!=ll(y2-y1)*ll(i-x2)) flag=false;
	}
	if(flag){
		printf("Yes\n");
		exit(0);
	}
	printf("No\n");
return 0;
}
