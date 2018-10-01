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
	int a[52][52];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]!=1){
				bool ok=false;
				for(int p=1;p<=n;p++){
					for(int q=1;q<=n;q++){
						if(a[i][p]+a[q][j]==a[i][j]) ok=true;
					}
				}
				if(ok==false){
					cout<<"No"<<endl;exit(0);
				}
			}
		}
	}
	cout<<"Yes"<<endl;
return 0; 
} 
