#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string


int registro() //função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	//string é uma variável que representa um conjunto de caracteres do tipo texto
	
	printf("Digite o CPF a ser cadastrado: "); //"printf" responsável pela conversa
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria arquivo
	file = fopen(arquivo, "w"); //cria arquivo  // "W" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //("")responsavel pelo comentário
	scanf("%s", nome); //"scanf" responsável por escanear o que o usuário coloca
	
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
	printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
	
	}
	
	system("pause");
	
	
}
int deletar()
{
	char cpf[40]; //"char" variável que representa um caractere do tipo texto
	
	printf("Digite o CPF a ser deletado: "); //"printf"
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)  //"if" (SE ele for)//
	{
		printf("O usuário ja foi deletado, não se encontra no sistema!\n");
		system("pause");
		
	}
	
	
	
}

int main() //função principal do sistema 
{ //chaves

	int opcao=0; //Definindo variáveis
	int laco=1; //"int" variável número do tipo inteiro, positivo e negativo
	 
	for(laco=1;laco=1;)	
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Inícío do menu
		printf("Escolha a opção desejada no menu\n\n"); // '\n' pula linha
		printf("\t1 - Consultar nomes\n\n");  //"\t" responsavel pelo espaço antes da palavra
		printf("\t2 - Registrar nomes\n\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("opcao:"); //Fim do menu
	
	scanf("%d", &opcao); //armazenando a escolha do usuário 
	
	system("cls"); //responável por limpar a tela
	
	switch(opcao) //
	{
		case 1:
		registro(); //chamada de funções
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
		break;  //Fim da seleção
			
	}
	
	}
}





