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
string s;
int a=0,b=0;

int main(){
	scanf("%d",&n);
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='U') a++;
		if(s[i]=='L') b--;
		if(s[i]=='R') b++;
		if(s[i]=='D') a--;
	}
	printf("%d\n",n-(abs(a)+abs(b)));
return 0;
}
