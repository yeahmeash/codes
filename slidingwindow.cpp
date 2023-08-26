class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> window; // Using a double-ended queue to store indices
        
        for (int i = 0; i < nums.size(); ++i) {
            // Remove elements that are out of the current window range
            while (!window.empty() && window.front() < i - k + 1) {
                window.pop_front();
            }
            
            // Remove smaller elements from the back as they won't be useful
            while (!window.empty() && nums[window.back()] < nums[i]) {
                window.pop_back();
            }
            
            window.push_back(i); // Add the current index to the window
            
            // The front element of the window is the maximum for the current window
            if (i >= k - 1) {
                result.push_back(nums[window.front()]);
            }
        }
        
        return result;
    }
};
