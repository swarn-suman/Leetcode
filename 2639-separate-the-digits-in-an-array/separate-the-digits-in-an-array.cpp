class Solution {
public:
    
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            while(nums[i]){
                int dig=nums[i]%10;
                ans.push_back(dig);
                nums[i]/=10;

            }
        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};