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
#include <memory.h>
#include <iomanip>
using namespace std;

int fact(int d,int x){
	int ans=0;
	while(x%d==0){
		x/=d;
		ans++;
	}
return ans;
}

int main(){
	int n,k;
	cin>>n>>k;
	int d2=fact(2,n),d5=fact(5,n);
	int d0=min(d2,d5);
	d2-=d0;
	d5-=d0;
	k-=d0;
	int mul=1;
	while(k>0){
		if(d5){
			d5--;
			k--;
			mul*=2;
		} 
		else if(d2){
			d2--;
			k--;
			mul*=5;
		}
		else{
			k--;
			mul*=10;
		}
	}
	cout<<(long long)mul*n<<"\n";
return 0;
} 
