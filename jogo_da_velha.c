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

    //inicializa a matriz
    init_matrix();

    do{ 
        do
        {
            //chama a funcao para mostrar a matriz
            show_matrix();

            //obtem o movimento do jogador
            get_player_action();

            //verifica se ha um vencedor 
            if(check_winner() == 1)
            {
                winner = 'C';
                break;
            }

            get_computer_action();

            if(check_winner() == 1)
            {
                winner = 'P';
                break;
            }

            //funcao que verifica se houve empate
            if(check_draw() == 1)
            {
                winner = 'E';
                break;
            }
        }
        while(1);

        show_matrix();

        //verifica quem venceu
        if(winner == 'P')
        {
            printf("\n\nParabéns, você venceu");
        }
        else if(winner == 'C')
        {
            printf("\n\nVocê perdeu...");
        }
        else
        {
            printf("\n\nEmpate");
        }

        printf("\n\nDeseja continuar jogando? <1>SIM <outro valor>NÃO: ");
        scanf("%d%*c", &cont);

        if(cont == 1)
        {
            system("clear");
            init_matrix();
            continue;
        }
        else 
        {
            break;
        }
    }
    while(1);
    
    printf("\n\nPressione enter para sair...");

    scanf("%*c");

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
    int i;

    //verifica as linhas
    for(i = 0; i < 3; i++)
    {
        if(matrix[i][0] != ' ' && matrix[i][1] != ' ' && matrix[i][2] != ' ')
        {
            if(matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
            {
                return 1;
            }
        }
    }

    //verifica as colunas
    for(i = 0; i < 3; i++)
    {
        if(matrix[0][i] != ' ' && matrix[1][i] != ' ' && matrix[2][i] != ' ')
        {
            if(matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
            {
                return 1;
            }
        }
    }

    //verifica as diagonais
    if(matrix[0][0] != ' ' && matrix[1][1] != ' ' && matrix[2][2] != ' ')
    {
        if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
        {
            return 1;
        }
    }

    if(matrix[0][2] != ' ' && matrix[1][1] != ' ' && matrix[2][0] != ' ')
    {
        if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
        {
            return 1;
        }
    }

    return 0;
}

//funcao que verifica o empate
int check_draw()
{
    int i, j; 

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(matrix[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}