#include <stdio.h>//biblioteca de comunicação com o usuário.
#include <stdlib.h>//biblioteca de alocação de espaço em memória.
#include <locale.h>//biblioteca de alocação de textos por região.
#include <string.h>//biblioteca responsavel por cuidar das string.


int registro()//função resposável pelo registro. 
{
	//inicio de criação de variaveis/string.
	char arquivo[500];
	char cpf[200];
	char nome[400];
	char sobrenome[400];
	char cargo[500]; 
	//final de criação de variaveis/string.
	
	printf("Digite o CPF que será cadastrado: ");//coletando informação do usuário.
	scanf("%s",cpf);//salva o cpf do usuario/ %s se refere a string.
	
	strcpy(arquivo,cpf);//responsável por copiar os valores das string.
	
	FILE *file;//cria o arquivo.
	file=fopen(arquivo , "w");//cria o arquivo/ "w" significa escrever.
	fprintf(file , cpf);//salva o valor da variável no arquivo.
	fclose(file);//fecha o arquivo.
	
	file=fopen(arquivo , "a");//abre o arquivo./"a" significa atualização.
	fprintf(file , ",");//separação entre as informações.
	fclose(file);//fecha o arquivo.
	
	printf("Digite o NOME que será cadastrado: ");//mensagen de comunicação com o usuário.
	scanf("%s" , nome);//salva na variavel.
	
	file=fopen(arquivo , "a");//abre o arquivo e faz atualização.
	fprintf(file , nome);//salva variavel dentro do arquivo a ser atualizado.
	fclose(file);//fecha o arquivo
	
	file=fopen(arquivo , "a");//atualização.
	fprintf(file , ",");
	fclose(file);
	
	printf("Digite o SOBRENOME a ser cadastrado:");
	scanf("%s" , sobrenome);
	
	file=fopen(arquivo , "a");//atualização.
	fprintf(file , sobrenome);
	fclose(file);
	
	file=fopen(arquivo , "a");//atualização.
	fprintf(file , ",");
	fclose(file);
	
	printf("Digite o CARGO a ser cadastrado :");
	scanf("%s" , cargo);
	
	file=fopen(arquivo , "a");//atualização.
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
	
	
	if(file == NULL)//se não encontrar o arquivo.
	{
		printf("Não foi possivel encontrar o arquivo.\n");
	}
	
	printf("\nEssas são as informações do usuário:");
			
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
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
	
}


int main()
{
	int opcao=0;//Definindo variáveis.
	int laco=1;//Variável de laço de repetição.
	
	for(laco=1;laco=1;)//instruções.
	{
	
		
		system("cls");//limpa tela.
		
		setlocale(LC_ALL,"portuguese");//definindo a linguagem. 
	
   
		printf("### CARTÓRIO DA EBAC ###\n\n"); //início do menu.
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("opção: ");//fim do menu.
		
   		
		scanf("%d", &opcao); //armazenando a escolha do usuário.
   		
		system("cls");//limpa tela.
   		
   		switch(opcao)//estrutura de se..
   		{
   			//chamda de funções.
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
			printf("Essa opção não existe.\n\n");//mensagen ao usuário.
			system("pause");//pausa na tela para leitura.
			break;
				
		}//fim da seleção
	}
}
	

