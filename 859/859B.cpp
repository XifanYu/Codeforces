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

int n;
int sq[1005];

int main(){
	for(int i=1;i<=1000;i++){
		sq[i]=i*i;
	}
	scanf("%d",&n);
	int lb=upper_bound(sq,sq+1001,n)-sq-1;
	if(n==sq[lb]) printf("%d\n",4*lb);
	else if(n-sq[lb]<=lb) printf("%d\n",4*lb+2);
	else printf("%d\n",4*lb+4);
return 0;
}
