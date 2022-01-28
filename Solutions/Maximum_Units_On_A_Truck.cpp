class Solution {
public:
    static bool func(vector<int>&a,vector<int>&b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(),boxTypes.end(),func);
        int n=boxTypes.size();
        int i;
        int ans=0;
        
        for(i=0;i<n;i++)
        {
           int kk=min(boxTypes[i][0],truckSize);
            ans+=kk*boxTypes[i][1];
            truckSize-=kk;
            
            if(truckSize<=0)
                break;
        }
        return ans;
    }
};
