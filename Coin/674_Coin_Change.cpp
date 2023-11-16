#include <iostream>
using namespace std;

// Función que cuenta el número de formas de hacer cambio para una cantidad dada
int countWays(int amount) {
    // Definición de los valores de las monedas disponibles
    int coins[] = {1, 5, 10, 25, 50};

    // Arreglo para almacenar los resultados intermedios, inicializado en 0
    int dp[7490] = {0};
    dp[0] = 1; // Inicializa la primera posición como 1, ya que hay una sola forma de hacer cambio para 0 centavos

    // Recorre cada tipo de moneda disponible
    for (int i = 0; i < 5; i++) {
        // Para cada moneda, calcula las combinaciones posibles para la cantidad actual
        for (int j = coins[i]; j <= amount; j++) {
            // Actualiza la cantidad de formas de hacer cambio sumando las formas anteriores
            dp[j] += dp[j - coins[i]];
        }
    }

    // Devuelve el número de formas de hacer cambio para la cantidad dada
    return dp[amount];
}

// Función principal
int main() {
    int amount;
    // Lee la cantidad de dinero desde la entrada estándar
    while (cin >> amount) {
        // Calcula el número de formas de hacer cambio para la cantidad ingresada y muestra el resultado
        int ways = countWays(amount);
        cout << ways << endl;
    }
    return 0;
}
