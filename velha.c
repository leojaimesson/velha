#include <stdio.h>
#include <stdlib.h>

//pacote com variaveis
struct variaveis{
	int validacao;
	int l;
	int c;
	int rodadas;
	int empate;
};
//funcao que mostra quem venceu
int vencedor(char matriz[][3], char *c){
	if((matriz[0][0] == c[0] && matriz[0][1] == c[0] && matriz[0][2] == c[0]) || (matriz[1][0] == c[0] && matriz[1][1] == c[0] && matriz[1][2]== c[0]) || (matriz[2][0] == c[0] && matriz[2][1] == c[0] && matriz[2][2] == c[0]))
		return 0;	
	if((matriz[0][0] == c[0] && matriz[1][0] == c[0] && matriz[2][0] == c[0]) || (matriz[0][1] == c[0] && matriz[1][1] == c[0] && matriz[2][1]== c[0]) || (matriz[0][2] == c[0] && matriz[1][2] == c[0] && matriz[2][2] == c[0]))
		return 0;
	if((matriz[0][0] == c[0] && matriz[1][1] == c[0] && matriz[2][2] == c[0]) || (matriz[0][2] == c[0] && matriz[1][1] == c[0] && matriz[2][0] == c[0]))
		return 0;
	return 1;
}
//funcao principal
int main(){
	
	system("clear");
	struct variaveis v;
	v.validacao = 1;
	v.rodadas = 1;
	v.empate = 0;
	char matriz[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
	char caracteri[1];

	//laco que faz o jogo funcionar
	while(v.validacao == 1){
		printf("digite a linha e a coluna\n\n");
		printf("%c | %c | %c\n%c | %c | %c\n%c | %c | %c\n\n",matriz[0][0],matriz[0][1],matriz[0][2],matriz[1][0],matriz[1][1],matriz[1][2],matriz[2][0],matriz[2][1],matriz[2][2]);
		scanf("%d %d",&v.l,&v.c);
	
		//verifica se a matriz ja esta preenchida
		if(matriz[v.l-1][v.c-1] == '-'){
			if(v.rodadas % 2 != 0){
				matriz[v.l-1][v.c-1] = 'x';
				caracteri[0] = 'x';			
				v.validacao = vencedor(matriz,caracteri);
				
				if(v.validacao == 0){
					printf("o 'x' ganhou!!!\n\n");
				}
				v.rodadas++;
				v.empate++;
			}
			else{
				matriz[v.l-1][v.c-1] = 'o';
				caracteri[0] = 'o';			
				v.validacao = vencedor(matriz,caracteri);
				
				if(v.validacao == 0){
					printf("o 'o' ganhou!!!\n\n");
				}
				v.rodadas++;
				v.empate++;
			}
			
			if(v.empate == 9){
				v.validacao = 0;
				printf("jogo empatado\n\n");
			}
			
			if(v.validacao == 0){
				printf("jogar novamente? 1 = sim | 0 = nao\n");
				scanf("%d",&v.validacao);
				if (v.validacao == 1)
				main();
			}
		}
	}
	return 0;
}