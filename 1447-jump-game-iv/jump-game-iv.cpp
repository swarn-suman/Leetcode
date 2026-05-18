class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if (n == 1)
            return 0;

        // value -> list of indices
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int i = q.front();
                q.pop();

                // Reached last index
                if (i == n - 1)
                    return steps;

                vector<int> neighbors;

                // Same value jumps
                for (int idx : mp[arr[i]]) {
                    neighbors.push_back(idx);
                }

                // Adjacent jumps
                if (i + 1 < n)
                    neighbors.push_back(i + 1);

                if (i - 1 >= 0)
                    neighbors.push_back(i - 1);

                // Process neighbors
                for (int nei : neighbors) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        q.push(nei);
                    }
                }

                // Optimization:
                // clear indices once processed
                mp[arr[i]].clear();
            }

            steps++;
        }

        return -1;
    }
};
