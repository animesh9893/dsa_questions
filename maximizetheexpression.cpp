#include <bits/stdc++.h>

using namespace std;

void display(vector<int> &v){
	for(auto &val:v){
		cout<<val<<" ";
	}cout<<endl;
}

vector<int> prefixMax(vector<int> &v){
	int max_so_far = v[0];
	vector<int> prefix;
	prefix.push_back(max_so_far);
	for(int i=1;i<v.size();i++){
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
// demo
vector<int> sufixMin(vector<int> &v){
        int l = v.size();
        int min_so_far = l-1;
        vector<int> sufix;
        sufix.push_back(l-1);
        for(int i=l-2;i>=0;i--){
            if(v[min_so_far]>=v[i]){
            	min_so_far = i;
            	sufix.push_back(i);
            }else{
            	sufix.push_back(min_so_far);
            }
        }
        reverse(sufix.begin(),sufix.end());
        return sufix;
}
int maxChunksToSorted(vector<int>& arr) {
        int chunk = 0;
        vector<int> sufix = sufixMin(arr);
        
        for(int i=0;i<arr.size();i++){
            i=sufix[i]+1;
            chunk++;
        }
        return chunk;
}

int maxTheExpression(vector<int> &v,int p,int q,int r){
	vector<int> pre(v),suf(v);
	for(auto &val:pre){
		val*=p;
	}
	for(auto &val:suf){
		val*=r;
	}
	pre = prefixMax(pre);
	suf = sufixMax(suf);

	int max_so_far = INT_MIN;
	for(int i=1;i<v.size()-1;i++){
		int x = pre[i-1]+suf[i+1]+q*v[i];
		max_so_far = max(max_so_far,x);
	}
	return max_so_far;
}

int main(){
	// vector<int> v = {1,2,3,4,-5};
	// vector<int> pre = prefixMax(v);
	// vector<int> suf = sufixMax(v);
	// display(pre);
	// display(suf);
	// display(v);
	// cout<<maxTheExpression(v,1,2,-3)<<endl;
	vector<int> v = {
	};
	// vector<int> v = {2,1,3,4,4};
	vector<int> sufix = sufixMin(v);
	display(sufix);
	display(v);
	for(auto &val:sufix){
		cout<<v[val]<<" ";
	}cout<<endl;
	// cout<<endl<<maxChunksToSorted(v)<<endl;
}