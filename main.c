#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

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
    system("cls");
    int i, j;

    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            if (i == y && j == x)
            {
                printf("O");
            }
            else if (cenario[i][j] == '.')
            {
                printf(" ");
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
        case 'q':
        case 'Q':
        {
            while (1)
            {
                char resp;

                gotoxy(0, altura + 2);
                printf("Você tem certeza que deseja sair? Você perderá seu progresso. (s/n)\n");

                ocultarCursor(1);

                scanf(" %c", &resp);
                if (resp == 's' || resp == 'S')
                {
                    printf("\nQue pena, você desistiu do jogo!\n");
                    exit(0);
                }
                else if (resp != 'n' && resp != 'N')
                {
                    printf("Não entendi :O\n");
                    continue;
                }

                gotoxy(0, altura + 2);
                printf("                                                                    \n   ");
                ocultarCursor(0);
                break;
            }
        }
        break;
        case 'w':
        case 'W':
            if (auxY > 0 && cenario[auxY - 1][auxX] != '|')
            {
                auxY--;
                show();
            }
            break;
        case 's':
        case 'S':
            if (auxY < altura - 1 && cenario[auxY + 1][auxX] != '|')
            {
                auxY++;
                show();
            }
            break;
        case 'a':
        case 'A':
            if (auxX > 0 && cenario[auxY][auxX - 1] != '|')
            {
                auxX--;
                show();
            }
            break;
        case 'd':
        case 'D':
            if (auxX < largura - 1 && cenario[auxY][auxX + 1] != '|')
            {
                auxX++;
                show();
            }
            break;
        default:
            break;
        }

        if (auxX >= 0 && auxX < largura && auxY >= 0 && auxY < altura && cenario[auxY][auxX] != '|')
        {
            gotoxy(*x, *y);
            printf(" ");

            gotoxy(auxX, auxY);
            *x = auxX;
            *y = auxY;
            printf("O");
        }

        if (auxX == fimX && auxY == fimY)
        {
            gotoxy(0, altura-1);
            printf("Você alcançou o fim do nível!\n");
            system("pause");
            break;
        }
    }
}

void show()
{
    pontos--;
    gotoxy(11, altura);
    printf("%i ", pontos);
}

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
    printf("Pontuação: %d  | Jogador: %s | Nível: %d\nPara mover, utilize o modo WASD(^<v>). Aperte q para sair.\n", pontos, jogador, nivel + 1);
    andar(&x, &y);
}

void ocultarCursor(int check)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    // Obtém as informações atuais do cursor
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    // Define a visibilidade do cursor como FALSE para ocultá-lo
    if (check == 0)
        cursorInfo.bVisible = FALSE;
    else
        cursorInfo.bVisible = TRUE;
    // Aplica a configuração atualizada
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int nivel = 0;
    printf("Olá, jogador(a)! Digite seu nickname: ");
    scanf("%s", jogador);

    ocultarCursor(0);

    while (nivel < 5)
    {
        jogar(nivel);
        nivel++;
    }
    return 0;
}