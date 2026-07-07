/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char **result = calloc(wordsSize, sizeof(char *));
    for (int i = 0; i < wordsSize; i++)
        result[i] = calloc(maxWidth + 1, sizeof(char));

    // Loop over words, compute current length until we reach maxWidth including spaces
    // If we're > maxWidth then save the last word for the next line
    int currentLine = 0;
    int i = 0;
    while (i < wordsSize) {
        int currentWidth = 0;
        int j = i;
        while (j < wordsSize) {
            int sum = strlen(words[j]) + (j > i ? 1 : 0);
            if (currentWidth + sum > maxWidth)
                break;

            currentWidth += sum;
            j++;
        }
        
        int pos = 0;
        for (int k = i; k < j; k++) {
            int len = strlen(words[k]);
            memcpy(result[currentLine] + pos, words[k], len);
            pos += len;
            if (k != j - 1) {
                result[currentLine][pos++] = ' ';
            }
        }
        

        // Now add as many spaces as necessary between words of the line
        // pos contains the end position of the last copied word so we know how much is left
        int remainingChars = maxWidth - pos;
        // We can compute the number of added words to know how many spaces we should be adding at each side
        int numberOfWords = j - i;
        int numberOfSpaces = numberOfWords - 1;
        int numberOfSpacesPerSpace = remainingChars / numberOfSpaces;
        int remainder = remainingChars % numberOfSpaces; // This will be added to the first space location
        // Now loop over the string and when we find a space, add the number of spaces with shifting the string, then continue until we find spaces again
        bool firstSpace = true;
        char *c = result[currentLine];
        while (*c != '\0') {
            while (*c != '\0' && *c != ' ')
                c++;

            if (*c == '\0')
                break;
            
            // Shift from number of spaces to add
            int len = numberOfSpacesPerSpace + (firstSpace ? remainder : 0);
            strcpy(c + len, c + 1);
            for (int k = 0; k < len; k++)
                *(c + k) = ' ';

            firstSpace = false;

            // While still spaces loop   
            while (*c != '\0' && *c == ' ')
                c++;
        }

        // /!\ Different case if currentLine is the last line


        i = j; 
        currentLine++;
    }

    *returnSize = currentLine;
    
    return result;
}