class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.size() == 1) {
            result.emplace_back(to_string(nums[0]));
            return result;
        }

        int start_idx = 0;
        int current_idx = 1;
        int previous_idx = start_idx;
        while (start_idx < nums.size()) {
            if (start_idx == nums.size() - 1) {
                result.emplace_back(to_string(nums[start_idx]));
                break;
            }
            while (current_idx < nums.size() && nums[current_idx] == nums[previous_idx] + 1) {
                current_idx++;
                previous_idx++;
            }
            if (previous_idx == start_idx)
                result.emplace_back(to_string(nums[start_idx]));
            else
                result.emplace_back(to_string(nums[start_idx]) + "->" + to_string(nums[previous_idx]));
            start_idx = current_idx;
            current_idx++;
            previous_idx = start_idx;
        }

        return result;
    }
};
