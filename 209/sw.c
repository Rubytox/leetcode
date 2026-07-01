int minSubArrayLen(int target, int* nums, int numsSize) {
    int min = -1;
    if (numsSize == 0)
        return 0;
    
    int window_sum = 0;
    int start_i = 0;
    int curr_i = 0;
    // Remove elements from the start until the sum is < target
    // Add more elements from the end until the sum is >= target
    while (curr_i < numsSize) {
        while (curr_i < numsSize && window_sum < target) {
            window_sum += nums[curr_i++];
        }
        while (window_sum >= target) {
            int len = curr_i - start_i;
            if (min == -1 || len < min)
                min = len;
            window_sum -= nums[start_i++];
        }
    }
    
    return min == -1 ? 0 : min;
}
