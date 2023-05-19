#include <iostream>
#include <string>
using namespace std;

class MaterialBibliografico {
protected:
    string titulo;
    string autor;
    string editorial;
    int fechaPublicacion;
public:
    MaterialBibliografico(const string& _titulo, const string& _autor, const string& _editorial, int _fechaPublicacion)
        : titulo(_titulo), autor(_autor), editorial(_editorial), fechaPublicacion(_fechaPublicacion) {}

    virtual ~MaterialBibliografico() {}

    virtual void mostrarInformacion() const {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Editorial: " << editorial << endl;
        cout << "Fecha de publicación: " << fechaPublicacion << endl;
    }
};

class Libro : private MaterialBibliografico {
private:
    int numeroPaginas;

public:
    Libro(const string& _titulo, const string& _autor, const string& _editorial, int _fechaPublicacion, int _numeroPaginas)
        : MaterialBibliografico(_titulo, _autor, _editorial, _fechaPublicacion), numeroPaginas(_numeroPaginas) {}

    void mostrarInformacion() const {
        MaterialBibliografico::mostrarInformacion();
        cout << "Numero de paginas: " << numeroPaginas << endl;
    }
};

class Revista : protected MaterialBibliografico {
private:
    int numeroEdicion;

public:
    Revista(const string& _titulo, const string& _autor, const string& _editorial, int _fechaPublicacion, int _numeroEdicion)
        : MaterialBibliografico(_titulo, _autor, _editorial, _fechaPublicacion), numeroEdicion(_numeroEdicion) {}

    void mostrarInformacion() const {
        MaterialBibliografico::mostrarInformacion();
        cout << "Numero de edicion: " << numeroEdicion << endl;
    }
};

class Tesis : public MaterialBibliografico {
private:
    string formato;

public:
    Tesis(const string& _titulo, const string& _autor, const string& _editorial, int _fechaPublicacion, const string& _formato)
        : MaterialBibliografico(_titulo, _autor, _editorial, _fechaPublicacion), formato(_formato) {}

    void mostrarInformacion() const {
        MaterialBibliografico::mostrarInformacion();
        cout << "Tesis en formato: " << formato << endl;
    }
};

class Articulo : public MaterialBibliografico {
private:
    string autorArticulo;
public:
    Articulo(const string& _titulo, const string& _autor, const string& _editorial, int _fechaPublicacion, const string& _autorArticulo)
        : MaterialBibliografico(_titulo, _autor, _editorial, _fechaPublicacion), autorArticulo(_autorArticulo) {}

    void mostrarInformacion() const {
        MaterialBibliografico::mostrarInformacion();
        cout << "Autor del artículo: " << autorArticulo<<endl;
    }
};
int main() {
    Libro libro("El Gran Gatsby", "F. Scott Fitzgerald", "Scribner", 1925, 180);
    libro.mostrarInformacion();
    cout << endl;

    Revista revista("National Geographic", "Varios", "National Geographic Society", 2023, 150);
    revista.mostrarInformacion(); 
    cout << endl;

    Tesis tesis("Tesis de Doctorado", "John Smith", "Universidad XYZ", 2022, "IEEE");
    tesis.mostrarInformacion();
    cout << endl;

    Articulo articulo("Artículo Científico", "Jane Doe", "Journal of Science", 2023, "Dra. María López");
    articulo.mostrarInformacion();

    return 0;
}