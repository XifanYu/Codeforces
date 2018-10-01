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

const int Maxn=1e5+5;
const int Maxk=2e6+5;
const int d=330;

int n,m,k;

class que{
	public:
		int l,r,id;
		bool operator<(const que &o)const{
			int k1=l/d,k2=o.l/d;
			return (k1<k2)||(k1==k2&&r<o.r);
		}
};

que q[Maxn];

int l=1,r=1;
int a[Maxn],cnt[Maxk];
ll Ans=0,ans[Maxn];

void add(int x){
	Ans+=cnt[x^k];
	cnt[x]++;
}

void del(int x){
	cnt[x]--;
	Ans-=cnt[x^k];
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		a[i]^=a[i-1];
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+m+1);
	cnt[0]++;
	cnt[a[1]]++;
	if(a[1]==k) Ans=1;
	for(int i=1;i<=m;i++){
		while(l>q[i].l){
			l--;
			add(a[l-1]);
		}
		while(r<q[i].r){
			r++;
			add(a[r]);
		}
		while(l<q[i].l){
			del(a[l-1]);
			l++;
		}
		while(r>q[i].r){
			del(a[r]);
			r--;
		}
		ans[q[i].id]=Ans;
	}
	for(int i=1;i<=m;i++) printf("%I64d\n",ans[i]);
return 0;
}
