int aux(int n, int *memory) {
    if (n <= 1)
        return 1;
    
    if (memory[n] != -1)
        return memory[n];

    memory[n] = aux(n-1, memory) + aux(n-2, memory);

    return memory[n];
}

int climbStairs(int n) {
    int memory[n + 1];
    memset(memory, -1, (n + 1) * sizeof(int));

    return aux(n, memory);
}