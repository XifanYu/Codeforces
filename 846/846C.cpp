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
using namespace std;

typedef pair<int,int> pi;
typedef long long ll;

const int Maxn=5005;

int n;
ll sum[Maxn];
ll res[5][Maxn];
int pr[5][Maxn];


int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%I64d",sum+i);
		sum[i]+=sum[i-1];
	}
	int id=3;
	for(int i=0;i<=n;i++) res[4][i]=(ll)(-1)*sum[i];
	for(int i=1;i<=3;i++) fill(res[i],res[i]+Maxn,-1e18);
	for(int i=0;i<=n;i++) pr[0][i]=i;
	while(id){
		int symb;
		if(id%2) symb=1;
		else symb=-1;
		for(int i=0;i<=n;i++){
			if(id<3){
			for(int j=i;j<=n;j++){
				if(res[id][i]<res[id+1][j]+(ll)2*symb*sum[i]){
					res[id][i]=res[id+1][j]+(ll)2*symb*sum[i];
					pr[id][i]=j;
				}
			}
			}
			else{
				if(res[id][i]<res[id+1][n]+(ll)2*symb*sum[i]){
					res[id][i]=res[id+1][n]+(ll)2*symb*sum[i];
					pr[id][i]=n;
				}
			}
		}
		id--;
	}
	for(int i=0;i<=n;i++){
		if(res[0][0]<res[1][i]){
			res[0][0]=res[1][i];
			pr[0][0]=i;
		}
	}
	int pos=0;
	
	while(id<3){
		pos=pr[id][pos];
		if(id) printf(" ");
		printf("%d",pos);
		id++;
	}
return 0;
}
