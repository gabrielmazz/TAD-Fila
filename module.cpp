#include "module.hpp"
#include <iostream>

#ifdef __linux__
    #include <unistd.h>
#elif _WIN32
    #include <windows.h>
#endif

using namespace std;

//Criação da fila usando classe e seus métodos com herança
fila :: fila(){}
fila :: ~fila(){}

//Função da criação da lista
lista :: lista(){
    this->primeiro = nullptr;
    this->proximo = nullptr;
    this->tamanho = 0;
}

//Função da destruição da lista
lista :: ~lista(){
    if(vazio())
        return;

    Node *aux = this->primeiro, *p;
    while (aux != nullptr){
        p = aux;
        aux = aux->next;
        delete[] p;
    }
}

//Função que retornara o tamanho da lista
int lista :: comprimento(){
    return this->tamanho;
}

//Função para o retorno de uma lista vazia
bool lista :: vazio(){
    return this->tamanho==0;
}

//Funçãao para o printa da lista
void lista :: printlista(){
    if(this->vazio())
        return;

    Node *aux = primeiro;

    for (int i = 0; i < comprimento(); i++, aux = aux->next)
        cout << aux->info << " ";
    cout << endl;
}

//Função de inserção na lista pela frente
bool lista::insercaofrente(Data data){
    Node *node = new Node;

    if(node==nullptr)
        return false;
        
    node->info = data;
    node->next = nullptr;

    if(vazio()){
        this->primeiro = node;
        this->proximo = node;
    }else{
        node->next = this->primeiro;
        this->primeiro = node;
    }

    this->tamanho++;
    return true;
}

//Função de inserção na lista pelo final
bool lista::insercaofinal(Data data){
    Node *node = new Node;

    if(node==nullptr)
        return false;

    node->info = data;
    node->next = nullptr;

    if(vazio()){
        this->primeiro = node;
        this->proximo = node;
    }else{
        this->proximo->next = node;
        this->proximo = node;
    }

    this->tamanho++;
    return true;
}

//Função de remoção da lista pela frente
bool lista :: remocaofrente(){
    if(vazio())
        return false;

    Node *aux = this->primeiro;

    this->primeiro = aux->next;
    this->tamanho--;

    delete[] aux;
    return true;
}

//Função de remoção da lista pelo final
bool lista :: remocaofinal(){
    if(vazio())
        return false;

    Node *aux = this->primeiro;

    for(int i = 0 ; i < this->comprimento() - 1 ; i++)
        aux = aux->next;

    this->proximo = aux;
    this->proximo->next = nullptr;
    this->tamanho--;

    delete[] aux->next;
    return true;
}

//Função de busca de elementos em uma lista
bool lista :: buscaelemento(Data data){
    if(vazio())
        return false;

    Node *aux = this->primeiro;

    for(int i=0 ; i < this->comprimento() ; i++){
        if(aux->info == data)
            return true;
        aux = aux->next;
    }

    return false;
}

//Função de busca de uma determinada posição na lista
Data lista :: posicaolista(int pos){
    if((this->vazio()) || (pos >= this->comprimento())){
        cerr << "Posição inválida" << endl;
        return -1;
    }

    Node *aux = this->primeiro;

    for (int i = 0; i < pos; i++)
        aux = aux->next;
    return aux->info;
}

//Função que determinada o tamanho da fila
int fila :: sizefila(){
    return this->comprimento();
}

//Função de inserção de um elemento na fila
bool fila :: insercaofila(Data data){
    return this->insercaofinal(data);
}

///Função de remoção de um elemento na fila
bool fila :: removefila(){
    return this->remocaofrente();
}

//Função que determina se a fila está vazia
bool fila :: vaziofila(){
    return this->vazio();
}

//Função de print da fila
void fila :: printfila(){
    this->printlista();
}

//Função que determina qual é o primeiro elemento da lista
Data fila :: primeiroelemento(){
    return this->posicaolista(0);
}

//Função que determina qual é o ultimo elemento da lista
Data fila :: ultimoelemento(){
    return this->posicaolista(this->comprimento()-1);
}


void clear_screen(void){
    //Comando para os dois sistemas "apagarem a tela"
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #else
    #endif
}

void stop_time(int tempo){
    #ifdef __linux__
        sleep(tempo);
    #elif WIN32
        Sleep(tempo);
    #else
    #endif
}

void stop(void){
    fflush(stdin);
    printf("\nPressione qualquer tecla para continuar. . ."); 
    fflush(stdin);
    getchar();
}
