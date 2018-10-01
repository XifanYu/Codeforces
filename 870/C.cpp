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
	int q;
	cin>>q;
	while(q--){
		int x;
		scanf("%d",&x);
		if(x<4) cout<<-1<<"\n";
		else if(x==5||x==7) cout<<-1<<"\n";
		else if(x==4||x==6) cout<<1<<"\n";
		else if(x==11) cout<<-1<<"\n";
		else{
			int y=x/4,r=x%4;
			if(r==0||r==2) cout<<y<<"\n";
			else cout<<y-1<<"\n";
		}
	}
return 0;
}
