# Single Element in Sorted Array

'''
You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once. 
Find this single element that appears only once.

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10

'''

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        /*
        
        // Approach 1 using XOR 
        int len = nums.size();
        int i=1;
        int result = nums[0];
        while(i<len){
            result = result ^ nums[i];
            i++;
        }
        return result;
        
        */
        
        //Approach 2 using Binary Search
        /* All elements before the required have first occurrence at even index (0, 2, ..) and next occurrence at odd index (1, 3, …). 
        And all elements after the required element have first occurrence at odd index and next occurrence at even index. */
        
        
        int len = nums.size();
        int start = 0;
        int end = len-1;
        while(start < end){
            int mid = (start + end)/2;
            if(mid %2 == 0 ){
                if(nums[mid] == nums[mid+1])
                    start = mid+2;
                else
                    end = mid;
            }
            else{
                if(nums[mid] == nums[mid-1])
                    start = mid + 1;
                else
                    end = mid-1;
            }
            
        }
        
            return nums[start];   
        
    }
};
