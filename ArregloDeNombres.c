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
int mostrarMenuOpciones();

int main(){
    char ** vector; //Vector puntero de punteros
    char palabraClave[MAX];
    int tamNombre, tamVector = 5, valor, opcion, indice;
    vector = malloc(sizeof(char *) * tamVector);
    cargarArreglo(vector, tamVector);

    mostrarPersonas(vector, tamVector);
    opcion = mostrarMenuOpciones();
    if (opcion == 1)
    {
        printf("Ingrese el indice del valor que desea buscar: ");
        scanf("%d", &indice);
        buscarNombrePorID(vector, tamVector, indice + 1);
    } else
    {
        printf("Ingrese una palabra clave: ");
        gets(palabraClave);
        buscarNombrePorPalabra(vector, tamVector, palabraClave);
    }
    liberarMemoria(vector, tamVector);

    return 0;
}



void cargarArreglo(char ** vector, int tamVector){
    int tamNombre;
    for (int i = 0; i < tamVector; i++){ //Itero para solicitar y luego almacenar los 5 nombres
        gets(buff);
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
        printf("Nombre numero [%d]: \n",(i + 1));
        puts(vector[i]);
    }
}

void buscarNombrePorID(char ** vector, int tamVector, int indice){
    int bandera = 0;
    int i = 0;

    while (i < tamVector && bandera == 0){
        if (indice == i){
            bandera = 1;
            printf("Nombre de la lista con indice [%d]: ", (i + 1));
            puts(vector[i]);
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
            printf("Nombre encontrado en la posicion [%d]: \n", (i + 1));
            puts(vector[i]);
            return 0;
        }
    }
    printf("Nombre no encontrado");
    return -1;
}

int mostrarMenuOpciones(){
    int opcion;
    printf("\n\n Elija como desea buscar el Nombre: \n");
    printf("1. Por ID \n");
    printf("2. Por palabra clave \n");
    scanf("%d", &opcion);
    return opcion;
}

