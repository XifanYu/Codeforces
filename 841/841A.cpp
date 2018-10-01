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

int main(){
	int n,k;
	int c[256];
	memset(c,0,sizeof c);
	cin>>n>>k;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		c[s[i]]++;
	}
	bool ok=true;
	for(int i='a';i<='z';i++){
		if(c[i]>k) {
			ok=false;
			break;
		}
	}
	if(!ok) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
return 0;
} 
