// You are given an array 
// A
//  of 
// N
//  integers.

// Count the number of unique prime factors of each element in it.

// Input Format
// The first line of the input contains a single integer 
// T
// , denoting the number of test cases.

// The description of 
// T
//  test cases follows.

// The first line of each test case contains a single integer 
// N
// .

// The second line of each test case contains 
// N
//  space-separated integers 
// A
// [
// 0
// ]
// ,
// A
// [
// 1
// ]
// ,
// .
// .
// .
// ,
// A
// [
// N
// −
// 1
// ]
// .

// Output Format
// For each test case output a line containing 
// N
//  space separated integers denoting the number of prime factors of each of the array element.

// Constraints
// 1
// ≤
// T
// ≤
// 10

// 1
// ≤
// N
// ≤
// 10
// 5

// 1
// ≤
// A
// i
// ≤
// 10
// 6

// Example
// Input
// 1
// 3
// 10 12 14
// Output
// 2 2 2


#include <bits/stdc++.h>
using namespace std;

vector<int> sei(1000005,-1);

void seive(){
    int n = sei.size();
    sei[0]=sei[1]=-2;
    for(int i = 2; i*i<n;i++){
        if(sei[i]==-1){
            sei[i]=i;
            for(int j=i*i;j<n;j+=i){
                if(sei[j]!=-1) continue;
                sei[j]=i;
            }
        }
    }
}

int count_nums(int n){
    int pr = -1,count=0;
    while(n>1){
    int new_pr=sei[n];
    if(pr==-1){
        pr=new_pr;
    }else if(pr!=new_pr){
        pr= new_pr;count++;
    }
    n=n/new_pr;
    if(n==1){
                    count++;
    }
    }
    return count;
}


int main() {
    seive();
    int t;cin>>t;
    while(t--){
    int n;cin>>n;
    vector<int> arr;
    for(int i = 0 ;i<n;i++){
        int temp;cin>>temp;
        arr.push_back(temp);
    }
    for(int i = 0 ; i < n ;i++){
        cout<<count_nums(arr[i])<<" ";
    }cout<<endl;
    }
    return 0;
}