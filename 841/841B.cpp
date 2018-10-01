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

int n,a[1000005],odd=0;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		if(a[i]%2) odd++;
		a[i]+=(i?a[i-1]:0);
	}
	if(a[n-1]%2) printf("First\n");
	else{
		if(odd) printf("First\n");
		else printf("Second\n");
	}
return 0;
}
