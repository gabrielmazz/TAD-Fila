#include <iostream>
#include <cstdlib>
#include "module.hpp"

int main(void){
    fila fila;

    unsigned seed = time(0);
    srand(seed);

    int switch01;
    int entrada, test01;
    int aleatorio;
    int tamanho_entradas;

    clear_screen();
    RETURN02: cout << "Algortimo de fila usando herança:" << endl;
    cout << "1 - Inserção manual\n2 - Inserção aleatória\nR: ";
    cin >> switch01;

    switch(switch01){
        case(1):
            RETURN01: cout << "Determine o número de inserção: ";
            cin >> entrada;

            fila.insercaofila(entrada);

            cout << "Deseja adicionar mais um número\n1 - Adicionar\n0 - Não adicionar\nR: ";
            cin >> test01;
            
            if(test01 == 1)
                goto RETURN01;
            else
                break;
        
        case(2):
            clear_screen();
            cout << "Determine quantos elementos a fila possuirá: ";
            cin >> tamanho_entradas;
            clear_screen();

            for(int i=0; i<tamanho_entradas; i++){
                aleatorio = rand() % 100;
                fila.insercaofila(aleatorio);
            }

            break;

        default:
            cout << "Entrada inválida, tente novamente" << endl;
            stop_time(3);
            clear_screen();
            goto RETURN02;
            
    }

    clear_screen();
    int switch02, switch03;
    int remove, tamanho_fila;

    RETURN03: cout << "1 - Imprime a fila" << endl;
    cout << "2 - Insere um novo elemento" << endl;
    cout << "3 - Remove alguns elementos" << endl;
    cout << "4 - Determina quantos elementos existe na fila" << endl;
    cout << "5 - Primeiro e ultimo elemento da fila" << endl;
    cout << "6 - Destruir a fila\nR: ";
    cin >> switch02;

    switch(switch02){
        case(1):
            clear_screen();
            fila.printfila();
            setbuf(stdin, NULL);
            stop();

            clear_screen();
            goto RETURN03;
            break;

        case(2):
            clear_screen();
            cout << "Determine o novo elemento: ";
            cin >> entrada;
            clear_screen();

            fila.insercaofila(entrada);
            goto RETURN03;
            break;

        case(3):
            clear_screen();
            cout << "Determine quantos elementos deseja excluir: ";
            cin >> remove;
            clear_screen();

            for(int i=0; i<remove; i++)
                fila.removefila();

            clear_screen();
            goto RETURN03;
            break;

        case(4):
            clear_screen();
            printf("Tamanho da fila: %d\n", fila.sizefila());
            setbuf(stdin, NULL);

            stop();
            clear_screen();
            goto RETURN03;
            break;
        
        case(5):
            clear_screen();
            cout << "Determine uma opção:" << endl;
            cout << "1 - Primeiro elemento da fila" << endl;
            cout << "2 - Ultimo elemento da fila\nR: ";
            cin >> switch03;
            clear_screen();

            switch(switch03){
                case(1):
                    printf("Primeiro elemento: %d\n", fila.primeiroelemento());
                    setbuf(stdin, NULL);
                    stop();
                    clear_screen();
                    goto RETURN03;
                    break;
                
                case(2):
                    printf("Ultimo elemento: %d\n", fila.ultimoelemento());
                    setbuf(stdin, NULL);
                    stop();
                    clear_screen();
                    goto RETURN03;
                    break;
                
                default:
                    cout << "Entrada inválida, tente novamente..." << endl;
                    stop_time(3);
                    goto RETURN03;
                    break;
            }

        case(6):
            clear_screen();
            cout << "Destruindo a lista..." << endl;
            stop_time(3);
            fila.~fila();
            break;

        default:
            cout << "Entrada inválida, tente novamente..." << endl;
            stop_time(3);
            goto RETURN03;
            break;

    }
}
