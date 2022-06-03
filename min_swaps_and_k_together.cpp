#include <bits/stdc++.h>

using namespace std;

int minSwap(int arr[], int n, int k) {
    int kn  = 0;
    for(int i=0;i<n;i++)
        if(arr[i]<=k)
            kn++;

    int max_so_far = 0;
    for(int i=0;i<kn;i++)
        if(arr[i]<=k)
            max_so_far++;
    int temp = max_so_far;
    for(int i=kn;i<n;i++){
        if(arr[i-kn]<=k){
            temp--;
        }
        if(arr[i]<=k){
            temp++;
        }
        max_so_far = max(max_so_far,temp);
    }
    return kn-max_so_far;
}

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;cin>>x;
    cout<<minSwap(arr,n,x)<<endl;
}