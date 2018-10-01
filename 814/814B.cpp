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
	int a[1005],b[1005];
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	vector<int> vec;
	for(int i=1;i<=n;i++)if(a[i]!=b[i])vec.push_back(i);
	if(vec.size()==2){
		int remain=1;
		vector<int> remains;
		for(remain;remains.size()<2;remain++){
			bool ok=false;
			bool findnext=true;
			for(int i=1;i<=n&&findnext;i++){
				if(i!=vec[0]&&i!=vec[1]&&(a[i]==remain||b[i]==remain)) {
					ok=true;
					findnext=false;
				}
			}
			if(ok==false) remains.push_back(remain);
		}
		int last=0;
		
		for(int i=1;i<=n;i++){
			if(i==vec[0]) {
				if((a[vec[0]]==remains[0]&&b[vec[1]]==remains[1])||(b[vec[0]]==remains[0]&&a[vec[1]]==remains[1])) cout<<remains[0]<<" ";
				else cout<<remains[1]<<" ";
			}
			else if(i==vec[1]){
				if((a[vec[0]]==remains[0]&&b[vec[1]]==remains[1])||(b[vec[0]]==remains[0]&&a[vec[1]]==remains[1])) cout<<remains[1]<<" ";
				else cout<<remains[0]<<" ";
			}
			else cout<<a[i]<<" ";
		}
	}
	if(vec.size()==1){
		int remain=0;
		bool ok=true;
		for(;ok;){
			remain++;
			ok=false;
			bool findnext=true;
			for(int i=1;i<=n&&findnext;i++){
				if(i!=vec[0]&&a[i]==remain) {
					ok=true;
					findnext=false;
				}
				if(i!=vec[0]&&b[i]==remain) {
					ok=true;
					findnext=false;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(i==vec[0]) cout<<remain<<" ";
			else cout<<a[i]<<" ";
		}
	}
return 0;
}
