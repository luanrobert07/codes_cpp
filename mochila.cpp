#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 110, maxp = 1e5+10;

int valor[maxn], peso[maxn], n, C;
long long dp[maxn][maxp];
bool vis[maxn][maxp];

long long int forca_bruta(int i, int C) {
	// Verifica se é o último item (caso base, não há mais itens para se considerar)
	if(i == n+1) return 0; 
	
	// Caso existam itens para considerar podemos:

	// (Primeira possibilidade) Não adicionar o elemento
	int ans1 = forca_bruta(i+1, C);
	
	// (Segunda possibilidade) Adicionar o elemento caso não ultrapasse o limite de capacidade
	// Devemos retirar o peso do item selecionado da capacidade
	int ans2 = 0;
	if(C >= peso[i])
	   ans2 = forca_bruta(i+1, C - peso[i]) + valor[i];
	
	
	return max(ans1, ans2);
}


long long programacao_dinamica(int i, int C) {
	// Verifica se é o último item (caso base, não há mais itens para se considerar)
	if(i == n+1) return 0;
	
	// Caso existam itens para considerar, diferente da força bruta, a memória (matriz dp) deve ser verificada para saber se esse cálculo já foi feito antes
	// Para isso, uma matriz de visitação (vis) é utilizado para saber se a posição já foi visitada anteriormente
	if(vis[i][C]) return dp[i][C];
	
	// Caso não tenha sido visitado ainda,a visita é feita:
	vis[i][C] = 1;
	
	// (Primeira possibilidade) Não adicionar o elemento
	dp[i][C] = programacao_dinamica(i+1, C);
	
	// (Segunda possibilidade) Adicionar o elemento caso não ultrapasse o limite de capacidade
	// Devemos retirar o peso do item selecionado da capacidade
	if(C >= peso[i])
		dp[i][C] = max(dp[i][C], programacao_dinamica(i+1, C - peso[i]) + valor[i]);
	
	return dp[i][C];
}


int main() {
    // Entrando com o número de itens e a capacidade da mochila
    cout << "Entre com o numero de itens: " << endl;
    cin >> n;

    cout << "Entre com a capacidade da mochila: " << endl;
    cin >> C;

    cout << " Entre com peso e valor de cada item: " << endl;

    for(int i = 1; i <= n; i++)
        cin >> peso[i] >> valor[i];

    cout << "Exibindo valor por forca bruta: " << endl;
    cout << forca_bruta(1, C) << endl;

    cout << "Exibindo valor por programacao dinamica: " << endl;
    cout << programacao_dinamica(1, C) << endl;
}


/*
	Caso de teste:
	input:
	4 10
	7 42
	3 12
	4 40
	5 25
	
	output:
	65
	65

*/