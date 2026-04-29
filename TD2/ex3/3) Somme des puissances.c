int somme(int a, int n) {

    if(n == 0)
        return 1;

    return puissance(a,n) + somme(a,n-1);

    // Complexité : O(n²)
}
