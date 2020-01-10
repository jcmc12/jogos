#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<locale.h>
#include<conio.h>
#include<string.h>

//PARA INICIAR O JOGO É NECESSÁRIO DIGITAR A PALAVRA. AO DIGITAR AS LETRAS DA PALAVRA ESSAS NÃO IRÃO APARECER,POIS É
//UMA FORMA DE ESCONDER A PALAVRA DO JOGADOR. AO TERMINAR DE DIGITAR A LETRA, POR FAVOR, DIGITE A TECLA =
//DURANTE O JOGO INSIRA SOMENTE LETRA MAIÚSCULA
 
int main(void)

{
    int i=0,cont=0,erro=0,j=0,resultado=0;
    char palv[40],dica[40],letr[29],r,a='A',resp[40],letra[29],inicio='s';
    
	setlocale(LC_ALL,"Portuguese");//BIBLIOTECA PORTUGUESE
    system("color 0A");//COR VERDE
    
    for(i=0;i<60;i++)
    {
    	system("cls");
    	
		printf("\t\t\tBem-vindo ao jogo da Forca\n"); //APRESENTAÇÃO DO JOGO DA FORCA.
    	printf("\t\t\t--------------------------\n");
    	
    	printf("\n\tDigite a palavra: ");   //LAÇO PARA CAPTURAR OS CARACTERES DA PALAVRA
    	fflush(stdin);                    //FOI UTILIZADO O getch() PARA NÃO MOSTRAR NA TELA OS CARACTERES       
    	palv[i]=getch();                 //QUANDO DIGITAR O ÚLTIMO CARACTERE DA PALAVRA ESCOLHIDA, DIGITE A TECLA '=' PARA
    	fflush(stdin);                     //FINALIZAR A PALAVRA.        
    	
    	if(palv[i]=='=')
    	{
    		palv[i]='\0';        //QUANDO A POSIÇÃO DO VETOR ENCONTRAR O CARACTERE '=' ESSE É TROCADO POR '\O' QUE É O  
			i=70;               //FINALIZADOR DA STRING. COMO FOI FINALIZADO A CAPTURA DOS CARACTERES QUE COMPÕEM A 
		}                      //O LAÇO DEVERÁ SER ESTOURADO COM i=70.
	}
	
    printf("\n\n\tDica: "); //IFORMAR UMA DICA PARA O USÁRIO QUE FOI DESAFIADO QUE IRÁ APARECER NA TELA.
    scanf("%s",&dica); 
    
    i=0; //INICIALIZAR COM ZERO PARA UTILIZAR NO LAÇO SEGUINTE, UMA VEZ QUE ESTAVA COM VALOR DE i=70 PARA ESTOURAR O LAÇO.
    
    for(;palv[i]!='\0';i++)
    {
    	cont=cont+1; //ESSE LAÇO FARÁ A CONTAGEM DO NÚMERO DE CARACTERES QUE COMPÕEM A PALAVRA (VETOR palv)  
	}               //E PARA QUANDO ENCONTRA '\0'. PARA ISSO FOI UTILIZADO A VARIÁVEL 'cont'.
		
	for(i=0;i<=28;i++)
    {
    	letr[i]='0'; //ESSE LAÇO REPRESENTA O VETOR 'letr' QUE SE REFERE AS LETRAS DO ALFABETO. COMO EXISTE 28 LETRAS, TODAS
	}               // AS POSIÇÕES SERÃO PREENCIDAS POR '0', POR QUE IRÁ REPRESENTAR AS LETRAS QUE JÁ FORAM INFORMADAS PELO
	               //USUÁRIO DURANTE O JOGO.
	
	for(i=0;i<=28;i++)
    {
    	letra[i]=a; //ESSE LAÇO IRÁ PREENCHER O VETRO 'letra' COM AS LETRAS DO ALFABETO PARA POSTERIORMENTE SER COMPARADO
    	a=a+1;     //COM O VETOR 'letr' E TROCADO O CARACTERE '0' PELA LETRA FORNECIDA PELO USUÁRIO.
	}
	
	for(i=0;i<40;i++)
	{
		resp[i]='_'; //ESSE LAÇO IRÁ ADICIONAR O CARACTERE '_' NO VETOR 'resp'. ESSES TRAÇOS IRÃO APARECER NO INICIO DO JOGO
	}    //E O TOTAL CORRESPONDERÁ AO TAMANHO DA PALAVRA INFORMADA. POSTERIORMENTE, SERÁ COMPARADA COM A LETRA FORCECIDA
	    //PELO USUÁRIO E CASO ESTEJA CERTO SERÁ SUBSTITUÍDO PELA LETRA.
	
    while(inicio=='s') //DEPOIS DE INSERIR A PALAVRA E SUA DICA. AQUI TERÁ INICIO O JOGO EM UMA NOVA TELA
    {
	
    
		system("cls");//LIMPAR A TELA 
			
    
    	iii();//FUNÇÃO QUE APARECE O INÍCIO DA FORÇA 
    	if(erro==1||erro==2||erro==3||erro==4||erro==5||erro==6||erro==7)
		pri();//ERROU UMA VEZ APARECE A CABEÇA NA FORCA
    	if(erro==2||erro==3||erro==4||erro==5||erro==6||erro==7)
    	seg();//ERROU DUAS VEZES APARECE A CABEÇA E O BRAÇO ESQUERDO NA FORCA
    	if(erro==3||erro==4||erro==5||erro==6||erro==7)
    	ter();//ERROU TRÊS VEZES APARECE A CABEÇA, BRAÇO ESQUERDO E CORPO NA FORCA
    	if(erro==4||erro==5||erro==6||erro==7)
    	qua();//ERROU QUATRO VEZES APARECE A CABEÇA, BRAÇO ESQUERDO, CORPO E BRAÇO DIREITO NA FORCA
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
		printf("\n\n\t\t       VOCÊ PERDEU\n");
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
		
		printf("\n\n\t\tVocê ganhou o desafio!!\n\n");
		
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
