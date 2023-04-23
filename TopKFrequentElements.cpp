Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // keep track of frequency of each element
        for (int num : nums) {
            freq[num]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // min-heap of size k
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            minHeap.push(make_pair(it->second, it->first)); // push (frequency, element) pairs onto heap
            if (minHeap.size() > k) {
                minHeap.pop(); // remove the smallest element from the heap
            }
        }
        
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second); // extract the k most frequent elements from the heap
            minHeap.pop();
        }
        
        return result;
    }
};
