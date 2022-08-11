using namespace std;

// Tipo armazenado na estrutura de dados
typedef int Data;

// Estrutura do nó utilizado na listaa encadeada
typedef struct Node{
	Data info; // dado armazenado no nó
	struct Node *next;	// ponteiro para o próximo nó
}Node;

void clear_screen(void);
void stop_time(int tempo);
void stop(void);

// Definição da classe e métodos da listaa encadeada
class lista{
    private:
        Node *primeiro;
        Node *proximo;
        int tamanho;

    public:
        //Constroi e destroi a lista
        lista();
        ~lista();

        //Determinia se a lista está vazia
        bool vazio();

        //Determina o comprimento da lista
        int comprimento();

        //Printa a lista alocada
        void printlista();

        /*Inserção de elementos de uma lista, primeiro sendo a inserção pela
          frente e a outra sendo a inserção pelo final*/
        bool insercaofrente(Data data);
        bool insercaofinal(Data data);

        
        /*Remove os elementos de uma lista, primeiro sendo a remoção pela
          inicio da lista, e o outro sendo a remoção pelo final*/
        bool remocaofrente();
        bool remocaofinal();
        
        //Verificação se existe um determinado elemento dentro da lista
        bool buscaelemento(Data data);
        
        //Retorna a posição da lista
        Data posicaolista(int pos);
};

// Definição da classe e métodos da Fila com herança da listaa encadeada
class fila : protected lista{
    public:
        //Constroi e destroi a lista
        fila();
        ~fila();

        //Determina o tamanho da fila
        int sizefila();

        //Funçõoes de inserção e remoção da fila
        bool insercaofila(Data data);
        bool removefila();

        //Verificação se a fila está vazia
        bool vaziofila();

        //Printa a fila alocada
        void printfila();

        //Funções em que retornaram o primeiro / ultimo elemento
        Data primeiroelemento();
        Data ultimoelemento();
};