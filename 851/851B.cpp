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
	
	ll ax,ay,bx,by,cx,cy;
	cin>>ax>>ay>>bx>>by>>cx>>cy;
	ll dx1=ax-bx,dy1=ay-by,dx2=bx-cx,dy2=by-cy;
	if(dx1*dx1+dy1*dy1==dx2*dx2+dy2*dy2) {
		if(bx*2==ax+cx&&by*2==ay+cy)cout<<"No"<<"\n";
		else cout<<"Yes"<<"\n";
	}
	else cout<<"No"<<"\n";
	
	
	
	
return 0;
}
