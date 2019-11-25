#include <bits/stdc++.h>
#define MAX_CIDADES 201

int voos[MAX_CIDADES][MAX_CIDADES];

using namespace std;

void zera_voos(){
  for(int i=0; i<MAX_CIDADES; i++){
    for(int j=0; j<MAX_CIDADES; j++){
      voos[i][j] = 0;
    }
  }
}

void cria_relacoes_voos(int informacoes_voos){
    int saida;
    int destino;
    int valor;
    for(int i=0; i<informacoes_voos; i++){
        cin >> saida >> destino >> valor;
            voos[saida][destino] = valor;
            voos[destino][saida] = valor;
    }
}


void print_voos(int numero_cidades, int informacoes_voos){
    for(int i=1; i<=numero_cidades; i++){
        for(int j=1; j<informacoes_voos; j++){
            cout << voos[i][j] << " ";
        }
        cout << endl;
    }
}




int main(){

    int numero_cidades;
    cin >> numero_cidades;

    int informacoes_voos;
    cin>> informacoes_voos;
    
    zera_voos();
    cria_relacoes_voos(informacoes_voos);
    print_voos(numero_cidades, informacoes_voos);

    int quantidade_amigos;
    cin >> quantidade_amigos;

    int assentos;
    cin>> assentos;

    int viagens = ceil(quantidade_amigos/assentos);

    cout << viagens << endl;


    // while(true){
    //     cin >> numero_cidades >> informacoes_ruas;
    //     if(numero_cidades == 0 || informacoes_ruas == 0){
    //         break;
    //     } else {
    //     }
    // }

    return 0;
}