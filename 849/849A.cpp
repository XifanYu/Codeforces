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

typedef pair<int,int> pi;
typedef long long ll;

int main(){
	int n;
	int a[105];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	if(a[1]%2==1&&a[n]%2==1){
		if(n%2==1) printf("Yes\n");
		else printf("No\n");
	}
	else{
		printf("No\n");
	}
return 0;
}
