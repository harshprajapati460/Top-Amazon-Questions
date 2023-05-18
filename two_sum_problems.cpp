// Problem link : https://leetcode.com/problems/two-sum
// Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target.

// You can return the answer in any order.
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

#include<bits/stdc++.h>
using namespace std;

//METHOD - 3 
// USING BINARY SEARCH FOR FINDING TARGET VALUES
// 1.SORT THE ARRAY
// 2.ITERATE OVER THE ARRAY 
// 3.USE BINARY SEARCH FOR FINDING SECOND VALUE i.e TARGET - ARR[i]
// 4.IF FOUND THEN RETURN THE ANSWER
// Array is not given sorted in leetcode but in case
// TIME COMPLEXITY O(N*LOG[N]) & Space Compelxity S(1)

vector<int>Method_3(vector<int>arr,int n,int target){
    sort(arr.begin(),arr.end());
    vector<int>ans;
    for(int i=0; i<n; i++){
        int x = target - arr[i];
        int low = i+1,high = n-1,mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(arr[mid] == x){

                ans.push_back(arr[i]);
                ans.push_back(arr[mid]);
                return ans;

            }
            else if(arr[mid] < x){

                low = mid+1;
            }
            else {

               high = mid-1;

            }
        }
    }
    return {-1,-1};
}
// METHOD - 2
// USING A HASHSET 
// 1.ITERATE OVER THE ARRAY AND CHECK IF TARGET - ARR[i] IF NOT PRESENT THEN STORE THE ARR[i]
// 2.IF PRESENT THEN RETURN INDEX
// TIME COMPLEXITY O(N^2) S(N)

vector<int>Method_2(vector<int>nums,int n,int target){
    unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            int num = target - nums[i];
            if(map.find(num) == map.end()){
                map[nums[i]] = i;
            }
            else {
                return {map[target-nums[i]],i};
            }
        }
        return {-1,-1};
}

// METHOD - 1
// USING TWO FOR LOOPS AND ADDING THEM TO GET THE ANSWER
//TIME COMPLEXITY 
// O(N^2) S(1)

vector<int> Method_1(vector<int>arr,int n,int target){
   vector<int>ans;
   for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
       if(arr[i]+arr[j] == target){
            ans.push_back(i);
            ans.push_back(j);
            return ans;
       }
    }
   }
   return {-1,-1};
}


int main(){

vector<int>arr = {1,4,2,1,5,2,35,6,3};
int n = arr.size();
int target = 6;
vector<int>ans = Method_3(arr,n,target);
cout<<ans[0]<<" "<<ans[1]<<endl;
return 0;
}