#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
char buff[MAX];

void cargarArreglo(char ** vector, int tamVector);
void liberarMemoria(char ** vector, int tamVector);
void mostrarPersonas(char ** vector, int tamVector);
int buscarNombre(char ** vector, int tamVector,char clave[MAX]);

int main(){
    char ** vector; //Vector puntero de punteros
    int tamNombre, tamVector = 5, valor;
    vector = malloc(sizeof(char *) * tamVector);
    cargarArreglo(vector, tamVector);
    mostrarPersonas(vector, tamVector);
    
    valor = buscarNombre(vector, tamVector, "martin");

    liberarMemoria(vector, tamVector);
}



void cargarArreglo(char ** vector, int tamVector){
    int tamNombre;
    for (int i = 0; i < tamVector; i++){ //Itero para solicitar y luego almacenar los 5 nombres
        scanf("%49s", buff);
        tamNombre = strlen(buff); //Obtengo la cantidad de caracteres del nombre
        vector[i] = malloc(sizeof(char) * tamNombre + 1); //Reservo la memoria necesaria para el nombre
        strcpy(vector[i], buff); //Copio el contenido de buff en la cadena
    }
}

void liberarMemoria(char ** vector, int tamVector){
    for (int i = 0; i < tamVector; i++)
    {
        free(vector[i]);
    }
    free(vector);
}

void mostrarPersonas(char ** vector, int tamVector){
    for (int i = 0; i < tamVector; i++){ //Itero para solicitar y luego almacenar los 5 nombres
        printf("Nombre numero [%d]: %s \n",(i + 1), vector[i]); 
    }
}

int buscarNombre(char ** vector, int tamVector,char clave[MAX]){
    for (int i=0; i < tamVector; i++){

        if (strstr(vector[i], clave) != NULL)
        {
            printf("Nombre encontrado en la posicion [%d]: %s \n", (i + 1), vector[i]);
            return 0;
        }
    }
    printf("Nombre no encontrado");
    return -1;
}