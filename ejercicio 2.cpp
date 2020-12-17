#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <string.h>

using namespace std;

void prueba(int& n,char producto[50][50],char mes[12][10],int anio[3],int vent [50][12][3],
			char ubicacion [50][50],float prec_unit[50],int stock[50][12][3], int stock_inicial[50][3])
{
	int i;
	
	system("cls");
	for (i=0 ; i<n ; i++)
	{
	cout << vent[0][11][2]<<endl;     
	}
	
	system ("PAUSE");
}



void ejerc1 (int& n,char marc_prod[50][50],int vent[50][12][3],int anio[3])
{	
	system("cls");
	char marc_busc[50];
	int i,j,z;
	int total[3]= {0,0,0};
	
	
	for (i=0 ; i < n ; i++)
	{
		cout << "Ingrese la marca del producto : "<< i+1<< "\n";
		cin >> marc_prod[i];
		
	}
	
	cout << "\nIngrese la marca buscada"<<endl;
	cin >> marc_busc;
		
	for(z=0 ; z<3 ; z++)
	{
		
		for (i = 0 ; i < n ; i++)
	    {
		
		
		    if (strcmp(marc_busc, marc_prod[i]) == 0)
		    {
			    for (j = 0 ; j < 12 ; j++)
			    {
					total[z] = total[z] + vent[i][j][z];
			    }
			
		    }
	    }
	}
	if (total[0] == 0)
    {
		system("cls");
		cout << "Marca no encontrada o incorrecta"<<endl;
		system ("PAUSE");
	}
	else
	{
		for ( i=0 ; i<3 ; i++)
	    {
			cout << "\n\nEl promedio de ventas de los productos marca "<<marc_busc<<" del anio "
		    << anio[i]<<" es : \n" <<total[i]<<endl;
	    }
	
	system ("PAUSE");
	}


}

void ejerc2 (int& n,int stock[50][12][3],char producto[50][50],int vent[50][12][3],char mes[12][10])
{
	int cant_min[50];
	int i,j,cont;
	cont = 0;
	system("cls");
	for( i  = 0 ; i < n ; i++)
	{
		do
		{
			cout << "ingrese la cantidad minima del producto:"<<i+1<<endl;
			cin >> cant_min[i];      // asignar cantidad minima
		}
		while (cant_min[i] < 0);
	}
	
	system("cls");
	for (i = 0  ; i < n ; i++)
	{
		if ( cant_min[i] > stock[i][11][2]) // comparacion con la existencia actual
		{
			cout << "Los productos que estan por debajo de la cantidad minima ("<<cant_min[i]<<") de "<<producto[i]<< " son:\n"
				"\nProducto\tVenta ultimo semestre\n";
			cout << "\n"<<producto[i];
			for (j = 11 ; j >= 6 ; j--)
			{
				cout << "\t\t"<< mes [j]<<"\t\t"<<vent[i][j][2]<<endl;
			}
		}
		else
		{
			cont = cont +1;
		}
		
		
	}
	
	if (cont == n)
	{
		cout << "Ningun producto esta por debajo de la cantidad minima"<<endl;
	}
	system ("PAUSE");	
}

void ejerc3 (int& n,int stock[50][12][3],char producto[50][50],int vent[50][12][3],char mes[12][10])
{
	int cant_max[50];
	int i,z,j,cont;
	int porcentaje[50][6];
	int total = 0 ;
	cont=0;
	system("cls");
	
	for(i=0 ; i<n ; i++)
    {
		do
		{
			cout << "Ingrese la cantidad maxima del producto "<<i+1<<endl;
			cin >>cant_max[i];
		} 
	    while(cant_max[i] < 0);
	}
	system("cls");
	
	
	
	for (i=0 ; i<n ; i++)
	{
		if( cant_max[i] < stock[i][11][2])  //Comparacion existencia actual
		{
			cout << "Los productos que exceden la cantidad maxima ("<<cant_max[i]<<") del producto "<<producto[i]<<" son:"<<endl;
		    cout << "\nProducto\t\tPorcentaje Venta Ultimo Semestre"<<endl;
		    cout << "\n" << producto[i];
		    for(j=11 ; j>=6 ; j--)
		    {
				for (z=0 ; z<n ; z++)
				{
					total = total + vent[z][j][2];
					
				}
				porcentaje[i][j] = (vent[i][j][2] * 100) / total ;
				total=0;
				cout << "\t\t\t"<< mes [j]<<"\t\t"<< porcentaje[i][j]<<endl;
			}
		}
		else
		{
			cont = cont +1;
		}
    }
	
	if (cont == n)
	{
		cout << "Ningun producto excede la cantidad maxima de stock"<<endl;
	}
	system("pause");
	
	
}

void ejerc4 (int& n, int anio[3], int vent[50][12][3], char mes[12][10], char producto[50][50])
{
	int i,j;
	int anio_buscado;
	int contador = 0;
	
	for (i=0 ; i<3 ; i++)
	{
		if (anio[i] == anio_buscado)
		{
			anio_buscado = anio[i];
		}
	}
	
	system("cls");
	do
	{
		cout << "Ingrese el año buscado"<<endl;
		cin >> anio_buscado;
	}
	while (anio_buscado < 2013 || anio_buscado > 2017);
	
	for (i=0 ; i<n ; i++)
	{
		for (j=0 ; j<12 ; j++)
	    {
			if (vent[i][j][2] == 0 )
			{
				cout << "No hubo ventas del producto "<<producto[i]<<" en el mes "<<mes[j]<<endl;
			}
			else
			{
				contador = contador + 1;
			}
	    }
	}
	
	if (contador == n*12)
	{
		cout << "\nHubo venta de todos los productos en "<<anio_buscado<<endl;
	}
	
	system("pause");
}

void ejerc5 ()
{
	
	
	
	
	
}

void cargardatos (int& n,char producto[50][50],char mes[12][10],int anio[3],int vent [50][12][3],
	char ubicacion [50][50],float prec_unit[50],int stock[50][12][3],int stock_inicial[50][3])
{
	
	int i,j,z,ventas;
	string nombre,ubic;
	system("cls");
	
	do
	{
		cout << "ingrese la cantidad de productos\n";
        cin >> n;
	}
	while (n <= 0);
	for(i = 0 ; i < n ; i++)
	{	
		cout << "ingrese el nombre del producto : "<< producto[i]<<"\n";
	    cin >> producto [i];
		
	}
	
	for(i = 0 ; i < n ; i++)
	{	
		do
		{
	    cout << "ingrese el stock inicial del producto : "<< producto [i]<<"\n";
		cin >> stock[n][0][2];
		}
		while (stock[n][0][2] <0);
	}
	
	for(i = 0 ; i < n ; i++)
	{
		do
		{
		cout << "ingrese el precio unitario del producto : "<< producto [i]<<"\n";
		cin >> prec_unit[i];
		}
		while ( prec_unit[i] < 0);
	}
	
	for(i = 0 ; i < n ; i++)
	{
		cout << "ingrese la ubicacion del producto : "<< producto [i]<<"\n";
		cin >> ubicacion[i];
	}
	
	for (z = 0 ; z < 3 ; z++)
	{
		for (i=0; i<n ; i++)
		{
			for( j=0 ; j < 12 ; j++)
			{
				do
				{
				cout << "ingrse cantidad de ventas del mes "<<mes [j]<< " del "
					"anio "<< anio[z]<< " del producto : "<< producto [i]<<"\n";
				cin >> ventas;
				vent [i][j][z] = ventas;
				}
				while (ventas <= 0);
			}
	    }
	}
}
	
void cargar_random(int& n,char producto[50][50],char mes[12][10],int anio[3],int vent [50][12][3],
				   char ubicacion [50][50],float prec_unit[50],int stock[50][12][3] , int stock_inicial[50][3])
{
	int i;
	int j;
	int z;
	int acumulador[50];
	
	srand(time(0));
	system("cls");
	cout << "ingrese la cantidad de productos\n";
	cin >> n;
	
	for (i=0 ; i<n ; i++)
	{
	cout << "Ingrese el nombre del producto : "<<i+1<<endl;
	cin >> producto[i];
	}
	
	for(i=0 ; i<n ; i++)
	{
		stock_inicial[i][0] = 3000+(rand()%1001);
		acumulador[i] = stock_inicial[i][0];
	}
	
	for (i = 0 ; i < n ; i++)
	{
		for (z=0; z<3 ; z++)
		{
			stock_inicial[i][z] = acumulador[i];
			
			for( j=0 ; j < 12 ; j++)
		    {
				vent [i][j][z]= rand()%101;  //asignar n° ventas random
                acumulador[i] = acumulador[i] - vent[i][j][z];  
				stock[i][j][z] = acumulador[i];
			}
			stock_inicial[i][z] = stock_inicial[i][z] - vent[i][0][z];
		}
	}
	
	
	
	for (i=0; i<n ;i++)
	{
		prec_unit [i] = rand()%51;     // asignar precio random
	}
	
	
	
}
	
void mostrar_datos	(int& n,char producto[50][50],char mes[12][10],int anio[3],int vent [50][12][3],
					 char ubicacion [50][50],float prec_unit[50],int stock[50][12][3], int stock_inicial[50][3])
{
	int i,j,z;
	system("cls");
	
	for (z = 0 ; z < 3 ; z++)
	{
		cout << "\t\t\t\t\tAño " << anio[z]<<endl;
		
		cout << "\nProducto\tExistencia\tUbicacion\tPrecio\t\tMes\tVentas"<<endl;
	    for ( i=0 ; i<n ; i++)        //mostrar datos
	    {
		    cout <<"\n"<< producto [i];
		    cout <<"\t\t"<<stock_inicial[i][z]<<"\t\t"<<ubicacion[i]<<"\t\t"<<prec_unit[i]
			<<"$\t\t"<<mes[0]<<"\t"<<vent[i][0][z]<<endl;
			
		    for (j = 1 ; j <12  ; j++)
		    {
				cout<< "\t\t"<<stock[i][j][z]<< "\t\t\t\t\t\t"<<mes[j]<<"\t"<<vent[i][j][z]<<endl;
	        }
	    }
    }
system ("PAUSE");
}



int main() 
{	
	int n,codigo;
	char producto [50][50];
	char mes [12][10] = {"enero", "febrero","marzo","abril","mayo","junio","julio",
		"agosto","setiemb","octubre","noviemb","diciemb"};
	int anio [3] = {2014,2015,2016};
	int vent [50][12][3];
	char ubicacion [50][50];
	float prec_unit [50];
	int stock [50][12][3];
	char marc_prod [50][50];
	int stock_inicial [50][3];
	
	do
	{
	do
	{
		system("cls");                              //MENNU
		cout << "Elija una opcion\n\n";
	    cout << "1)Cargar datos manualmente\n";
	    cout << "2)Cargar datos (random)\n";
	    cout << "3)Mostrar datos\n";
	    cout << "4)Calcular promedio de determinada marca (ejercicio 1)\n";
		cout << "5)Establecer valor minimos en stock (ejercicio 2)\n";
		cout << "6)Establecer valores maximos de stock (ejercicio 3)\n";
		cout << "7)Mostrar productos y periodo sin ventas (ejercicio 4)\n";
		cout << "8)salir"<<endl;
	    cin >> codigo;
	}
	while (codigo<1 || codigo>8);
		
	switch (codigo)
	{
	    case 1:
			cargardatos (n , producto, mes, anio, vent,ubicacion, prec_unit, stock, stock_inicial);
			break;
	    case 2:
			cargar_random(n,producto, mes, anio, vent,ubicacion, prec_unit, stock , stock_inicial);
			break;
	    case 3:
			mostrar_datos(n,producto, mes, anio, vent,ubicacion, prec_unit, stock, stock_inicial );
			break;
	    case 4:
			ejerc1 (n,marc_prod, vent, anio);
			break;
	    case 5:
			ejerc2 (n,stock,producto,vent,mes);
			break;
	    case 6:
			ejerc3(n,stock,producto,vent,mes);
	    case 7:
			ejerc4(n,anio,vent,mes,producto);
	}
	
	}
	while (codigo < 8);
	
	

	return 0;
}

