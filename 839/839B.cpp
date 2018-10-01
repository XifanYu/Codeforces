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

int main(){
	int n,k,n1,n2,n4,a[105];
	scanf("%d %d",&n,&k);
	n1=0;
	n2=2*n;
	n4=n;
	bool ok=true;
	for(int i=1;i<=k;i++){
		scanf("%d",a+i);
	}
	sort(a+1,a+k+1);
	reverse(a+1,a+k+1);
	for(int i=1;i<=k;i++){
		int x=a[i];
		while(x){
			if(x>=4){
				if(n4){
					x-=4;
					n4--;
				}
				else if(n2){
					x-=2;
					n2--;
				}
				else{
					ok=false;
					break;
				}
			}
			else if(x==3){
				if(n4){
					x-=3;
					n4--;
				}
				else if(n2){
					x-=2;
					n2--;
				}
				else if(n1){
					x--;
					n1--;
				}
				else{
					ok=false;
					break;
				}
			}
			else if(x==2){
				if(n2){
					n2--;
					x-=2;
				}
				else if(n4){
					n4--;
					x-=2;
					n1++;
				}
				else if(n1){
					n1--;
					x--;
				}
				else{
					ok=false;
					break;
				}
			}
			else if(x==1){
				if(n1){
					n1--;
					x--;
				}
				else if(n4){
					n4--;
					n2++;
					x--;
				}
				else if(n2){
					n2--;
					x--;
				}
				else{
					ok=false;
					break;
				}
			}
		}
	}
	if(ok) printf("YES\n");
	else printf("NO\n");
return 0;
}
