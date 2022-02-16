#include <bits/stdc++.h>

using namespace std;

vector<int> prefixMax(vector<int> &v){
	int l =v.size(),max_so_far = v[0];
	vector<int> prefix;
	prefix.push_back(v[0]);
	for(int i=1;i<l;i++){
		max_so_far = max(max_so_far,v[i]);
		prefix.push_back(max_so_far);
	}
	return prefix;
}

vector<int> sufixMax(vector<int> &v){
	int l = v.size();
	int max_so_far = v[l-1];
	vector<int> sufix;
	sufix.push_back(max_so_far);
	for(int i=l-2;i>=0;i--){
		max_so_far = max(max_so_far,v[i]);
		sufix.push_back(max_so_far);
	}
	reverse(sufix.begin(),sufix.end());
	return sufix;
}

int histogramProblem(vector<int> &v){
	vector<int> pre = prefixMax(v);
	vector<int> suf = sufixMax(v);

	int sum = 0;

	for(int i=1;i<v.size()-1;i++){
		if(pre[i-1]>v[i] and suf[i+1]>v[i]){
			sum +=min(pre[i-1],suf[i+1])-v[i];
		}
	}
	return sum;
}


int main(){
	vector<int> v = {0,1,0,2,1,3,0,2};
	cout<<histogramProblem(v)<<endl;
	
}