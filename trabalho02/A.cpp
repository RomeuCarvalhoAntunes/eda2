#include <bits/stdc++.h>

using namespace std;

int relacoes[5001][5001];
vector <int> visitados(5001,-1);
int cont =0;

void dfs(int i, int quantidade_animais){
  cont++;
  visitados[i]=1;
  for(int j=0; j< quantidade_animais; j++){
    if(visitados[j] == -1 && relacoes[i][j] == 1){
      dfs(j, quantidade_animais);
    }
  }
}

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

int main(){

  int quantidade_animais;
  cin >> quantidade_animais;
  
  int numero_relacoes;
  cin >> numero_relacoes;

  vector <pair <string, int>> graph;


  string aux;

  for(int i=0; i<quantidade_animais; i++){
    cin >> aux;
    graph.push_back(make_pair(aux, i));    
  }
  
  sort(graph.begin(), graph.end());

  string presa;
  string predador;
  int indice_predador= 0;
  int indice_presa = 0;

  // matrix de relacoes zerada
  for(int i=0; i<quantidade_animais; i++){
    for (int j=0; j<quantidade_animais; j++){
      relacoes[i][j] = 0;
    }
  }

  // criar relacoes entre as especies
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
  }

  int maior = 0;
  
  for(int i=0; i<quantidade_animais; i++){
    dfs(i, quantidade_animais);
    if(cont > maior){
      maior = cont;
    }
    cont = 0;
  }

  cout << maior+1 << endl;


  return 0;
}