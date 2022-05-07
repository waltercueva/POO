#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Instrumento {
protected:
	float costo;
	short anno;
	string nombre;
public:
	Instrumento() { }
	Instrumento(float costo,short anno,string nombre) {
		this->costo=costo;
		this->anno=anno;
		this->nombre=nombre;	
	}
	~Instrumento() { }
	void setCosto(float a) { costo = a; }
	void setAnno(short b) { anno = b; }
	void setNombre(string nom) { nombre = nom; }
	float getCosto() { return costo; }
	short getAnno() { return anno; }
	string getNombre() { return nombre; }
	string toString() { return to_string(costo) + " " + to_string(anno) + " " + nombre; }
};

class InstCuerda : public Instrumento {//Herencia
protected:
	short cantCuerdas;
public:
	InstCuerda(float costo, short anno, string nombre, short cantCuerdas) {
		this->costo = costo;
		this->anno = anno;
		this->nombre = nombre;	
		this->cantCuerdas = cantCuerdas;
	}
	InstCuerda() { }
	~InstCuerda() { }
	void setCantCuerdas(short a) { cantCuerdas = a; }
	short getCantCuerdas() { return cantCuerdas; }
	string toString() { return Instrumento::toString() + " " +  to_string(cantCuerdas); }
};
class InstViento : public Instrumento {
protected:
	float frecuencia;
public:
	InstViento(float costo, short anno, string nombre, short frecuencia):Instrumento(costo,anno,nombre) {
		this->frecuencia = frecuencia;	
	}
	~InstViento() { }
	void setFrecuencia(float a) { frecuencia = a; }
	float getFrecuencia() { return frecuencia; }
};
class InstPercusion : public Instrumento {
protected:
	float volumen;
public:
	InstPercusion(float costo, short anno, string nombre, float volumen) :volumen(volumen) {
		this->costo = costo;
		this->anno = anno;
		this->nombre = nombre;		
	}
	InstPercusion() { }
	~InstPercusion() { }
	void setVolumen(float a) { volumen = a; }
	float getFrecuencia() { return volumen; }
};
class Instrumentos {
	vector <Instrumento*> instrumentos;
public:
	Instrumentos() {}
	void insertar(Instrumento* i) { instrumentos.push_back(i); }
	void insercionManual() {
		short opcion;
		float costo;
		short anno;
		string nombre;
		cout << "Ingrese Tipo de Instrumento:1(Cuerda),2(Viento),3(Percusion)";
		cin >> opcion;
		cout << "Nombre: ";
		cin >> nombre;
		cout << "Costo: ";
		cin >> costo;
		cout << "Anho: ";
		cin >> anno;		
		switch (opcion) {
		case 1: {
			short c;
			cout << "Ingrese Cant de Cuerdas: ";
			cin >> c;
			instrumentos.push_back(new InstCuerda(costo, anno, nombre, c));
		};break;
		case 2: {
			float f;
			cout << "Ingrese Frecuencia: ";
			cin >> f;
			instrumentos.push_back(new InstViento(costo, anno, nombre, f));
		};break;
		case 3: {
			float v;
			cout << "Ingrese Volumen: ";
			cin >> v;
			instrumentos.push_back(new InstPercusion(costo, anno, nombre, v));
		};break;

		}
	}
	void imprimir() {
		for (size_t i = 0;i < instrumentos.size();++i)
			cout << instrumentos[i]->toString()<<"\n";
	}
};
class Controlador {
	Instrumentos coleccion;
public:
	Controlador() { ingresar();imprimir(); }
	void ingresar() {
		for(size_t i=0;i<3;++i)
		coleccion.insercionManual();
	}
	void imprimir() {
		coleccion.imprimir();
	}
};
int main() {	
	Controlador c;//implicita	
	//Controlador* c1=new Controlador();//explicita

	cin.ignore();
	cin.get();
	return 0;
}
/*
* Implementar la clase Persona
* Implementar la clase Músico,clase hija de Persona
* Implementar la clase Músicos, coleccion de objetos de la clase musico
Implementar los siguientes métodos:
* Asignar instrumento a un músico
* Eliminar instrumento a un músico
* Ordenar instrumentos por el nombre
* Obtener los 5 instrumentos mas baratos
* 
*/
