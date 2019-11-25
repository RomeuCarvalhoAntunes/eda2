#include <bits/stdc++.h>
#define MAX_CIDADES 2001

int ruas[MAX_CIDADES][MAX_CIDADES];
int floyd[MAX_CIDADES][MAX_CIDADES];

using namespace std;

void zera_ruas(){
  for(int i=0; i<MAX_CIDADES; i++){
    for(int j=0; j<MAX_CIDADES; j++){
      ruas[i][j] = 0;
    }
  }
}

void zera_floyd(){
  for(int i=0; i<MAX_CIDADES; i++){
    for(int j=0; j<MAX_CIDADES; j++){
      floyd[i][j] = 0;
    }
  }
}
void cria_relacoes_ruas(int informacoes_ruas){
    int saida;
    int destino;
    int sentido;
    for(int i=0; i<informacoes_ruas; i++){
        cin >> saida >> destino >> sentido;
        if(sentido == 2){
            ruas[saida][destino] = 1;
            ruas[destino][saida] = 1;
        } else {
            ruas[saida][destino] = 1;
        }
    }
}

void floyd_warshall(int numero_cidades){
    for(int i=1; i<=numero_cidades; i++){
        for(int j=1; j<=numero_cidades; j++){
            floyd[i][j] = ruas[i][j];
        }
    }

    for(int k=1; k<=numero_cidades; k++){
        floyd[k][k] = 1;
    }
    
    for(int i=1; i<=numero_cidades; i++){
        for(int j=1; j<=numero_cidades; j++){
            if(floyd[j][i] == 1){
                for(int t=1; t<=numero_cidades; t++){
                    if(floyd[i][t] == 1){
                        floyd[j][t] = 1;
                    }
                }
            }
        }
    }
}

int verifica_conexidade(int numero_cidades){
    for(int i=1; i<=numero_cidades; i++){
        for(int j=1; j<=numero_cidades; j++){
            if(floyd[i][j] != 1){
                return 0;
            }
        }
    }

    return 1;
}

void print_ruas(){
    for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
            cout << floyd[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){

    int numero_cidades;
    int informacoes_ruas;

    while(true){
        cin >> numero_cidades >> informacoes_ruas;
        if(numero_cidades == 0 || informacoes_ruas == 0){
            break;
        } else {
            zera_ruas();
            zera_floyd();
            cria_relacoes_ruas(informacoes_ruas);
            floyd_warshall(numero_cidades);
            cout << verifica_conexidade(numero_cidades) << endl;
        }
    }

    return 0;
}