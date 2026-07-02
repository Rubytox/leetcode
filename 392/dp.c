bool isSubsequence(char* s, char* t) {
    while (*s != '\0') {
        while (*s != *t && *t != '\0') 
            t++;
        if (*t == '\0')
            return false;
        s++;
        t++;
    }
    return true;
}
