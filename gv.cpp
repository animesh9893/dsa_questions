#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cout<<"Enter number of questions : ";cin>>n;cout<<endl;

    vector<string> arr(n);

    for(int i=0;i<n;i++){
        string s;cin>>s;
        arr[i]=s;
    }
    cout<<endl;
    for(auto x:arr){
        cout<<"\""<<x<<"\", ";
    }cout<<endl;
}