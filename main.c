#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
// #include <conio.h> // Adicionando a biblioteca correta para usar getch()

#define altura 25
#define largura 50

char cenario[altura][largura], jogador[50];
int pontos = 1000, fimX, fimY;

void criarCen(int nivel)
{
	switch (nivel)
	{
	case 0:
		strcpy(cenario[0], "|||||||||||||||||||||||||");
		strcpy(cenario[1], "|...|||||||||||||||||||||");
		strcpy(cenario[2], "||.||||||||||||||||||||||");
		strcpy(cenario[3], "||.||||||||||||||||||||||");
		strcpy(cenario[4], "||.||||||||||||||||||||||");
		strcpy(cenario[5], "||.||||||||||||||||||||||");
		strcpy(cenario[6], "||...........||||||||||||");
		strcpy(cenario[7], "||||||||||||.||||||||||||");
		strcpy(cenario[8], "||||||||||||.||||||||||||");
		strcpy(cenario[9], "||||||||||||.............");
		strcpy(cenario[10], "|||||||||||||||||||||||||");
		break;
	case 1:
		strcpy(cenario[0], "||||||||||||||||||||||||||||||||");
		strcpy(cenario[1], "|..|||||||||||||||||||||||||||||");
		strcpy(cenario[2], "||......||||||||||||||||||||||||");
		strcpy(cenario[3], "||.||||.||||||||||||||||||||||||");
		strcpy(cenario[4], "||.||||.||||||||||||||||||||||||");
		strcpy(cenario[5], "||.||||.||||||||.....|||||||||||");
		strcpy(cenario[6], "||...........|||.|||.........|||");
		strcpy(cenario[7], "||.|||||||||.||.....||||||||.|||");
		strcpy(cenario[8], "||.|....||||.||.|||||...||||.|||");
		strcpy(cenario[9], "||...|||||||..........|.||||....");
		strcpy(cenario[10], "||||||||||||||||||||||||||||||||");
		break;
	case 2:
		strcpy(cenario[0], "|||||||||||||||||||||||||||||||||||||||||");
		strcpy(cenario[1], "|......|||||||||||||............|......||");
		strcpy(cenario[2], "||.|||.||||....|||||.||.||||||.||.||||.||");
		strcpy(cenario[3], "||.|.|......||.|||||.|||||.|||.||.||||.||");
		strcpy(cenario[4], "||.|.||.||||||..........|......||.||||.||");
		strcpy(cenario[5], "||...||....|||.|||||||||||.|||..||||...||");
		strcpy(cenario[6], "|||||||.||.|||.||||....|||.|||.|||||.||||");
		strcpy(cenario[7], "||......|..|||......||.|||.....|||.....||");
		strcpy(cenario[8], "|.||.|||||.|||||||||||.|||||||||||.|||.||");
		strcpy(cenario[9], "|.||.||......|||||||||.|||||...........||");
		strcpy(cenario[10], "|....|.|.|.||||........||....|||||.||||||");
		strcpy(cenario[11], "||.|||.|.|.||||.|||||||||.|.|||||||||||||");
		strcpy(cenario[12], "|......|...||||...........|..............");
		strcpy(cenario[13], "|||||||||||||||||||||||||||||||||||||||||");
		break;
	case 3:
		strcpy(cenario[0], "|||||||||||||||||||||||||||||||||||||||||");
		strcpy(cenario[1], "|.|||...||||||....||.||..|......|........");
		strcpy(cenario[2], "|.|||.|......||||.||.||.|||.|||||.|||||||");
		strcpy(cenario[3], "|.....|.||||......||..........||........|");
		strcpy(cenario[4], "||.||||.|||||||||||||.||.||||.|||||||||.|");
		strcpy(cenario[5], "||.|..|.............|....|||............|");
		strcpy(cenario[6], "||...|.||||||||||||.||||.|||.||||||||||||");
		strcpy(cenario[7], "||.|||.|.||....||||.|.||.|||.||||||.....|");
		strcpy(cenario[8], "||...|...||.||.||||.|.||.|||.....||.|||.|");
		strcpy(cenario[9], "|||||||||||.||......|.......||||....|||.|");
		strcpy(cenario[10], "|.|.........|||||||||||||||.|..|.|.||...|");
		strcpy(cenario[11], "|.|.||||||||||............|...||.|.||.|||");
		strcpy(cenario[12], "|.|.|||||.......||||.|.||.||.|||.|.||...|");
		strcpy(cenario[13], "|...||||||||||||||||.|.||.||||||.|.||.|.|");
		strcpy(cenario[14], "|||..................|..|........|..|.|.|");
		strcpy(cenario[15], "|||||||||||||||||||||||||||||||||||||||||");
		break;
	case 4:
		strcpy(cenario[0], "||||||||||||||||||||||||||||||||||||||||||||||");
		strcpy(cenario[1], "|....|||||......||.|||||.|...|...........||...");
		strcpy(cenario[2], "||||......||.||..........|.|||.|||||||||.||.||");
		strcpy(cenario[3], "|....||||.||.|||||||||||.|.|||....|...||....||");
		strcpy(cenario[4], "|.|||||||......|.....|||.|....|||.|.|...||||||");
		strcpy(cenario[5], "|.|.....||||||||.|.||....|.|.||||.|||||.|....|");
		strcpy(cenario[6], "|...|||.||||||||.|.|..|||||||||||.....|...|.||");
		strcpy(cenario[7], "|.|...|....|.......|.||.....|....||||.|.|.|.||");
		strcpy(cenario[8], "|.|||.|.||||.|||.|.|.||.|||.||.|....|.|.|.|.||");
		strcpy(cenario[9], "|...|.||.....|||.|...||.|.|.||.||||||.|.|.||||");
		strcpy(cenario[10], "||.||.||.|.|||||.||||||.|.|.||........|......|");
		strcpy(cenario[11], "||.||....|.|.|...||.....|.|.||.||.|||||.||||||");
		strcpy(cenario[12], "|....|.|||.|.|.||||.|||||.|.|||||.||.........|");
		strcpy(cenario[13], "|.|||...|..|.|......|.....|.||....||.|.|||||||");
		strcpy(cenario[14], "|.|.||.||.|..||||.||..|.|||.||.||.||.|.||.||||");
		strcpy(cenario[15], "|.|....||...|||......||...|....||....|.......|");
		strcpy(cenario[16], "||||||||||||||||||||||||||||||||||||||||||||||");
		break;
	}
}

void exibirCen(int x, int y)
{
	system("cls"); // Adicionando a limpeza de tela
	int i, j;

	for (i = 0; i < altura; i++)
	{
		for (j = 0; j < largura; j++)
		{
			if (i == y && j == x)
			{
				printf(":)");
			}
			else
			{
				printf("%c", cenario[i][j]);
			}
		}
		printf("\n");
	}
}

void andar(int *x, int *y)
{
	char move;
	int auxX = *x, auxY = *y;
	while (1)
	{
		move = getch();
		switch (move)
		{
		case 'w':
			if (auxX >= 0 && auxX < largura && auxY >= 0 && auxY < altura && cenario[auxY - 1][auxX] != '|')
			{
				auxY--;
			}
			break;
		case 's':
			if (auxX >= 0 && auxX < largura && auxY >= 0 && auxY < altura && cenario[auxY + 1][auxX] != '|')
			{
				auxY++;
			}
			break;
		case 'a':
			if (auxX >= 0 && auxX < largura && auxY >= 0 && auxY < altura && cenario[auxY][auxX - 1] != '|')
			{
				auxX--;
			}
			break;
		case 'd':
			if (auxX >= 0 && auxX < largura && auxY >= 0 && auxY < altura && cenario[auxY][auxX + 1] != '|')
			{
				auxX++;
			}
			break;
		case 'q':
			close();
			return; // Adicionando retorno para sair do loop
		default:
			break;
		}

		if (auxX >= 0 && auxX < largura && auxY >= 0 && auxY < altura && cenario[auxY][auxX] != '|')
		{
			gotoxy(*x, *y);
			printf(". ");

			gotoxy(auxX, auxY);
			*x = auxX;
			*y = auxY;
			printf(":)");
		}
		else
		{
		}

		if (auxX == fimX && auxY == fimY) break;
	}
}

/*void close()
{
	printf("\nQue pena, você desistiu do jogo!\n");
}*/

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void jogar(int nivel)
{
	int x, y;

	switch (nivel)
	{
	case 0:
		x = 1;
		y = 1;
		fimX = 24;
		fimY = 9;
		break;
	case 1:
		x = 1;
		y = 1;
		fimX = 31;
		fimY = 9;
		break;
	case 2:
		x = 1;
		y = 1;
		fimX = 40;
		fimY = 12;
		break;
	case 3:
		x = 1;
		y = 1;
		fimX = 40;
		fimY = 1;
		break;
	case 4:
		x = 1;
		y = 8;
		fimX = 45;
		fimY = 1;
		break;
	}

	criarCen(nivel);
	exibirCen(x, y);
	printf("Pontuação: %d  | Jogador: %s\n Para mover, utilize o modo WASD(^<v>). Aperte q para sair.", pontos, jogador);
	andar(&x, &y);

	printf("Outro nivel porra");
	system("pause");
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int nivel = 0;
	printf("Olá, jogador(a)! Digite seu nickname: ");
	scanf("%s", jogador);

	jogar(nivel);

	return 0;
}