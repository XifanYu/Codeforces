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

const int Maxn=200005;

int n;
int t[Maxn],used[Maxn];

int main(){
	scanf("%d",&n);
	int ans=n;
	for(int i=1;i<=n;i++)scanf("%d",t+i);
	for(int i=1;i<=n;i++){
		if(t[i]&&!used[t[i]]){
			used[t[i]]=1;
			ans--;
		}
	}
	printf("%d\n",ans);
return 0;
}
