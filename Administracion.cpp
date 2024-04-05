#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

// Declaracion de Objetos a Utilizar
struct Libro{
	int id;
    string titulo;
    string autor;
    string genero;
    int anioPublicacion;
    int numCopiasDisponibles;
};

struct Usuario{
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

// FUNCION PARA AÑADIR CADA USUARIO
void aniadirUsuarios(string nameUser);

// FUNCION PARA OBTENER LOS USUARIOS
void obtenerUsuarios(vector<Usuario>& usuarios);


// FUNCION PARA LEER LOS LIBROS
void obtenerLibros(vector<Libro>& libros);

// DECLARACION DE VARIABLES GLOBALES
string nameUser = "";


/********************************* FUNCION PRINCIPAL *********************************************************/
int main() {
	//Declaracion de variables con scope en el Main
    string fName, lName;
    int op; // variable para la seleccion del usuario
    
    // CREAR LOS VECTORES DE CADA OBJETO
    vector<Usuario> usuarios;
    vector<Libro> libros;
    
	
	inicio:
	system("cls");
	cout<<"+++++++++++++  ADMINISTRACION DE BIBLIOTECA +++++++++++++\n\n"<<endl;
	
    cout << "Ingrese un Nombre" << endl;
    cin >> fName;
    cout << "Ingrese un Apellido" << endl;
    cin >> lName;
    nameUser = fName + " " + lName;

	// Validar datos de entrada correctos
    if (f_validarEntrada(nameUser)) {
    	system("cls");
        cout << "**** EL NOMBRE O APELLIDO NO ES VALIDO, INTENTE NUEVAMENTE ****" << endl;
        
        /* Menu para reintentar loguearse o salir*/
        cout <<" ------- Presione:\n1. Intentar nuevamente\n0. Salir  -------"<<endl;
        cin >> op;
        if(op == 0){
        	system("cls");
        	cout<<"Ha salido del programa con exito"<<endl;
        	exit(1);
		}else if(op != 1){
			system("cls");
			cout<<"***** Seleccion invalida, intente nuevamente *****"<<endl;
			clearScreen();
		}
        
        goto inicio;
		
    } else {
	    aniadirUsuarios(nameUser);
	    obtenerUsuarios(usuarios);
    }
    

    
    // BIENVENIDA Y ACCESO AL MENU PRINCIPAL
	menu_principal:
   	system("cls");
	
    cout << "Bienvenido: " + nameUser << "\n"<<endl;
    cout <<"*** Seleccione una opcion: ***\n1. Gestion de Libros\n2. Busqueda de Libros\n3. Prestamo o Devolucion\n0. Salir"<<endl;
    cin >> op;
    
    switch(op){
    	case 1:
    		cout<<endl<<"----------------------------------------------------------------------------------------"<<endl;
    		cout<<"¿Que desea realizar?\n1. Crear Libros\n2. Modificar Libros\n3. Eliminar Libros\n4. Regresar al menu anterior\n0. Cerrar el programa"<<endl;
    		cin>>op;
    		switch(op){
    			case 1:
    				break;
    			case 2:
    				system("cls");
    				obtenerLibros(libros);
    				break;
    			case 3:
    				break;
    			case 4:
    				goto menu_principal;
    				break;
    			case 0:
    				cout<<"Ha salido del programa con exito"<<endl;
    				exit(1);
    				break;
    			default:
    				cout<<"Seleccion invalida, intente nuevamente"<<endl;
    				goto menu_principal;
    				break;
			}

    		break;
    	case 2:
    		cout<<endl<<"----------------------------------------------------------------------------------------"<<endl;
    		cout<<"¿Seleccione el metodo a buscar el libro?\n1. Buscar por titulo\n2. Buscar por autor\n3. Buscar por genero\n4. Buscar por anio"<<endl;
    		cout<<"5. Regresar al menu anterior\n0. Cerrar el programa"<<endl;
    		cin>>op;
    		
    		switch(op){
    			case 1:
    				break;
    			case 2:
    				break;
    			case 3:
    				break;
    			case 4:
    				break;
    			case 5:
    				goto menu_principal;
    				break;
    			case 0:
    				cout<<"Ha salido del programa con exito"<<endl;
    				exit(1);
    				break;
    			default:
    				cout<<"Seleccion invalida, intente nuevamente"<<endl;
    				system("pause");
    				goto menu_principal;
    				break;
			}
    		break;
    	case 3:
    		cout<<"Ha seleccionado Devolucion"<<endl;
    		break;
    	case 0:
    		system("cls");
    		cout<<"*** Ha salido con exito del programa ***"<<endl;
    		break;
    	default:
    		cout<<"El datos que ingreso es incorrecto, intente nuevamente"<<endl;
    		system("pause");
			goto menu_principal;
    		break;
	}
        
    
    return 0;
}






void aniadirUsuarios(string nameUser){
	ofstream archivoUsuarios;
	
	archivoUsuarios.open("usuarios.txt", ios::app);
	
	if(archivoUsuarios.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
	archivoUsuarios<<nameUser<<endl;
	
	archivoUsuarios.close();
}



// FUNCION PARA OBTENER USUARIOS
void obtenerUsuarios(vector<Usuario>& usuarios){
	ifstream archivoUsuarios;
	
	archivoUsuarios.open("usuarios.txt", ios::in);
	
	if(archivoUsuarios.fail()){
		cout<<"No se pudo abrir el archivo usuarios.txt"<<endl;
		exit(1);
	}
	
	string linea;
	
	while(getline(archivoUsuarios, linea)){
		Usuario usuario;
		usuario.nameUser = linea;
		usuarios.push_back(usuario);
	}
	archivoUsuarios.close();
	
	
} 


// FUNCION PARA OBTENER LIBROS
void obtenerLibros(vector<Libro>& libros){
	
	ifstream archivoLibros;
	
	archivoLibros.open("libros.txt", ios::in);
	
	if(archivoLibros.fail()){
		cerr<<"No se pudo abrir el archivo Libros.txt"<<endl;
		system("pause");
		exit(1);
	}
	string dataLibros;
	
	while(getline(archivoLibros, dataLibros)){
		
		stringstream ss(dataLibros);
        string anioPublicacionStr, numCopiasDisponiblesStr, idStr;
		
		Libro libro;
		
        getline(ss, idStr, ',');
		getline(ss, libro.titulo, ','); 
        getline(ss, libro.autor, ','); 
        getline(ss, libro.genero, ','); 
		getline(ss, anioPublicacionStr, ',');
        getline(ss, numCopiasDisponiblesStr); 
        libro.id = stoi(idStr);
        libro.anioPublicacion = stoi(anioPublicacionStr); 
        libro.numCopiasDisponibles = stoi(numCopiasDisponiblesStr);
        
        libros.push_back(libro); 
		
	}
	
 	cout << "| ID |      TITULO                          |              AUTOR            |       GENERO          | ANIO | NO. DE COPIAS |" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (const Libro& libro : libros) {
        cout << "| " << setw(3) << libro.id
             << "| " << setw(39) << libro.titulo
             << "| " << setw(30) << libro.autor
             << "| " << setw(24) << libro.genero
             << "| " << setw(4) << libro.anioPublicacion
             << "| " << setw(4) << libro.numCopiasDisponibles << " |" << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    
    system("pause");
		archivoLibros.close();
		
}