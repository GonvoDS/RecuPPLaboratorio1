#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#define TAM 500

int getValidInt(char mensaje[], char error[]){
	char numeroSolicitado[TAM];
	int largo;
	int fallo;
	int resultado;

	do{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]",numeroSolicitado);

		largo = strlen(numeroSolicitado);

		for (int i=0;i<largo;i++){


			if (isdigit(numeroSolicitado[i]) || numeroSolicitado[0] == '-'){
				fallo=0;
			}
			else{
				fallo=1;
				printf("%s",error);
				break;
			}
		}

	} while (fallo==1);

	resultado = atoi(numeroSolicitado);

	return resultado;
}

float getValidFloat(char mensaje[], char error[]){
	char numeroSolicitado[TAM];
	int largo;
	int fallo;
	int flag;
	float resultado;

	do{
		flag=1;
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]",numeroSolicitado);

		largo = strlen(numeroSolicitado);

		for (int i=0;i<largo;i++){

			if (isdigit(numeroSolicitado[i]) || (numeroSolicitado[i] == '.' && flag==1) || numeroSolicitado[0] == '-'){
				if(numeroSolicitado[i] == '.'){
					flag=0;
				}
				fallo=0;
			}
			else{
				fallo=1;
				printf("%s",error);
				break;

			}
		}

	} while (fallo==1);

	resultado = atof(numeroSolicitado);

	return resultado;
}


int getInt(char mensaje[],int min,int max){
	int numero;


	numero = getValidInt(mensaje,"Dato invalido\n");

	while(numero <min || numero > max){
		printf("Numero invalido, ingrese un numero en el rango pedido (%d a %d)\n",min,max);

		numero = getValidInt(mensaje,"Dato invalido\n");
	}

	return numero;

}

float getFloat(char mensaje[],int min,int max){
	float numero;

	numero = getValidFloat(mensaje,"Dato incorrecto\n");
	while(numero <min || numero > max){
		printf("Numero invalido, ingrese un numero en el rango pedido (%d a %d)\n",min,max);
		numero = getValidFloat(mensaje,"Dato incorrecto\n");
	}

	return numero;

}


void getString (char mensaje [], char cadena[],int tam)
{
	int flagE=0;
	int largo;

	do{

		if(flagE){
			printf("Dato invalido, ingreselo nuevamente.\n");
		}
		printf("%s", mensaje);
		fflush(stdin);
		gets(cadena);
		largo = strlen(cadena);
		if(cadena == NULL || largo <2){
			flagE=1;
		}
		else {
			for(int i=0; i<largo; i++){
				if((isdigit(cadena[i]) == 1 && cadena[i]!=' ') || (cadena[i-1]==' ' && cadena[i]==' ')  || (largo<5 && cadena[i]==' ')){
					flagE=1;
					break;
				}
				else{
					flagE=0;
				}

			}
		}
	}while(flagE);
    corregirString(cadena);
}
void corregirString(char cadena[]){
	int largo;

	largo = strlen(cadena);

	strlwr(cadena);

	for(int i=0; i<largo;i++){

		if(i==0 || cadena[i-1]==' '){
			cadena[i] = toupper(cadena[i]);
		}

	}
}
int ValidarStringComoEntero(char cadena[]){
	int todoOk=1;
	int largo;
	largo = strlen(cadena);

	if(largo!=0){
		for (int i=0;i<largo;i++){
			if (!isdigit(cadena[i])){
				todoOk=0;
				break;
			}
		}
	}
	return todoOk;
}
int StringAEntero(char cadena[], int* entero){
    int todoOk = 0;

    if(cadena != NULL && ValidarStringComoEntero(cadena)){
    	*entero = atoi(cadena);
    	todoOk = 1;
     }

    return todoOk;
}
int getValidCuit(char mensaje[], char error[],char cuit[]){

	int largo, fail;

	do{
		printf("%s", mensaje);
		fflush(stdin);
		gets(cuit);

		largo = strlen(cuit);

		if(largo==11){
			for (int i=0;i<largo;i++){


				if (isdigit(cuit[i])){
					fail=0;

				}
				else{
					fail=1;
					printf("%s",error);
					break;
				}
			}
		}
		else{
			fail=1;
			printf("%s",error);
		}

	} while (fail==1);


	return fail;
}
