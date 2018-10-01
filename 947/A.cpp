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

const int Maxn=1e6+5;

int n,ans=Maxn;
int v[Maxn],f[Maxn];

void sieve(){
	for(int i=2;i<=n;i++){
		if(!f[i]){
			for(int j=2*i;j<=n;j+=i){
				f[j]=1;
				v[j]=max(v[j],i);
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	sieve();
	for(int i=n-v[n]+1;i<=n;i++){
		ans=min(ans,i-v[i]+1);
	}
	printf("%d\n",ans);
return 0;
}
