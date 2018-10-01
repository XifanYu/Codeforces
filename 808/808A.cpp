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
	int n_=n;
	int m=1;
	while(n_>=10){
		n_/=10;
		m*=10;
	}
	cout<<(n_+1)*m-n<<endl;
return 0;
}
