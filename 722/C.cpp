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

#define MP make_pair
#define FS first
#define SC second
#define LB lower_bound
#define PB push_back
#define lc p*2+1
#define rc p*2+2

typedef long long ll;
typedef pair<int,int> pi; 

const int Maxn=100005;

int n,x;
int a[Maxn],b[Maxn],f[Maxn];
ll v[Maxn],ans[Maxn];

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	for(int i=n;i>=1;i--){
		x=b[i];
		f[x]=x;
		v[x]=a[x];
		if(f[x-1]){
			f[x]=find(x-1);
			v[f[x]]+=v[x];
		}
		if(f[x+1]){
			f[x+1]=find(x);
			v[f[x]]+=v[x+1];
		}
		ans[i-1]=max(ans[i],v[f[x]]);
	}
	for(int i=1;i<=n;i++){
		printf("%I64d\n",ans[i]);
	}
	return 0;
}
