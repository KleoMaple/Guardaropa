#include <iostream>
#include <sstream>
using namespace std;
class TipoPrenda {
    private:
        string tejido;
        string categoria;
        string nombre;
    public:
        // Constructor
        TipoPrenda(string _tejido, string _categoria, string _nombre) {
            tejido = _tejido;
            categoria = _categoria;
            nombre = _nombre;
        }
        // Constructor por defecto
        TipoPrenda() = default;
        // Getters y setters
        string getTejido() { return tejido; }
        string getCategoria() { return categoria; }
        string getNombre() { return nombre; }
        void setTejido(string _tejido) { tejido = _tejido; }
        void setCategoria(string _categoria) { categoria = _categoria; }
        void setNombre(string _nombre) { nombre = _nombre; }
};


class TamanioPrenda {
private:
int ancho;
int largo;
string talla;
public:
// Constructor
TamanioPrenda(int _ancho, int _largo) {
ancho = _ancho;
largo = _largo;
calcularTalla(); // Llamamos al método para calcular la talla
}
// Getters y setters
int getAncho() { return ancho; }
int getLargo() { return largo; }
string getTalla() { return talla; } // Agregamos el getter para la talla
void setAncho(int _ancho) { ancho = _ancho; calcularTalla(); } // Al cambiar el ancho o largo recalculamos la talla
void setLargo(int _largo) { largo = _largo; calcularTalla();}
    // Método para calcular la talla
    void calcularTalla() {
        int medida = (ancho + largo) / 2; // Calculamos la medida promedio
        if (medida < 30) {
            talla = "XS";
        } else if (medida < 35) {
            talla = "S";
        } else if (medida < 40) {
            talla = "M";
        } else if (medida < 45) {
            talla = "L";
        } else {
            talla = "XL";
        }
    }
};


class EstacionPrenda {
    private:
    string estacion;
    public:
    // Constructor
    EstacionPrenda (int _estacion){
        if (_estacion == 1){
            estacion = "Primavera";
            } else if (_estacion == 2){
                estacion = "Verano";
            } else if (_estacion == 3){
                estacion = "Otoño";
            } else {
                estacion = "Invierno";
            }
        }
   // Getter y Setter
   string getEstacion() {return estacion;}
   void setEstacion (int _estacion){
       if (_estacion == 1){
            estacion = "Primavera";
            } else if (_estacion == 2){
                estacion = "Verano";
            } else if (_estacion == 3){
                estacion = "Otoño";
            } else {
                estacion = "Invierno";
            }
       }
};


class Prenda {
    private:
        string nombre;
        EstacionPrenda estacion;
        TipoPrenda tipo;
        string color;
        TamanioPrenda tamanio;
    public:
        // Constructor
        Prenda(string _nombre, EstacionPrenda _estacion, TipoPrenda _tipo, string _color, TamanioPrenda _tamanio)
            : nombre(_nombre), estacion(_estacion), tipo(_tipo), color(_color), tamanio(_tamanio) {}
        // Getters y setters
        string getNombre() { return nombre; }
        EstacionPrenda getEstacion() { return estacion; }
        TipoPrenda getTipo() { return tipo; }
        string getColor() { return color; }
        TamanioPrenda& getTamanio() { return tamanio; } // Devolvemos una referencia a la instancia de TamanioPrenda
        string getTalla() { return tamanio.getTalla(); } // Nuevo getter para la talla
        void setNombre(string _nombre) { nombre = _nombre; }
        void setEstacion(EstacionPrenda _estacion) { estacion = _estacion; }
        void setTipo(TipoPrenda _tipo) { tipo = _tipo; }
        void setColor(string _color) { color = _color; }
        void setTamanio(TamanioPrenda _tamanio) { tamanio = _tamanio; } // Actualizamos el nombre del parámetro
};

template <typename objeto>
class listaDoble
{
    public:
        listaDoble(const listaDoble <objeto> &rhs);
        ~listaDoble();
        listaDoble(listaDoble <objeto> &&rhs);
        listaDoble();
        listaDoble <objeto> & operator=(const listaDoble <objeto> & rhs);
        void iniciar();
        bool llena ();
        void push_b(const objeto &x);
        void push_b(objeto &&x);
        bool vacia();
        void push_f(const objeto &x);
        void push_f(objeto &&x);
        void push_p(const objeto &x, int po);
        void push_p(objeto &&x, int po);
        bool validacion();
        string imprimir();

    protected:

    private:
        struct nodo
        {
            objeto dato;
            nodo *prev;
            nodo *next;
            nodo (const objeto &d=objeto{}, nodo *p=nullptr, nodo *n=nullptr):dato{d},prev{p},next{n}
            {}
            nodo (objeto &&d=objeto{}, nodo *p=nullptr, nodo *n=nullptr):dato{move(d)},prev{p},next{n}
            {}
        };
        nodo *head;
        nodo *tail;
        int tamanio;
        int capacidad;
        bool valido = true;
class iterador_const
        {
        	public:
        		iterador_const():actual{nullptr}
        		{}
        		const objeto & operator*()const
        		{
        			return recuperar();
				}
				iterador_const & operator++()
				{
					actual=actual->next;
					return *this;
				}
				iterador_const & operator++(int)
				{
					iterador_const viejo=*this;
					++(*this);
					return viejo;
				}
				bool operator== (const iterador_const &rhs)const
				{
					return actual==rhs.actual;
				}
				bool operator!=(const iterador_const &rhs)const
				{
					return !(*this==rhs);
				}
				protected:
					nodo *actual;
					objeto & recuperar() const
					{
						return actual->dato;
					}
					iterador_const (nodo *p):actual{p}
					{
					}
					friend class listaDoble <objeto>;
		};
		class iterador:public iterador_const
		{
			public:
			iterador()
			{
			}
			objeto & operator*()
			{
				return iterador_const::recuperar();
			}
			const objeto & operator*()const
			{
				return iterador_const::operator*();
			}
			iterador & operator++()
			{
				this->actual=this->actual->next;
				return *this;
			}
			iterador operator++(int)
			{
				iterador viejo=*this;
				++(*this);
				return viejo;
			}
			protected:
				friend class listaDoble <objeto>;
		};
};
template <typename objeto>
listaDoble <objeto>::listaDoble(const listaDoble <objeto> &rhs)
{
            iniciar();
            /*for(auto &x:rhs)
            push_b(x);*/
            //copy ctor
}
template <typename objeto>
listaDoble <objeto>::listaDoble(listaDoble <objeto> &&rhs):head{rhs.head},tail{rhs.tail},tamanio{rhs.tamanio},capacidad{rhs.capacidad}
{
            rhs.head=nullptr;
            rhs.tail=nullptr;
            rhs.tamanio=0;
            rhs.capacidad=10000;
}
template <typename objeto>
listaDoble <objeto>::~listaDoble()
{
	//metodo limpiar
    delete head;
    delete tail;
    //dtor
}
template <typename objeto>
listaDoble <objeto>::listaDoble()
{
    iniciar();
}
template <typename objeto>
listaDoble <objeto> & listaDoble <objeto>::operator=(const listaDoble <objeto> & rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
template <typename objeto>
void listaDoble <objeto>::iniciar()
{
	head=nullptr;
    tail=nullptr;
    tamanio=0;
    capacidad=10000;
}
template <typename objeto>
bool listaDoble <objeto>::llena()
{
    if (tamanio==capacidad)
        return true;
    else
        return false;
}
template <typename objeto>
bool listaDoble <objeto>::vacia()
{
    if(head==nullptr)
        return true;
    else
        return false;
}
template <typename objeto>
void listaDoble <objeto>::push_b(const objeto &x)
{
    if (llena()) {
        valido = false;
        return;
    }
    nodo *p=new nodo{x,nullptr,nullptr};
    if(vacia())
    {
      head=p;
      tail=p;
      tamanio++;
    }
    else
    {
    p->next=head;
    head->prev=p;
    head=p;
    tamanio++;
	}
}

template <typename objeto>
void listaDoble<objeto>::push_b(objeto &&x)
{
    if (llena()) {
        valido = false;
        return;
    }

    nodo *p = new nodo{move(x), nullptr, nullptr};
    if (vacia())
    {
        head = p;
        tail = p;
        tamanio++;
    }
    else
    {
        p->next = head;
        head->prev = p;
        head = p;
        tamanio++;
    }

    // Agregar el puntero previo en el nuevo nodo
    if (p->next != nullptr) {
        p->next->prev = p;
    }
}

template <typename objeto>
void listaDoble <objeto>::push_f(const objeto &x)
{
    if (llena()) {
        valido = false;
        return;
    }

    nodo *p = new nodo{x, tail, nullptr}; // prev = tail
    if (vacia())
    {
        head = p;
        tail = p;
    }
    else
    {
        tail->next = p; // el puntero next del último nodo apunta al nuevo nodo
        tail = p;
    }
    tamanio++;
}


template <typename objeto>
void listaDoble <objeto>::push_f(objeto &&x)
{
    if (llena()) {
        valido = false;
        return;
    }

    nodo *p = new nodo{x, tail, nullptr}; // prev = tail
    if (vacia())
    {
        head = p;
        tail = p;
    }
    else
    {
        tail->next = p; // el puntero next del último nodo apunta al nuevo nodo
        tail = p;
    }
    tamanio++;
}
template <typename objeto>
void listaDoble <objeto>::push_p(const objeto &x, int po)
{
    if (llena()) {
        valido = false;
        return;
    }

    if (po < 0 || po > tamanio) {
        valido = false;
        return;
    }

    if (po == 0) { // insertar al principio
        push_b(x);
        return;
    }

    if (po == tamanio) { // insertar al final
        push_f(x);
        return;
    }

    nodo *p = new nodo{x, nullptr, nullptr};
    nodo *q = head;
    for (int i = 0; i < po-1; i++) {
        q = q->next;
    }
    p->prev = q; // el puntero prev del nuevo nodo apunta al nodo anterior
    p->next = q->next; // el puntero next del nuevo nodo apunta al nodo siguiente
    q->next->prev = p; // el puntero prev del nodo siguiente apunta al nuevo nodo
    q->next = p; // el puntero next del nodo anterior apunta al nuevo nodo
    tamanio++;
}


template <typename objeto>
void listaDoble<objeto>::push_p(objeto&& x, int po) {
    if (llena()) {
        valido = false;
        return;
    }

    if (po < 0 || po > tamanio) {
        valido = false;
        return;
    }

    if (po == 0) { // insertar al principio
        push_b(x);
        return;
    }

    if (po == tamanio) { // insertar al final
        push_f(x);
        return;
    }

    nodo *p = new nodo{x, nullptr, nullptr};
    nodo *q = head;
    for (int i = 0; i < po-1; i++) {
        q = q->next;
    }
    p->prev = q; // el puntero prev del nuevo nodo apunta al nodo anterior
    p->next = q->next; // el puntero next del nuevo nodo apunta al nodo siguiente
    q->next->prev = p; // el puntero prev del nodo siguiente apunta al nuevo nodo
    q->next = p; // el puntero next del nodo anterior apunta al nuevo nodo
    tamanio++;
}
template <typename objeto>
bool listaDoble<objeto>::validacion() {
    if (tamanio > capacidad) {
    valido = false;
    return false;
    }
    else {
        if(valido==true)
        {
            return true;
        }
        else{
            return false;
        }
    }
}
void agregarElemento(listaDoble<Prenda>& listaPrendas, listaDoble<EstacionPrenda>& listaEstaciones) {
                int opcion;
                cout << "----- AGREGAR -----" << endl;
                cout << "1. Agregar al principio" << endl;
                cout << "2. Agregar al final" << endl;
                cout << "3. Agregar en una posición especifica" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opcion;

                switch (opcion) {
                    case 1: {
                        // Agregar al principio
                        // Lógica para agregar al principio en las listas
                        break;
                    }
                    case 2: {
                        // Agregar al final
                        // Lógica para agregar al final en las listas
                        break;
                    }
                    case 3: {
                        // Agregar en una posición específica
                        // Lógica para agregar en una posición específica en las listas
                        break;
                    }
                    default: {
                        cout << "Opcion invalida." << endl;
                        break;
                    }
                }
            }
void eliminarElemento(listaDoble<Prenda>& listaPrendas, listaDoble<EstacionPrenda>& listaEstaciones) {
                int opcion;
                cout << "----- ELIMINAR -----" << endl;
                cout << "1. Eliminar al principio" << endl;
                cout << "2. Eliminar al final" << endl;
                cout << "3. Eliminar en una posicion especifica" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opcion;

                switch (opcion) {
                    case 1: {
                        // Eliminar al principio
                        // Lógica para eliminar al principio en las listas
                        break;
                    }
                    case 2: {
                        // Eliminar al final
                        // Lógica para eliminar al final en las listas
                        break;
                    }
                    case 3: {
                        // Eliminar en una posición específica
                        // Lógica para eliminar en una posición específica en las listas
                        break;
                    }
                    default: {
                        cout << "Opcion invalida." << endl;
                        break;
                    }
                }
            }

void editarElemento(listaDoble<Prenda>& listaPrendas, listaDoble<EstacionPrenda>& listaEstaciones) {
    // Lógica para editar un elemento en la lista que sea localizable a partir de alguna característica
    // Invocar la función de búsqueda binaria para localizar el elemento y obtener su ubicación
    // Desplegar las opciones de edición y facilitar el proceso
}

void buscarElemento(listaDoble<Prenda>& listaPrendas, listaDoble<EstacionPrenda>& listaEstaciones) {
    // Lógica para buscar un elemento en la lista a partir de un valor numérico característico
    // Devolver su dirección si se encuentra o un indicativo de que no se encuentra
}

void ordenarElementos(listaDoble<Prenda>& listaPrendas, listaDoble<EstacionPrenda>& listaEstaciones) {
    // Lógica para ordenar los elementos de las listas a partir de un atributo entero, como folio
}

void mostrarElementos(listaDoble<Prenda>& listaPrendas, listaDoble<EstacionPrenda>& listaEstaciones) {
    int opcion;
    cout << "----- MOSTRAR ELEMENTOS -----" << endl;
    cout << "1. Mostrar todas las prendas" << endl;
    cout << "2. Mostrar todas las estaciones" << endl;
    cout << "3. Mostrar una prenda especifica" << endl;
    cout << "4. Mostrar una estación específica" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1: {
            // Mostrar todas las prendas
            // Lógica para mostrar todas las prendas en la listaPrendas
            break;
        }
        case 2: {
            // Mostrar todas las estaciones
            // Lógica para mostrar todas las estaciones en la listaEstaciones
            break;
        }
        case 3: {
            // Mostrar una prenda específica
            // Invocar la función de búsqueda para localizar la prenda y mostrarla
            break;
        }
        case 4: {
            // Mostrar una estación específica
            // Invocar la función de búsqueda para localizar la estación y mostrarla
            break;
        }
        default: {
            cout << "Opcion invalida." << endl;
            break;
        }
    }
}

void menu(listaDoble<Prenda>& listaPrendas, listaDoble<EstacionPrenda>& listaEstaciones) {
    int opcion;

    do {
        cout << "----- MENU -----" << endl;
        cout << "1. Agregar elemento" << endl;
        cout << "2. Eliminar elemento" << endl;
        cout << "3. Editar elemento" << endl;
        cout << "4. Buscar elemento" << endl;
        cout << "5. Ordenar elementos" << endl;
        cout << "6. Mostrar elementos" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                agregarElemento(listaPrendas, listaEstaciones);
                break;
            }
            case 2: {
                eliminarElemento(listaPrendas, listaEstaciones);
                break;
            }
            case 3: {
                editarElemento(listaPrendas, listaEstaciones);
                break;
            }
            case 4: {
                buscarElemento(listaPrendas, listaEstaciones);
                break;
            }
            case 5: {
                ordenarElementos(listaPrendas, listaEstaciones);
                break;
            }
            case 6: {
                mostrarElementos(listaPrendas, listaEstaciones);
                break;
            }
            case 7: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default: {
                cout << "Opcion inválida." << endl;
                break;
            }
        }

    } while (opcion != 7);
}

int main() {
    listaDoble<Prenda> listaPrendas;
    listaDoble<EstacionPrenda> listaEstaciones;

    menu(listaPrendas, listaEstaciones);

    return 0;
}
