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

int main(){
	int n,k;
	cin>>n>>k;
	int r;
	if(n-k-1==0) r=0;
	else if((n-k-1)%k==1) r=2*((n-k-1)/k)+1;
	else r=2*((n-k-2)/k)+2;
	cout<<2+r<<endl;
	for(int i=1;i<=k;i++){
		cout<<1<<' '<<i+1<<endl;
	}
	int m=n-k-1,p=1;
	while(m>=k){
		for(int i=2;i<=k+1;i++){
			cout<<(p-1)*k+i<<' '<<p*k+i<<endl;
		}
		p++;
		m-=k;
	}
	int i=2;
	while(m){
		cout<<(p-1)*k+i<<' '<<p*k+i<<endl;
		m--;
		i++;
	}
return 0;
}
