#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int x;
    int y;
} coordenadas;

void lab (vector<vector<coordenadas>> &labirinto, vector<vector<bool>> visitados, int linha, int coluna, int *resultado) {
    if(visitados[linha][coluna] == true) {
        *resultado = 2;
    }
    if(labirinto[linha][coluna].x == 0 and labirinto[linha][coluna].y == 0) {
        *resultado = 1;
    }
    
    linha = labirinto[linha][coluna].x;
    coluna = labirinto[linha][coluna].y;
    visitados[linha][coluna] = true;
        
    lab(labirinto, visitados, linha, coluna, resultado);
}

int main () {

    int linhas, colunas, resultado = 0;
    int x_inicial, y_inicial;

    cin >> linhas >> colunas;
    vector<vector<bool>> visitados(linhas, vector<bool>(colunas));
    vector<vector<coordenadas>> labirinto(linhas, vector<coordenadas>(colunas));

    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            cin >> labirinto[i][j].x >> labirinto[i][j].y;
        }
    }

    cin >> x_inicial >> y_inicial;

    lab(labirinto, visitados, x_inicial, y_inicial, &resultado);

    if(resultado == 1) cout << "VENCE" << endl;
    else {
        cout << "PRESO" << endl;
    }

    return 0;
}