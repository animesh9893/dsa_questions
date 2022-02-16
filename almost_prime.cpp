// A number is called 
// H
// a
// p
// p
// y
 
// P
// r
// i
// m
// e
//  if there are exactly 
// 2
//  distinct prime divisors of it. Find the number of 
// H
// a
// p
// p
// y
 
// P
// r
// i
// m
// e
//  numbers between 
// 1
//  and 
// N
// , both inclusive.

// Input Format

// The first line of the input contains a single integer 
// T
//  denoting the number of test cases.
// Each test case contains a single integer 
// N
// .
// Constraints

// 1
 
// ≤
 
// T
 
// ≤
 
// 10
// 6
// 1
 
// ≤
 
// N
 
// ≤
 
// 10
// 6
// Output Format

// For each test case, output the number of Happy Prime numbers between 
// 1
//  and 
// N
//  on a separate line.
// Sample Input

// 2
// 1
// 10

// Sample Output

// 0
// 2

// Explanation

// For testcase 
// 1
// , there are no numbers between 
// 1
//  to 
// 1
//  which contain exactly 
// 2
//  distinct prime divisors.
// For testcase 
// 2
// , there are 
// 2
//  numbers 
// 6
//  and 
// 10
//  between 
// 1
//  to 
// 10
//  which contain exactly 
// 2
//  distinct prime divisors.
// Example
// Input
// 2 
// 1 
// 10
// Output
// 0
// 2

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

vector<int> psum(1000005,0);

void almost(){
    vector<bool> almostPrime(1000005,false);
    vector<int> tempArr(1000005);
    int n = tempArr.size();
    for(int i = 0 ;i<n;i++)
        tempArr[i]=i;
    
    for(int i = 2;i<n;i++){
        if(tempArr[i]/sei[i]!=1){
            int firstP = sei[i];
            int secP = tempArr[i]/sei[i];
            if(firstP != secP and sei[secP]==secP){
                almostPrime[i]=true;
            }
        }
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if(almostPrime[i]==true){
            count++;
        }
        psum[i]=count;
    }
}


int main() {
    seive();
    almost();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<psum[n]<<endl;
    }
    return 0;
}