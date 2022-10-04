#include <iostream>
#include <fstream>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;
#define INF "~"

void merge_sort(vector<string> &v){
	if(v.size()==1) return;
	vector<string> u1, u2;
	for(int i=0;i<v.size()/2;i++) u1.push_back(v[i]);
	for(int i=v.size()/2;i<v.size();i++) u2.push_back(v[i]);
	merge_sort(u1);
	merge_sort(u2);
	u1.push_back(INF);
	u2.push_back(INF);
	int ini1=0, ini2=0;
	for(int i=0;i<v.size();i++){
		if(u1[ini1]<u2[ini2]){
			v[i]=u1[ini1];
			ini1++;
		}
		else{
			v[i]=u2[ini2];
			ini2++;
		}
	}
	return;
}

int main (){
    int tempo_ini, tempo_fin, tempo_ms;
    tempo_ini=(int) clock();
    ios_base::sync_with_stdio(false);
    fstream aurelio40000;
    int i=0,n=30000;
    string palavras[30000],ch;
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
    //aqui é o merge sort
    vector<string>teste;
    for(int i=0;i<n;i++)
        teste.push_back(palavras[i]);
    merge_sort(teste);
    tempo_fin=(int) clock();
    tempo_ms=((tempo_fin - tempo_ini)*1000/CLOCKS_PER_SEC);
    for (i=0;i<30000;i++)
        cout << "\n" << teste[i];
    cout << "\nTotal de tempo para execucao: ";
    cout << tempo_ms ;
    cout << " ms";



}
