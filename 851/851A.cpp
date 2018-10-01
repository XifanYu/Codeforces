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
	
	int n,k,t;
	scanf("%d%d%d",&n,&k,&t);
	int minp=max(1,t-k+1),maxp=min(n,t);
	cout<<maxp-minp+1<<"\n";
	
	
	
return 0;
}

