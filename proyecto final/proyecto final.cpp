#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

using namespace std;

struct Tienda 
{
	int num; //numero de articulo
	int lanz; //año de lanzamiento 
	char nombre[100]; //Nombre del videojuego
	char genero[30]; //genero
	char clas[10]; //clasificacion
	char consola[50]; //consola
	char caract[100]; //caracteristicas
	char desc[600]; //descripcion del videojuego
	float precio; //precio unitario
	float imp; //impuesto
	float total; //total 
	char estado[20]; // eliminado, vigente
	int activo = 0;
}T[50];

void Agregar();
void Modificar();
void Eliminar();
void Listas();
void Archivos();
void leer();


int main()
{
	setlocale(LC_CTYPE, "spanish");
	int num = 0;
	int opcion;
	int j;
	int i;
	leer();
	printf("\t -- MENU DE OPCIONES --\n");
	printf("1.- Agregar Articulo\n");
	printf("2.- Modificar Articulo\n");
	printf("3.- Eliminar Articulo\n");
	printf("4.- Lista de Articulos vigentes\n");
	printf("5.- Limpiar Pantalla\n");
	printf("6.- Salir\n");
	scanf_s("%d", &opcion);
	
	switch (opcion)
	{
	case 1:
		Agregar();
		return main();
		break;

	case 2:
		Modificar();
		return main();
		break;

	case 3:
		Eliminar();
		return main();
		break;

	case 4:
		Listas();
		return main();
		break;

	case 5: 
		system("cls"); //system("clear");
		return main();
		break;

	case 6: 
		Archivos();
		break;

	default:

		break;
	}
	
}

void Agregar()
{
	int num = 0;
	int i = 0;
	int j;
		system("cls");
		printf("cuantos registros desea dar de alta: \n");
		scanf("%d", &i);
		for (j = 1; j <= i; j++)
		{
			system("cls");
			printf("Numero del articulo:\n");
			scanf("%d", &num);
			while ((getchar() != '\n')) { fflush(stdin); }

			printf("Ingrese el nombre del videojuego: \n");
			gets_s(T[j].nombre);

			printf("Ingrese descripcion del videojuego: \n");
			gets_s(T[j].desc);

			printf("Ingrese la clasificacion: \n");
			gets_s(T[j].clas);

			printf("Ingrese el genero:\n");
			gets_s(T[j].genero);

			printf("Ingrese la consola:\n");
			gets_s(T[j].consola);

			printf("Ingrese el año de lanzamiento:\n");
			scanf("%d", &T[j].lanz);
			printf("Ingrese el precio Unitario:\n");
			scanf("%f", &T[j].precio);
			T[j].activo = 1;
		}
	
}

void Modificar()
{
	int j, opcion, i;
	do
	{
		system("cls");
		opcion = 0; int n;
		printf("\n--Modificar articulo--\n");
		printf("\nNumero de articulo a modificar: ");
		scanf("%d", &n);
		fflush(stdin);
		for (i = 0; i <= 599; i++)
		{
			if (n == T[i].num)
			{
				n = -1;
				
				if (strcmp(T[i].estado, "Eliminado") == 0)
				{
					printf("\nRegistro elimimado, ingrese un registro valido...\n");
					system("pause");
					opcion = 1;
					break;
				}
			}
	
			printf("Ingrese que desea modificar: \n");
			printf("1.- Numero de Articulo\n");
			printf("2.- Nombre de Articulo\n");
			printf("3.- Descripcion de Articulo\n");
			printf("4.- Clasificacion de Articulos\n");
			printf("5.- Genero del Articulo\n");
			printf("6.- Consola\n");
			printf("7.- Año de lanzamiento\n");
			printf("8.- Precio unitario\n");
			scanf_s("%d", &opcion);

			switch (opcion)
			{
			case 1:

			default:
				break;
			}
		}
	} while (opcion == 1);
	
}

void Eliminar()
{
	int j;
	printf("Ingrese el numero de registro a eliminar");
	scanf("%d", &j);
	j = j - 1;

	for (int i = j; i == j; i++)
	{
		printf("Registro eliminado %d\n", j + 1);
	}
}

void Listas()
{
	int i;
	system("cls");
	printf("\n--Listado de articulos--\n");
	for (i = 0; i <= 49; i++)
	{
		if (T[i].activo == 1)
		{
			printf("\n\nNumero del articulo: %d", T[i].num);
			printf("\nNombre: %s", T[i].nombre);
			printf("\nDescripcion: %s", T[i].desc);
			printf("\nClasificacion: %s", T[i].clas);
			printf("\nGenero: %s", T[i].genero);
			printf("\nConsola: %s", T[i].consola);
			printf("\nAño de lanzamiento: %s", T[i].lanz);
			printf("\nPrecio unitario: %s", T[i].precio);
		}
	}
}

void Archivos()
{
	int i;
	FILE* Archivo;
	FILE* archivo;
	Archivo = fopen("Tiendadevideojuegos.txt", "w");
	fprintf(Archivo, "%s", "Numarticulo\tNombre\tDescripcion\tClasificacion\tGenero\tConsola\tAñodelanzamiento\tPreciounitario\n");
	for (i = 1; i <= 49; i++)
	{
		if (T[i].activo == 1)
		{
			fprintf(Archivo, "\t%d\t", T[i].num + 1);
			fprintf(Archivo, "%s\t", T[i].nombre);
			fprintf(Archivo, "%s\t", T[i].desc);
			fprintf(Archivo, "%s\t", T[i].clas);
			fprintf(Archivo, "%s\t", T[i].genero);
			fprintf(Archivo, "%s\t", T[i].consola);
			fprintf(Archivo, "%d\t\t", T[i].lanz);
			fprintf(Archivo, "%.2f", T[i].precio);
			fprintf(Archivo, "%c", '\n');
		}
	}
	fflush(Archivo);
	fclose(Archivo);
	archivo = fopen("Tiendadevideojuegos1.txt", "wb");
	fwrite(T, sizeof(Tienda), 49, archivo);
	fflush(archivo);
	fclose(archivo);
}

void leer()
{
	FILE* Archivo;
	Archivo = fopen("Tiendadevideojuegos1.txt", "rb");
	if (Archivo == NULL)
	{
		Archivo = fopen("Tiendadevideojuegos1.txt", "wb");
		fclose(Archivo);
	}
	fread(T, sizeof(Tienda), 49, Archivo);
	fflush(Archivo);
	fclose(Archivo);
}