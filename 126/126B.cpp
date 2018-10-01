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

char c[1000005];
int f[1000005];


int main(){
	string s;
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++) c[i]=s[i];
	for(int i=2;i<=l;i++){
		int p=f[i-1];
		while(p>0&&c[p]!=c[i-1]) p=f[p];
		if(c[p]==c[i-1]) f[i]=p+1;
		else f[i]=0;
	}
	for(int i=1;i<l;i++){
		if(f[i]==f[l]&&f[l]){
			for(int j=0;j<f[l];j++) cout<<c[j];
			exit(0);
		}
	}
	if(f[f[l]]){
		for(int i=0;i<f[f[l]];i++) cout<<c[i];
		exit(0);
	}
	cout<<"Just a legend"<<endl;
return 0; 
} 
