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
	int n;
	map<string,int> t;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		t[s]++;
		if(t[s]>=2) cout<<"YES\n";
		else cout<<"NO\n";
	} 
return 0;
}
