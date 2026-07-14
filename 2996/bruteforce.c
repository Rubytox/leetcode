bool isInArray(int *nums, int numsSize, int val) {
    for (int i = 0; i < numsSize; i++)
        if (nums[i] == val)
            return true;
    
    return false;
}

int missingInteger(int* nums, int numsSize) {
    // First find longest sequential prefix
    int sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1] + 1)
            break;

        sum += nums[i];
    }

    // Bruteforce: check if sum is in list
    // If not return sum
    // If yes restart with sum + 1
    while (isInArray(nums, numsSize, sum++));
    
    return sum - 1;
}