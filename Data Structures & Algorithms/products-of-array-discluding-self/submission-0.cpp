class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l=nums.size();
        int left[l];
        int right[l];
        left[0]=1;
        for(int i=1;i<l;i++)
        {
            left[i]=left[i-1] *nums[ i-1];
        }
        right[l-1]=1;
        for(int i=l-2;i>-1;i--)
        {
            right[i]=right[i+1] * nums[i+1];
        }
        vector<int> ans;
        for(int i=0;i<l;i++)
        {
            ans.push_back(left[i]*right[i]);
        }
   return ans;
    }
};
