#include <stdio.h>
#include <stdlib.h>

int matrix[3][3];//declara a matriz do jogo

int check_winner(); //verifica o vencedor
int check_draw();//verifica empate
void init_matrix();//inicializa a matriz
void get_player_action();//obtém a acao do jogador
void get_computer_action();//obtém a acao do pc
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

        //obtem o movimento do jogador
        get_player_action();

        //verifica se ha um vencedor 
        if(check_winner() == 1)
        {
            winner = 'P';
            break;
        }

        get_computer_action();
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

//funcao que obtem o movimento do jogador
void get_player_action()
{
    int x, y;

    printf("\nDigite as coordenadas (exemplo: 1 2): ");
    scanf("%d %d*c", &x, &y);

    //decrementa para obter as posicoes corretas
    x--;
    y--;

    if(matrix[x][y] != ' ')
    {
        printf("\nPosição Invalida, tente novamente\n");
        get_player_action();
    }
    else
    {
        matrix[x][y] = 'X';
    }
}

//funcao que obtem o movimento do computador 
void get_computer_action()
{
    int i, j;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(matrix[i][j] == ' ')
            {
                matrix[i][j] = 'O';
                return;
            }
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


//funcao que verifica o vencedor 
int check_winner()
{
    return 0;
}
