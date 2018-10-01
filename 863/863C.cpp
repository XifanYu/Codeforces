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

typedef pair<int,int> pi;

int a,b;
long long k;
int alice[4][4];
int bob[4][4];
int win[4][4];
pi s[20];
pi ls[20];


int main(){
	scanf("%I64d%d%d",&k,&a,&b);
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(i==j) win[i][j]=0;
			else if(i==1&&j==3) win[i][j]=1;
			else if(i==2&&j==1) win[i][j]=1;
			else if(i==3&&j==2) win[i][j]=1;
			else win[i][j]=-1;
		}
	}
	for(int m=0;m<2;m++){
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				if(m==0) scanf("%d",&alice[i][j]);
				else scanf("%d",&bob[i][j]);
			}
		}
	}
	int id=1,loopnode;
	while(true){
		bool loop=false;
		for(int i=1;i<id;i++){
			if(s[i]==pi(a,b)){
				loopnode=i;
				loop=true;	
				break;
			}
		}
		if(loop) break;
		s[id++]=pi(a,b);
		int a1,b1;
		a1=alice[a][b];
		b1=bob[a][b];
		a=a1,b=b1;
	}
	int la=0,lb=0;
	for(int i=loopnode;i<id;i++){
		ls[i-loopnode+1]=s[i];
		int x=s[i].first,y=s[i].second;
		int c=win[x][y];
		if(c>0) la++;
		if(c<0) lb++;
	}
	long long ap=0,bp=0;
	if(k<loopnode){
		for(int i=1;i<=k;i++){
			int x=s[i].first,y=s[i].second;
			int c=win[x][y];
			if(c>0) ap++;
			if(c<0) bp++;
		}
	}
	else{
		k-=loopnode-1;
		for(int i=1;i<loopnode;i++){
			int x=s[i].first,y=s[i].second;
			int c=win[x][y];
			if(c>0) ap++;
			if(c<0) bp++;
		}
		long long j=k/(id-loopnode);
		k-=j*(id-loopnode);
		ap+=j*la;
		bp+=j*lb;
		for(int i=1;i<=k;i++){
			int x=ls[i].first,y=ls[i].second;
			int c=win[x][y];
			if(c>0) ap++;
			if(c<0) bp++;
		}
	}
	printf("%I64d %I64d",ap,bp);
return 0;
}
