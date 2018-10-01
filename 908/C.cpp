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

int n,r;
int x[1005];
double y[1005];

void test(int id){
	if(id==1){
		y[id]=r;
		cout<<fixed<<setprecision(8)<<r<<" ";
	}
	else{
		double ans=0;
		for(int i=1;i<id;i++){
			double nex;
			if(abs(x[id]-x[i])>2*r) nex=r;
			else{
				nex=y[i]+sqrt(4*r*r-(x[id]-x[i])*(x[id]-x[i]));
			}
			ans=max(ans,nex);
		}
		y[id]=ans;
		cout<<fixed<<setprecision(8)<<ans<<" ";
	}
}

int main(){
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++){
		scanf("%d",x+i);
	}
	int now=1;
	while(now<=n){
		test(now);
		now++;
	}
return 0;
}
