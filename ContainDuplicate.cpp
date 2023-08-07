class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> numSet;
    for (int num : nums) {
        if (numSet.count(num) > 0) {
            return true;
        }
        numSet.insert(num);
    }
    return false;
}
};
