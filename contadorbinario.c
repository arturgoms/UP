#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define ENTRADA 1
#define SAIDA	0
#define HIGH	1
#define LOW	0

bool GPIOexport(int pino);
bool GPIOdirection(int pino, int direcao);
bool GPIOWrite(int pino, int valor);
bool GPIORead(int pino);
bool GPIOUnexport(int pino);
int morse(char *palavra);
int readBtn();

void main()
{

int contador = 0;

/*  Ler String
	int 	tamanho = 0;
	char	aux;
	char *	texticulo;

	texticulo = (char *)malloc(tamanho);

	do
	{
		scanf("%c", &aux);
		if( aux == '\n' )
			break;

texticulo = (char *)realloc(texticulo, (tamanho+1)*sizeof(char));

		texticulo[tamanho] = aux;
		tamanho++;
	}while(true);
	morse(texticulo);
	printf("%s",texticulo );
	// Fim leitura String
	// Exemplo pinos

	GPIOexport(7);
	GPIOdirection(7, SAIDA);
	while(1)
	{
		GPIOWrite(7, HIGH);
		usleep(1000000);
		GPIOWrite(7, LOW);
		usleep(1000000);
	}
	GPIOUnexport(7);
	// Fim pinos

*/



// Contador Binario


	printf("Aperte o Btn\n");
	
	GPIOexport(15);
	GPIOdirection(15, ENTRADA);
	while(true){
	
		if (GPIORead(15) == 1){  // ReadBtn
			
			contador++;
			
			usleep(1000000);
	
			printf("%d", contador); 
		}
	
	}
	GPIOUnexport(15);

	
}

bool GPIOexport(int pino)
{
	char 	buffer[3];
	int 	arquivo;

	arquivo = open("/sys/class/gpio/export", O_WRONLY);
	if( arquivo == -1 )
		return false;

	snprintf( buffer, 3, "%d", pino );
	if( write( arquivo, buffer, 3 ) == -1 )
	{
		close(arquivo);
		return false;
	}

	close(arquivo);
	return true;
}

bool GPIOUnexport(int pino)
{
	char 	buffer[3];
	int 	arquivo;

	arquivo = open("/sys/class/gpio/unexport", O_WRONLY);
	if( arquivo == -1 )
		return false;

	snprintf( buffer, 3, "%d", pino );
	if( write( arquivo, buffer, 3 ) == -1 )
	{
		close(arquivo);
		return false;
	}

	close(arquivo);
	return true;
}

bool GPIOdirection(int pino, int direcao)
{
	char 	caminho[35];
	int	arquivo;

	snprintf( caminho, 35, "/sys/class/gpio/gpio%d/direction", pino);
	arquivo = open( caminho, O_WRONLY);
	if( arquivo == -1 )
		return false;

	if( write( arquivo, (direcao == ENTRADA)?"in":"out", (direcao == ENTRADA)?2:3 ) == -1 )
	{
		close(arquivo);
		return false;
	}

	close(arquivo);
	return true;
}

bool GPIOWrite(int pino, int valor)
{
	char 	caminho[35];
	int	arquivo;

	snprintf( caminho, 35, "/sys/class/gpio/gpio%d/value", pino);
	arquivo = open( caminho, O_WRONLY);
	if( arquivo == -1 )
		return false;

	if( write( arquivo, (valor == HIGH)?"1":"0", 1 ) == -1 )
	{
		close(arquivo);
		return false;
	}

	close(arquivo);
	return true;
}

bool GPIORead(int pino){
	char 	caminho[35];
	int	arquivo;
	char	retorno[2]; 

	snprintf( caminho, 35, "/sys/class/gpio/gpio%d/value", pino);
	arquivo = open(caminho,O_RDONLY);
	if( arquivo == -1 )
		return false;

	if( read(arquivo,retorno,2) == -1)
	{
		close(arquivo);
		return false;
	}

	printf("%s", retorno);

	close(arquivo);
	return (int)retorno[0]-48;

}


int morse(char *palavra){
	int len = 0;
	len = strlen(palavra);

	for(int i = 0;i <= len;i++){

		switch(palavra[i]){
			case 'a':case 'A':
				printf("Letra a\n");
			break;
 			case 'b': case 'B':
				printf("Letra b\n");
			break;
 			case 'c': case 'C':
				printf("Letra C\n");
			break;
 			case 'd': case 'D':
				printf("Letra D\n");
			break;
 			case 'e': case 'E':
				printf("Letra E\n");
			break;
 			case 'f': case 'F':
				printf("Letra F\n");
			break;
 			case 'g': case 'G':
				printf("Letra G\n");
			break;
 			case 'h': case 'H':
				printf("Letra H\n");
			break;
 			case 'i': case 'I':
				printf("Letra I\n");
			break;
 			case 'j': case 'J':
				printf("Letra J\n");
			break;
 			case 'k': case 'K':
				printf("Letra K\n");
			break;
 			case 'l': case 'L':
				printf("Letra L\n");
			break;
 			case 'm': case 'M':
				printf("Letra M\n");
			break;
 			case 'n': case 'N':
				printf("Letra N\n");
			break;
 			case 'o': case 'O':
				printf("Letra O\n");
			break;
 			case 'p': case 'P':
				printf("Letra p\n");
			break;
 			case 'q': case 'Q':
				printf("Letra q\n");
			break;
 			case 'r': case 'R':
				printf("Letra r\n");
			break;
			case 's': case 'S':
				printf("Letra s\n");
			break;
			case 't': case 'T':
				printf("Letra t\n");
			break;
			case 'u': case 'U':
				printf("Letra u\n");
			break;
			case 'v': case 'V':
				printf("Letra v\n");
			break;
			case 'w': case 'W':
				printf("Letra w\n");
			break;
			case 'x': case 'X':
				printf("Letra x\n");
			break;
			case 'y': case 'Y':
				printf("Letra y\n");
			break;
			case 'z': case 'Z':
				printf("Letra z\n");
			break;
			case '8':
				printf("Letra espaço\n");
			break;
			default:
				printf("Não encontrado\n");
				
		}
		usleep(1000*1000);
	}
	return 1;
}

int readBtn(){
	
	int contador = 0;
	GPIOexport(10);
	GPIOdirection(10, ENTRADA);
	if (GPIORead(10) == 1){  // ReadBtn
		
		contador++;
		
		usleep(1000*500);

		return contador; 
		

	}
	GPIOUnexport(10);
	
	
	
 	
}





