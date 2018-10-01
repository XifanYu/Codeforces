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

int t,n;
int a[105];
int b[105];
bool notok[1000005];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		printf("YES\n");
		memset(notok,0,sizeof notok);
		int id=1,pos=1;
		while(id<=n){
			while(notok[pos]) pos++;
			b[id]=pos;
			printf("%d ",pos);
			pos++;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(b[id]+a[i]-a[j]>0&&b[id]+a[i]-a[j]<=1000000) notok[b[id]+a[i]-a[j]]=true;
				}
			}
			id++;
		}
		printf("\n");
	}
return 0;
}
