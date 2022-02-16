// You are given a non-negative number 
// N
// .

// Count the number of prime numbers less than or equal to 
// N
// .

// Input Format
// The first line of the input contains a single integer 
// T
//  denoting the number of test cases.

// The description of 
// T
//  test cases follows.

// Next 
// T
//  lines each contain a single integer 
// N
// .

// Output Format
// For each test case, output the number of prime numbers less than or equal to 
// N
//  on a seperate line.

// Constraints
// 1
// ≤
// T
// ≤
// 10
// 5

// 0
// ≤
// N
// ≤
// 10
// 6

// Example
// Input
// 2
// 1
// 10
// Output
// 0
// 4


#include <bits/stdc++.h>
using namespace std;

vector<bool> sei(1000005,true);
vector<int> count_prime(1000005,0);
void seive(){
    int n = sei.size();
    sei[0]=sei[1]=false;
    for(int i = 2;i*i<n;i++){
    if(sei[i]==true){
        for(int j=i*i;j<n;j+=i){
        sei[j]=false;
        }
    }
    }
    int count = 0;
    for(int i = 0;i<n;i++){
    if(sei[i]==true) count++;
    count_prime[i]=count;
    }
}

int main() {
    seive();

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<count_prime[n]<<endl;
    }
    return 0;
}