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
	bool a[26];
	memset(a,0,sizeof a);
	string s;
	cin>>s;
	int k;
	cin>>k;
	if(k>s.length()) {
		printf("impossible\n");
		exit(0);
	}
	for(int i=0;i<s.length();i++){
		if(!a[s[i]-'a']) a[s[i]-'a']=true;
	}
	int cnt=0;
	for(int i=0;i<26;i++){
		if(a[i]) cnt++;
	}
	printf("%d\n",max(k-cnt,0));
return 0;
}
