#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int binstr_to_int(char *str) {
    int num = 0;
    int n = strlen(str);
    int power = 1;
    for (int i = n - 1; i >= 0; i--) {
        int bit = str[i] == '0' ? 0 : 1;
        num += power * bit;
        power *= 2;
    }
    return num;
}

char *int_to_binstr(int num) {
    int length = floor(log2(num)) + 1;
    char *str = calloc(length, sizeof(char));

    int i = length - 1;
    while (num != 0 && i >= 0) {
        int bit = num % 2;
        num >>= 1;
        str[i] = bit == 0 ? '0' : '1';
        i--; 
    }

    return str;
}

char* addBinary(char* a, char* b) {
    int num_a = binstr_to_int(a);
    printf("num_a: %d\n", num_a);
    int num_b = binstr_to_int(b);
    printf("num_b: %d\n", num_b);
    int sum = num_a + num_b;

    return int_to_binstr(sum);
}

int main(int argc, char *argv[])
{
    char *a = "11";
    char *b = "1";
    char *output = addBinary(a, b);
    printf("%s\n", output);

    return 0;
}
