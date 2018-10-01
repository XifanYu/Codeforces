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

typedef pair<long long,long long> pll;

bool comp(pll f1, pll f2){
	return f1.first*f2.second>=f1.second*f2.first;
}

pll minu(pll f1, pll f2){
	long long x,y;
	x=f1.second;
	y=f2.second;
	while(x){
		long long temp=x;
		x=y%x;
		y=temp;
	}
	pll f3,f4;
	f3=make_pair(f1.first*f2.second/y,f1.second*f2.second/y);
	f4=make_pair(f2.first*f1.second/y,f1.second*f2.second/y);
	f1=f3;
	f2=f4;
	pll f;
	f=make_pair(max(f1.first-f2.first,f2.first-f1.first),f1.second);
	long long x1,y1;
	x1=f.first;
	y1=f.second;
	while(x1){
		long long temp1=x1;
		x1=y1%x1;
		y1=temp1;
	}
	f=make_pair(f.first/y1,f.second/y1);
return f;
}

long long div(pll f1,pll f2){
	long long x,y;
	x=f1.second;
	y=f2.second;
	while(x){
		long long temp=x;
		x=y%x;
		y=temp;
	}
	pll f3,f4;
	f3=make_pair(f1.first*f2.second/y,f1.second*f2.second/y);
	f4=make_pair(f2.first*f1.second/y,f1.second*f2.second/y);
	f1=f3;
	f2=f4;
return f1.first/f2.first;
} 

int main(){
	long long n,a;
	cin>>n>>a;
	pll u=make_pair((long long)180,n);
	long long m=div(make_pair(a,1),u);
	pll f1,f2,p;
	f1=make_pair(u.first*m,u.second);
	f2=make_pair(u.first*(m+1),u.second);
	p=make_pair(a,1);
	if(comp(minu(f1,p),minu(f2,p))){
		cout<<1<<" "<<2<<" "<<max(n-m,(long long)3)<<endl;
	}
	else cout<<1<<" "<<2<<" "<<max(min(n-m+1,n),(long long)3)<<endl;
return 0;
}
