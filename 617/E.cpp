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
const int d=400;

int n,m,k,l=1,r=1;
ll Ans=0;
int a[Maxn];
ll cnt[Maxk],ans[Maxn];

class que{
	public:
		int l,r,id;
};

que q[Maxn];

bool cmp(que q1,que q2){
	if(q1.l/d<q2.l/d) return true;
	if(q1.l/d==q2.l/d) return q1.r<q2.r;
	return false;
}

void delL(){
	Ans-=cnt[a[l-1]^k]+(a[r]==(a[l-1]^k)?1:0);
	cnt[a[l]]--;
	l++;
}

void delR(){
	Ans-=cnt[a[r]^k]+(a[l-1]==(a[r]^k)?1:0);
	r--;
	cnt[a[r]]--;
}

void addL(){
	l--;
	cnt[a[l]]++;
	Ans+=cnt[a[l-1]^k]+(a[r]==(a[l-1]^k)?1:0);
}

void addR(){
	cnt[a[r]]++;
	r++;
	Ans+=cnt[a[r]^k]+(a[l-1]==(a[r]^k)?1:0);
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
	Ans=(a[1]==k?1:0);
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=m;i++){
		while(r<q[i].r) addR();
		while(l>q[i].l) addL();
		while(r>q[i].r) delR();
		while(l<q[i].l) delL();
		ans[q[i].id]=Ans;
	}
	for(int i=1;i<=m;i++) printf("%I64d\n",ans[i]);
return 0;
}
