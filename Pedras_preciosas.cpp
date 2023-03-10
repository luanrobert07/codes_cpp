#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int dp[MAXN][MAXN]; // Matriz de programação dinâmica
int peso[MAXN], volume[MAXN], preco[MAXN];

int main() {
    int n, v, c;
    cin >> n >> v >> c; // Entrada com o número max de pedras e capacidade max do carrinho

    for (int i = 1; i <= n; i++) {
        cin >> volume[i] >> peso[i] >> preco[i]; // Leitura dos dados de cada pedra
    }

    for (int i = 1; i <= n; i++) { // Para cada pedra
        for (int j = v; j >= volume[i]; j--) { // Para cada volume possível
            for (int k = c; k >= peso[i]; k--) { // Para cada peso possível
                dp[j][k] = max(dp[j][k], dp[j - volume[i]][k - peso[i]] + preco[i]); // Atualiza a solução
            }
        }
    }

    cout << "Valor total: R$ " << dp[v][c] << endl;
    cout << "Pedras selecionadas: " << endl;

    int v_atual = v, c_atual = c;
    
    for (int i = n; i > 0; i--) {
        if (dp[v_atual][c_atual] != dp[v_atual - volume[i]][c_atual - peso[i]] + preco[i]) {
            // A pedra i foi selecionada
            cout << "Pedra " << i << ": peso = " << peso[i] << " kg, valor = R$ " << preco[i] << endl;
            v_atual -= volume[i];
            c_atual -= peso[i];
        }
    }

    return 0;
}
