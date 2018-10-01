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

int main(){
	int k;
	scanf("%d",&k);
	int r[25];
	for(int i=0;i<k;i++){
		scanf("%d",r+i);
	}
	sort(r,r+k);
	printf("%d\n",r[k-1]-25>0?r[k-1]-25:0);
return 0;
	
} 
