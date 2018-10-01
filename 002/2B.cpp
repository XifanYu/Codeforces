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

int n;
pair<int,int> a[1005][1005];
pair<int,char> dp2[1005][1005];
pair<int,char> dp5[1005][1005];
pair<int,int> zero=make_pair(0,0);
vector<char> ans;
int p2[30],p5[13];
int p=1,q=1;

pair<int,int> get_factor(int m){ 
	int n2d=0,n2u=29,n2m,n5d=0,n5u=12,n5m;
	while(n2u-n2d>1){
		n2m=(n2u+n2d)/2;
		if(m%p2[n2m]) n2u=n2m;
		else n2d=n2m;
	}
	if(m%p2[n2u]==0) n2m=n2u;
	else n2m=n2d;
	while(n5u-n5d>1){
		n5m=(n5u+n5d)/2;
		if(m%p5[n5m]) n5u=n5m;
		else n5d=n5m;
	}
	if(m%p5[n5u]==0) n5m=n5u;
	else n5m=n5d;
return make_pair(n2m,n5m);
}



int main(){
	p2[0]=p5[0]=1;
	for(int i=1;i<30;i++){
		p2[i]=p*2;
		p*=2;
	}
	for(int i=1;i<13;i++){
		p5[i]=q*5;
		q*=5;
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			a[i][j]=get_factor(x);
			if(x==0) zero=make_pair(i,j);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==1&&j==1){
				dp2[1][1]=make_pair(a[1][1].first,' ');
				dp5[1][1]=make_pair(a[1][1].second,' ');
			}
			else if(i==1){
				dp2[i][j]=make_pair(dp2[i][j-1].first+a[i][j].first,'R');
				dp5[i][j]=make_pair(dp5[i][j-1].first+a[i][j].second,'R');
			}
			else if(j==1){
				dp2[i][j]=make_pair(dp2[i-1][j].first+a[i][j].first,'D');
				dp5[i][j]=make_pair(dp5[i-1][j].first+a[i][j].second,'D');	
			}
			else if(i>1&&j>1){
				if(dp2[i-1][j].first<=dp2[i][j-1].first) dp2[i][j]=make_pair(dp2[i-1][j].first+a[i][j].first,'D');
				else dp2[i][j]=make_pair(dp2[i][j-1].first+a[i][j].first,'R');
				if(dp5[i-1][j].first<=dp5[i][j-1].first) dp5[i][j]=make_pair(dp5[i-1][j].first+a[i][j].second,'D');	
				else dp5[i][j]=make_pair(dp5[i][j-1].first+a[i][j].second,'R');
			}
		}
	}
	if(dp2[n][n].first<=dp5[n][n].first){
		if(zero!=make_pair(0,0)){
			if(dp2[n][n].first==0){
				cout<<dp2[n][n].first<<endl;
				pair<int,char> x=dp2[n][n];
				int i=n,j=n;
				while(i!=1||j!=1){
					ans.push_back(x.second);
					if(x.second=='D') x=dp2[--i][j];
					else if(x.second=='R') x=dp2[i][--j];
				}
				for(int m=0;m<ans.size();m++) cout<<ans[ans.size()-1-m];
			}
			else{
				cout<<1<<endl;
				for(int i=2;i<=zero.first;i++) cout<<'D';
				for(int i=2;i<=n;i++) cout<<'R';
				for(int i=zero.first+1;i<=n;i++) cout<<'D';
			}
		}
		else{
			cout<<dp2[n][n].first<<endl;
			pair<int,char> x=dp2[n][n];
			int i=n,j=n;
			while(i!=1||j!=1){
				ans.push_back(x.second);
				if(x.second=='D') x=dp2[--i][j];
				else if(x.second=='R') x=dp2[i][--j];
			}
			for(int m=0;m<ans.size();m++) cout<<ans[ans.size()-1-m];
		}
	}
	else{
		if(zero!=make_pair(0,0)){
			if(dp5[n][n].first==0){
				cout<<dp5[n][n].first<<endl;
				pair<int,char> x=dp5[n][n];
				int i=n,j=n;
				while(i!=1||j!=1){
				ans.push_back(x.second);
				if(x.second=='D') x=dp5[--i][j];
				else if(x.second=='R') x=dp5[i][--j];
				}
				for(int m=0;m<ans.size();m++) cout<<ans[ans.size()-1-m];
			}
			else{
				cout<<1<<endl;
				for(int i=2;i<=zero.first;i++) cout<<'D';
				for(int i=2;i<=n;i++) cout<<'R';
				for(int i=zero.first+1;i<=n;i++) cout<<'D';
			}
		}
		else{
			cout<<dp5[n][n].first<<endl;
			pair<int,char> x=dp5[n][n];
			int i=n,j=n;
			while(i!=1||j!=1){
				ans.push_back(x.second);
				if(x.second=='D') x=dp5[--i][j];
				else if(x.second=='R') x=dp5[i][--j];
			}
		for(int m=0;m<ans.size();m++) cout<<ans[ans.size()-1-m];
		}
	}
return 0;
} 
