// Given a number 
// N
// , print all its unique prime factors and their exponents in 
// N
// .

// Input Format
// The first line of the input contains a single integer 
// T
//  denoting the number of test cases.

// The description of 
// T
//  test cases follows.

// Each test case contains a single integer 
// N
//  in a separate line.

// Output Format
// For each test case, for each prime factor of the number 
// N
//  in that test case, output two space separated integers: the prime factor and its power in 
// N
// .

// Prime factors should be printed in increasing order.

// Constraints
// 1
// ≤
// T
// ≤
// 10
// 5

// 2
// ≤
// N
// ≤
// 10
// 6

// Example
// Input
// 2
// 100
// 35
// Output
// 2 2
// 5 2
// 5 1
// 7 1

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

int main(){
    seive();
    // for(int i=0;i<100;i++){
    //     cout<<sei[i]<<" ";
    // }cout<<endl;
    int t;cin>>t;
    while(t--){
        vector<int> prime;
        vector<int> power;
        int n;cin>>n;
        int count = 0 ,pr = -1; 
        while(n>1){
            // cout<<n<<" \t"<<pr<<endl;
            int new_pr = sei[n];
            if(pr==-1){
                pr=new_pr;
            }else if(pr!=new_pr){
                prime.push_back(pr);
                power.push_back(count);
                pr= new_pr;count=0;
            }
            if(pr==new_pr){
                count++;
            }
            n=n/new_pr;
            if(n==1){
                prime.push_back(pr);
                power.push_back(count); 
            }
        }
        for(int i=0;i<prime.size();i++){
            cout<<prime[i]<<" "<<power[i]<<endl;
        }
    }
    return 0;
}