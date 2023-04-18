class Solution {
public:

vector<int> searchRange(vector<int>& nums, int target) {

   int s=0;

    int end= nums.size()-1;

    int firstocc=-1;

    vector<int>v;

    while(s<=end){

         int mid= s+(end-s)/2;

        if(nums[mid]==target) {

        firstocc=mid;

        end= mid-1;    

        }

        else if(nums[mid]<target){s= mid +1; }

        else {end = mid-1; }

    } 

    //lastocc

    s=0;

    end=nums.size()-1;

    // int mid= s+(end-s)/2;

    int lastocc=-1;

    while(s<=end){

         int mid= s+(end-s)/2;

        if(nums[mid]==target) {

        lastocc=mid;

        s= mid+1;    

        }

        else if(nums[mid]<target){s= mid +1; }

        else   {

            end = mid-1; }

    }

    v.push_back(firstocc);

    v.push_back(lastocc);

    return v;

    }
};
