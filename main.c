#include <stdio.h>
#include <string.h>
#include <locale.h>

#define altura 25
#define largura 50

char cenario[altura][largura], jogador[50];
int pontos=1000;

void criarCen(int nivel){
	switch(nivel){
		case 0:
			 strcpy(cenario[0], "|||||||||||||||||||||||||");
			 strcpy(cenario[1], "|..||||||||||||||||||||||");
			 strcpy(cenario[2], "||.||||||||||||||||||||||");
			 strcpy(cenario[3], "||.||||||||||||||||||||||");
			 strcpy(cenario[4], "||.||||||||||||||||||||||");
			 strcpy(cenario[5], "||.||||||||||||||||||||||");
			 strcpy(cenario[6], "||...........||||||||||||");
			 strcpy(cenario[7], "||||||||||||.||||||||||||");
			 strcpy(cenario[8], "||||||||||||.||||||||||||");
			 strcpy(cenario[9], "||||||||||||............|");
			strcpy(cenario[10], "|||||||||||||||||||||||||");
		break;
		case 1:
			 strcpy(cenario[0], "||||||||||||||||||||||||||||||||||||||||||||||||||");
			 strcpy(cenario[1], "|..|||||||||||||||||||||||||||||||||||||||||||||||");
			 strcpy(cenario[2], "||.|||||||||||||||||||||||||||||||||||||||||||||||");
			 strcpy(cenario[3], "||.|||||||||||||||||||||||||||||||||||||||||||||||");
			 strcpy(cenario[4], "||.|||||||||||||||||||||||||||||||||||||||||||||||");
			 strcpy(cenario[5], "||.|||||||||||||||||||||||||||||||||||||||||||||||");
			 strcpy(cenario[6], "||...........|||||||||||||||||||||||||||||||||||||");
			 strcpy(cenario[7], "||||||||||||.|||||||||||||||||||||||||||||||||||||");
			 strcpy(cenario[8], "||||||||||||.|||||||||||||||||||||||||||||||||||||");
			 strcpy(cenario[9], "||||||||||||.|||||||||||||||||||||||||||||||||||||");
			strcpy(cenario[10], "||||||||||||...........................|||||||||||");
			strcpy(cenario[11], "||||||||||||||||||||||||||||||||||||||.|||||||||||");
			strcpy(cenario[12], "||||||||||||||||||||||||||||||||||||||...........|");
			strcpy(cenario[13], "||||||||||||||||||||||||||||||||||||||||||||||||.|");
			strcpy(cenario[14], "||||||||||||||||||||||||||||||||||||||||||||||||||");
		break;
	}
}

void exibirCen(int x, int y){
	system("cls");
	int i, j;
	
	for(i=0; i<altura; i++){
		for(j=0; j<largura; j++){
			if(i==y && j==x){
				printf(":)");
			}else{
				printf(" %c", cenario[i][j]);
			}
		}
		printf("\n");
	}
}

int moverJogador(int *x, int *y, char move){
	int auxX=*x, auxY=*y;
	
	switch(move){
		case 'w': auxY--; break;
		case 's': auxY++; break;
		case 'a': auxX--; break;
		case 'd': auxX++; break;
		default: return 0;
	}
	
	if(auxX>=0 && auxX<largura && auxY>=0 && auxY<altura && cenario[auxY][auxX]=='.'){
		*x=auxX;
		*y=auxY;
		
		return 1;
	}
	
	return 0;
}

void jogar(int nivel){
	char move;
	int x, y, fimX, fimY;
iniciar:	switch(nivel){
				case 0: 
				x=1;
				y=1;
				fimX=23;
				fimY=9;
				break;
				case 1: 
				x=1;
				y=1;
				fimX=48;
				fimY=13;
				break;
			}
		
	while(nivel<5){
	criarCen(nivel);	
	exibirCen(x, y);
	printf("Pontua��o: %d  | Jogador: %s\n Para mover, utilize o modo WASD(^<v>). Aperte q para sair.", pontos, jogador);
	move = getch();
	if(move=='q'){
		printf("Que pena, voc� desistiu do jogo!\n");
		break;
	}
	if(moverJogador(&x, &y, move)){
		pontos--;
		if(x==fimX && y==fimY){
			printf("N�vel %d completo! Pontua��o final: %d", nivel+1, pontos);
			nivel++;
			goto iniciar;
		}
	}
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int nivel = 0;
	printf("Ol�, jogador(a)! Digite seu nickname: ");
	scanf(" %s", jogador);

	jogar(nivel);
		
	return 0;
}
