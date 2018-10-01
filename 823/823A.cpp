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
	int n,a,b;
	cin>>n>>a>>b;
	int c=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		if(t==1){
			if(a) a--;
			else if(b){b--;c++;}
			else if(c) c--;
			else ans++;
		}
		if(t==2){
			if(b) b--;
			else ans+=2;
		}
	}
	cout<<ans<<endl;
return 0;
} 
