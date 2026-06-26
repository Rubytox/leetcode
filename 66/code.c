/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    bool overflow = true;
    for (int i = 0; i < digitsSize; i++) {
        if (digits[i] != 9) {
            overflow = false;
            break;
        }
    }

    *returnSize = overflow ? digitsSize + 1 : digitsSize;
    int *result = calloc(*returnSize, sizeof(int));

    int i = digitsSize - 1;
    int j = *returnSize - 1;
    int carry = 1;
    while (i >= 0) {
        result[j] = digits[i] + carry;
        if (result[j] >= 10) {
            result[j] = 0;
            carry = 1;
        }
        else
            carry = 0;
        i--;
        j--;
    }
    if (carry)
        result[0] = 1;
    

    return result;
}
