/* Calcul de a^n */
int puissance(int a, int n) {

    // Cas de base
    if(n == 0)
        return 1;

    // Appel récursif
    return a * puissance(a, n-1);

    // Complexité : O(n)
}
