//Guilherme de Moura - 2110362


#include <iostream>
#include <vector>

using namespace std;

class ArvoreBinaria {
private:
    vector<int> arvore;
    int tamanho;
    int n_elementos;
    
public:
    ArvoreBinaria(int tamanho) {
        this->arvore.resize(tamanho+1);
        this->tamanho = tamanho;
        this->n_elementos = 0;
    }
    
    void criar_arvore(int raiz) {
        arvore[1] = raiz;
        n_elementos = 1;
    }
    
    void inserir_elemento(int elemento) {
        if (n_elementos == tamanho) {
            throw "A árvore já está cheia.";
        }
        
        int i = n_elementos + 1;
        arvore[i] = elemento;
        
        while (i > 1 && arvore[i] > arvore[i/2]) {
            swap(arvore[i], arvore[i/2]);
            i = i/2;
        }
        
        n_elementos++;
    }
    
    static pair<vector<int>, vector<int>> construir_arvore(vector<int> lista) {
        ArvoreBinaria arvore(lista.size()+1);
        vector<int> repetidos;
        
        for (int elemento : lista) {
            try {
                arvore.inserir_elemento(elemento);
            } catch (const char* msg) {
                repetidos.push_back(elemento);
            }
        }
        
        return make_pair(arvore.arvore, repetidos);
    }
};

int main() {
    vector<int> lista = {10, 8, 15, 12, 17, 5, 7, 10};
    auto arvore = ArvoreBinaria::construir_arvore(lista);
    
    cout << "Árvore construída: ";
    for (int i = 1; i < arvore.first.size(); i++) {
        cout << arvore.first[i] << " ";
    }
    cout << endl;
    
    cout << "Elementos repetidos: ";
    for (int i = 0; i < arvore.second.size(); i++) {
        cout << arvore.second[i] << " ";
    }
    cout << endl;
    
    return 0;
}
