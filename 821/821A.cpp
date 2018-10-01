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
	int c,v0,v1,a,l;
	cin>>c>>v0>>v1>>a>>l;
	int x=0;
	int i=1;
	x+=v0;
	v0+=a;
	v0=min(v0,v1);
	while(x<c){
		x-=l;
		x+=v0;
		v0+=a;
		v0=min(v0,v1);
		i++;
	}
	cout<<i<<endl;
return 0;
}
