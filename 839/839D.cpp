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

const int Maxn=200005;
const int Maxa=1000005;
const int md=1e9+7;

int n;
int a[Maxn];
int cnt[Maxa];
long long num[Maxa];
long long ans[Maxa];
int p[Maxa];

int main(){
	scanf("%d",&n);
	memset(cnt,0,sizeof cnt);
	fill(ans,ans+Maxa,-1);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		for(int j=1;j<=sqrt(a[i]);j++){
			if(a[i]%j==0){
				cnt[j]++;
				if(j!=a[i]/j) cnt[a[i]/j]++;
			}
		}
	}
	p[0]=1;
	for(int i=1;i<Maxa;i++){
		p[i]=(p[i-1]*2)%md;
	}
	for(int i=2;i<Maxa;i++){
		if(cnt[i]) num[i]=((long long)cnt[i]*p[cnt[i]-1])%md;
	}
	long long s=0;
	for(int i=Maxa-1;i>=2;i--){
		ans[i]=num[i];
		for(int j=2*i;j<Maxa;j+=i){
			ans[i]=(ans[i]-ans[j]+md)%md;
		}
		s=(s+ans[i]*i)%md;
	}
	printf("%I64d\n",s);
return 0;
}
