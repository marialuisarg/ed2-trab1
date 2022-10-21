#include <string>
#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

#include "manager.h"

// testa todas as funções hash (resultado das comparações no REPORT.md)

////////////////// - FUNÇÕES HASH - //////////////////

int hash1(string palavra, int tam){
    long key = 0;
    const char* pK = palavra.c_str();
    for (int i = 0; i < strlen(pK); i++)
        key += pK[i];
    key = abs(key);
    return (int)key%tam;
};

int hash2(string palavra, int tam){
    int key = 0;
    const char* pK = palavra.c_str();
    for (int i = 0; i < strlen(pK); i++)
        key += pK[i];
    key = abs(key);

    int A = (sqrt(5)-1)/2;
    return (int)(tam*((key*A)%1));
};


int hash3(string palavra, int tam){
    int key = 0;
    const char* pK = palavra.c_str();
    for (int i = 0; i < strlen(pK); i++)
        key += pK[i];
    key = abs(key);
    return (key*(key+3))%tam;
};

int hash4(string palavra, int tam){
    int key = 0;
    const char* pK = palavra.c_str();
    for (int i = 0; i < strlen(pK); i++)
        key += pK[i];
    key = abs(key);
    key = key*key;

    if(tam > 1000){
        key = key >> 2;
        key = key%1000;
    } else if(tam < 1000){
        key = key >> 1;
        key = key%100;
    }

    return key;
};

int main(int argc, char *argv[])
{
    manager i;
    string input = INPUT_DIR + string("triste_fim_polycarpo_quaresma.txt");
    vector<string> nome_arquivo;
    nome_arquivo.push_back(input);

    i.mainGutemberg(QUICKSORT, nome_arquivo, 0, hash1);
    cout << "Numero de palavras: " << i.return_n_words() << endl;
    cout << "Numero de colisoes: " << i.return_hash()->getColisoes() << endl;

    return 0;
}