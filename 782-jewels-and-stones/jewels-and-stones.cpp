class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st;

        for(int i=0; i<jewels.size(); i++){
            if(st.count(jewels[i]) == 0){
                st.insert(jewels[i]);
            }
        }

        int ans = 0;
        for(int i=0; i<stones.size(); i++){
            if(st.count(stones[i]) != 0){
                ans++;
            }
        }
        return ans;
    }
};