class Solution {
public:

    bool isPrime(int x) {
        if (x < 2) return false;
        
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        
        return true;
    }
    


    vector<int> getPrimeFactors(int x) {
        vector<int> factors;
        
        for (int p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                factors.push_back(p);
                
                while (x % p == 0)
                    x /= p;
            }
        }
        
        if (x > 1)
            factors.push_back(x);
        
        return factors;
    }
    
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> primeToIndices;
        
        for (int i = 0; i < n; i++) {
            vector<int> factors = getPrimeFactors(nums[i]);
            
            for (int p : factors) {
                primeToIndices[p].push_back(i);
            }
        }
        
        vector<int> dist(n, -1);
        queue<int> q;
        
        dist[0] = 0;
        q.push(0);
        
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            
            int steps = dist[i];
            
            if (i == n - 1)
                return steps;
            
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = steps + 1;
                q.push(i - 1);
            }
            
        
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = steps + 1;
                q.push(i + 1);
            }
            
            if (isPrime(nums[i])) {
                int p = nums[i];
                
                for (int nextIdx : primeToIndices[p]) {
                    if (dist[nextIdx] == -1) {
                        dist[nextIdx] = steps + 1;
                        q.push(nextIdx);
                    }
                }
                primeToIndices[p].clear();
            }
        }
        
        return -1;
    }
};