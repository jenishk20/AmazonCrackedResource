class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        
        int i=0;
        int j=nums.size()-1;
        map<int,int>ma;
        int n=nums.size();
        for(i=0;i<n;i++)
        {
            if(ma.find(target-nums[i])!=ma.end())
            {
                return {i,ma[target-nums[i]]};
            }
            ma[nums[i]]=i;
        }
        return {};
    }
};
