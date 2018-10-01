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

const int Maxn=400005;
const ll INF=1e16;

int Q,t,ans=0,cnt=1; 
ll p,q;
ll w[Maxn]; //weight
int par[20][Maxn]; //par[i][node] denotes (1<<i)th parent of node
ll sum[20][Maxn]; //sum[i][node] denotes the sum of the weight of the sequence until par[i][node]

int main(){
	scanf("%d",&Q);
	w[0]=INF;
	par[0][0]=0;
	sum[0][0]=INF;
	for(int i=1;i<20;i++){
		par[i][0]=0;
		sum[i][0]=INF;
	}
	w[1]=0;
	par[0][1]=0;
	sum[0][1]=0;
	for(int i=1;i<20;i++){
		par[i][1]=0;
		sum[i][1]=INF;
	}
	while(Q--){
		scanf("%d%I64d%I64d",&t,&p,&q);
		p^=ans;q^=ans;
		if(t==1){
			w[++cnt]=q;	
			int pos=p;
			if(w[p]>=q){
				par[0][cnt]=p;
				sum[0][cnt]=q;
			}
			else{
				for(int i=19;i>=0;i--){
					if(w[par[i][pos]]<q){
						pos=par[i][pos];
					}
				}
				par[0][cnt]=par[0][pos];
				sum[0][cnt]=q;
			}
			for(int i=1;i<20;i++){
				par[i][cnt]=par[i-1][par[i-1][cnt]];
				sum[i][cnt]=(sum[i-1][par[i-1][cnt]]!=INF?sum[i-1][cnt]+sum[i-1][par[i-1][cnt]]:INF);
			}
		}
		else{
			ans=0;
			int pos=p;
			for(int i=19;i>=0;i--){
				if(sum[i][pos]<=q){
					q-=sum[i][pos];
					pos=par[i][pos];
					ans+=(1<<i);
				}
			}
			printf("%d\n",ans);
		}
	}
return 0;
}
