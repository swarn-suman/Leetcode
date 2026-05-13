class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        double med;

        for(int i=0; i<nums1.size(); i++){
            ans.push_back(nums1[i]);
        }

        for(int j=0; j<nums2.size(); j++){
            ans.push_back(nums2[j]);
        }

        sort(ans.begin(),ans.end());

        int n = ans.size();

        if(n%2 == 0){
            med = (ans[n/2]+ans[(n/2)-1])/2.0;
        }

        if(n%2 != 0){
            med = ans[n/2];
        }
        return med;
    }
};