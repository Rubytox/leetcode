// Create a trie
struct TrieNode {
    struct TrieNode *children[26];
    bool endOfWord;
};

struct TrieNode *initTrie() {
    struct TrieNode *trie = malloc(sizeof(struct TrieNode));
    for (int i = 0; i < 26; i++)
        trie->children[i] = NULL;
    
    trie->endOfWord = false;
    
    return trie;
}

void freeTrie(struct TrieNode **trie) {
    if (trie == NULL || *trie == NULL)
        return;
    
    for (int i = 0; i < 26; i++)
        freeTrie(&((*trie)->children[i]));
    
    free(*trie);
    *trie = NULL;
}

int idx(char c) {
    return c - 'a';
}

char chr(int i) {
    return i + 'a';
}

void addWord(struct TrieNode *trie, const char *word) {
    // Loop over the characters of word
    // If letter not in current trie, create new trie at this place
    for (const char *c = word; *c != '\0'; c++) {
        // Is current letter in trie?
        // If not, create trie under this letter
        if (trie->children[idx(*c)] == NULL)
            trie->children[idx(*c)] = initTrie();
        
        // Now we know trie->children[idx(*c)] has a Trie
        // we can continue onto the next letter
        trie = trie->children[idx(*c)];
    }
    trie->endOfWord = true;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    struct TrieNode *trie = initTrie();

    int maxLength = 0;

    for (int i = 0; i < strsSize; i++) {
        addWord(trie, strs[i]);

        int len = strlen(strs[i]);
        if (len == 0) {
            freeTrie(&trie);
            return strdup("");
        }

        if (len > maxLength)
            maxLength = len;
    }

    if (maxLength == 0) {
        freeTrie(&trie);
        return strdup("");
    }

    char *result = calloc(maxLength + 1, sizeof(char));

    // The prefix is common only while there aren't any other letters on the same level
    struct TrieNode *curr = trie;
    int level = 0;
    bool finished = false;
    while (curr != NULL && !finished) {
        // count number of children not NULL
        int count = 0;
        char letter = '\0';
        for (int i = 0; i < 26; i++) {
            if (count > 1) {
                finished = true;
                break;
            }

            if (curr->children[i] != NULL) {
                count++;
                letter = chr(i);
            }
        }
        if (count == 0 || curr->endOfWord)
            break;
        
        // here count = 1
        if (!finished) {
            result[level] = letter;
            curr = curr->children[idx(letter)];
            level++;
        }
    }
  

    freeTrie(&trie);

    return result;
}