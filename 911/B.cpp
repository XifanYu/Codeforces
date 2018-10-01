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
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;


int main(){
	int n,a,b;
	int ans=0;
	cin>>n>>a>>b;
	for(int i=1;i<n;i++){
		if(a>=i&&b>=(n-i))ans=max(ans,min((a/i),(b/(n-i))));
	}
	cout<<ans<<"\n";
return 0;
}
