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
	int k,n;
	vector<int> ans;
	cin>>k>>n;
	int a[2005];
	for(int i=1;i<=k;i++) {cin>>a[i];a[i]=a[i]+a[i-1];}
	int b;
	cin>>b;
	for(int i=1;i<=k;i++) ans.push_back(b-a[i]);
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	for(int i=1;i<=n-1;i++){
		cin>>b;
		for(int j=0;j<ans.size();j++){
			bool ok=false;
			for(int m=1;m<=k;m++) if(ans[j]+a[m]==b) {ok=true;break;}
			if(ok==false) {ans.erase(ans.begin()+j);j--;}
		}
	}
	cout<<ans.size()<<endl;
return 0;
}
