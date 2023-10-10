#include <stdlib.h>
#include <iostream>
using namespace std;

class info{
	public:
		int ISBN;
		string title;
		int total_amount;
		int sell;
		int buy;
		int value_buy;
		int value_sell;
		
		info (){
			ISBN = 10000;
			title = "none";
			value_buy = 8000;
			value_sell = 10000;
			total_amount = 0;
			sell = 0;
			buy = 0;
		}
		
		void crear (int ISBN_number, string name, int num_buy, int num_sell){
			ISBN = ISBN_number;
			title = name;
			value_buy = num_buy;
			value_sell = num_sell;
			total_amount = 1;
		}
		
		virtual void details (){
			cout << "ID: " << ISBN << endl;
			cout << "TITULO: " << title << endl;
			cout << "CANTIDAD: " << total_amount << endl;
			cout << "VALOR DE VENTA: " << sell << endl;
			cout << "VALOR DE COMPRA: " << buy << endl;
		}
		
};

class book: public info {
	public:
		
		void details (int& total_cash){
			cout << "ID: " << ISBN << endl;
			cout << "TITULO: " << title << endl;
			cout << "CANTIDAD: " << total_amount << endl;
			cout << "VALOR DE VENTA: " << value_sell << endl;
			cout << "VALOR DE COMPRA: " << value_buy << endl;
			cout << "CANTIDAD VENDIDA: " << sell << endl;
			cout << "CANTIDAD COMPRADA:" << buy << endl;
			
			int select;
				cout << "Desea realizar alguna compra o venta" << "\n1. SI" << "\n2. NO"<< endl;
				cin >> select;
			
					if (select == 1){
						cout << "comprar (1) o vender (2)" << endl;
						 	cin >> select;
						 		if ( select == 1){
						 			menu_buy(total_cash);
						 		} else if(select == 2){
								 menu_sell(total_cash);
								}
						 			
					}
		}
		
		void menu_sell(int& total_cash){
			int amount_sell;
			bool control = true;
			
				while (control){
				
					cout << "Cuantos libros quiere vender" << endl;
					cin >> amount_sell;
				
						if (amount_sell > 0) {
							control = false;
							book_sell(amount_sell, total_cash);							
						}
				}
		}
		
		void menu_buy(int& total_cash){
			int amount_buy;
			bool control = true;
			
				while (control){
				
					cout << "Cuantos libros quiere comprar" << endl;
					cin >> amount_buy;
				
						if (amount_buy > 0) {
							control = false;
							book_buy(amount_buy, total_cash);							
						}
				}
		}
		
		void book_sell(int amount_sell, int& total_cash){
			for(int i = 1; i <= amount_sell; i++){
				total_cash += value_sell;
			}
			
			sell += amount_sell;
			total_amount -= amount_sell; 
			
			cout << total_cash << endl;
			
		}
		
		void book_buy(int amount_buy, int& total_cash){
			for(int i = 1; i <= amount_buy; i++){
				total_cash -= value_buy;
			}
			
			buy += amount_buy;
			total_amount += amount_buy;
			
			cout << total_cash << endl;
			
		}
		
		
		
};


int select, search, salir, ID, number_sell, number_buy, isbn_delete, delete_confirm, position, book_select, new_book = 1, new_isbn = 10001;
string word, title_name;
bool verify, notFound = true;

int main()
{
	int total_cash = 1000000;
	book* libro = new book[1000];
	
	
	do {
	
	cout << "\t\t\tBIENVENIDO\n\n" << "Dinero disponible: " << total_cash << "\n\n\t1.Buscar Libro\n" << "\t2.Agregar Libro\n" << "\t3.Eliminar Libro\n" << "\t4.Filtro\n" << "\t5.Catalogo Completo" << endl;
	cin >>select;
	system("cls");
	switch (select){
		
		case 1:	
			cout << "Buscar libro por: \n" << "\t1.Titulo \n" << "\t2.ISBN" << endl;
			cin >> search;
			system("cls");
			
				if (search == 1){
					cout << "\tEscriba el titulo del libro" << endl;
					cin >> word;
								 
						for (int i = 1; i <= 100; i++ ){
							if ( word == libro[i].title)			
								cout << i << ". " << libro[i].title << endl;
						}
						
							cin >> book_select;
							libro[book_select].details(total_cash);
							

				} else if (search == 2){
					cout << "\t\tEscriba el ISBN del libro" << endl;
					cin >> ID;
							 
						for (int i = 1; i <= 100; i++ ){
							if ( ID == libro[i].ISBN)
								cout << "\t" << i << ". " << libro[i].title << endl;					
						}
						
							cin >> book_select;
							libro[book_select].details(total_cash);								
				} 
			system("pause");
			system("cls");
		break;
		
		case 2:
			
			do {
				verify = false;
				cout << "\tIntroduzca el titulo del libro (usar '_' para los espacios entre palabras)" << endl;
				cin >> title_name;
				
				cout << "\tDigite el valor de compra" << endl;
				cin >> number_buy;
				
				cout << "\tDigite el valor de venta" << endl;
				cin >> number_sell;
				
					if ( number_sell < number_buy || number_buy <= 0 || number_sell <= 0){
						verify = true;
						cout << "\t\tResgistro invalido" << endl;
					}
				
			} while(verify == true);
				
				libro[new_book].crear(new_isbn, title_name, number_buy, number_sell);
				cout << "\t\tresgistro exitoso" << endl;
				new_book++;
				new_isbn++;
	
			system ("pause");
			system ("cls");
		break;
		
		case 3:
			
			cout << "\tDigite el ISBN del libro a eliminar" << endl;
			cin >> isbn_delete;
				
					for (int i = 1; i <= 100; i++ ){
							if ( isbn_delete == libro[i].ISBN){
								position = i;
								cout << "Quiere eliminar el libro " << libro[i].title << "\n\t-SI" << "\n\t-NO" << endl;
								cin >> delete_confirm;
									
									if (delete_confirm == 1){
										for (int i = position; i < 100; i++){
											libro[i] = libro[i+1];
										}
										
											cout << "t\t\t\tEliminacion exitosa" << endl;
											notFound = false;
									} else {
										cout << "\t\t\tEliminacion cancelada" << endl;
										notFound = false;
									}
										
							}											
					}
					if (notFound){
						cout << "\t\tLibro no encontrado" << endl;
					}
				
			system("pause");
			system("cls");			
		break;		
		case 4:
		break;
		
		case 5:
			for (int i = 1; i <= 100; i++){
				cout << "-" << libro[i].title << endl; 
			}
				system("pause");
				system("cls");
		break;
	}
    
	 
	
	cout << "Desea volver al menu de inicio\n" << "\t1.volver\n" << "\t2.salir" << endl;
	cin >> salir;
	system("cls");
	} while ( salir == 1);


    return 0;
}
