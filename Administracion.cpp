#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Declaracion de Objetos a Utilizar
struct Libro{
    string titulo;
    string autor;
    string genero;
    int anioPublicacion;
    int numCopiasDisponibles;
    double nota;
};

struct Usuario{
	int idUser;
	string nameUser;
};

struct Prestamo{
	string nameUser;
	string tituloLibro;
};

// DECLARACION DE FUNCIONES GLOBALES

// Valida que los datos de entrada no sean numericos o con signo
bool f_validarEntrada(const string& cadena) {
    for (char caracter : cadena) {
        if (isdigit(caracter) || ispunct(caracter)) {
            return true;
        }
    }
    return false;
}

//Funcion para limpiar pantalla
void clearScreen(){
	system("pause");
	system("cls");
}


int idUser = 000;
string nameUser = "";

int main() {
	//Declaracion de variables con scope en el Main
    string fName, lName, lName2;
    int op; // variable para la seleccion del usuario
    
    vector<Usuario> usuarios;
    
    Usuario usuario;
	
	inicio:
	cout<<"+++++++++++++  ADMINISTRACION DE BIBLIOTECA +++++++++++++\n\n"<<endl;
	
    cout << "Ingrese un Nombre" << endl;
    cin >> fName;
    cout << "Ingrese un Apellido" << endl;
    cin >> lName;
    nameUser = fName + " " + lName;

	// Validar datos de entrada correctos
    if (f_validarEntrada(nameUser)) {
        cout << "La entrada no es valida, intentelo nuevamente" << endl;
		clearScreen();
        
        goto inicio;
    } else {
    	getline(cin, usuario.nameUser);
    	system("cls");
    	usuarios.push_back(usuario);
    }
    
    
    ofstream archivoUsuarios("usuarios.txt");
    
    if(!archivoUsuarios.is_open()){
    	cerr<<"Error al abrir el archivo";
    	return 1;
	}
	
	for (const Usuario &usuario : usuarios){
		archivoUsuarios << nameUser << endl;
	}
	
	archivoUsuarios.close();
    
    // BIENVENIDA Y ACCESO AL MENU PRINCIPAL
    cout << "Bienvenido: " + nameUser << "\n"<<endl;
    cout <<"*** Seleccione una opcion: ***\n1. Consulta de un Libro\n2. Prestamo de Libro\n3. Devolucion de Libro\n4. Salir"<<endl;
    cin >> op;
    
    switch(op){
    	case 1:
    		cout<<"Ha seleccionado consulta"<<endl;
    		break;
    	case 2:
    		cout<<"Ha seleccionado Prestamo"<<endl;
    		break;
    	case 3:
    		cout<<"Ha seleccionado Devolucion"<<endl;
    		break;
    	case 4:
    		cout<<"Ha seleccoinado Salir"<<endl;
    		break;
    	default:
    		cout<<"El datos que ingreso es incorrecto"<<endl;
    		break;
	}
        
    
    return 0;
}