/* Fonction MiniMax
   Pour chaque ligne : on prend le maximum
   Puis on prend le minimum de ces maximums */
int MiniMax(int tab[][3], int n, int m) {
    int i, j;
    int max, minimax;

    for(i = 0; i < n; i++) {

        max = tab[i][0];

        for(j = 1; j < m; j++) {

            // Recherche du max dans la ligne
            if(tab[i][j] > max)
                max = tab[i][j];
        }

        // Initialisation
        if(i == 0)
            minimax = max;

        // Mise à jour
        else if(minimax > max)
            minimax = max;
    }

    return minimax;
}
