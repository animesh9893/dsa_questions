#include <bits/stdc++.h>

using namespace std;

void display(vector<int> a){
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

std::vector<int> merge(std::vector<int> v1,std::vector<int> v2){
	int n=v1.size(),m=v2.size();
	int i=0,j=0;
	vector<int> res;

	while(i<n and j<m){
		if(v1[i]<=v2[j]){
			res.push_back(v1[i]);
			i++;
		}else{
			res.push_back(v2[j]);
			j++;
		}
	}
	for(;i<n;i++){
		res.push_back(v1[i]);
	}
	for(;j<m;j++){
		res.push_back(v2[j]);
	}
	return res;
}

void merge_halves(vector<int> &arr,int l,int m,int r){
	vector<int> res;
	if(r>arr.size())
		r=arr.size()-1;
	int i=l,j=m+1;
	while(i<=m and j<=r){
		if(arr[i]<=arr[j]){
			res.push_back(arr[i]);
			i++;
		}else{
			res.push_back(arr[j]);
			j++;
		}
	}
	for(;i<=m;i++){
		res.push_back(arr[i]);
	}
	for(;j<=r;j++){
		res.push_back(arr[j]);
	}
	// display(arr);
	for(int x=l;x<=r;x++){
		arr[x]=res[x-l];
	}
}

void two_way(vector<int> &v){
	int n= v.size();
	vector<int>pre={1};

	for(int i=1;i<50;i++)
		pre.push_back(pre[i-1]+pre[i-1]);

	for(int i=0;pre[i]<n;i++){
		int start = 0,pair = pre[i];
		int end = start+pair*2-1;
		while(start<n){
			int mid = start+pair-1;
			merge_halves(v,start,mid,end);
			start = end+1;
			end = start+pair*2-1;
		}
	}
	// display(v);
}

int main(){
	vector<int> a={2,4,6,8,10};
	vector<int> b={1,3,5,7,9};
	vector<int> res = merge(a,b);
	display(res);
	vector<int> c={3,2,4,8,7,6,9,0};
	// merge_halves(c,0,3,7);
	two_way(c);
	display(c);
}




static bool mycomp(vector<int>& a,vector<int>& b){
        return abs(a[0]-a[1])>abs(b[0]-b[1]);
    }




