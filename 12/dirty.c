char max_subtract_value(int num) {
    if (num - 1000 >= 0)
        return 'M';
    else if (num - 500 >= 0)
        return 'D';
    else if (num - 100 >= 0)
        return 'C';
    else if (num - 50 >= 0)
        return 'L';
    else if (num - 10 >= 0)
        return 'X';
    else if (num - 5 >= 0)
        return 'V';
    else if (num - 1 >= 0)
        return 'I';
    return '\0';
}

char* intToRoman(int num) {
    int map[128] = { 0 };
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;

    int counter = 0;
    char *result = calloc(100, sizeof(char));

    while (num != 0) {
        int first_digit = 0;
        int tmp = num;
        while (tmp != 0) {
            first_digit = tmp;
            tmp /= 10;
        }

        if (first_digit != 4 && first_digit != 9) {
            char symbol = max_subtract_value(num);
            result[counter++] = symbol;
            
            int value = map[symbol];
            num -= value;
        }
        else if (first_digit == 4) {
            if (num - 400 >= 0) {
                result[counter++] = 'C';
                result[counter++] = 'D';
                num -= 400;
            }
            else if (num - 40 >= 0) {
                result[counter++] = 'X';
                result[counter++] = 'L';
                num -= 40;
            }
            else if (num - 4 >= 0) {
                result[counter++] = 'I';
                result[counter++] = 'V';
                num -= 4;
            }
        }
        else { // Then it's 9
            if (num - 900 >= 0) {
                result[counter++] = 'C';
                result[counter++] = 'M';
                num -= 900;
            }
            else if (num - 90 >= 0) {
                result[counter++] = 'X';
                result[counter++] = 'C';
                num -= 90;
            }
            else if (num - 9 >= 0) {
                result[counter++] = 'I';
                result[counter++] = 'X';
                num -= 9;
            }
        }

        //printf("result: %s\n", result);
    }

    return result;
}