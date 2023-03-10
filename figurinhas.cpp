#include <iostream> // biblioteca
using namespace std;

int main() // start
{
	int n, f1, f2;
	int divid, divis, x; // variaveis

	do
	{
		cin >> n;
	}
	while(1 > n || n >= 3000); //entrada de controle p/pessoas

	for (int i = 0; i < n; ++i) //loop para as cartas
	{
		do
		{
			cin >> f1;
		}
		while(1 > f1 && f1 <= 1000); // quantidade de carta

		do
		{
			cin >> f2;
		}
		while(1 > f2 && f2 <= 1000); // outra quantidade de carta

		if(f2 > f1) //comparando os monte de cartas
		{
			divid = f2;
			divis = f1;
		}
		else
		{
			divid = f1;
			divis = f2;
		}

		while(divid % divis != 0) // usando a relaçao de disivibilidade entre dividendo e divisor para achar o tamanho da pilha
		{
			x = divid % divis;
			divid = divis;
			divis = x;
		}

		cout << divis << endl; // tamanho da pilha
	}

	return 0;
}



