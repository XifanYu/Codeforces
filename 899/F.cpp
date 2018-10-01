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

const int Maxn=1<<19;

int n,m,MN=1;
char c[Maxn];
int bit[Maxn];
set<int> ss[255];
int l,r;
char s;

void add(int i){
	while(i<=MN){
		bit[i]++;
		i+=i&(-i);
	}
}

void del(int i){
	while(i<=MN){
		bit[i]--;
		i+=i&(-i);
	}
}

int find(int i){
	int rez=0,k=MN>>1,sum=0;
	while(k>0){
		if(sum+bit[rez+k]<i) {
			sum+=bit[rez+k];
			rez+=k;
		}
		k>>=1;
	}
	return rez+1;
}

int calc(int i){
	int rez=0;
	while(i>0){
		rez+=bit[i];
		i-=i&(-i);
	}
	return rez;
}


int main(){
	scanf("%d%d",&n,&m);
	while(MN<=n) MN<<=1;
	scanf("%s",c+1);
	for(int i=1;i<=n;i++){
		ss[c[i]].insert(i);
		add(i);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d %c",&l,&r,&s);
		l=find(l);
		r=find(r);
		set<int>::iterator it=ss[s].LB(l),tp;
		while(it!=ss[s].end()&&*it<=r){
			tp=it++;
			del(*tp);
			ss[s].erase(tp);
		}
	}
	l=0;
	r=0;
	for(int i=1;i<=n;i++){
		r=calc(i);
		if(r-l) putchar(c[i]);
		l=r;
	}
	putchar('\n');
return 0;
}
