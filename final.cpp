#include <stdio.h>
#include <iostream>
using namespace std;


struct registro {
    int id;
    string n;
    string c;
    string t;
    registro *siguiente;
};

void push(registro *&pila,string,string,string);
void pop(registro *&);

//push de datos
void push(registro *&pila,string n,string c, string t){
	
	registro *nuevo_nodo = new registro(); 
	nuevo_nodo -> n = n;
	nuevo_nodo -> c = c;
	nuevo_nodo -> t = t;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
}

//pop de datos
void pop(registro *&pila){
	
	if(pila == NULL){
		
		cout << " la pila esta vacia!" << endl;
		
	} else{
		
		registro *aux = pila;
		string n = aux->n;
		string c = aux->c;
		string t = aux->t;
		cout << endl;
		cout << "haciendo un pop: " << endl;
		cout << "nombre: " << n << endl;
		cout << "correo: " << c << endl;
		cout << "telefono: " << t << endl;
		pila = aux->siguiente;
		delete aux;
	}
}

int main() {
	registro *pila = NULL;
    FILE* archivo;
    struct registro x;
    
    
    //escritura
    
    int i = 0;
    archivo = fopen("registros.txt", "a");
    while (i < 2) {
        cout << "nueva entrada: nombre/correo/telefono " << endl;
        cin >> x.n;
        cin >> x.c;
        cin >> x.t;
        x.id = i + 1;
        if (archivo) {
            fwrite(&x, sizeof(registro), 1, archivo);
            
            //llamada de funciones pila
           push(pila,x.n,x.c,x.t);
           
           
        }
        i++;
    }
    fclose(archivo);
    
    pop(pila);
    pop(pila);
	pop(pila);
    //lectura
    cout << "comenzando lectura: " << endl;
    
    archivo = fopen("registros.txt", "r");
    
    while (fread(&x, sizeof(registro), 1, archivo)) {
    
        cout << "nombre: " << x.n << " " << endl;
        cout << "correo: " << x.c << " " << endl;
        cout << "telefono: " << x.t << " " << endl;
      
       
    }
    fclose(archivo);
    
    system("pause");
    return 0;
}
