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

int n;
int a[1505];
int now=0;
int m;



int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]>a[j]) now=(now+1)%2;
		}
	}
	scanf("%d",&m);
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		int x=r-l+1;
		if((x*(x-1)/2)%2){
			if(now%2) printf("even\n");
			else printf("odd\n");
			now=(now+1)%2;
		}
		else{
			if(now%2) printf("odd\n");
			else printf("even\n");
		}
	}
return 0;
}
