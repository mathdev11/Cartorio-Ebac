#include<stdio.h> //bliblioteca de comunica��o de usu�rio
#include<stdlib.h> //bliblioteca de aloca��o de espa�o em memoria 
#include<locale.h> //blibloteca de aloca�ao de texto por regi�o
#include<string.h>//blibloteca responsavel por cuidar das strings

int registro()//fun��o respons�vel por cadastrar o �suario no sistem
{  //in�cio da cria��o de v�riaveis/string
   char arquivo [40];
   char cpf[40];
   char nome [40];
   char sobrenome[40];
   char cargo [40];
    //Final da cria��o de v�riaveis/string
     printf("Digite o CPF a ser cadastrado:   \n");//coletando informa��o do us�ario
     scanf("%s", cpf);//%s referece a strings
   
     strcpy(arquivo, cpf);//responsavel por copiar os valores das strings
   
     FILE *file; //cria o arquivo
     file = fopen(arquivo, "w");//criando o arquivo/ w siginifica escrever
     fprintf(file, cpf);//salvo o valor da variavel
     fclose(file);//fecha o armazenamento
   
     file = fopen(arquivo, "a");//responsavel pela atualiza��o de cadrastro
     fprintf(file,"\n");//\n � responsabel por pular uma linha
     fclose(file);//usado para encerrar/fechar o arquivo
     
   
     printf("Digite o nome a ser cadrastrado:   \n");//colentando informa��oes do usu�rio
     scanf("%s", nome);//%s usado nessa para localizar a variavel nome
   
     file = fopen(arquivo,"a");//respons�vel por abrir/ atualizar o arquivo
     fprintf(file,nome);//salvar o valor da variavel
     fclose(file);//fechar o arquvo 
   
     file = fopen(arquivo, "a");//abrir/atualizar o arquivo
     fprintf(file,"\n");//pular uma linha do arquivo
     fclose(file);//fechar o arquivo
          
     printf("Digite o sobrenome a ser cadastrado:   \n");//coletando informa��es do usuario
     scanf("%s", sobrenome);//%s resposavel pela coleta do sobrenome
   
     file = fopen(arquivo,"a");//atualiza��o do arquivo
     fprintf (file, sobrenome);//salvando o valor da variavel 
     fclose(file);// fechando o arquivo
   
     file = fopen(arquivo, "a");//atulaizar o arquivo
     fprintf(file,"\n");//pular uma linha no arquivo
     fclose(file);//encerrrar/fechar o arquivo
     
     printf("Digite o cargo a ser cadastrado:   \n");//coletar dados do usu�rio
     scanf("%s", cargo);//%s resposavel pela coleta do cargo 
   
     file = fopen(arquivo, "a");//atualiza��o do arquivo
     fprintf(file, cargo);//salvadon o valor da variavel
     fclose(file);//fechadno a variavel
   
     system("pause");//''func�o resposav�l para deixar a tela est�tica   	
}
int consulta ()//func�o responsav�l pela consulta 
{
   setlocale(LC_ALL, "Portuguese");//definindo a linguaguem do sistema
   //inicio da cria��o das variaves/strings
    char cpf[40];
    char conteudo[200];
   
      printf("Digite o cpf a ser consultado:  ");//recebendo qual usuario vai ser consultado
      scanf("%s",cpf);//%s resposavel pela coleta a char
   
      FILE *file;//criar o arquivo
      file = fopen(cpf,"r");//responsavel por abrir o arquivo/ r � read ( ler o contedudo do arquivo)
      system("cls");
	     
    if(file == NULL)// ''Se a op��o dor nula, aloca��o de resposta''
   {
	    printf("\nN�o foi poss�vel localizar esse arquivo, n�o localizado");//informar dados ao usuario
	    printf("\n\n");//responsavel por pular a linha 
	    system("pause");//mantem o sistema na pagina atual	  
   }  
   
    while(fgets(conteudo, 200, file) != NULL)//while � ''enquando o usuario est� escrevendo''
    {
    	printf("\nEssas s�o as informa��es do Usu�rio:  ");//coletar dados do usuario
    	printf("%s",conteudo);//%s resposavel pelo dado conteudo
    	printf("\n\n");//usado para pular a linha
    
    	
    	system("pause");//manter o sistema na pagina atual
	}



	
}
int deletar()
{   //inicio da cria�ao de variaveis 
	char cpf[40];
	
	printf("Digite o CPF do Usu�rio a ser deletado: ");//coletando dados do usuario
	scanf("%s", cpf);//%s usado para selecionar a variavel 
	
	remove(cpf);//deletar o dado 
	
	FILE *file;//criar o arquivo
	file = fopen(cpf, "r"); // abrir o arquivo/ r � de ''read''
	
	if(file == NULL) //variavel de ''n�o h� no sistema'' com dados 
	{
	   printf("Usu�rio n�o encontrado no sistema\n"); //resposta do sistema ao usuario
	   system("pause"); // manter na tela 
	}
}

int main()
{
    int opcao=0; //Definindo v�riaveis
    int laco=1;
    char senhadigitada[10]="a";
    int comparacao; 
    
    printf("### Cart�rio da EBAC ###\n\n");
    printf("Login de administrador!\n\nDigite sua senha: ");
    scanf("%s",senhadigitada);
    
    comparacao = strcmp(senhadigitada, "admin"); //strcmp � string de comparacao
    
    if(comparacao == 0)//func�o usada para o login 
    {
    	 system("cls");
	     for(laco=1;laco=1;)//se o usuario desejar sair � s� igualar a 0
         {
         
	      system("cls"); //resposavel por limpar a tela       	
	
	
	      setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	      printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	      printf("Escolha op��o desejada do menu:\n\n");
	      printf("\t1 - Regristrar nomes\n");
	      printf("\t2 - Consultar nomes\n");
	      printf("\t3 - Deletar nome\n");
	      printf("\t4 - Sair do sistema\n\n");
	      printf("Op��o:"); // Fim do menu
	
	      scanf("%d",  &opcao); // Armazenando a escolha do usu�rio
	
	      system("cls");//resposavel por limpar a tela 
	    
	        switch(opcao)//inicio da sele��o de menu
	       {
	     
		      case 1:
	          registro();//chamada de fun��es
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
	          printf("Essa opc�o n�o esta dispon�vel\n");
	          system("pause");
	          break;
           }  //fim da sele��o
       }
   }
    
    else
       printf("Senha incorreta!");
     
	
}

 

