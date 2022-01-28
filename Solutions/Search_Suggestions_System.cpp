class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        
        vector<vector<string>>ans;
        int i,j;
        int n=searchWord.size();
        sort(products.begin(),products.end());
        for(i=0;i<n;i++)
        {
            string cw=searchWord.substr(0,i+1);
            
            vector<string>res;
            int low=0;
            int high=products.size();
            
            while(low<high)
            {
                int mid = low + (high - low)/2;
                
                if(products[mid]>=cw)
                {
                    high=mid;
                }
                else
                {

                    low=mid+1;
                }
            }
            
            for(int j=low;j<low+3 and j<products.size();j++)
            {
             if(products[j].find(cw) == 0){
                    res.push_back(products[j]);
                }else{
                    break;
                }
            }
            
            ans.push_back(res);
        }
        return ans;
    }
};
