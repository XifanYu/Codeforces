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

int n,t;
int a[105];
int d=0;

int main(){
	scanf("%d%d",&n,&t);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	while(t>0){
		t-=86400-a[d++];
	}
	printf("%d",d);
return 0;
}
