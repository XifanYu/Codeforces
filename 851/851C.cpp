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
using namespace std;

typedef pair<int,int> pi;
typedef long long ll;

const int Maxn=1005;

int n;
int a[Maxn],b[Maxn],c[Maxn],d[Maxn],e[Maxn];
int re[100*Maxn];
int l=0,r=0;
vector<int> ans;

bool check(int i,int j,int k){
	int da1=a[j]-a[i],db1=b[j]-b[i],dc1=c[j]-c[i],dd1=d[j]-d[i],de1=e[j]-e[i];
	int da2=a[k]-a[i],db2=b[k]-b[i],dc2=c[k]-c[i],dd2=d[k]-d[i],de2=e[k]-e[i];
	return (ll)da1*da2+(ll)db1*db2+(ll)dc1*dc2+(ll)dd1*dd2+(ll)de1*de2>0; 
}

bool check2(int k){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(i!=k&&j!=k){
				if(check(k,i,j)) return false;
			}
		}
	}
return true;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d%d",a+i,b+i,c+i,d+i,e+i);
		re[r++]=i;
	}
	while(r-l>=3){
		int x1=re[l++],x2=re[l++],x3=re[l++];
		bool bad1=false,bad2=false,bad3=false;
		if(check(x1,x2,x3)) bad1=true;
		if(check(x2,x3,x1)) bad2=true;
		if(check(x3,x1,x2)) bad3=true;
		if(!bad1) re[r++]=x1;
		if(!bad2) re[r++]=x2;
		if(!bad3) re[r++]=x3;
	}
	while(r>l){
		int x=re[l++];
		if(check2(x)) ans.push_back(x);
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		if(i) printf(" ");
		printf("%d",ans[i]+1);
	}
	printf("\n");	
return 0;
}
