#include<stdio.h> //bliblioteca de comunicação de usuário
#include<stdlib.h> //bliblioteca de alocação de espaço em memoria 
#include<locale.h> //blibloteca de alocaçao de texto por região
#include<string.h>//blibloteca responsavel por cuidar das strings

int registro()//função responsável por cadastrar o úsuario no sistem
{  //início da criação de váriaveis/string
   char arquivo [40];
   char cpf[40];
   char nome [40];
   char sobrenome[40];
   char cargo [40];
    //Final da criação de váriaveis/string
     printf("Digite o CPF a ser cadastrado:   \n");//coletando informação do usúario
     scanf("%s", cpf);//%s referece a strings
   
     strcpy(arquivo, cpf);//responsavel por copiar os valores das strings
   
     FILE *file; //cria o arquivo
     file = fopen(arquivo, "w");//criando o arquivo/ w siginifica escrever
     fprintf(file, cpf);//salvo o valor da variavel
     fclose(file);//fecha o armazenamento
   
     file = fopen(arquivo, "a");//responsavel pela atualização de cadrastro
     fprintf(file,"\n");//\n é responsabel por pular uma linha
     fclose(file);//usado para encerrar/fechar o arquivo
     
   
     printf("Digite o nome a ser cadrastrado:   \n");//colentando informaçãoes do usuário
     scanf("%s", nome);//%s usado nessa para localizar a variavel nome
   
     file = fopen(arquivo,"a");//responsável por abrir/ atualizar o arquivo
     fprintf(file,nome);//salvar o valor da variavel
     fclose(file);//fechar o arquvo 
   
     file = fopen(arquivo, "a");//abrir/atualizar o arquivo
     fprintf(file,"\n");//pular uma linha do arquivo
     fclose(file);//fechar o arquivo
          
     printf("Digite o sobrenome a ser cadastrado:   \n");//coletando informações do usuario
     scanf("%s", sobrenome);//%s resposavel pela coleta do sobrenome
   
     file = fopen(arquivo,"a");//atualização do arquivo
     fprintf (file, sobrenome);//salvando o valor da variavel 
     fclose(file);// fechando o arquivo
   
     file = fopen(arquivo, "a");//atulaizar o arquivo
     fprintf(file,"\n");//pular uma linha no arquivo
     fclose(file);//encerrrar/fechar o arquivo
     
     printf("Digite o cargo a ser cadastrado:   \n");//coletar dados do usuário
     scanf("%s", cargo);//%s resposavel pela coleta do cargo 
   
     file = fopen(arquivo, "a");//atualização do arquivo
     fprintf(file, cargo);//salvadon o valor da variavel
     fclose(file);//fechadno a variavel
   
     system("pause");//''funcão resposavél para deixar a tela estática   	
}
int consulta ()//funcão responsavél pela consulta 
{
   setlocale(LC_ALL, "Portuguese");//definindo a linguaguem do sistema
   //inicio da criação das variaves/strings
    char cpf[40];
    char conteudo[200];
   
      printf("Digite o cpf a ser consultado:  ");//recebendo qual usuario vai ser consultado
      scanf("%s",cpf);//%s resposavel pela coleta a char
   
      FILE *file;//criar o arquivo
      file = fopen(cpf,"r");//responsavel por abrir o arquivo/ r é read ( ler o contedudo do arquivo)
      system("cls");
	     
    if(file == NULL)// ''Se a opção dor nula, alocação de resposta''
   {
	    printf("\nNão foi possível localizar esse arquivo, não localizado");//informar dados ao usuario
	    printf("\n\n");//responsavel por pular a linha 
	    system("pause");//mantem o sistema na pagina atual	  
   }  
   
    while(fgets(conteudo, 200, file) != NULL)//while é ''enquando o usuario está escrevendo''
    {
    	printf("\nEssas são as informações do Usuário:  ");//coletar dados do usuario
    	printf("%s",conteudo);//%s resposavel pelo dado conteudo
    	printf("\n\n");//usado para pular a linha
    
    	
    	system("pause");//manter o sistema na pagina atual
	}



	
}
int deletar()
{   //inicio da criaçao de variaveis 
	char cpf[40];
	
	printf("Digite o CPF do Usuário a ser deletado: ");//coletando dados do usuario
	scanf("%s", cpf);//%s usado para selecionar a variavel 
	
	remove(cpf);//deletar o dado 
	
	FILE *file;//criar o arquivo
	file = fopen(cpf, "r"); // abrir o arquivo/ r é de ''read''
	
	if(file == NULL) //variavel de ''não há no sistema'' com dados 
	{
	   printf("Usuário não encontrado no sistema\n"); //resposta do sistema ao usuario
	   system("pause"); // manter na tela 
	}
}

int main()
{
    int opcao=0; //Definindo váriaveis
    int laco=1;
    char senhadigitada[10]="a";
    int comparacao; 
    
    printf("### Cartório da EBAC ###\n\n");
    printf("Login de administrador!\n\nDigite sua senha: ");
    scanf("%s",senhadigitada);
    
    comparacao = strcmp(senhadigitada, "admin"); //strcmp é string de comparacao
    
    if(comparacao == 0)//funcão usada para o login 
    {
    	 system("cls");
	     for(laco=1;laco=1;)//se o usuario desejar sair é só igualar a 0
         {
         
	      system("cls"); //resposavel por limpar a tela       	
	
	
	      setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	      printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
	      printf("Escolha opção desejada do menu:\n\n");
	      printf("\t1 - Regristrar nomes\n");
	      printf("\t2 - Consultar nomes\n");
	      printf("\t3 - Deletar nome\n");
	      printf("\t4 - Sair do sistema\n\n");
	      printf("Opção:"); // Fim do menu
	
	      scanf("%d",  &opcao); // Armazenando a escolha do usuário
	
	      system("cls");//resposavel por limpar a tela 
	    
	        switch(opcao)//inicio da seleção de menu
	       {
	     
		      case 1:
	          registro();//chamada de funções
	          break;
	    
	
	          case 2:
	          consulta();
              break;
	    
		      case 3:
		      deletar();
	          break; 
	        
	          case 4: 
	          printf("Obrigado por utilizar o sistema!\n");
	          return 0;//faz o usuario sair do sistema = 0
	          break;
	        	    
	          default:
	          printf("Essa opcão não esta disponível\n");
	          system("pause");
	          break;
           }  //fim da seleção
       }
   }
    
    else
       printf("Senha incorreta!");
     
	
}

 

