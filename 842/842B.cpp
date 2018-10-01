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
using namespace std;

int main(){
	int r,d;
	scanf("%d %d",&r,&d);
	int n;
	scanf("%d",&n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		int x,y,ra;
		scanf("%d %d %d",&x,&y,&ra);
		int d1=r-d+ra,d2=r-ra;
		if(d1*d1<=x*x+y*y&&d2*d2>=x*x+y*y) cnt++;
	}
	printf("%d\n",cnt);
return 0;
}
