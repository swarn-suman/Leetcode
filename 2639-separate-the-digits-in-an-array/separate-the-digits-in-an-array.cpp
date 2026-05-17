class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int n = nums[i];
            vector<int> temp;

            while (n > 0) {
                int digit = n % 10;
                temp.push_back(digit);
                n = n/10;
            }
            reverse(temp.begin(), temp.end());

            for (int digit : temp) {
                ans.push_back(digit);
            }
        }
        return ans;
    }
};