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
	int n;
	cin>>n;
	int a[105];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=1,j=n;
	for(i;i<n&&a[i]<a[i+1];i++);
	for(j;j>1&&a[j]<a[j-1];j--);
	if(i==j) cout<<"Yes"<<endl;
	else{
		for(i;i<j;i++){if(a[i]!=a[i+1]){cout<<"No"<<endl;exit(0);}}
		cout<<"Yes"<<endl;
	}
return 0;
} 
