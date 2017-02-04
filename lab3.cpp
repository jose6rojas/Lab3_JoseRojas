// viernes, 3 de febrero de 2017

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int menu();
int menu_fechas();
// int menu_consulta();
string calcularDia(int, int, int, string);
string calcularMes(int);

int main()
{
	vector<string> cadenas;
	cout << "Laboratorio 3 - Jose Rojas - 11541234" << endl;	
	int op_principal = 0;
	while(op_principal != 3)
	{
		op_principal = menu();
		if(op_principal == 1)
		{
			int op_fechas = 0;
			while(op_fechas != 5)
			{				
				op_fechas = menu_fechas();
				if(op_fechas == 1) // Ingresar una fecha
				{
					string fecha;
					bool leapYear;
					cout << "Ingrese una fecha en formato YYYYMMDD: ";
					cin >> fecha;
					if(fecha.length() != 8)
					{
						cout << "Debe ingresar una cadena de 8 caracteres." << endl;
						break;
					}
					else
					{
						string year = fecha.substr(0, 4);
						int y = stoi(year);
						if(y <= 0 || y > 2017)
						{
							cout << "Debe ingresar un year valido (> 0 y <= 2017)" << endl;
							break;
						}
						else // year valido
						{
							if(y % 4 == 0 && y % 100 == 0 && y % 400 == 0) // verifica si y es leap year
								leapYear = true;
							string mes = fecha.substr(4, 2);
							if(stoi(mes) <= 0 || stoi(mes) > 12)
							{
								cout << "Debe ingresar un mes valido (> 00 y <= 12)" << endl;
								break;
							}
							else // mes valido
							{
								string dia = fecha.substr(6, 2);
								if(stoi(dia) <= 0 || stoi(dia) > 31)
								{
									cout << "Debe ingresar un dia valido (> 00 y <= 31)\n";
									break;
								}
								else // dia valido
								{
									if(!leapYear && stoi(mes) == 2 && stoi(dia) > 28)
									{
										cout << "Este year no es bisiesto\n";
										break;
									}
									else if(stoi(mes) == 2 && stoi(dia) > 28)
									{
										cout << "Febrero solo tiene 28 dias\n";
										break;
									}
									// fecha valida
									cadenas.push_back(fecha);
									cout << "Fecha agregada correctamente" << endl;
									/* cout << calcularDia(stoi(year), stoi(mes), stoi(dia)) << ", " << stoi(dia) << " " << calcularMes(stoi(mes)) << " de " << stoi(year) << endl; */								}
							}
						}
					} // fin Ingresar una fecha
				}
				else if(op_fechas == 2) // Listar todo
				{
					for(int i = 0; i < cadenas.size(); i++)
					{
						cout << cadenas[i] << endl;
					}
				}
				else if(op_fechas == 3) // Listar ordenado
				{
				}
				else if(op_fechas == 4) // Listar por consulta
				{
				}
				else if(op_fechas == 5)
					break;
			}
		}
		else if(op_principal == 2)
		{
			// Minesweeper
		}
		else if(op_principal == 3)
			break;
	}
	return 0;
}

int menu()
{
	int opcion;
        cout << "Menu Principal\n";
        cout << "\t1. Fechas\n";
        cout << "\t2. Minesweeper\n";
        cout << "\t3. Salir\n";
        cout << "\tEscoja una opcion: ";
        cin >> opcion;
        return opcion;
}

int menu_fechas()
{
	int opcion;
	cout << "Menu - Ejercicio de Fechas\n";
	cout << "\t1. Ingresar una fecha\n";
	cout << "\t2. Listar todo\n";
	cout << "\t3. Listar ordenado\n";
	cout << "\t4. Listar por consulta\n";
	cout << "\t5. Salir\n";
	cout << "\tEscoja una opcion: ";
	cin >> opcion;
	return opcion;
}

string calcularDia(int year, int mes, int d, string y)
{
	/* bool leapYear;
	if(year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
		leapYear = true;
	int M;
	if(leapYear)
	{
		if(mes == 1)
			M = 0;
		else if(mes == 2)
			M = 3;
		else if(mes == 3)
			M = 3;
		else if(mes == 4)
			M = 6;
		else if(mes == 5)
			M = 1;
		else if(mes == 6)
			M = 4;
		else if(mes == 7)
			M = 6;
		else if(mes == 8)
			M = 2;
		else if(mes == 9)
			M = 5;
		else if(mes == 10)
			M = 0;
		else if(mes == 11)
			M = 3;
		else if(mes == 12)
			M = 5;
	}
	else
	{
		if(mes == 1)
                        M = 0;
                else if(mes == 2)
                        M = 3;
                else if(mes == 3)
                        M = 4;
                else if(mes == 4)
                        M = 0;
                else if(mes == 5)
                        M = 2;
                else if(mes == 6)
                        M = 5;
                else if(mes == 7)
                        M = 0;
                else if(mes == 8)
                        M = 3;
                else if(mes == 9)
                        M = 6;
                else if(mes == 10)
                        M = 1;
                else if(mes == 11)
                        M = 4;
                else if(mes == 12)
                        M = 6;
	}
	int D;
	D = ((year - 1) % 7 + ((year - 1) / 4 - 3 * ((year - 1) / 100 + 1) / 4) % 7 + M + d % 7) % 7;
	
	int A;
	if(year >= 1700 && year < 1799)
		A = 5;
	else if(year >= 1800 && year < 1899)
		A = 3;
	else if(year >= 1900 && year < 1999)
		A = 1;
	else if(year >= 2000 && year < 2099)
		A = 0;
	
	double B;
	string digitos = y.substr(2, 2);
	
	
	string day;
	if(d = 0)
		day = "domingo";
	else if(d = 1)
		day = "lunes";
	else if(d = 2)
		day = "martes";
	else if(d = 3)
		day = "miercoles";
	else if(d = 4)
		day = "jueves";
	else if(d = 5)
		day = "viernes";
	else if(d = 6)
		day = "sabado";
	return day; */
}

string calcularMes(int mes)
{
	string month;
	if(mes == 1)
		month = "enero";
	else if(mes == 2)
		month = "febrero";
	else if(mes == 3)
		month = "marzo";
	else if(mes == 4)
		month = "abril";
	else if(mes == 5)
		month = "mayo";
	else if(mes == 6)
		month = "junio";
	else if(mes == 7)
		month = "julio";
	else if(mes == 8)
		month = "agosto";
	else if(mes == 9)
		month = "septiembre";
	else if(mes == 10)
		month = "octubre";
	else if(mes == 11)
		month = "noviembre";
	else if(mes == 12)
		month = "diciembre";
	return month;
}
