#include <bits/stdc++.h>
#define MAX_ANIMAIS 5001

using namespace std;

// variaveis globais
int relacoes[MAX_ANIMAIS][MAX_ANIMAIS];
vector <int> visitados(MAX_ANIMAIS,-1);
int cont;

// comparacao quando for realizar a busca da string
struct comp {
    bool operator()(const pair<string,int> &a, const string & b)
    {
        return (a.first < b);
    }
    bool operator()(const string & a,const pair<string,int> &b)
    {
        return (a < b.first);
    }
};

void reset_visitados(){
  for(int i=0; i<MAX_ANIMAIS; i++){
    visitados[i] = 0;
  }
}

//DFS
void dfs(int i, int quantidade_animais){
  cont++;
  if(visitados[i]){
    return;
  }
  visitados[i] = 1;
  for(int j=0; j<quantidade_animais; j++){
    if(!visitados[j] && relacoes[i][j]){
      dfs(j, quantidade_animais);
    }
  }
}

// ZERA MATRIZ DE RELACOES
void zera_matrix(){
  for(int i=0; i<MAX_ANIMAIS; i++){
    for(int j=0; j<MAX_ANIMAIS; j++){
      relacoes[i][j] = 0;
    }
  }
}

// FUNCAO PARA CRIAR O VETOR DO GRAPH
vector<pair<string, int>> cria_vetor(int quantidade_animais){
  vector <pair <string, int>> v;
  string aux;

  for(int i=0; i<quantidade_animais; i++){
    cin >> aux;
    v.push_back(make_pair(aux, i));    
  }

  sort(v.begin(), v.end());

  return v;
}

//FUNCAO PARA CRIAR AS RELACOES DENTRO DA MATRIZ GLOBAL
void cria_relacoes(vector<pair<string,int>> graph, int numero_relacoes){
  string presa;
  string predador;
  int indice_predador= 0;
  int indice_presa = 0;

  for(int i=0; i<numero_relacoes; i++){
    cin >> presa >> predador;

    auto it = lower_bound(graph.begin(), graph.end(), presa, comp());
    if(it != graph.end()){
      int index = distance(graph.begin(), it);
      indice_presa = graph.at(index).second;
    }

    auto it2 = lower_bound(graph.begin(), graph.end(), predador, comp());
    if(it2 != graph.end()){
      int index = distance(graph.begin(), it2);
      indice_predador = graph.at(index).second;
    }
    relacoes[indice_presa][indice_predador] = 1;
    relacoes[indice_predador][indice_presa] = 1;
  }
}

// ACHAR MAIOR CADEIA
int maior_cadeia(int quantidade_animais){
  int maior =0;

  for(int i=0; i<quantidade_animais; i++){
    cont = 0;
    dfs(i,quantidade_animais);
    if(cont > maior){
      maior = cont;
    }
  }

  return maior;
}

int main(){

  int quantidade_animais;
  int numero_relacoes;

  vector<pair<string, int>> graph;

  while(true){

    cin >> quantidade_animais >> numero_relacoes;
    
    if(quantidade_animais == 0 && numero_relacoes == 0){
      break;
    } else {
      reset_visitados();
      zera_matrix();
      graph = cria_vetor(quantidade_animais);
      cria_relacoes(graph, numero_relacoes);
      cout << maior_cadeia(quantidade_animais) << endl;
    }
  }
  return 0;
}