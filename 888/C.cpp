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

string s;
vector<int> pos[256];

int main(){
	cin>>s;
	for(int i='a';i<='z';i++) pos[i].push_back(-1);
	for(int i=0;i<s.length();i++){
		pos[s[i]].push_back(i);
	}
	for(int i='a';i<='z';i++) pos[i].push_back(s.length());
	int ans=100005;
	for(int i='a';i<='z';i++){
		int mint=0;
		for(int j=1;j<pos[i].size();j++){
			mint=max(mint,pos[i][j]-pos[i][j-1]);
		}
		ans=min(ans,mint);
	}
	printf("%d\n",ans);
return 0;
}
