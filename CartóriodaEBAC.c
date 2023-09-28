#include <stdio.h>//biblioteca de comunica��o com o usu�rio.
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria.
#include <locale.h>//biblioteca de aloca��o de textos por regi�o.
#include <string.h>//biblioteca responsavel por cuidar das string.


int registro()//fun��o respos�vel pelo registro. 
{
	//inicio de cria��o de variaveis/string.
	char arquivo[500];
	char cpf[200];
	char nome[400];
	char sobrenome[400];
	char cargo[500]; 
	//final de cria��o de variaveis/string.
	
	printf("Digite o CPF que ser� cadastrado: ");//coletando informa��o do usu�rio.
	scanf("%s",cpf);//salva o cpf do usuario/ %s se refere a string.
	
	strcpy(arquivo,cpf);//respons�vel por copiar os valores das string.
	
	FILE *file;//cria o arquivo.
	file=fopen(arquivo , "w");//cria o arquivo/ "w" significa escrever.
	fprintf(file , cpf);//salva o valor da vari�vel no arquivo.
	fclose(file);//fecha o arquivo.
	
	file=fopen(arquivo , "a");//abre o arquivo./"a" significa atualiza��o.
	fprintf(file , ",");//separa��o entre as informa��es.
	fclose(file);//fecha o arquivo.
	
	printf("Digite o NOME que ser� cadastrado: ");//mensagen de comunica��o com o usu�rio.
	scanf("%s" , nome);//salva na variavel.
	
	file=fopen(arquivo , "a");//abre o arquivo e faz atualiza��o.
	fprintf(file , nome);//salva variavel dentro do arquivo a ser atualizado.
	fclose(file);//fecha o arquivo
	
	file=fopen(arquivo , "a");//atualiza��o.
	fprintf(file , ",");
	fclose(file);
	
	printf("Digite o SOBRENOME a ser cadastrado:");
	scanf("%s" , sobrenome);
	
	file=fopen(arquivo , "a");//atualiza��o.
	fprintf(file , sobrenome);
	fclose(file);
	
	file=fopen(arquivo , "a");//atualiza��o.
	fprintf(file , ",");
	fclose(file);
	
	printf("Digite o CARGO a ser cadastrado :");
	scanf("%s" , cargo);
	
	file=fopen(arquivo , "a");//atualiza��o.
	fprintf(file , cargo);
	fclose(file);
	
	file=fopen(arquivo , "a");
	fprintf(file , ",");
	fclose(file);
	
	system("pause");//pausa tela para leitura e aguardar o proximo comando.
	
}

int consultar()
{
	setlocale(LC_ALL,"portuguese");//definindo a linguagem. 
	
	char cpf[200];
	char conteudo[500];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s" , cpf);
	
	FILE *file;//encontrar o arquivo.
	file=fopen(cpf , "r");
	
	
	if(file == NULL)//se n�o encontrar o arquivo.
	{
		printf("N�o foi possivel encontrar o arquivo.\n");
	}
	
	printf("\nEssas s�o as informa��es do usu�rio:");
			
	while(fgets(conteudo , 500 , file) != NULL)
	{
		printf("\n\n\t%s" ,conteudo);
		printf("\n\n");
	}
	fclose(file);	
	system("pause");

}

int deletar()
{	
	char cpf [200];
	
	printf("\tDigite o CPF que deseja deletar: \n\n");
	scanf("%s" , cpf);
	
	remove(cpf);
	
	FILE *file;
	file =fopen(cpf , "r");
	
	if(file == NULL);
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
	
}


int main()
{
	int opcao=0;//Definindo vari�veis.
	int laco=1;//Vari�vel de la�o de repeti��o.
	
	for(laco=1;laco=1;)//instru��es.
	{
	
		
		system("cls");//limpa tela.
		
		setlocale(LC_ALL,"portuguese");//definindo a linguagem. 
	
   
		printf("### CART�RIO DA EBAC ###\n\n"); //in�cio do menu.
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("op��o: ");//fim do menu.
		
   		
		scanf("%d", &opcao); //armazenando a escolha do usu�rio.
   		
		system("cls");//limpa tela.
   		
   		switch(opcao)//estrutura de se..
   		{
   			//chamda de fun��es.
			case 1:
			registro();
			break;
			
				
			case 2:
			consultar();
			break;
			
			
			case 3:	
			deletar();
			break;
			
			
			
			
			default:
			printf("Essa op��o n�o existe.\n\n");//mensagen ao usu�rio.
			system("pause");//pausa na tela para leitura.
			break;
				
		}//fim da sele��o
	}
}
	

