#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;


class Menu
{
	private:
		// 	COMO ATRIBUTOS TENEMOS LAS OPCIONES DEL MENU ALMACENADAS EN UN ARRAY DE 'STRINGS'
		string opciones[3];
		bool salir; // Evaluamos si queremos salir
		public:
			Menu() //Constructor donde limpiamos todas las posiciones
			{
				for(int i = 0; i < 3; i++)
				{
					this->opciones[i] = "";
				}
				this->opciones[0] = ">"; // Iniciamos en una posicion
				this->salir = false; // Comenzamos como falsa la opcion de salir
			}
			
			//		METODO SALUDAR
			string Saludar(string n)
			{
				return "Hola " + n;
			}
			
			string Hablar()
			{
				return "HOLA ESTOY HABLANDO";
			}
			
			
			int ObtenerPosicion()
			{
				for(int i = 0; i < 3; i++)
				{
					if(this->opciones[i] != "") // Si encontramos la opcion entonces retornamos la posicion de esta
					{
						return i; // RETORNAMOS
						break;
					}
				}
			}
			
			void Principal()
			{
				
				do
				{
					system("cls");
					cout << "	MENU	" << endl;
					cout << this->opciones[0] << " Saludar" << endl;
					cout << this->opciones[1] << " Hablar" << endl;
					cout << this->opciones[2] << " Salir" << endl;
					cout << "Ingrese una opcion" << endl;
					//getch();
					/*if(kbhit())
					{*/
						char tecla = getch();
						if(tecla == 72)
						{
							int posicion = this->ObtenerPosicion();
							if(posicion >=0 && posicion < 3)
							{
								this->opciones[posicion] = "";
								this->opciones[posicion - 1] = ">";
							}
						}
						else if(tecla == 80)
						{
							int pocision = this->ObtenerPosicion();
							if(pocision >= 0 && pocision < 3)
							{
								this->opciones[pocision] = "";
								this->opciones[pocision + 1] = ">";
							}
						}
						else if(tecla == 13)
						{
							system("cls");
							if(this->ObtenerPosicion() == 0)
							{
								string nombre;
								cout << "Ingrese su nombre" << endl;
								cin >> nombre;
								cout << this->Saludar(nombre) << endl;
								system("pause");
							}
							else if(this->ObtenerPosicion() == 1)
							{
								cout << this->Hablar() << endl;
								system("pause");
							}
							else
							{
								salir = true;
							}
						}
						else if(tecla == 27)
						{
							salir = true;
						}
					//}
				}while(!salir);
			}
};



int main()
{
	Menu a = Menu();
	a.Principal();
	system("pause");
}

