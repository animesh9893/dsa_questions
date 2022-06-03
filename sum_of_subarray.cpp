// https://practice.geeksforgeeks.org/problems/sum-of-subarrays2229/1
#include <bits/stdc++.h>

using namespace std;


long long subarraySum(long long a[], long long n)
    {
        // Your code goes here
        long long sum = 0;
        const unsigned int M = 1000000007;
        for(int i=0;i<n;i++){
            int start = i+1;
            int end = n-i;
            long long ans = ((start%M)*(end%M))%M;
            ans = ((ans%M)*(a[i]%M))%M;
            sum = ((ans%M)+(sum%M))%M;
        }
        return sum;
}

int main(){
	int n;cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++)
		cin>>arr[i];
	cout<<subarraySum(arr,n)<<endl;
}