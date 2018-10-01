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

const int Maxn=300005;

int n,m,x=0;
int a[Maxn];
bool bt[1<<20];
int dig[19];
int ans[19];



int main(){
	scanf("%d %d",&n,&m);
	memset(bt,false,sizeof bt);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		int j=(1<<19)-1;
		bt[a[i]+j]=true;		
	}
	for(int i=(1<<19)-2;i;i--){
		if(bt[2*i+1]&&bt[2*i+2]) bt[i]=true;
		else bt[i]=false;
	}
	for(int i=1;i<=m;i++){
		int y;
		scanf("%d",&y);
		x^=y;
		memset(dig,0,sizeof dig);
		int z=x,d=0;
		while(z){
			dig[d++]=z%2;
			z/=2;
		}
		int s=0;
		for(int j=18;j>=0;j--){
			if(dig[j]==0){
				if(bt[2*s+1]==false){
					ans[j]=0;
					s=2*s+1;
				}
				else{
					ans[j]=1;
					s=2*s+2;
				}
			}
			else{
				if(bt[2*s+2]==false){
					ans[j]=0;
					s=2*s+2;
				}
				else{
					ans[j]=1;
					s=2*s+1;
				}
			}
		}
		int sum=0;
		for(int j=18;j>=0;j--){
			sum*=2;
			sum+=ans[j];
		}
		printf("%d\n",sum);
	}
return 0;
}
