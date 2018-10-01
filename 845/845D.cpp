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

const int INF=1e9;

int main(){
	int n;
	stack<int> sl;//speed limit//
	stack<int> os;//overtake status//
	int ans=0;
	int speed;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		if(t==1){
			int s;
			scanf("%d",&s);
			speed=s;
			while(!sl.empty()&&speed>sl.top()){
				sl.pop();
				ans++;
			}
		}
		else if(t==2){
			while(!os.empty()&&os.top()==0){
				os.pop();
				ans++;
			}
		}
		else if(t==3){
			int s;
			scanf("%d",&s);
			sl.push(s);
			while(!sl.empty()&&speed>sl.top()){
				sl.pop();
				ans++;
			}
		}
		else if(t==4){
			os.push(1);
		}
		else if(t==5){
			sl.push(INF);
		}
		else if(t==6){
			os.push(0);
		}
	}
	printf("%d\n",ans);
return 0;
}
