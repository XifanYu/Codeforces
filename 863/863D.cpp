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

const int Maxn=200005;

int n,m,q;
int a[Maxn];
int t[Maxn],l[Maxn],r[Maxn];
int b[105];

int main(){
	scanf("%d%d%d",&n,&q,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",t+i,l+i,r+i);
	}
	reverse(t+1,t+q+1);
	reverse(l+1,l+q+1);
	reverse(r+1,r+q+1);
	for(int i=1;i<=m;i++) scanf("%d",b+i);
	for(int i=1;i<=q;i++){
		for(int j=1;j<=m;j++){
			if(l[i]<=b[j]&&b[j]<=r[i]){
				if(t[i]==1) {
					b[j]--;
					if(b[j]<l[i]) b[j]=r[i];
				}
				else{
					b[j]=l[i]+r[i]-b[j];
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(i>1) printf(" ");
		printf("%d",a[b[i]]);
	}
	printf("\n");
return 0;
}
