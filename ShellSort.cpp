#include <iostream>
#include <fstream>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;

int main (){
    int tempo_ini, tempo_fin, tempo_ms;
    tempo_ini=(int) clock();
    ios_base::sync_with_stdio(false);
    fstream aurelio40000;
    int i=0,n=30000;
    string palavras[30000],ch,aux,temp;
    aurelio40000.open("aurelio40000.txt", ios::in);
    if(!aurelio40000){
        cout << "Nao encontrado";
    }else{
        while (1){
            aurelio40000 >> ch ;
            palavras[i]=ch;
            if (aurelio40000.eof())
                break;
            i++;
        }
    }
// aqui é o shell
    int gap, j, k;
    for(gap = n/2; gap > 0; gap = gap / 2) {
        for(j = gap; j < n; j++) {
            for(k = j-gap; k >= 0; k -= gap) {
                if(palavras[k+gap] >= palavras[k]){
                    break;
                }
                else{
                    aux = palavras[k+gap];
                    palavras[k+gap] = palavras[k];
                    palavras[k] = aux;
                }
            }
        }
    }
    tempo_fin=(int) clock();
    tempo_ms=((tempo_fin - tempo_ini)*1000/CLOCKS_PER_SEC);
    for (i=0;i<n;i++)
        cout << "\n" << palavras[i];
    cout << "\nTotal de tempo para execucao: ";
    cout << tempo_ms ;
    cout << " ms";
}
