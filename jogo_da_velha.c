#include <stdio.h>
#include <stdlib.h>

int matrix[3][3];//declara a matriz do jogo

int check_winner(); //verifica o vencedor
//int check_draw();//verifica empate
void init_matrix();//inicializa a matriz
//void get_player_action();//obtém a acao do jogador
//void get_computer_action();//obtém a acao do pc
void show_matrix();//mostra a matriz

int main(int argc, char *argv[])
{
    printf("                                Jogo da velha                                          ");

    //o jogo começa empatado
    char winner = 'E';

    int cont;

    init_matrix();

    do
    {
        //chama a funcao para mostrar a matriz
        show_matrix();

        break;
    }
    while(1);

    return 0;
} 

//funcao que inicializa a matriz
void init_matrix()
{
    int i, j;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j< 3; j++)
        {
            matrix[i][j] = ' ';
        }
    }
}

//funcao que mostra a matriz
void show_matrix()
{
	int i;

	printf("\n");

	for(i = 0; i < 3; i++)
	{
		printf("                                  %c | %c | %c ", matrix[i][0],
			   matrix[i][1], matrix[i][2]);

		if(i != 2)
		{
			printf("\n                                 ---|---|---\n");
		}
	}

	printf("\n");
}
