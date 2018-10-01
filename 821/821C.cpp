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
	int a,b,l,r;
	cin>>a>>b>>l>>r;
	int s=a+b;
	if((l-a-1+s)/s-1==(r-a-1+s)/s-1){
		if((l-a-1)%s+1>b) cout<<r-l+1<<endl;
		else if((r-a-1)%s+1<=b) cout<<1<<endl;
		else cout<<(r-a-1)%s-b+2<<endl;
	}
	else{
		if(b>=a){
			int i1,i2,le,re;
			i1=(l-a+s-1)/s-1;
			i2=(r-a+s-1)/s-1;
			le=(i1+1)*s+a-l+1;
			re=r-i2*s-a;
			if(i2==i1+1){
				if(le<=a){
					if(re<s) cout<<max(re-b,le)<<endl;
					if(re==s) cout<<a+1<<endl;
				}
				else if(re<=b){
					if(le<=a) cout<<le<<endl;
					else if(le>a) cout<<a+1<<endl;
				}
				else{
					cout<<a+1<<endl;
				}
			}
			else{
				cout<<a+1<<endl;
			}
		}
		else{
			int i1,i2,le,re;
			i1=(l-a+s-1)/s-1;
			i2=(r-a+s-1)/s-1;
			le=(i1+1)*s+a-l+1;
			re=r-i2*s-a;
			if(i2==i1+1){
				if(le+re>s){
					cout<<a+le+re-s<<endl;
				}
				if(le+re<=s){
					if(re>b) cout<<re-b+le<<endl;
					else if(le>a) cout<<a+1<<endl;
					else cout<<le<<endl;
				}
			}
			else{
				if(le+re>s) cout<<2*a-b<<endl;
				else{
					if(le>=a-b) cout<<2*a-b<<endl;
					else if(re>2*b) cout<<a+le+re-2*b<<endl;
					else cout<<2*a-b<<endl;
				}
			}	
		}	
	}
return 0;
}
