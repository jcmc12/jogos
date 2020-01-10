#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<locale.h>
#include<conio.h>
#include<string.h>

//PARA INICIAR O JOGO � NECESS�RIO DIGITAR A PALAVRA. AO DIGITAR AS LETRAS DA PALAVRA ESSAS N�O IR�O APARECER,POIS �
//UMA FORMA DE ESCONDER A PALAVRA DO JOGADOR. AO TERMINAR DE DIGITAR A LETRA, POR FAVOR, DIGITE A TECLA =
//DURANTE O JOGO INSIRA SOMENTE LETRA MAI�SCULA
 
int main(void)

{
    int i=0,cont=0,erro=0,j=0,resultado=0;
    char palv[40],dica[40],letr[29],r,a='A',resp[40],letra[29],inicio='s';
    
	setlocale(LC_ALL,"Portuguese");//BIBLIOTECA PORTUGUESE
    system("color 0A");//COR VERDE
    
    for(i=0;i<60;i++)
    {
    	system("cls");
    	
		printf("\t\t\tBem-vindo ao jogo da Forca\n"); //APRESENTA��O DO JOGO DA FORCA.
    	printf("\t\t\t--------------------------\n");
    	
    	printf("\n\tDigite a palavra: ");   //LA�O PARA CAPTURAR OS CARACTERES DA PALAVRA
    	fflush(stdin);                    //FOI UTILIZADO O getch() PARA N�O MOSTRAR NA TELA OS CARACTERES       
    	palv[i]=getch();                 //QUANDO DIGITAR O �LTIMO CARACTERE DA PALAVRA ESCOLHIDA, DIGITE A TECLA '=' PARA
    	fflush(stdin);                     //FINALIZAR A PALAVRA.        
    	
    	if(palv[i]=='=')
    	{
    		palv[i]='\0';        //QUANDO A POSI��O DO VETOR ENCONTRAR O CARACTERE '=' ESSE � TROCADO POR '\O' QUE � O  
			i=70;               //FINALIZADOR DA STRING. COMO FOI FINALIZADO A CAPTURA DOS CARACTERES QUE COMP�EM A 
		}                      //O LA�O DEVER� SER ESTOURADO COM i=70.
	}
	
    printf("\n\n\tDica: "); //IFORMAR UMA DICA PARA O US�RIO QUE FOI DESAFIADO QUE IR� APARECER NA TELA.
    scanf("%s",&dica); 
    
    i=0; //INICIALIZAR COM ZERO PARA UTILIZAR NO LA�O SEGUINTE, UMA VEZ QUE ESTAVA COM VALOR DE i=70 PARA ESTOURAR O LA�O.
    
    for(;palv[i]!='\0';i++)
    {
    	cont=cont+1; //ESSE LA�O FAR� A CONTAGEM DO N�MERO DE CARACTERES QUE COMP�EM A PALAVRA (VETOR palv)  
	}               //E PARA QUANDO ENCONTRA '\0'. PARA ISSO FOI UTILIZADO A VARI�VEL 'cont'.
		
	for(i=0;i<=28;i++)
    {
    	letr[i]='0'; //ESSE LA�O REPRESENTA O VETOR 'letr' QUE SE REFERE AS LETRAS DO ALFABETO. COMO EXISTE 28 LETRAS, TODAS
	}               // AS POSI��ES SER�O PREENCIDAS POR '0', POR QUE IR� REPRESENTAR AS LETRAS QUE J� FORAM INFORMADAS PELO
	               //USU�RIO DURANTE O JOGO.
	
	for(i=0;i<=28;i++)
    {
    	letra[i]=a; //ESSE LA�O IR� PREENCHER O VETRO 'letra' COM AS LETRAS DO ALFABETO PARA POSTERIORMENTE SER COMPARADO
    	a=a+1;     //COM O VETOR 'letr' E TROCADO O CARACTERE '0' PELA LETRA FORNECIDA PELO USU�RIO.
	}
	
	for(i=0;i<40;i++)
	{
		resp[i]='_'; //ESSE LA�O IR� ADICIONAR O CARACTERE '_' NO VETOR 'resp'. ESSES TRA�OS IR�O APARECER NO INICIO DO JOGO
	}    //E O TOTAL CORRESPONDER� AO TAMANHO DA PALAVRA INFORMADA. POSTERIORMENTE, SER� COMPARADA COM A LETRA FORCECIDA
	    //PELO USU�RIO E CASO ESTEJA CERTO SER� SUBSTITU�DO PELA LETRA.
	
    while(inicio=='s') //DEPOIS DE INSERIR A PALAVRA E SUA DICA. AQUI TER� INICIO O JOGO EM UMA NOVA TELA
    {
	
    
		system("cls");//LIMPAR A TELA 
			
    
    	iii();//FUN��O QUE APARECE O IN�CIO DA FOR�A 
    	if(erro==1||erro==2||erro==3||erro==4||erro==5||erro==6||erro==7)
		pri();//ERROU UMA VEZ APARECE A CABE�A NA FORCA
    	if(erro==2||erro==3||erro==4||erro==5||erro==6||erro==7)
    	seg();//ERROU DUAS VEZES APARECE A CABE�A E O BRA�O ESQUERDO NA FORCA
    	if(erro==3||erro==4||erro==5||erro==6||erro==7)
    	ter();//ERROU TR�S VEZES APARECE A CABE�A, BRA�O ESQUERDO E CORPO NA FORCA
    	if(erro==4||erro==5||erro==6||erro==7)
    	qua();//ERROU QUATRO VEZES APARECE A CABE�A, BRA�O ESQUERDO, CORPO E BRA�O DIREITO NA FORCA
    	if(erro==5||erro==6||erro==7)
    	qui();
    	if(erro==6||erro==7)
    	sext();
    	
		printf("\n\n\t");
	
		for(i=0;i<=28;i++)
		{
			printf("%c ",letr[i]);
		}
		
	
		printf("\n\n\t\t\t");
	
		for(i=0;i<cont;i++)
		{
			printf("%c ",resp[i]);
		}
		
		printf("\nDica: %s",dica);
	
		printf("\n\n\tLetra: ");
		fflush(stdin);
		scanf("%c",&r);
	
		for(i=0;i<cont;i++)
		{
			if(palv[i]==r)
			{
				resp[i]=r;
				j++;
			}
		}
		
		for(i=0;i<=cont;i++)
		{
			if(i==cont)
			{
				resp[i]='\0';
			}
		}
		
		if(j==0)
		{
			erro++;
		}
		
		j=0;
		
		for(i=0;i<=28;i++)
		{
			if(letra[i]==r)
			{
				letr[i]=r;
			}
		}
		
		if(erro==7)
		{
			inicio='n';
			resultado=1;				
		}
		
		if(strcmp(palv,resp)==0)
		{
			inicio='n';
			resultado=2;
		}
		
		
	}
	
	if(resultado==1)
	{
		printf("\n\n\t\t       VOC� PERDEU\n");
		printf("\t\tPalavra correta: ");
		
		for(i=0;i<=cont;i++)
    	{
    		printf("%c",palv[i]);
		}
		
	}
	else
	{
		system("cls");
		
		iii();
    	if(erro==1||erro==2||erro==3||erro==4||erro==5||erro==6||erro==7)
		pri();
    	if(erro==2||erro==3||erro==4||erro==5||erro==6||erro==7)
    	seg();
    	if(erro==3||erro==4||erro==5||erro==6||erro==7)
    	ter();
    	if(erro==4||erro==5||erro==6||erro==7)
    	qua();
    	if(erro==5||erro==6||erro==7)
    	qui();
    	if(erro==6||erro==7)
    	sext();
    	
		printf("\n\n\t");
		
		for(i=0;i<=28;i++)
		{
			printf("%c ",letr[i]);
		}
		
		printf("\n\n\t\t\t");
	
		for(i=0;i<cont;i++)
		{
			printf("%c ",resp[i]);
		}
		
		printf("\n\n\t\tVoc� ganhou o desafio!!\n\n");
		
		printf("\t\t      Erros: %d",erro);
		
		pisca();
		
	}
	
    printf("\n\n");
    system("pause");
    return (0);
}

iii(void)
{
	printf("--------\n");//INICIO
    printf("       |\n");//INICIO
}
pri(void)
{
	printf("       0\n");//PRIMEIRA TENTATIVA
}
seg(void)
{
	printf("      /");//SEGUNDA TENTATIVA
}
ter(void)
{
	printf("|");//TERCEIRA TENTATIVA
}
qua(void)
{
	printf("\\\n");//QUARTA TENTATIVA
}
qui(void)
{
	printf("      /");//QUINTA TENTATIVA
}
sext(void)
{
	printf(" \\\n");//SEXTA TENTATIVA
}
pisca(void)
{
		int i=0;
		
		for(i=0;i<5;i++)
    	{
    		Sleep(800);
			system("color 0E");
    		Sleep(800);
    		system("color 0A");
    		Sleep(800);
    		system("color 0C");
		}
}
