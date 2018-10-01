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
int num[105];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		num[x]++;
	}
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			if(i!=j){
				if(num[i]==num[j]&&num[i]+num[j]==n){
					printf("YES\n");
					printf("%d %d\n",i,j);
					return 0;
				}
			}
		}
	}
	printf("NO\n");
return 0;
}
