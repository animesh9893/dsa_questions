#include <bits/stdc++.h>

using namespace std;

#define max(a,b) (a<b? b:a)
#define min(a,b) (a<b? a:b)
#define mod 1e9+7
#define FOR(a,c) for(int (a)=0;(a)<(c);(a)++)
#define FORL(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define FORR(a,b,c) for(int (a)=(b);(a)>=(c);(a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
template <class T>
T modadd(T a,T b,ll m){return (a%b+b%m)%m;}
template <class T>
T modsub(T a,T b,ll m){T ans = (a%m)-(b%m);if(ans<0) ans+=m;return ans;}
template <class T>
T modmul(T a,T b,ll m){ return ((a%m)*(b%m))%m; }
vector<int> inputArray(int n){vector<int> arr(n);int i=0; FOR(i,n) cin>>arr[i];return arr;}


void displayVector(vector<int> &v){
	for(auto x:v){
		cout<<x<<" ";  
	}cout<<endl;
}

void displayVector(vector<int> &v,int n){
	n = min(n,v.size());
	for(int i = 0;i<n;i++){
		cout<<v[i]<<" ";  
	}cout<<endl;
}

void displayVector(vector<int> &v,int i,int n){
	n = min(n,v.size());
	i = max(0,i);
	for(;i<n;i++){
		cout<<v[i]<<" ";  
	}cout<<endl;
}

void displayVector(vector<int> &v,int i,int n, bool rev){
	n = min(n,v.size());
	i = max(0,i);
	if(!rev){
		for(;i<n;i++){
			cout<<v[i]<<" ";  
		}cout<<endl;
	}else{
		n--;
		for(;n>=i;n--){
			cout<<v[n]<<" ";  
		}cout<<endl;
	}
}


double medianArrays(vector<int> &v1,vector<int> &v2){
	// vector<int> ans;
	int i=0,j=0;
	int median_index=(v1.size()+v2.size())/2;
	int median_index_2 = median_index-1;
	int a,b;
	for(;i<v1.size() and j<v2.size();){
		if(v1[i]<v2[j]){
			// ans.push_back(v1[i]);
			if(i+j==median_index){
				a=v1[i];
			}else if(i+j==median_index_2){
				b=v1[i];
			}
			i++;
		}else{
			// ans.push_back(v2[j]);
			if(i+j==median_index){
				a=v2[j];
			}else if(i+j==median_index_2){
				b=v2[j];
			}
			j++;
		}
	}
	for(;i<v1.size();i++){
		if(i+j==median_index){
				a=v1[i];
			}else if(i+j==median_index_2){
				b=v1[i];
			}
		// ans.push_back(v1[i]);
	}
	for(;j<v2.size();j++){
		// ans.push_back(v2[j]);
		if(i+j==median_index){
				a=v2[j];
			}else if(i+j==median_index_2){
				b=v2[j];
			}
	}
	if((v1.size()+v2.size())%2==0) return (a+b)*1.0/2;
	return a*1.0;
}


// vector<int> mergeArray(vector<int> v1,vector<int> v2){
	// // vector<int> ans;
	// int i=0,j=0;
	// int median_index=(v1.size()+v2.size())/2;
	// int median_index_2 = median_index-1;
	// int a,b;
	// for(;i<v1.size() and j<v2.size();){
	// 	if(v1[i]<v2[j]){
	// 		// ans.push_back(v1[i]);
	// 		if(i+j==median_index){
	// 			a=v1[i];
	// 		}else if(i+j==median_index_2){
	// 			b=v1[i];
	// 		}
	// 		i++;
	// 	}else{
	// 		// ans.push_back(v2[j]);
	// 		if(i+j==median_index){
	// 			a=v2[j];
	// 		}else if(i+j==median_index_2){
	// 			b=v2[j];
	// 		}
	// 		j++;
	// 	}
	// }
	// for(;i<v1.size();i++){
	// 	if(i+j==median_index){
	// 			a=v1[i];
	// 		}else if(i+j==median_index_2){
	// 			b=v1[i];
	// 		}
	// 	// ans.push_back(v1[i]);
	// }
	// for(;j<v2.size();j++){
	// 	// ans.push_back(v2[j]);
	// 	if(i+j==median_index){
	// 			a=v2[j];
	// 		}else if(i+j==median_index_2){
	// 			b=v2[j];
	// 		}
	// }
	// if((v1.size()+v2.size())%2==0) return (a+b)*1.0/2;
	// return a*1.0;
// }

int main(){
	vector<int> arr1 = {1,3,5,7,9,11};
	vector<int> arr2 = {2,4,6,8,10,12};
	// auto ans = mergeArray(arr1,arr2);
	// displayVector(ans);
	cout<<medianArrays(arr2,arr1)<<endl;	
	return 0;
}