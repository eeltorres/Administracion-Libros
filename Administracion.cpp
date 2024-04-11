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

// FUNCION PARA AÑADIR LIBRO
void aniadirLibro(Libro& libro);

// FUNCION OBTENER ULTIMO ID
int obtenerUltimoId();

//FUNCION PARA INYECTAR LOS DATOS MODIFICADOS
void actualizarLibros(vector<Libro>& libros);

// DECLARACION DE VARIABLES GLOBALES
string nameUser = "";



/********************************* FUNCION PRINCIPAL *********************************************************/
int main() {
	//Declaracion de variables con scope en el Main
    string fName, lName;
    int op, op_1; // variable para la seleccion del usuario
    
    // CREAR LOS VECTORES DE CADA OBJETO
    vector<Usuario> usuarios;
    vector<Libro> libros;
    
    // DECLARAR OBJETO
	Libro libro;
    
	
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
    		cout << endl <<"----------------------------------------------------------------------------------------"<<endl;
    		cout << "¿Que desea realizar?\n1. Crear Libros\n2. Modificar Libros\n3. Eliminar Libros\n4. Regresar al menu anterior\n0. Cerrar el programa"<<endl;
    		cin >> op_1;
    		
    		switch(op_1){
    			case 1:
    				system("cls");
    				
    				libro.id = obtenerUltimoId() + 1; 
    				cout <<"Ingrese Titulo del Libro: ";
    				cin >> libro.titulo;
    				cout <<"Ingrese Autor del Libro: ";
    				cin >> libro.autor;
    				cout << "Ingrese Genero del Libro: ";
    				cin >> libro.genero;
    				cout << "Ingrese Anio de Publicacion: ";
    				cin >> libro.anioPublicacion;
    				cout << "Ingrese no. de Copias Disponibles: ";
    				cin >> libro.numCopiasDisponibles;
    				
    				aniadirLibro(libro);
    				break;
    			case 2:
    				system("cls");
    				obtenerLibros(libros);
    				
    				cout << "\nSeleccione el numero de Libro que desea modificar: ";
    				cin >> op;
    				op = op -1;
    				
    				system("cls");
	    				cout << "Titulo anterior: " << libros[op].titulo << endl;
	    				cout << endl << "Ingrese el nuevo Titulo a Modificar: ";
	    				getline(cin, libros[op].titulo);
	    				
	    				cout << "Autor anterior: " << libros[op].titulo << endl;
	    				cout << endl << "Ingrese el nuevo Autor a modificar: " ;
	    				getline(cin, libros[op].autor);
	    				
	    				cout << "Genero anterior: " << libros[op].genero;
	    				cout << "Ingrese el nuevo genero a modificar: ";
	    				getline(cin, libros[op].genero);
	    				
	    				cout << "Anio de publicacion anterior: " << libros[op].anioPublicacion << endl;
	    				cout << "Anio de publicacion nuevo a modificar: ";
	    				getline(cin, libros[op].anioPublicacion);
	    				
	    				cout << "Numero de Copias disponibles actualmente: " << libros[op].noCopiasDisponibles << endl;
	    				cout << "Numero de Copias disponibles a modificar :";
	    				getline(cin, libros[op].noCopiasDisponibles);
	    				
	    				system ("pause");
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
        
    system("cls");
    cout << "Si desea volver al menu principal presione 1, si desea salir presione cualquier tecla " <<endl;
    cin >> op;
    
    if(op == 1){
    	goto menu_principal;
	}
	system("cls");
	cout << " HA TERMINADO EL PROGRAMA "<< endl;

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
    
	archivoLibros.close();
		
}

// AÑADIR LIBRO
void aniadirLibro(Libro& libro){
	ofstream archivoLibros;
	
	archivoLibros.open("libros.txt", ios::app);
	
	if(archivoLibros.fail()){
		cout<<"Hubo un error al abrir el archivo libros.txt"<<endl;
		exit(1);
	}
	
	archivoLibros << libro.id<<", "<<libro.titulo<<", "<<libro.autor<<", "<<libro.genero<<", "<<libro.anioPublicacion<<", "<<libro.numCopiasDisponibles<<endl;
	
	archivoLibros.close();
	cout << "Libro agregado con Exito"<< endl;
}


// OBTENER ULTIMO ID
int obtenerUltimoId(){
	
	ifstream archivoLibros;
	
	archivoLibros.open("libros.txt", ios::in);
	
	if(archivoLibros.fail()){
		cerr<<"No se pudo abrir el archivo Libros.txt"<<endl;
		system("pause");
		exit(1);
	}
	
	string dataLibros;
	int lastId;
	
	while(getline(archivoLibros, dataLibros)){
		stringstream ss(dataLibros);
		
        string idStr;
        getline(ss, idStr, ',');
		
		int id = stoi(idStr);
        if (id > lastId) {
            lastId = id; // Actualizar el último id si es mayor que el actual
        }
	}
	
	archivoLibros.close();
	
	return lastId;
}

//FUNCION PARA INYECTAR LOS DATOS MODIFICADOS
void actualizarLibros(vector<Libro>& libros){
	
	ofstream archivoLibros;
	
	archivoLibros.open("libros.txt");
	
	if(archivoLibros.fail()){
		cerr<<"Hubo un error al abrir el archivo libros.txt"<<endl;
		exit(1);
	}
	
	for (const Libro libro& : libros){
		
	}
	
}