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

int sum(int x,int y){
	int ans=0;
	ans+=(x+1)*x*(y+1)/2;
	ans+=(y+1)*y*(x+1)/2;
return ans;
}

int main(){
	int m,b;
	cin>>m>>b;
	int best=0;
	for(int i=0;i<=b;i++){
		best=max(best,sum(i*m,b-i));
	}
	cout<<best<<endl;
return 0;
}
