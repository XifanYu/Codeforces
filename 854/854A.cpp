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

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n;
	cin>>n;
	int x=n/2;
	while(true){
		if(gcd(x,n-x)==1){
			printf("%d %d\n",x,n-x);
			break;
		}
		x--;
	}
	
	
	
return 0;
}
