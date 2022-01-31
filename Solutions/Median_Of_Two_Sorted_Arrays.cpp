/* TC: O(n1+n2)
   SC: O(n1+n2)
*/

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
//         vector<int>ans;
//         int i=0,j=0;
//         int n=nums1.size();
//         int m=nums2.size();
        
//         while(i<n && j<m)
//         {
//             if(nums1[i]<nums2[j])
//             {
//                 ans.push_back(nums1[i]);
//                 i++;
//             }
//             else if(nums1[i]>nums2[j])
//             {
//                 ans.push_back(nums2[j]);
//                 j++;
//             }
//             else
//             {
//                 ans.push_back(nums1[i]);
//                 ans.push_back(nums2[j]);
//                 i++;
//                 j++;
                
//             }
//         }
//         while(i<n)
//         {
//              ans.push_back(nums1[i++]);
//         }
//         while(j<m)
//         {
//              ans.push_back(nums2[j++]);
//         }
        
//         int nn=n+m;
//         if(nn&1)
//         {
//             return ans[nn/2]*1.0;
//         }
//         else
//         {
//             int kk=ans[nn/2]+ans[(nn/2)-1];
            
//             return (double)kk/2.0;
//         }
//     }
// };

/* TC: O(log(n1+n2))
   
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
      int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2)
            return findMedianSortedArrays(nums2,nums1);
        
        int low=0;
        int high=n1;
        
        while(low<=high)
        {
            int cut1=(low+high)>>1;
            int cut2=((n1+n2+1)/2)-cut1;
            
            int l1=cut1==0?INT_MIN:nums1[cut1-1];
            int l2=cut2==0?INT_MIN:nums2[cut2-1];
            
            int r1=cut1==n1?INT_MAX:nums1[cut1];
            int r2=cut2==n2?INT_MAX:nums2[cut2];
            
            
            if(l1<=r2 && l2<=r1)
            {
                    if((n1+n2)%2==0)
                    {
                        int k1=max(l1,l2);
                        int k2=min(r1,r2);
                        
                        return (k1+k2)/(2.0);
                    }
                    else
                    {
                        return max(l1,l2);
                    }
            }
            else if(l1>r2)
            {
                high=cut1-1;
            }
            else
            {
                low=cut1+1;
            }
        }
        
        return 0.0;
    }
};
