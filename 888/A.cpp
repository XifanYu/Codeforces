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
int a[1005];
int l,m;
int ans=0;


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	l=a[0];
	m=a[1];
	for(int i=2;i<n;i++){
		if(m>l&&m>a[i]) ans++;
		else if(m<l&&m<a[i]) ans++;
		l=m;
		m=a[i];
	}
	printf("%d\n",ans);
return 0;
}
