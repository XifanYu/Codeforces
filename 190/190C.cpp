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

typedef long long ll;
typedef pair<int,int> pi;


int main(){
	int n;
	char s[10];
	string ans="";
	stack<int> stk;
	rint(n);
	while(scanf("%s",s)==1){
		while(!stk.empty()&&stk.top()==2) {
			stk.pop();
			ans+=">";
			stk.top()++;
		}
		if(s[0]=='p'){
			stk.push(0);
			ans+="pair<";
		}
		if(s[0]=='i'){
			if(stk.top()==0){
				stk.pop();
				stk.push(1);
				ans+="int,";
			}
			else if(stk.top()==1){
				stk.pop();
				stk.push(2);
				ans+="int";
			}
		}
	}
	cout<<ans<<"\n";
return 0;
}
