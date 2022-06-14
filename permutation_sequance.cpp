#include <bits/stdc++.h>

using namespace std;

vector<int> factorial(11,1);

void fact(){
	for(int i=1;i<factorial.size();i++){
		factorial[i] = factorial[i-1]*i;
	}
}
void rightShift(string &s,int i,int j){
	char temp = s[j];
	for(int a=j-1;a>=i and a>=0;a--){
		s[a+1] = s[a];
	}
	s[i] = temp;
}

void leftShift(string &s,int i,int j){
	char temp = s[i];
	for(int a=i+1;a<=j+1 and a<s.size();a++){
		s[a-1] = s[a];
	}
	s[j] = temp;
}

string permu(int n,int k){
	string s = "";
	fact();
	for(int i=1;i<=n;i++){
		s+=(i+'0');
	}
	string ans = "";
	n = s.size();
	for(int i=n-1;i>=1 and s.size()>1;i--){
		int index = k/factorial[i];
		k%=factorial[i];
		cout<<index<<" ";
		rightShift(s,0,index);
		ans+=s[0];
		s = s.substr(1,s.size()-1);
	}cout<<endl;
	cout<<s<<endl;
	return ans+s;
}

int main(){
	int n;cin>>n;
	int k;cin>>k;
	cout<<permu(n,k)<<endl;
}