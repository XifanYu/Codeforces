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

int main(){
	int x;
	cin>>x;
	while(x%10==0)x/=10;
	int dig[15],id=1;
	while(x){
		dig[id++]=x%10;
		x/=10;
	}
	for(int i=1;i<=id/2;i++){
		if(dig[i]!=dig[id-i]) {
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
return 0;
}
