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

int n;

double p[100][100];
double w[10][100];
double s[10][100];
vector<int> opp[10][100];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int k=1;k<=(1<<n);k+=(1<<i)){
			for(int j=k;j<k+(1<<(i-1));j++){
				for(int m=k+(1<<(i-1));m<k+(1<<i);m++) opp[i][j].push_back(m);
			}
			for(int j=k+(1<<(i-1));j<k+(1<<i);j++){
				for(int m=k;m<k+(1<<(i-1));m++) opp[i][j].push_back(m);
			}
		}
	}
	for(int i=1;i<=(1<<n);i++){
		for(int j=1;j<=(1<<n);j++){
			scanf("%lf",&p[i][j]);
			p[i][j]/=(double)100;
		}
	}
	for(int i=1;i<=(1<<n);i++){
		w[0][i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=(1<<n);j++){
			for(auto k: opp[i][j]) w[i][j]+=w[i-1][j]*w[i-1][k]*p[j][k];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=(1<<n);j++){
			for(auto k: opp[i][j]) s[i][j]=max(s[i][j],s[i-1][k]+s[i-1][j]+(1<<(i-1))*w[i][j]);
		}
	}
	double ans=0;
	for(int i=1;i<=(1<<n);i++){
		ans=max(ans,s[n][i]);
	}
	cout<<fixed<<setprecision(10)<<ans<<"\n";
return 0;
}
