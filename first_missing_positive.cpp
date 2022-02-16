// https://leetcode.com/problems/first-missing-positive/

#include <bits/stdc++.h>

using namespace std;

void display(vector<int>& nums){
	for(auto x:nums){
		cout<<x<<" ";
	}cout<<endl;
}


int firstMissingPositive(vector<int>& nums) {
    // display(nums);

	int  n = nums.size();
	bool one = false;
	for(int i = 0;i<n;i++){
        if(nums[i]==1){
            one = true;
            break;
        }
    }
    if(!one) return 1;
    
    for(int i = 0 ; i < n ; i++){
        if(nums[i]<0 or nums[i]>n){
            nums[i] = -1 ;
        }else{
        	nums[i]--;
        }
    }
    // display(nums);

    for(int i=0;i<n;i++){
    	if(nums[i]>=0){
    		int index = nums[i];
    		if(index>=0){
    			while(index!=i and nums[index]!=-1 and nums[index]>=0){
    				int temp = nums[index];
    				nums[index] = -(index+100);
    				index = temp;
    // display(nums);

    			}
    		}
    		if(index>=0)
    			nums[index]=-(index+100);
    	}
    }

    for(int i=0;i<n;i++){
    	if(nums[i]!=-1){
    		nums[i] = abs(nums[i]+100);
    	}
    }
    
    int ans = n+1;
    for(int i = 0;i<n;i++){
    	if(nums[i]!=i){
    		ans = i+1;
    		break;
    	}
    }
    // display(nums);

    return ans;
}

int main(){
	vector<int> nums = {
		3,4,-1,1,2,6,7,9,100
	};
	cout<<firstMissingPositive(nums)<<endl;
}