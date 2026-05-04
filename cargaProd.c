#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char * TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
    // "CantidadProductosAPedir"
} typedef Cliente;


int cargarMenu();
void cargarClientes(int cantidadClientes, Cliente ** listaClientes);
int calcularCosto(Producto p);
int calcularCostoTotal(Cliente * l);
void mostrarResultados(Cliente ** l, int cantClientes);

int main()
{
    srand(time(NULL));
    Cliente ** listaClientes;
    int cantidadClientes;
    cantidadClientes = cargarMenu();
    listaClientes = malloc(sizeof(Cliente *) * cantidadClientes);
    cargarClientes(cantidadClientes, listaClientes);
    mostrarResultados(listaClientes, cantidadClientes);
    return 0;
}

int cargarMenu(){
    int cant;
    printf("\n\nBienvenido a la Interfaz de carga de productos para preventistas!\n\n");
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cant);
    return cant;
}

void cargarClientes(int cantidadClientes, Cliente ** listaClientes){

    for (int i = 0; i < cantidadClientes; i++)
    {
        listaClientes[i]->ClienteID = i + 1;
        printf("Ingrese el nombre del cliente \n");
        gets(listaClientes[i]->NombreCliente);
        listaClientes[i]->CantidadProductosAPedir = (rand() % 5) + 1;
        listaClientes[i]->Productos = malloc(sizeof(Producto) * listaClientes[i]->CantidadProductosAPedir);
        for (int j = 0; j < listaClientes[i]->CantidadProductosAPedir; j++)
        {
            listaClientes[i]->Productos->ProductoID = j;
            listaClientes[i]->Productos->Cantidad = (rand() % 10) + 1;
            listaClientes[i]->Productos->PrecioUnitario = (rand() % 91) + 10;
            listaClientes[i]->Productos->TipoProducto = TiposProductos[rand() % 5];
        }
        

    }
    
}

int calcularCosto(Producto p){
    return p.Cantidad * p.PrecioUnitario;
}

int calcularCostoTotal(Cliente * c){
    int suma = 0;
    for (int i = 0; i < c->CantidadProductosAPedir; i++)
    {
        suma += calcularCosto(c->Productos[i]);
    }
    
}

void mostrarResultados(Cliente ** l, int cantClientes){
    printf("Resumen de Clientes:\n\n");
    for (int i = 0; i < cantClientes; i++)
    {
        puts(l[i]->NombreCliente);
        for (int i = 0; i < l[i]->CantidadProductosAPedir; i++)
        {
            printf("ID: \n%d\n",l[i] ->Productos->ProductoID);
            printf("Tipo de Producto: %s\n",l[i] ->Productos->TipoProducto);
            printf("Precio Unitario: %f\n",l[i] ->Productos->PrecioUnitario);
            printf("Cantidad: %d\n",l[i] ->Productos->Cantidad);
        }
        printf("\nTotal: %d", calcularCostoTotal(l[i]));
        
    }
    
}
