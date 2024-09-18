#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string


int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	//string � uma vari�vel que representa um conjunto de caracteres do tipo texto
	
	printf("Digite o CPF a ser cadastrado: "); //"printf" respons�vel pela conversa
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria arquivo
	file = fopen(arquivo, "w"); //cria arquivo  // "W" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //("")responsavel pelo coment�rio
	scanf("%s", nome); //"scanf" respons�vel por escanear o que o usu�rio coloca
	
	file = fopen(arquivo, "a"); //"fopen" abrir arquivo
	fprintf(file,nome); //
	fclose(file); //"fclose" fechar arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
	
}

int consultar()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //'r'ler arquivo
	
	if(file == NULL)
	{
	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
	
	}
	
	system("pause");
	
	
}
int deletar()
{
	char cpf[40]; //"char" vari�vel que representa um caractere do tipo texto
	
	printf("Digite o CPF a ser deletado: "); //"printf"
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)  //"if" (SE ele for)//
	{
		printf("O usu�rio ja foi deletado, n�o se encontra no sistema!\n");
		system("pause");
		
	}
	
	
	
}

int main() //fun��o principal do sistema 
{ //chaves

	int opcao=0; //Definindo vari�veis
	int laco=1; //"int" vari�vel n�mero do tipo inteiro, positivo e negativo
	 
	for(laco=1;laco=1;)	
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�c�o do menu
		printf("Escolha a op��o desejada no menu\n\n"); // '\n' pula linha
		printf("\t1 - Consultar nomes\n\n");  //"\t" responsavel pelo espa�o antes da palavra
		printf("\t2 - Registrar nomes\n\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("opcao:"); //Fim do menu
	
	scanf("%d", &opcao); //armazenando a escolha do usu�rio 
	
	system("cls"); //respon�vel por limpar a tela
	
	switch(opcao) //
	{
		case 1:
		registro(); //chamada de fun��es
		break;
		
		case 2:	
		consultar();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar nosso sistema!\n");
		return 0;
		break;
		
		
		default:
		printf("Essa opcao nao esta disponivel!");
		system("pause");
		break;  //Fim da sele��o
			
	}
	
	}
}





