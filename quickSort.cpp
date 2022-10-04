#include <iostream>
#include <fstream>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;

string palavras[30000];
void swap (const int i, const int j)
{
    string k = palavras[i];
    palavras[i] = palavras[j];
    palavras[j] = k;
}

int partition (const int start, const int end)
{
    int i = start;
    for (int j = start; j < end; j++) {
        if (palavras[j] <= palavras[end]) {
            swap(i++, j);
        }
    }
    swap(i, end);

    return i;
}

void quicksort (const int start, const int end)
{
    if (start >= end) return;

    int pivot = partition(start, end);

    quicksort(start, pivot - 1);
    quicksort(pivot + 1, end);
}


int main (){
    int tempo_ini, tempo_fin, tempo_ms;
    ios_base::sync_with_stdio(false);
    fstream aurelio40000;
    int i=0,n=30000;
    tempo_ini=(int) clock();
    string ch,aux;
    string temp;
    aurelio40000.open("aurelio40000.txt", ios::in);
    if(!aurelio40000){
        cout << "Nao enontrado";
    }else{
        while (1){
            aurelio40000 >> ch ;
            palavras[i]=ch;
            if (aurelio40000.eof())
                break;
            i++;
        }
    }
    quicksort(0,n-1);
    tempo_fin=(int) clock();
    tempo_ms=((tempo_fin - tempo_ini)*1000/CLOCKS_PER_SEC);
     for (i=0;i<30000;i++)
        cout << "\n" << palavras[i];
    cout << "\nTotal de tempo para execucao: ";
    cout << tempo_ms ;
    cout << " ms";
}
