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

int n;
int a[100005],mit=1e9+7,ans=1e9+7;
vector<int> pos;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		mit=min(mit,a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==mit) pos.push_back(i);
	}
	for(int i=0;i+1<pos.size();i++){
		ans=min(ans,pos[i+1]-pos[i]);
	}
	cout<<ans<<"\n";
return 0;
}
