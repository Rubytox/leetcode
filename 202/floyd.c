int next(int n) {
    int sum = 0;
    while (n != 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int tortoise = n;
    int hare = next(n);
    while (hare != 1 && tortoise != hare) {
        tortoise = next(tortoise);
        hare = next(next(hare));
    }
    return hare == 1;
}
