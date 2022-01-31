class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int i;
        int mini=INT_MAX;
        
        int ans=0;
        for(i=0;i<n;i++)
        {
            mini=min(mini,prices[i]);
            
            ans=max(ans,prices[i]-mini);
        }
        return ans;
    }
};
