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
using namespace std;

int n2[205][205],n5[205][205],n[205][205];
long long a[205];
long long n,k;

int calc(long long i,long long m){
	int ans=0;
	while(m%i==0){
		m/=i;
		ans++;
	}
return ans;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	for(int i=1;i<=k;i++){
		for(int j=i;j<=n;j++){
			n2[i][j]=max(n2[i][j-1],n2[i-1][j-1]+calc(2,a[j]));
			n5[i][j]=max(n5[i][j-1],n5[i-1][j-1]+calc(5,a[j]));
			n[i][j]=min(n[i][j-1],n[i-1][j-1]);
		}
	}
	printf("%d\n",;
return 0;
}


