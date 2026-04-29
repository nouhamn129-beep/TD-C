int expRapide(int a, int n) {

    if(n == 0)
        return 1;

    int x = expRapide(a, n/2);

    // Si n est pair
    if(n % 2 == 0)
        return x * x;

    // Si n est impair
    else
        return a * x * x;

    // Complexité : O(log n)
}
