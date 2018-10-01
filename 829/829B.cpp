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
using namespace std;

int main(){
	char k1[30],k2[30];
	string s;
	for(int i=1;i<=26;i++) cin>>k1[i];
	for(int i=1;i<=26;i++) cin>>k2[i];
	cin>>s;
	for(int i=0;i<s.length();i++){
		for(int j=1;j<=26;j++){
			if(s[i]==k1[j]) {cout<<k2[j];break;}
			if(s[i]==k1[j]-'a'+'A') {cout<<char(k2[j]-'a'+'A');break;}
			if(s[i]=='0') {cout<<0;break;}
			if(s[i]=='1') {cout<<1;break;}
			if(s[i]=='2') {cout<<2;break;}
			if(s[i]=='3') {cout<<3;break;}
			if(s[i]=='4') {cout<<4;break;}
			if(s[i]=='5') {cout<<5;break;}
			if(s[i]=='6') {cout<<6;break;}
			if(s[i]=='7') {cout<<7;break;}
			if(s[i]=='8') {cout<<8;break;}
			if(s[i]=='9') {cout<<9;break;}
		}
	}
return 0;
}
