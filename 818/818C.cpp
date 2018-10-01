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
	string s;
	vector<int> a;
	int m,ans=0,ind=0;
	for(int i=1;i<=2*n;i++){
		cin>>s;
		if(s[0]=='a'){
			cin>>m;
			a.push_back(m);
		}
		if(s[0]=='r'){
			int siz=a.size();
			ind++;
			if(a[siz-1]!=0&&a[siz-1]!=ind){
				ans++;
				a.pop_back();
				if(siz>1) for(int j=siz-2;a[j]!=0&&j>=0;j--) a[j]=0;
			}
			else{
				a.pop_back();
			}
		}
	}
	cout<<ans<<endl;
return 0;
}
