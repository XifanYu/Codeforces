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

string s[10];

bool check1(){
	for(int i=0;i<10;i++){
		for(int j=0;j<6;j++){
			int ans=0;
			for(int k=0;k<5;k++){
				if(ans>1) break;
				if(s[i][j+k]=='O') break;
				if(s[i][j+k]=='.') ans++;
				if(ans==1&&k==4) return true;
			}
		}
	}
return false;
}

bool check2(){
	for(int i=0;i<6;i++){
		for(int j=0;j<10;j++){
			int ans=0;
			for(int k=0;k<5;k++){
				if(ans>1) break;
				if(s[i+k][j]=='O') break;
				if(s[i+k][j]=='.') ans++;
				if(ans==1&&k==4) return true;
			} 
		}
	}
return false;
}

bool check3(){
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			int ans=0;
			for(int k=0;k<5;k++){
				if(ans>1) break;
				if(s[i+k][j+k]=='O') break;
				if(s[i+k][j+k]=='.') ans++;
				if(ans==1&&k==4) return true;
			}
		}
	}
return false;
}

bool check4(){
	for(int i=0;i<6;i++){
		for(int j=4;j<10;j++){
			int ans=0;
			for(int k=0;k<5;k++){
				if(ans>1) break;
				if(s[i+k][j-k]=='O') break;
				if(s[i+k][j-k]=='.') ans++;
				if(ans==1&&k==4) return true;
			}
		}
	}
return false; 
}

int main(){
	for(int i=0;i<10;i++) cin>>s[i];
	if(check1()||check2()||check3()||check4()) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
return 0;
}
