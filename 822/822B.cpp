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
	int n,m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	int pos[1005];
	int ans=1005;
	for(int i=0;i<=m-n;i++){
		int now=0;
		int tem[1005];
		for(int j=0;j<n;j++){
			if(s[j]!=t[i+j]){
				now++;
				tem[now]=j+1;
			}
		}
		if(now<ans){
			ans=now;
			for(int j=1;j<=ans;j++) pos[j]=tem[j];
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++) cout<<pos[i]<<" ";
return 0;
} 
