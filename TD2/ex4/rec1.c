int rec1(int n) {

    if(n == 0)
        return 1;

    return 2 * rec1(n-1);

    // Complexité : O(n)
}
