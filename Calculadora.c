#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>


FILE *arq;

struct tpCalculadora {
    float n1; //primeiro número
    float n2; //número que soma, subtrai, multiplica ou divide o primeiro número ou o resultado da operação
    float resultado; //resultado parcial ou final da expressão
};

typedef struct tpCalculadora Calculadora;

void getComposta (float* p) {
	//lê o resultado na composta.txt
	if(*p == 07){
        arq = fopen ("composta.txt", "r");
  			if(arq != NULL)
  	 		{
     			 while( (fscanf(arq,"%f",&*p))!=EOF)
	  				fclose(arq); 
  			 }}
  		
}


void somar(int i) {
	
   Calculadora al;
   char string[200]; // para poder pegar a tudo que estar na parcial.txt para poder pôr entre parênteses
   char ch; //pega cada caractere da parcial.txt
   int j=0; //contador
   
    if(i==0){
		printf("Diga o primeiro número\n");
        scanf("%f", &al.n1);
		arq = fopen ("parcial.txt", "w"); //apaga tudo que está na parcial
   		if(arq != NULL)
      		fprintf(arq,"");
   		fclose(arq);}
        printf("Diga o número\n");
        scanf("%f",&al.n2);
        
        
        //recebe o resultado na composta.txt
		if(al.n2 == 07){  
		float l = al.n2;  
		float *p = &l;   				 	
    	getComposta(&l);
       	al.n2 = l;}
       	 	
        arq = fopen ("resultado.txt", "r"); //lê o resultado para poder continuar a expressão
   if(arq != NULL)
   {
      while( (fscanf(arq,"%f",&al.resultado))!=EOF)
	  	
      fclose(arq);
   }   
        
   // faz a operação de soma
   if(i==0) 
   al.resultado =  al.n1 + al.n2;
   else 
   al.resultado += al.n2; 		 

	// adiciona na parcial.txt
   arq = fopen ("parcial.txt", "a");
   if(arq == NULL)
      printf("Nao foi possivel abrir o arquivo\n");
   else
   	if(i==0)
      fprintf(arq,"%.2f + %.2f",al.n1, al.n2);
    else 
      fprintf(arq," + %.2f",al.n2);
   fclose(arq);
   
   //armazena o resultado
   arq = fopen ("resultado.txt", "w");
   		if(arq != NULL)
      		fprintf(arq,"%.2f",al.resultado);
   fclose(arq);
   
   j=0;
   //lê a parcial para mostrar a expressão parcial
   arq = fopen ("parcial.txt", "r");
   if(arq != NULL)
   {
      while( (ch=fgetc(arq))!=EOF){
      	string[j] = ch;
      	j++;
	  }    	
      fclose(arq);
   }
   printf("\nExpressão: %s = %.2f\n\n",string,al.resultado); 
}

void subtrair(int i) {
   Calculadora al;
   char string[200];
   char ch;
   int j=0; 
   
    if(i==0){
		printf("Diga o primeiro número\n");
        scanf("%f", &al.n1);
		arq = fopen ("parcial.txt", "w"); //apaga tudo que está na parcial.txt
   			if(arq != NULL)
      			fprintf(arq,"");
   			fclose(arq);}
        printf("Diga o número\n");
        scanf("%f",&al.n2);
           	
		 //recebe o resultado na composta.txt
		if(al.n2 == 07){  
		float l = al.n2;  
		float *p = &l;   				 	
    	getComposta(&l);
       	al.n2 = l;}
        
        //lê o resultado
        arq = fopen ("resultado.txt", "r");
   if(arq != NULL)
   {
      while( (fscanf(arq,"%f",&al.resultado))!=EOF)
	  	
      fclose(arq);
   }
   // faz a operação     
   if(i==0)
   al.resultado =  al.n1 - al.n2;
   else 
   al.resultado -= al.n2;		 
	
	//adiciona na parcial.txt
   arq = fopen ("parcial.txt", "a");
   if(arq == NULL)
      printf("Nao foi possivel abrir o arquivo\n");
   else
   	if(i==0)
      fprintf(arq,"%.2f - %.2f",al.n1, al.n2);
    else 
      fprintf(arq," - %.2f",al.n2);
   fclose(arq);
   
   //grava o resultado parcial
   arq = fopen ("resultado.txt", "w");
   		if(arq != NULL)
      		fprintf(arq,"%.2f",al.resultado);
   fclose(arq);
   
   j=0;
   //lê a parcial para poder mostrar a expressão parcial
   arq = fopen ("parcial.txt", "r");
   if(arq != NULL)
   {
      while( (ch=fgetc(arq))!=EOF){
      	string[j] = ch;
      	j++;
	  }    	
      fclose(arq);
   }
   printf("\nExpressão: %s = %.2f\n\n",string,al.resultado);  
}

void multiplicar(int i) {
   Calculadora al; 
   char string[200];
   char ch;
   int j=0;
    if(i==0){
		printf("Diga o primeiro número\n");
        scanf("%f", &al.n1);
		al.resultado = 1;
		arq = fopen ("parcial.txt", "w"); //apaga tudo que está na parcial.txt
   			if(arq != NULL)
      			fprintf(arq,"");
   		fclose(arq);}
        if (i!=0) al.n1 = 1; 
        printf("Diga o número\n");
        scanf("%f",&al.n2);
        
         //recebe o resultado na composta.txt
		if(al.n2 == 07){  
		float l = al.n2;  
		float *p = &l;   				 	
    	getComposta(&l);
       	al.n2 = l;}
        
        //lê o resultado
        arq = fopen ("resultado.txt", "r");
   if(arq != NULL)
   {
      while( (fscanf(arq,"%f",&al.resultado))!=EOF)
	  	
      fclose(arq);
   }
   //lê a parcial para colocá-la entre parênteses
   arq = fopen ("parcial.txt", "r");
   if(arq != NULL)
   {
      while( (ch=fgetc(arq))!=EOF){
      	string[j] = ch;
      	j++;
	  }    	
      fclose(arq);
   }
   //faz a operação
   if(i==0)
   al.resultado =  al.n1 * al.n2;
   else 
   al.resultado *= al.n2;
	//grava na parcial toda a expressão entre parênteses (só o primeiro, no caso)		 
	arq = fopen ("parcial.txt", "w");
   		if(arq != NULL)
   			if (i==0)
      			fprintf(arq,"%s",string);
      		else
      			fprintf(arq,"(%s",string);
   fclose(arq);
   // grava na parcial.txt com o parênteses final
   arq = fopen ("parcial.txt", "a");
   if(arq == NULL)
      printf("Nao foi possivel abrir o arquivo\n");
   else{
   	if(i==0)
      fprintf(arq,"%.2f * %.2f",al.n1, al.n2);
    else 
      fprintf(arq,") * %.2f",al.n2);
	}
   fclose(arq);
   
   //grava o resultado
   arq = fopen ("resultado.txt", "w");
   		if(arq != NULL)
      		fprintf(arq,"%.2f",al.resultado);
   fclose(arq);
   j=0;
   //lê a parcial para poder mostrar a expressão parcial
   arq = fopen ("parcial.txt", "r");
   if(arq != NULL)
   {
      while( (ch=fgetc(arq))!=EOF){
      	string[j] = ch;
      	j++;
	  }    	
      fclose(arq);
   }
  printf("\nExpressão: %s = %.2f\n\n",string,al.resultado); 
}

void dividir(int i) {
   Calculadora al; 
   char string[200];
   char ch;
   int j=0;
    if(i==0){
		printf("Diga o primeiro número\n");
        scanf("%f", &al.n1);
		al.resultado = 1;
		arq = fopen ("parcial.txt", "w");//apaga tudo que está na parcial.txt
   			if(arq != NULL)
      			fprintf(arq,"");
   		fclose(arq);}
   		
        if (i!=0) al.n1 = 1; 
        printf("Diga o número\n");
        scanf("%f",&al.n2);
        
        //recebe o resultado na composta.txt
		if(al.n2 == 07){  
		float l = al.n2;  
		float *p = &l;   				 	
    	getComposta(&l);
       	al.n2 = l;}
        
        //lê o resultado
        arq = fopen ("resultado.txt", "r");
  			if(arq != NULL)
  	 		{
     			 while( (fscanf(arq,"%f",&al.resultado))!=EOF)
	  	
        fclose(arq);
  			 }
   //lê toda expressão para colocá-la entre parênteses
   arq = fopen ("parcial.txt", "r");
   if(arq != NULL)
   {
      while( (ch=fgetc(arq))!=EOF){
      	string[j] = ch;
      	j++;
	  }    	
      fclose(arq);
   }
   //faz a operação
   if(i==0)
   al.resultado =  al.n1 / al.n2;
   else 
   al.resultado /= al.n2;		 
	//salva na parcial.txt com o primeiro parênteses
	arq = fopen ("parcial.txt", "w");
   		if(arq != NULL){
      		if (i==0)
      			fprintf(arq,"%s",string);
      		else
      			fprintf(arq,"(%s",string);
      				   }
   fclose(arq);
	//salva na parcial com o fechar dos parênteses (quando necessário)
   arq = fopen ("parcial.txt", "a");
   if(arq == NULL)
      printf("Nao foi possivel abrir o arquivo\n");
   else{
   	if(i==0)
      fprintf(arq,"%.2f / %.2f",al.n1, al.n2);
    else 
      fprintf(arq,") / %.2f",al.n2);
  }
   fclose(arq);
      
   //salva o resultado
   arq = fopen ("resultado.txt", "w");
   		if(arq != NULL)
      		fprintf(arq,"%.2f",al.resultado);
   fclose(arq);
   j=0;
   //lê a parcial para poder mostrar a expressão parcial
  arq = fopen ("parcial.txt", "r");
   if(arq != NULL)
   {
      while( (ch=fgetc(arq))!=EOF){
      	string[j] = ch;
      	j++;
	  }    	
      fclose(arq);
   }
   printf("\nExpressão: %s = %.2f\n\n",string,al.resultado);  
}

void potencia(int i) {
   Calculadora al; 
   char string[200];
   char ch;
   int j=0;
    if(i==0){
		printf("Diga o primeiro número\n");
        scanf("%f", &al.n1);
		al.resultado = 1;
		arq = fopen ("parcial.txt", "w");//apaga tudo que está na parcial.txt
   			if(arq != NULL)
      			fprintf(arq,"");
   		fclose(arq);}
        if (i!=0) al.n1 = 1; 
        printf("Diga o expoente\n");
        scanf("%f",&al.n2);
        
         //recebe o resultado na composta.txt
		if(al.n2 == 07){  
		float l = al.n2;  
		float *p = &l;   				 	
    	getComposta(&l);
       	al.n2 = l;}
        
        //lê o resultado
        arq = fopen ("resultado.txt", "r");
  			if(arq != NULL)
  	 		{
     			 while( (fscanf(arq,"%f",&al.resultado))!=EOF)
	  	
        fclose(arq);
  			 }
   //lê toda expressão para colocá-la entre parênteses
   arq = fopen ("parcial.txt", "r");
   if(arq != NULL)
   {
      while( (ch=fgetc(arq))!=EOF){
      	string[j] = ch;
      	j++;
	  }    	
      fclose(arq);
   }
   //faz a operação
   int r;
   if(i==0){
   	al.resultado = 1;   		   
   al.resultado = pow(al.n1,al.n2);}
   else
   al.resultado = pow(al.resultado,al.n2);		 
	//salva na parcial.txt com o primeiro parênteses
	arq = fopen ("parcial.txt", "w");
   		if(arq != NULL){
      		if (i==0)
      			fprintf(arq,"%s",string);
      		else
      			fprintf(arq,"(%s",string);
      				   }
   fclose(arq);
	//salva na parcial com o fechar dos parênteses (quando necessário)
   arq = fopen ("parcial.txt", "a");
   if(arq == NULL)
      printf("Nao foi possivel abrir o arquivo\n");
   else{
   	if(i==0)
      fprintf(arq,"%.2f ^ %.2f",al.n1, al.n2);
    else 
      fprintf(arq,") ^ %.2f",al.n2);
  }
   fclose(arq);
      
   //salva o resultado
   arq = fopen ("resultado.txt", "w");
   		if(arq != NULL)
      		fprintf(arq,"%.2f",al.resultado);
   fclose(arq);
   j=0;
   //lê a parcial para poder mostrar a expressão parcial
  arq = fopen ("parcial.txt", "r");
   if(arq != NULL)
   {
      while( (ch=fgetc(arq))!=EOF){
      	string[j] = ch;
      	j++;
	  }    	
      fclose(arq);
   }
   printf("\nExpressão: %s = %.2f\n\n",string,al.resultado);  
}

void raiz(int i) {
   Calculadora al; 
   char string[200];
   char ch;
   int j=0;
    if(i==0){
		printf("Diga o primeiro número\n");
        scanf("%f", &al.n1);
		al.resultado = 1;
		arq = fopen ("parcial.txt", "w");//apaga tudo que está na parcial.txt
   			if(arq != NULL)
      			fprintf(arq,"");
   		fclose(arq);}
        if (i!=0) al.n1 = 1; 
        printf("Diga o expoente\n");
        scanf("%f",&al.n2);
        
         //recebe o resultado na composta.txt
		if(al.n2 == 07){  
		float l = al.n2;  
		float *p = &l;   				 	
    	getComposta(&l);
       	al.n2 = l;}
        
        
        //lê o resultado
        arq = fopen ("resultado.txt", "r");
  			if(arq != NULL)
  	 		{
     			 while( (fscanf(arq,"%f",&al.resultado))!=EOF)
	  	
        fclose(arq);
  			 }
   //lê toda expressão para colocá-la entre parênteses
   arq = fopen ("parcial.txt", "r");
   if(arq != NULL)
   {
      while( (ch=fgetc(arq))!=EOF){
      	string[j] = ch;
      	j++;
	  }    	
      fclose(arq);
   }
   //faz a operação
   int r;
   if(i==0){
   	al.resultado = 1;   		   
   al.resultado = pow(al.n1,1/al.n2);} //porque a raiz é o inverso da potência
   else
   al.resultado = pow(al.resultado,1/al.n2);	//porque a raiz é o inverso da potência	 
	//salva na parcial.txt com o primeiro parênteses
	arq = fopen ("parcial.txt", "w");
   		if(arq != NULL){
      		if (i==0)
      			fprintf(arq,"%s",string);
      		else
      			fprintf(arq,"(%s",string);
      				   }
   fclose(arq);
	//salva na parcial com o fechar dos parênteses (quando necessário)
   arq = fopen ("parcial.txt", "a");
   if(arq == NULL)
      printf("Nao foi possivel abrir o arquivo\n");
   else{
   	if(i==0)
      fprintf(arq,"%.2f ^ 1/%.2f",al.n1, al.n2);//porque a raiz é o inverso da potência
    else 
      fprintf(arq,") ^ 1/%.2f",al.n2);
  }
   fclose(arq);
      
   //salva o resultado
   arq = fopen ("resultado.txt", "w");
   		if(arq != NULL)
      		fprintf(arq,"%.2f",al.resultado);
   fclose(arq);
   j=0;
   //lê a parcial para poder mostrar a expressão parcial
  arq = fopen ("parcial.txt", "r");
   if(arq != NULL)
   {
      while( (ch=fgetc(arq))!=EOF){
      	string[j] = ch;
      	j++;
	  }    	
      fclose(arq);
   }
   printf("\nExpressão: %s = %.2f\n\n",string,al.resultado);  
}

void porcentagem(int i) {
   Calculadora al; 
   char string[200];
   char ch;
   int j=0;
    if(i==0){
		printf("Diga o primeiro número\n");
        scanf("%f", &al.n1);
		al.resultado = 1;
		arq = fopen ("parcial.txt", "w");//apaga tudo que está na parcial.txt
   			if(arq != NULL)
      			fprintf(arq,"");
   		fclose(arq);}
        if (i!=0) al.n1 = 1; 
        printf("Diga o número\n");
        scanf("%f",&al.n2);
        
        //lê o resultado
        arq = fopen ("resultado.txt", "r");
  			if(arq != NULL)
  	 		{
     			 while( (fscanf(arq,"%f",&al.resultado))!=EOF)
	  	
        fclose(arq);
  			 }
   //lê toda expressão para colocá-la entre parênteses
   arq = fopen ("parcial.txt", "r");
   if(arq != NULL)
   {
      while( (ch=fgetc(arq))!=EOF){
      	string[j] = ch;
      	j++;
	  }    	
      fclose(arq);
   }
   //faz a operação
   if(i==0)
   al.resultado =  al.n1 * al.n2/100;
   else 
   al.resultado *= al.n2/100;		 
	//salva na parcial.txt com o primeiro parênteses
	arq = fopen ("parcial.txt", "w");
   		if(arq != NULL){
      		if (i==0)
      			fprintf(arq,"%s",string);
      		else
      			fprintf(arq,"(%s",string);
      				   }
   fclose(arq);
	//salva na parcial com o fechar dos parênteses (quando necessário)
   arq = fopen ("parcial.txt", "a");
   if(arq == NULL)
      printf("Nao foi possivel abrir o arquivo\n");
   else{
   	if(i==0)
      fprintf(arq,"%.2f%% de %.2f",al.n2, al.n1);
    else 
      fprintf(arq,") %.2f%%",al.n2);
  }
   fclose(arq);
      
   //salva o resultado
   arq = fopen ("resultado.txt", "w");
   		if(arq != NULL)
      		fprintf(arq,"%.2f",al.resultado);
   fclose(arq);
   j=0;
   //lê a parcial para poder mostrar a expressão parcial
  arq = fopen ("parcial.txt", "r");
   if(arq != NULL)
   {
      while( (ch=fgetc(arq))!=EOF){
      	string[j] = ch;
      	j++;
	  }    	
      fclose(arq);
   }
   printf("\nExpressão: %s = %.2f\n\n",string,al.resultado);  
}

void fatorial(int i) {
   Calculadora al; 
   char string[200];
   char ch;
   int j=0;
    if(i==0){
		printf("Diga o primeiro número\n");
        scanf("%f", &al.n1);
		al.resultado = 1;
		arq = fopen ("parcial.txt", "w");//apaga tudo que está na parcial.txt
   			if(arq != NULL)
      			fprintf(arq,"");
   		fclose(arq);}
        if (i!=0) al.n1 = 1; 
        
        
        //lê o resultado
        arq = fopen ("resultado.txt", "r");
  			if(arq != NULL)
  	 		{
     			 while( (fscanf(arq,"%f",&al.resultado))!=EOF)
	  			fclose(arq);
  			 }
  			 
   //lê toda expressão para colocá-la entre parênteses
   arq = fopen ("parcial.txt", "r");
   if(arq != NULL)
   {
      while( (ch=fgetc(arq))!=EOF){
      	string[j] = ch;
      	j++;
	  }    	
      fclose(arq);
   }
   int r;
   //faz a operação
   if(i==0){
   	al.resultado = al.n1;
   for(r=1;r<al.n1;r++)
   al.resultado *=  r;}
   else 
   for(r=1;r<al.resultado;r++)
   al.resultado *=  r;		 
	//salva na parcial.txt com o primeiro parênteses
	arq = fopen ("parcial.txt", "w");
   		if(arq != NULL){
      		if (i==0)
      			fprintf(arq,"%s",string);
      		else
      			fprintf(arq,"(%s",string);
      				   }
   fclose(arq);
	//salva na parcial com o fechar dos parênteses (quando necessário)
   arq = fopen ("parcial.txt", "a");
   if(arq == NULL)
      printf("Nao foi possivel abrir o arquivo\n");
   else{
   	if(i==0)
      fprintf(arq,"%.2f!",al.resultado);
    else 
      fprintf(arq,")! ",al.resultado);
  }
   fclose(arq);
      
   //salva o resultado
   arq = fopen ("resultado.txt", "w");
   		if(arq != NULL)
      		fprintf(arq,"%.2f",al.resultado);
   fclose(arq);
   j=0;
   //lê a parcial para poder mostrar a expressão parcial
  arq = fopen ("parcial.txt", "r");
   if(arq != NULL)
   {
      while( (ch=fgetc(arq))!=EOF){
      	string[j] = ch;
      	j++;
	  }    	
      fclose(arq);
   }
   printf("\nExpressão: %s = %.2f\n\n",string,al.resultado);  
}

void visualizar(int *q, int i) {
	char string[2000];
    char ch;
    int j=0;
   //lê o que está no histórico.txt
	arq = fopen ("historico.txt", "r");
   if(arq != NULL)
   {
      while( (ch=fgetc(arq))!=EOF){
      	string[j] = ch;
      	j++;
	  }    	
      fclose(arq);
   }
   printf("\nHistórico:\n%s\n",string);
   if(i==0)
   *q=-1;
}
void apagar(int *q, int i) {
	//apenas troca o que está no histórico por nenhum caractere.
	arq = fopen ("historico.txt", "w");
   			if(arq != NULL)
      			fprintf(arq,"");
   		fclose(arq);
   printf("Histórico apagado com sucesso\n");
   if (i==0)
   *q=-1;
}
void finalizar() {
	Calculadora al; 
    char string[200];
    char ch;
	int j=0;
	//lê o que está na parcial
  arq = fopen ("parcial.txt", "r");
   if(arq != NULL)
   {
      while( (ch=fgetc(arq))!=EOF){
      	string[j] = ch;
      	j++;
	  }    	
      fclose(arq);
   }
   //lê o resultado para poder imprimir junto   
   arq = fopen ("resultado.txt", "r");
  			if(arq != NULL)
  	 		{
     			 while( (fscanf(arq,"%f",&al.resultado))!=EOF)
	  	
        fclose(arq);
  			 }
   //salva a parcial mais o resultado no histórico
    arq = fopen ("historico.txt", "a");
   if(arq != NULL){
   	fprintf(arq,"%s = %.2f\n",string,al.resultado);
  }
   fclose(arq);
   
   //salva o resultado no arquivo composta.txt
   arq = fopen ("composta.txt", "w");
   		if(arq != NULL)
      		fprintf(arq,"");
   fclose(arq);
   
}

void novo(int* q)
{
	Calculadora al; 
    char string[200];
    char ch;
	int j=0;
	//lê o que está na parcial
  arq = fopen ("parcial.txt", "r");
   if(arq != NULL)
   {
      while( (ch=fgetc(arq))!=EOF){
      	string[j] = ch;
      	j++;
	  }    	
      fclose(arq);
   }
   //lê o resultado para poder imprimir junto   
   arq = fopen ("resultado.txt", "r");
  			if(arq != NULL)
  	 		{
     			 while( (fscanf(arq,"%f",&al.resultado))!=EOF)
	  	
        fclose(arq);
  			 }
   //salva a parcial mais o resultado no histórico
    arq = fopen ("historico.txt", "a");
   if(arq != NULL){
   	fprintf(arq,"%s = %.2f\n",string,al.resultado);
  }
   fclose(arq);
   *q=-1;
   system("cls");
}

void back(int* q) {
	system("cls");
	*q = 1;
}


void composta() {
	Calculadora al;
	//lê o resultado
        arq = fopen ("resultado.txt", "r");
  			if(arq != NULL)
  	 		{
     			 while( (fscanf(arq,"%f",&al.resultado))!=EOF)
	  				fclose(arq);
  			 }
  		
  		
  		//salva o resultado no arquivo composta.txt
   arq = fopen ("composta.txt", "w");
   		if(arq != NULL)
      		fprintf(arq,"%.2f",al.resultado);
   fclose(arq);
}
	

int main ()
{
	Calculadora al; 
	setlocale(LC_ALL,"portuguese");
    unsigned fim, opcao;
    int i = 0;
    int* q = &i;
    int c = 0;
    int *d = &c;
    fim = 0;
    printf("CALCULADORA JAIRO FILHO 2.0 S2\n");
    do {
    	if (c == 0)
        printf("MENU PRINCIPAL (GRAU)\n");
        if (c == 1)
        printf("MENU PRINCIPAL (RADIANO)\n");
        printf("1 - SOMAR        "); //faz a operação de soma
        printf("2 - SUBTRAIR     "); //faz a operação de subtração
        printf("3 - MULTIPLICAR     "); //faz a operação de multiplicação
        printf("4 - DIVIDIR\n\n"); //faz a operação de divisão
        printf("5 - POTÊNCIA     "); //faz a operação de potência
        printf("6 - RAIZ         "); //faz a operação de radiciação
        printf("7 - PORCENTAGEM     "); //faz a operação de porcentagem
        printf("8 - FATORIAL\n\n"); //faz a operação de fatorial
        printf("9 - VISUALIZAR HISTÓRICO         "); //visualiza o histórico
		printf("10 - APAGAR HISTÓRICO\n\n"); // apaga o histórico        
        printf("11 - NOVA EXPRESSÃO    "); // limpa o parcial.txt
        printf("12 - LIMPAR TELA\n"); // Limpa a tela.
        printf("13 - SALVAR COMPOSTA (para acionar, digite 07 em vez do número)\n\n"); // Salva o resultado na composta.txt
		printf("14 - FINALIZAR PROGRAMA\n"); // salva o que está na parcial e no resultado para o histórico
        printf("  -> DIGITE SUA OPÇÃO: ");
        scanf("%d", &opcao);  
        switch (opcao) {
          case 1:somar(i);
                  break;
          case 2:subtrair(i);
                  break;
          case 3:multiplicar(i);
                  break;
          case 4:dividir(i);
                  break;
          case 5:potencia(i);
                  break;
		  case 6:raiz(i);
                  break;
		  case 7:porcentagem(i);
                  break;
		  case 8:fatorial(i);
                  break;		  		  		          
          case 9:visualizar(&i,i);
                  break;
          case 10:apagar(&i,i);
                  break;
		  case 11:novo(&i);
                  break;
		  case 12:back(&i);
                  break; 
		  case 13:composta();
                  break;		  		                      
          case 14:finalizar();
                  fim = 1;
        }
		i++;
     } while (! fim);   
    

    return (0);
}
