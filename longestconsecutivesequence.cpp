class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end()); // Create an unordered set to store all the numbers
        
        int longestStreak = 0; // Initialize the longest streak to 0
        
        for (int num : nums) {
            if (numSet.find(num - 1) == numSet.end()) { // Check if the current number is the start of a sequence
                int currentNum = num;
                int currentStreak = 1; // Initialize the streak for the current sequence
                
                while (numSet.find(currentNum + 1) != numSet.end()) { // Increment the current number until the sequence ends
                    currentNum++;
                    currentStreak++;
                }
                
                longestStreak = max(longestStreak, currentStreak); // Update the longest streak if necessary
            }
        }
        
        return longestStreak;
    }
};
