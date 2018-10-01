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

typedef long long ll;

const ll md=1e9+7;

int n;
int a[505][505];
ll dp1[505][505]; //stands for total ways
ll dp2[505][505]; //stands for ways to directly connect

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		dp1[i][i]=dp2[i][i]=1;
	}
	for(int i=1;i<n;i++){
		for(int x=0,y=i;x<n;x++,y=(y+1)%n){
			if(a[x][y]){
				for(int k=x;k!=y;k=(k+1)%n){
					dp2[x][y]+=dp1[x][k]*dp1[(k+1)%n][y];
					dp2[x][y]%=md;
				}
			}
			for(int k=x;k!=y;k=(k+1)%n){
				dp1[x][y]+=dp2[x][(k+1)%n]*dp1[(k+1)%n][y];
				dp1[x][y]%=md;
			}
		} 
	}
	printf("%I64d\n",dp1[0][n-1]);
}
