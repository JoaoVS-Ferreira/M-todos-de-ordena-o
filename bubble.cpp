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
    string ch,aux;
    string palavras[30000];
    string temp;
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
    //aqui é o bubble
    for(int i = 0; i < n; i++){
        for(int j=0; j < n-1-i; j++){
            if (palavras[j] > palavras[j+1]){
                temp=palavras[j];
                palavras[j]=palavras[j+1];
                palavras[j+1]=temp;
            }
        }
    }
    tempo_fin=(int) clock();
    tempo_ms=((tempo_fin - tempo_ini)*1000/CLOCKS_PER_SEC);
    for (i=0;i<30000;i++)
        cout << "\n" << palavras[i];
    cout << "\nTotal de tempo para execucao: ";
    cout << tempo_ms ;
    cout << " ms";
}
