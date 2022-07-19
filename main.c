#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char tab[3][3] = {{' ',' ', ' '},
                {' ', ' ', ' '},
                {' ', ' ', ' '}};
void inicial(){
        printf(" ----------------------------------------------\n");
        printf("|               JOGO DA VELHA                  |\n");
        printf("|    jogador 1 e o X e o jogador 2 e o O       |\n");
        printf("|        Localizacao do tabuleiro              |\n");
        printf("|               00|01|02                       |\n");
        printf("|               --------                       |\n");
        printf("|               10|11|12                       |\n");
        printf("|               --------                       |\n");
        printf("|               20|21|22                       |\n");
        printf(" ----------------------------------------------\n");
}
void mostraTab(){
    for(int c = 0; c < 3; c++){
        printf("    %c | %c | %c\n",tab[c][0],tab[c][1],tab[c][2]);
        if(c<2){
            puts("   ----------");
       }
    }
}
int verificador(){
    if (tab[0][0]=='X' && tab[0][1]=='X' && tab[0][2]=='X' || tab[1][0]=='X' && tab[1][1]=='X' && tab[1][2]=='X' || tab[2][0]=='X' && tab[2][1]=='X' && tab[2][2]=='X' || tab[0][0]=='X' && tab[1][0]=='X' && tab[2][0]=='X' || tab[0][1]=='X' && tab[1][1]=='X' && tab[2][1]=='X' || tab[0][2]=='X' && tab[1][2]=='X' && tab[2][2]=='X' || tab[0][0]=='X' && tab[1][1]=='X' && tab[2][2]=='X' || tab[0][2]=='X' && tab[1][1]=='X' && tab[2][0]=='X'){
        printf("\njogador 1 ganhou\n");
        return 1;
    }
    else if(tab[0][0]=='O' && tab[0][1]=='O' && tab[0][2]=='O' || tab[1][0]=='O' && tab[1][1]=='O' && tab[1][2]=='O' || tab[2][0]=='O' && tab[2][1]=='O' && tab[2][2]=='O' || tab[0][0]=='O' && tab[1][0]=='O' && tab[2][0]=='O' || tab[0][1]=='O' && tab[1][1]=='O' && tab[2][1]=='O' || tab[0][2]=='O' && tab[1][2]=='O' && tab[2][2]=='O' || tab[0][0]=='O' && tab[1][1]=='O' && tab[2][2]=='O' || tab[0][2]=='O' && tab[1][1]=='O' && tab[2][0]=='O'){
        printf("\njogador 2 ganhou\n");
        return 1;
    }
    else if (tab[0][0] != ' ' && tab[0][1]!=' ' && tab[0][2]!=' ' && tab[1][0]!=' ' && tab[1][1]!=' ' && tab[1][2]!=' ' && tab[2][0]!=' ' && tab[2][1]!=' ' && tab[2][2]!=' ' ){
        printf("\nEmpate\n");
        return 1;
    }
}
int testePosicao(int linha, int coluna, char jogador){
    if (tab[linha][coluna] != ' '){
                printf("Espaco ja ocupado\n");
            }
            else{
                tab[linha][coluna] = jogador;
                return 1;
            }
}
int jogada(int jogador, char caracter){
    int linha, coluna, controle;
    printf("jogador %d digite uma cordenada\n", jogador);
    scanf("%d %d", &linha, &coluna);
    controle = testePosicao(linha, coluna, caracter);
    mostraTab();
    return controle;
}
void main(){
    int c = 0, c1, s0 = 0, m0 = 0, h0 = 0;
    inicial();
    time_t inicial = time(NULL);
    time_t fin;
    double segundos;
    while(c != 1){
        c1 = 0;
        while(c1 == 0){
            c1 = jogada(1,'X');
        }
        c = verificador();
        c1 = 0;
       if (c != 1){
           while(c1 == 0){
                c1 = jogada(2, 'O');
            }
        c = verificador();
       }
     else{}
    }
    fin = time(NULL);
    segundos = abs(difftime(fin,inicial));
    s0 = segundos;
    if(s0>60){
        m0 = s0/60;
        s0 -= m0*60;
        if(m0>60){
                h0 = m0/60;
                m0 -= h0*60;
        }
    }

    printf("Tempo %d:%d:%d",h0,m0,s0);
}
