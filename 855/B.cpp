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

ll a[100005];

ll n1[100005],n2[100005],n3[100005];

int main(){
	fill(n1,n1+100005,-1e18);
	fill(n2,n2+100005,-1e18);
	fill(n3,n3+100005,-1e18);
	int n,p,q,r;
	scanf("%d%d%d%d",&n,&p,&q,&r);
	for(int i=1;i<=n;i++) scanf("%I64d",a+i);
	for(int i=1;i<=n;i++) n1[i]=max((ll)p*a[i],n1[i-1]);
	for(int i=1;i<=n;i++) {
		if(i>1) n2[i]=max(((ll)q*a[i]+n1[i]),n2[i-1]);
		else n2[i]=(ll)q*a[i]+n1[i];
	}
	for(int i=1;i<=n;i++) {
		if(i>1) n3[i]=max(((ll)r*a[i]+n2[i]),n3[i-1]);
		else n3[i]=(ll)r*a[i]+n2[i];
	}
	printf("%I64d\n",n3[n]);
return 0;
}
