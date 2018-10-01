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

int n1,n2,n3;
int u1,u2,u3;
int s1,s2,s3;

bool flag[10];


int main(){
	int t;
	string s;
	scanf("%d",&t);
	while(t--){
		cin>>s;
		n1=n2=n3=u1=u2=u3=0;
		s1=s2=s3=1;
		bool head=false;
		memset(flag,false,sizeof flag);
		char op;
		int id=0;
		if(s[id]=='-'){
			s1=-1;
			id++;
		}
		if(s[id]=='?'){
			n1=n1*10;
			u1=u1*10+1;
			if((s[id+1]!='+'&&s[id+1]!='-'&&s[id+1]!='*')||s1==-1)head=true;
			id++;
		}
		while(s[id]!='+'&&s[id]!='-'&&s[id]!='*'){
			if(s[id]=='?'){
				n1=n1*10;
				u1=u1*10+1;
			}
			else{
				n1=n1*10+(s[id]-'0');
				u1=u1*10;
				flag[s[id]-'0']=true;
			}
			id++;
		}
		if(s[id]=='+'){
			op='+';
			id++;
		}
		else if(s[id]=='-'){
			op='-';
			id++;
		}
		else{
			op='*';
			id++;
		}
		if(s[id]=='-'){
			s2=-1;
			id++;
		}
		if(s[id]=='?'){
			n2=n2*10;
			u2=u2*10+1;
			if((s[id+1]!='=')||s2==-1)head=true;
			id++;
		}
		while(s[id]!='='){
			if(s[id]=='?'){
				n2=n2*10;
				u2=u2*10+1;
			}
			else{
				n2=n2*10+(s[id]-'0');
				u2=u2*10;
				flag[s[id]-'0']=true;
			}
			id++;	
		}
		id++;
		if(s[id]=='-'){
			s3=-1;
			id++;
		}
		if(s[id]=='?'){
			n3=n3*10;
			u3=u3*10+1;
			if((id+1<s.length())||s3==-1)head=true;
			id++;
		}
		while(id<s.length()){
			if(s[id]=='?'){
				n3=n3*10;
				u3=u3*10+1;
			}
			else{
				n3=n3*10+(s[id]-'0');
				u3=u3*10;
				flag[s[id]-'0']=true;
			}
			id++;
		}
		if(op=='+'){
			int v1=s1*n1+s2*n2-s3*n3;
			int v2=s3*u3-s1*u1-s2*u2;
			bool ok=false;
			if(v1%v2==0){
				if(v1/v2>0&&v1/v2<10&&!flag[v1/v2]) {
					printf("%d\n",v1/v2); ok=true;
				}
				else if(v1==0&&!head&&!flag[0]){
					printf("0\n"); ok=true;
				}
			}
			if(!ok){
				printf("-1\n");
			}
		}
		else if(op=='-'){
			int v1=s1*n1-s2*n2-s3*n3;
			int v2=s3*u3-s1*u1+s2*u2;
			bool ok=false;
			if(v1%v2==0){
				if(v1/v2>0&&v1/v2<10&&!flag[v1/v2]) {
					printf("%d\n",v1/v2); ok=true;
				}
				else if(v1==0&&!head&&!flag[0]){
					printf("0\n"); ok=true;
				}
			}
			if(!ok){
				printf("-1\n");
			}
		}
		else{
			int v1=s1*n1*s2*n2-s3*n3;
			int v2=s3*u3-s1*u1*s2*n2-s2*u2*s1*n1;
			int v3=-s1*u1*s2*u2;
			bool ok=false;
			if(v1==0&&!head&&!flag[0]){
				printf("0\n"); ok=true;
			}
			if(!ok){
				for(int i=1;i<10;i++){
					if(v1==v2*i+v3*i*i&&!flag[i]){
						printf("%d\n",i);
						ok=true;
						break;
					}
				}
			}
			if(!ok){
				printf("-1\n");
			}
		}
	}
return 0;
}
