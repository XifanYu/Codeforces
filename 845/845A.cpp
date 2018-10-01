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
	int n;
	int a[1005];
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++) scanf("%d",a+i);
	sort(a+1,a+2*n+1);
	int x=a[n],y=a[n+1];
	if(y>x) printf("YES\n");
	else printf("NO\n");
return 0;
}
