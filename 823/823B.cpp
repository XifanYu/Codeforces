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
	int u=101,d=0,l=101,r=0;
	int num=0;
	string c;
	for(int i=1;i<=n;i++){
		cin>>c;
		for(int j=1;j<=m;j++){
			if(c[j-1]=='B'){
				if(j<l) l=j;
				if(j>r) r=j;
				if(i<u) u=i;
				if(i>d) d=i;
				num++;
			}
		}
	}
	if(num){
		if(r-l>d-u){
			if(r-l+1<=n) cout<<(r-l+1)*(r-l+1)-num<<endl;
			else cout<<-1<<endl;
		}
		else if(r-l<d-u){
			if(d-u+1<=m) cout<<(d-u+1)*(d-u+1)-num<<endl;
			else cout<<-1<<endl;
		}
		else if(r-l==d-u){
			cout<<(r-l+1)*(r-l+1)-num<<endl;
		}
	}
	else cout<<1<<endl;
return 0;
}
