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


int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a==1||b==1||c==1){
		cout<<"YES\n";
		return 0;
	}
	if(a==2){
		if(b==2||c==2){
			cout<<"YES\n";
			return 0;
		}
		if(b==4&&c==4){
			cout<<"YES\n";
			return 0;
		}
		cout<<"NO\n";
		return 0;
	}
	else if(b==2){
		if(a==2||c==2){
			cout<<"YES\n";
			return 0;
		}
		if(a==4&&c==4){
			cout<<"YES\n";
			return 0;
		}
		cout<<"NO\n";
		return 0;
	}
	else if(c==2){
		if(a==2||b==2){
			cout<<"YES\n";
			return 0;
		}
		if(a==4&&b==4){
			cout<<"YES\n";
			return 0;
		}
		cout<<"NO\n";
		return 0;
	}
	if(a==3&&b==3&&c==3){
		cout<<"YES\n";
		return 0;
	}
	cout<<"NO\n";
return 0;
}
