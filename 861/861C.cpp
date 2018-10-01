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
using namespace std;

bool check(char c){
	return (c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u');
}

bool split[3005];

int main(){
	string s;
	cin>>s;
	for(int i=2;i<s.length();){
		if(check(s[i-2])&&check(s[i-1])&&check(s[i])){
			if(s[i-2]==s[i-1]&&s[i-1]==s[i]){
				i++;
				continue;
			}
			else {
				split[i]=true;
				i+=2;
			}
		}
		else i++;
	}
	for(int i=0;i<s.length();i++){
		if(split[i]) printf(" ");
		printf("%c",s[i]);
	}
	
return 0;
}
