int rec2(int n) {

    if(n == 0)
        return 1;

    return rec2(n-1) + rec2(n-1);

    // Complexité : O(2^n)
}
