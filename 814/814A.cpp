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
	int a[105],b[105];
	fill(a,a+105,0);
	vector<int> ind;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=k;i++)cin>>b[i];
	sort(b+1,b+k+1);
	reverse(b+1,b+k+1);
	int last_i=0;
	ind.push_back(0);
	for(int i=1;i<=n;i++){
		if(a[i]){
			if(a[i]<a[last_i]){
				cout<<"Yes"<<endl;
				exit(0);
			}
			last_i=i;
			ind.push_back(i);
		}
	}
	ind.push_back(n+1);
	a[n+1]=205;
	for(int i=0;i<ind.size()-1;i++){
		if(ind[i+1]-ind[i]==2){
			if(a[ind[i]]>b[k]||b[1]>a[ind[i+1]]) {
				cout<<"Yes"<<endl;
				exit(0);}
		}
		if(ind[i+1]-ind[i]>=3){
			cout<<"Yes"<<endl;
			exit(0);
		}
	}
	cout<<"No"<<endl;
return 0;
} 
