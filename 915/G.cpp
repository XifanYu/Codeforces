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

const int Maxn=2000005;
const int md=1e9+7;

int n,k;
int u[Maxn],p[Maxn]; 
vector<int> d[Maxn];
int ans=0,sum=0;

ll fastpow(int x,int y){
	ll rez=1;
	if(y==0) return rez;
	rez=fastpow(x,y/2);
	rez*=rez;
	rez%=md;
	if(y&1) {
		rez*=x;
		rez%=md;
	}
	return rez;
}

void precompute(){
	for(int i=1;i<Maxn;i++) p[i]=fastpow(i,n);
}

void sieve(){
	for(int i=2;i<Maxn;i++){
		if(u[i]==0){
			for(int j=i,s=i*i;j<Maxn;j+=i){
				if(j%s) {
					if(u[j]!=-1) u[j]++;
				}
				else u[j]=-1;
			}
		}
	}
	for(int i=1;i<Maxn;i++){
		if(u[i]==-1) u[i]=0;
		else if(u[i]%2) u[i]=-1;
		else u[i]=1;
	}
	for(int i=1;i<Maxn;i++){
		if(u[i]==0) continue;
		for(int j=i;j<Maxn;j+=i){
			d[j].push_back(i);
		}
	}
}

int main(){
	scanf("%d%d",&n,&k);
	precompute();
	sieve();
	for(int i=1;i<=k;i++){
		for(auto v:d[i]){ 
			ans+=u[v]*(p[i/v]-p[(i-1)/v]);
			if(ans<0) ans+=md;
			ans%=md;
		}
		sum+=(ans^i);
		sum%=md;
	}
	printf("%d\n",sum);
return 0;
}
