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

int a,b,f,k;
int dr=1;
int p,ans=0;

int main(){
	scanf("%d%d%d%d",&a,&b,&f,&k);
	int id=0;
	p=b;
	while(id<k-1){
		if(dr==1){
			p-=f;
			if(p<0){
				printf("%d\n",-1);
				return 0;
			}
			if(p<2*(a-f)) {
				p=b;
				ans++;
			}
			p-=(a-f);
			dr=-1;
			id++;
		}
		else if(dr==-1){
			p-=(a-f);
			if(p<0){
				printf("%d\n",-1);
				return 0;
			}
			if(p<2*f) {
				p=b;
				ans++;
			}
			p-=f;
			dr=1;
			id++;
		}
	}
	if(dr==1){
		p-=f;
		if(p<0){
			printf("%d\n",-1);
			return 0;
		}
		if(p<(a-f)) {
			p=b;
			ans++;
		}
		p-=(a-f);
		if(p<0){
			printf("%d\n",-1);
			return 0;
		}
		dr=-1;
		id++;
	}
	else if(dr==-1){
		p-=(a-f);
		if(p<0){
			printf("%d\n",-1);
			return 0;
		}
		if(p<f) {
			p=b;
			ans++;
		}
		p-=f;
		if(p<0){
			printf("%d\n",-1);
			return 0;
		}
		dr=1;
		id++;
	} 
	printf("%d\n",ans);
return 0;
}
