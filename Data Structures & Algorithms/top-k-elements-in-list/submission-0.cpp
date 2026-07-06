class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;

        // Count frequency
        for (int n : nums) {
            freqMap[n]++;
        }

        // Create buckets where index = frequency
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto &it : freqMap) {
            int num = it.first;
            int freq = it.second;
            bucket[freq].push_back(num);
        }

        // Collect top k frequent elements
        vector<int> res;

        for (int i = nums.size(); i >= 0 && res.size() < k; i--) {
            for (int num : bucket[i]) {
                res.push_back(num);
                if (res.size() == k)
                    break;
            }
        }

        return res;
    }
};