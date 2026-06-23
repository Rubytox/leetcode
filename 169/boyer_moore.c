int majorityElement(int* nums, int numsSize) {
    // Implement with Boyer Moore

    // Find match
    int candidate = 0;
    int counter = 0;
    for (int i = 0; i < numsSize; i++) {
        if (counter == 0) {
            candidate = nums[i];
            counter = 1;
        }
        else if (candidate == nums[i])
            counter++;
        else
            counter--;
    }


    // Now candidate contains a potential majority element
    // We could stop now because we know there is a majority element
    // But we should check if it is a majority element indeed
    return candidate;
}