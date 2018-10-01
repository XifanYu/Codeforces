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
#define FF first
#define SS second
#define LB lower_bound
#define PB push_back
#define lc p*2+1
#define rc p*2+2
#define rep(n) for(int i=1;i<=n;i++)
#define rep0(n) for(int i=0;i<n;i++)
#define rrep(n) for(int i=n;i;i--)
#define rrep0(n) for(int i=n-1;i>=0;i--)
#define forw(v) (v).begin(),(v).end()

typedef long long ll;
typedef pair<int,int> pi; 

/*
 * high precision: cout<<fixed<<setprecision(10)<<;
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=1e5+5;
const int Maxp=2e6+5;

int n;
int a[Maxn],b[Maxn],id=1;
int p[Maxp];
vector<int> d[Maxn];

void sieve(){
	for(int i=2;i<Maxp;i++){
		if(!p[i]){
			for(int j=2*i;j<Maxp;j+=i){
				p[j]=1;
			}
			for(int j=i;j<Maxn;j+=i){
				d[j].PB(i);
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sieve();
	for(;id<=n;id++){
		bool flag=false;
		if(a[id]==1) flag=true;
		for(auto v:d[a[id]]){
			if(p[v]==-1) {
				flag=true;
				break;
			}
		}
		if(flag) break;
		for(auto v:d[a[id]]){
			p[v]=-1;
		}
		b[id]=a[id];
	}
	if(id<=n){
		for(int i=a[id]+1;i<Maxp;i++){
			bool flag=false;
			for(auto v:d[i]){
				if(p[v]==-1) {
					flag=true;
					break;
				}
			}
			if(flag) continue;
			for(auto v:d[i]){
				p[v]=-1;
			}
			b[id++]=i;
			break;
		} 
	}
	for(int pt=2;id<=n;id++){
		while(p[pt]){
			pt++;
		}
		p[pt]=-1;
		b[id]=pt++;
	}
	for(int i=1;i<=n;i++) printf("%d ",b[i]);printf("\n");
return 0;
}
