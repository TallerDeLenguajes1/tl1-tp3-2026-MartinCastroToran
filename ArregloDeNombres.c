#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
char buff[MAX];

void cargarArreglo(char ** vector, int tamVector);
void liberarMemoria(char ** vector, int tamVector);
void mostrarPersonas(char ** vector, int tamVector);
int buscarNombrePorPalabra(char ** vector, int tamVector,char clave[MAX]);
void buscarNombrePorID(char ** vector, int tamVector,int indice);

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

void buscarNombrePorID(char ** vector, int tamVector, int indice){
    int bandera = 0;
    int i = 0;

    while (i < tamVector || bandera == 1){
        if (indice = i){
            bandera = 1;
            printf("Nombre de la lista con indice [%d]: %s", (i + 1) , vector[i]);
        }
        i++;
    }
    if (bandera == 0){
        printf("no se encontró el valor buscado");
    }
}



int buscarNombrePorPalabra(char ** vector, int tamVector,char clave[MAX]){
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