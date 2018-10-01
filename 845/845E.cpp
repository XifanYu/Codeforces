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

typedef pair<int,int> pi;

const int Maxk=505;

int n,m,k;
pi p[Maxk];
pi px[Maxk],py[Maxk];//按照x,y坐标分别排序后的点//
int c[4][Maxk];//考察的行或列//

bool compx(pi a,pi b){
	return a.first<=b.first;
}

bool compy(pi a,pi b){
	return a.second<=b.second;
}

bool sweepx(int row,int t){
	if(row<=0||row>n) return true;
	int l=1;
	for(int i=1;i<=k;i++){
		pi np=py[i];
		if(abs(np.first-row)<=t){
			if(np.second-t<=l) l=np.second+t+1;
			else return false;
		}
	}
	if(l>m) return true;
	else return false;
}

bool sweepy(int col,int t){
	if(col<=0||col>m) return true;
	int u=1;
	for(int i=1;i<=k;i++){
		pi np=px[i];
		if(abs(np.second-col)<=t){
			if(np.first-t<=u) u=np.first+t+1;
			else return false;
		}
	}
	if(u>n) return true;
	else return false;
}

bool check(int t){
	for(int i=1;i<=k;i++){
		c[0][i]=px[i].first+t+1;
		c[1][i]=px[k+1-i].first-t-1;
		c[2][i]=py[i].second+t+1;
		c[3][i]=py[k+1-i].second-t-1;
	}
	int d[4];
	for(int i=0;i<2;i++){
		int j=0;
		while(j<=k&&sweepx(c[i][j],t)) j++;
		d[i]=(j<=k?c[i][j]:n+1);
	}
	for(int i=2;i<4;i++){
		int j=0;
		while(j<=k&&sweepy(c[i][j],t)) j++;
		d[i]=(j<=k?c[i][j]:m+1);
	}
	if(max(d[1]-d[0],d[3]-d[2])<=2*t) return true;
	else return false;
}


int main(){
	scanf("%d %d %d",&n,&m,&k);
	int x,y;
	for(int i=1;i<=k;i++){
		scanf("%d %d",&x,&y);
		p[i]=pi(x,y);
		px[i]=pi(x,y);
		py[i]=pi(x,y);
	}
	sort(px+1,px+k+1,compx);
	sort(py+1,py+k+1,compy);
	c[0][0]=1,c[1][0]=n,c[2][0]=1,c[3][0]=m;
	int lb=-1,ub=1e9;
	while(ub-lb>1){
		int mi=(ub+lb)/2;
		if(check(mi)) ub=mi;
		else lb=mi;
	}
	printf("%d\n",ub);
return 0;
}
