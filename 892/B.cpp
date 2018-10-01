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

int n;
int l[1000005];
int pre[1000005];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",l+i);
		pre[i]=i-l[i];
	}
	int r=n-1,l=n-1;
	int sum=0;
	while(r>=0&&l>=0){
		sum++;
		l=pre[r];
		while(true){
			int nex=l;
			for(int i=max(l,0);i<r;i++){
				nex=min(nex,pre[i]);
			}
			if(nex<l) {
				r=l;
				l=nex;
			}
			else{
				r=l-1;
				break;
			}
		}
	}
	printf("%d\n",sum);
return 0;
}
