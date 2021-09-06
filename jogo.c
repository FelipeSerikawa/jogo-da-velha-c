//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Declaracao de variaveis e da matriz base do jogo
char jogo[3][3], jogador1[30], jogador2[30];
char jogador3[30] = "Computador";
int quemJoga = 1;
int modoDeJogo = 0, ganhador = 0;
int linhaGerada, colunaGerada;

//Construtor da matriz de inicializacao 
char matriz()
{
 	int i, j;
 	printf("   0 1 2\n");
 	
  for (i=0; i<3; i++)
 	{		
 		printf("%d ", i);
 		for (j=0; j<3; j++)
 		{
 		  printf("|");
 		  jogo[i][j] = '*';
 		  printf("%c", jogo[i][j]);
 		  if (j==2)
 		  {
 		    printf("|");
 	 	  }
 		}
 		 printf("\n");
	}
	return 0;
}

//Funcao que exibe o menu de escolha do modo de jogo
int menu()
{
	//Apresentação
	printf("\nBem Vindo ao jogo da velha Arandu!\n\n======================\nEscolha o modo de jogo\n======================\n");
	
	//Estrutura de repetição que limita o modo de jogo em 1 ou 2
	while (modoDeJogo<1 || modoDeJogo>2)
	{
	
		printf("\n[1] Jogador vs Jogador\n[2] Jogador vs Computador\n");
		printf("\nModo de jogo: ");
		scanf("%d", &modoDeJogo);
		if (modoDeJogo<1 || modoDeJogo>2)
		{
			system("clear");
			printf("Esse modo de jogo não existe, digite um modo válido\n");
		}
	}
	return 0;
}    

//Construtor da matriz do jogo (tabuleiro) 
char tabuleiro()
{
 	int linha, coluna;
 	printf("   0 1 2\n");
 	for (linha=0; linha<3; linha++)
 	{
 		printf("%d ", linha);
 		for (coluna=0; coluna<3; coluna++)
 		{
 		  printf("|");
 		  printf("%c", jogo[linha][coluna]);
 		  if (coluna==2)
 		  {
 		  	printf("|");
     	}
   	}
   	printf("\n");
 	}
 	return 0;
}
 
//Funcao que verifica se alguma linha da matriz do jogo possui o mesmo valor em sequencia
int verificaLinhas()
{
 	if (quemJoga == 1)
 	{
 	  if ((jogo[0][0] == 'x' && jogo[0][1] == 'x' && jogo[0][2] == 'x') || (jogo[1][0] == 'x' && jogo[1][1] == 'x' && jogo[1][2] == 'x') || (jogo[2][0] == 'x' && jogo[2][1] == 'x' && jogo[2][2] == 'x'))
 	  {
 	    ganhador = 1;
 	   	printf("\nO jogador %s venceu!\n", jogador1);
    }
 
  }
     
  if (quemJoga == 2)
  {
    if ((jogo[0][0] == 'o' && jogo[0][1] == 'o' && jogo[0][2] == 'o') || (jogo[1][0] == 'o' && jogo[1][1] == 'o' && jogo[1][2] == 'o') || (jogo[2][0] == 'o' && jogo[2][1] == 'o' && jogo[2][2] == 'o'))
    {
     	ganhador = 2;
     	if (modoDeJogo==1)
 	   	{
 	   		printf("\nO jogador %s venceu!\n", jogador2);
 	   	}
 	   	else
 	   	{
 	   		printf("\nO Computador venceu!\n");
 	   	}
    } 
  }
  return 0;
}
 
//Funcao que verifica se alguma coluna da matriz do jogo possui o mesmo valor em sequencia 
int verificaColunas()
{
 	if (quemJoga == 1)
 	{
 	  if ((jogo[0][0] == 'x' && jogo[1][0] == 'x' && jogo[2][0] == 'x') || (jogo[0][1] == 'x' && jogo[1][1] == 'x' && jogo[2][1] == 'x') || (jogo[0][2] == 'x' && jogo[1][2] == 'x' && jogo[2][2] == 'x'))
 	  {
 	   	ganhador = 1;
 	   	printf("\nO jogador %s venceu!\n", jogador1);
    }
	}
 
	if (quemJoga == 2)
	{
	  if ((jogo[0][0] == 'o' && jogo[1][0] == 'o' && jogo[2][0] == 'o') || (jogo[0][1] == 'o' && jogo[1][1] == 'o' && jogo[2][1] == 'o') || (jogo[0][2] == 'o' && jogo[1][2] == 'o' && jogo[2][2] == 'o'))
	  {
	    ganhador = 2;
	    if (modoDeJogo==1)
 	   	{
 	   		printf("\nO jogador %s venceu!\n", jogador2);
 	   	}
 	   	else
 	   	{
 	   		printf("\nO Computador venceu!\n");
 	   	}
	  }
	}
	return 0;
}
 
//Funcao que verifica se alguma diagonal da matriz do jogo possui o mesmo valor em sequencia 
int verificaDiagonais()
{
 	if (quemJoga == 1)
 	{
 	  if ((jogo[0][0] == 'x' && jogo[1][1] == 'x' && jogo[2][2] == 'x') || (jogo[2][0] == 'x' && jogo[1][1] == 'x' && jogo[0][2] == 'x'))
 	  {
 	    ganhador = 1;
 	   	printf("\nO jogador %s venceu!\n", jogador1);
 	  }
 	}
 	
 	if (quemJoga == 2)
 	{
 	  if ((jogo[0][0] == 'o' && jogo[1][1] == 'o' && jogo[2][2] == 'o') || (jogo[2][0] == 'o' && jogo[1][1] == 'o' && jogo[0][2] == 'o'))
 	  {
 	  ganhador = 2;
 	  if (modoDeJogo==1)
 	   	{
 	   		printf("\nO jogador %s venceu!\n", jogador2);
 	   	}
 	  else
 	   	{
 	   		printf("\nO Computador venceu!\n");
 	   	}
 	   	
    }
 	}
 	return 0;
}

//Funcao para gerar um valor para linha e coluna de forma randômica
int gerarCoordenada()
{
	linhaGerada = rand() % 3;
	colunaGerada = rand() % 3;
	return 0;
} 
       
//Parte principal, a qual iniciará todas as funcionalidades do algoritmo      
int main(void)
{
 	int linha, coluna;
 	int jogadas = 0;
	 
	 //Definicao dos jogadores e carregamento da matriz base
	menu();
	system("clear");
	printf("\nJogador 1: ");
	scanf("%s", jogador1);
	if (modoDeJogo == 1)
	{
	  printf("Jogador 2: ");
	 	scanf("%s", jogador2);
	}	 
	matriz();
	 
	//Estrutura de repeticao que alterna os jogadores durante a partida
	while(ganhador == 0)
	{
	  if (quemJoga == 1)
	  {
	    printf("\nVez de %s!\n", jogador1);
   		printf("Linha: ");
    	scanf("%d", &linha);
    		
    	//Se o jogador digitar uma linha diferente do intervalo permitido, uma mensagem será exibida e o jogador digitará novamente
    	while (linha<0 || linha>2)
    	{
    		printf("\nJogada invalida!\n");
    		printf("\nA linha %d nao existe, tente novamente!\n", linha);
    		printf("Linha: ");
    		scanf("%d", &linha);
     	}
     	   
     	printf("Coluna: ");
     	scanf("%d", &coluna);
     	   
     	//Se o jogador digitar uma coluna diferente do intervalo permitido, uma mensagem será exibida e o jogador digitará novamente
     	while (coluna<0 || coluna>2)
     	  {
     		  printf("\nJogada invalida!\n");
     			printf("\nA coluna %d nao existe, tente novamente!\n", coluna);
    		 	printf("Coluna: ");
 		    	scanf("%d", &coluna);
    		}
    		 
    		//Se o jogador digitar uma coordenada já inserida anteriormente, uma mensagem será exibida e pedirá para que ele insira uma outra linha e coluna
    		if (jogo[linha][coluna] != '*')
    		{
     			printf("Erro: a coordenada (%d, %d) já foi utilizada! Escolha uma outra casa.\n", linha, coluna);
     			continue;
     		}
     		
     		//Caso tudo ocorra sem problemas, a coordenada receberá o valor 'x' do jogador 1
     		jogo[linha][coluna] = 'x';
     		
     		//O console é limpo e o tabuleiro atualizado. Ocorre uma verificação se há um ganhador
     		system("clear");
		    tabuleiro();
		    verificaLinhas();
		    verificaColunas();
		    verificaDiagonais();
		     
     		//Se a verificação retornar um ganhador, o programa será encerrado
     		if (ganhador == 1)
     		{
     			break;
     		}
     		//Se ainda não houver um ganhador, a vez passa para o oponente
     		quemJoga = 2;
     	}
     	
    else if(quemJoga == 2)
    {
     	if (modoDeJogo==1)
     	{
     		printf("\nVez de %s!\n", jogador2);
     		printf("Linha: ");
   			scanf("%d", &linha);
   			//Se o jogador digitar uma linha diferente do intervalo permitido, uma mensagem será exibida e o jogador digitará novamente
   		  while (linha<0 || linha>2)
   		  {
   		  	printf("\nJogada invalida!\n");
   		  	printf("\nA linha %d nao existe, tente novamente!\n", linha);
     			printf("Linha: ");
     			scanf("%d", &linha);
     		}
      	printf("Coluna: ");
    		scanf("%d", &coluna);
    		 
    		//Se o jogador digitar uma coluna diferente do intervalo permitido, uma mensagem será exibida e o jogador digitará novamente
 		    while (coluna<0 || coluna>2)
 		    {
     			printf("\nJogada invalida!\n");
  		   	printf("\nA coluna %d nao existe, tente novamente!\n", coluna);
   		  	printf("Coluna: ");
		     	scanf("%d", &coluna);
		    }
		     
		    //Se o jogador digitar uma coordenada já inserida anteriormente, uma mensagem será exibida e pedirá para que ele insira uma outra linha e coluna
		    if (jogo[linha][coluna] != '*')
		    {
     			printf("Erro: a coordenada (%d, %d) já foi utilizada! Escolha uma outra casa.\n", linha, coluna);
     			continue;
     		}
     		
     		//Caso tudo ocorra sem problemas, a coordenada receberá o valor 'o' do jogador 2
     		jogo[linha][coluna] = 'o';     			  
     	}
     		
     		//Se o jogador estiver jogando contra o Computador, o algoritmo irá chamar a funcao gerarCoordenada enquanto a combinacao linha-coluna for inválida
     	else
     	{
     		printf("\nVez de Computador\n");
     		printf("\nO Computador está jogando...\n");
     		system("sleep 04");
     		while (jogo[linhaGerada][colunaGerada] != '*')
     		{
     			gerarCoordenada();
     		}
     			
     		jogo[linhaGerada][colunaGerada] = 'o';
     			    			     			
     	}     				          		  
     		
     	//O console é limpo e o tabuleiro atualizado. Ocorre uma verificação se há um ganhador
     	system("clear");
		  tabuleiro();
  		verificaLinhas();
		  verificaColunas();
		  verificaDiagonais();
		     
		  //Se a verificação retornar um ganhador, o programa será encerrado
		  if (ganhador == 2)
		  {
       	break;
	 		}
	 		//Se ainda não houver um ganhador, a vez passa para o oponente
	 		quemJoga = 1;
	 	}
	 	jogadas+=1;

	 	//Caso todas as casas se esgotem e nenhum jogador ganhe, a partida será encerrada com um empate
	 	if (jogadas == 9)
	 	{
	 		printf("\nO jogo acabou! Nenhum jogador venceu!\n");
	 		break;
	 	}
	}
  printf("\nObrigado por jogar!\n");	    
	return 0;
}
//Fim do programa
