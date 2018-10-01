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

int l,r,x,y,k;

int main(){
	scanf("%d %d %d %d %d",&l,&r,&x,&y,&k);
	for(int i=x;i<=y&&i<=r/k;i++){
		int m=i*k;
		if(l<=m&&m<=r){
			printf("YES\n");
			exit(0);
		}
	}
	printf("NO\n");
return 0;
}
