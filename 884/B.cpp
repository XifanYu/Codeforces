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

int n,x;
int a[100005]; 
int l;

int main(){
	scanf("%d%d",&n,&x);
	for(int i=0;i<n;i++) {
		scanf("%d",a+i);
		l+=a[i]+1;
	}
	l-=1;
	if(l==x) cout<<"YES\n";
	else cout<<"NO\n";
return 0;
}
