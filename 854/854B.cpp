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

typedef pair<int,int> pi;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	ll n,k;
	cin>>n>>k;
	if(k<n&&k>0) cout<<1<<" ";
	else cout<<0<<" ";
	if(k*3<=n) cout<<2*k<<endl;
	else cout<<n-k<<endl;
	
	
	
	
return 0;
}
