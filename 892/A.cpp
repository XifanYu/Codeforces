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
ll a[100005],b[100005];
ll sum=0;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%I64d",a+i);
		sum+=a[i];
	}
	for(int i=0;i<n;i++) scanf("%I64d",b+i);
	sort(b+0,b+n);
	if(sum<=b[n-2]+b[n-1]) cout<<"YES\n";
	else cout<<"NO\n";
return 0;
}
