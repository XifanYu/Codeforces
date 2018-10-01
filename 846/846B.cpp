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

const int Maxk=50;

int n,k;
ll m;
ll t[Maxk];
ll sum=0;

int main(){
	scanf("%d%d%I64d",&n,&k,&m);
	for(int i=0;i<k;i++){
		scanf("%I64d",t+i);
		sum+=t[i];
	}
	sort(t,t+k);
	int maxp=0;
	for(int i=0;i<=n;i++){
		ll time1=(ll)i*sum;
		ll time2=m-time1;
		if(time2>=0){
		int id=0,idh=i+1,p=i*(k+1);
		while(id<k&&time2>=t[id]){
			if(idh==n+1){
				idh=i+1;
				id++;
				continue;
			}
			time2-=t[id];
			idh++;
			p++;
			if(id==k-1) p++;
		}
		maxp=max(maxp,p);
		}
		else break;
	}
	printf("%d\n",maxp);
return 0;
}
