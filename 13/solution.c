int romanToInt(char* s) {
    int sum = 0;
    for (char *c = s; *c != '\0'; c++) {
        switch (*c) {
        case 'I':
            if (*(c+1) == 'V') {
                sum += 4;
                c++;
            }
            else if (*(c+1) == 'X') {
                sum += 9;
                c++;
            }
            else
                sum++;
            
            break;

        case 'V':
            sum += 5;
            break;

        case 'X':
            if (*(c+1) == 'L') {
                sum += 40;
                c++;
            }
            else if (*(c+1) == 'C') {
                sum += 90;
                c++;
            }
            else
                sum += 10;
            
            break;

        case 'L':
            sum += 50;
            break;

        case 'C':
            if (*(c+1) == 'D') {
                sum += 400;
                c++;
            }
            else if (*(c+1) == 'M') {
                sum += 900;
                c++;
            }
            else
                sum += 100;
            
            break;

        case 'D':
            sum += 500;
            break;

        case 'M':
            sum += 1000;
            break;

        default:
            break;
        }
    }
    return sum;
}