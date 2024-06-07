#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
#include "zona.h"
#include "dtdepartamento.h"
#include "dtzona"

using namespace std;

class Departamento: public ICollectible {
    private:
        string letra;
        string nombre;
        ICollection * zonas;
        int cantZonas;
    public:
        Departamento(string, string);
        ~Departamento();

        // Getters

        string getLetra();
        string getNombre();
        int getCantZonas();
        ICollection * getZonas();

        // Setters

        void setLetra(string);
        void setNombre(string);
        void setCantZonas(int);

        // Agregar-Quitar (Creo que esta mal)

        void agregarZona(Zona *);
        void quitarZona(int);

        // Métodos del Departamento (DCD)

        DTDepartamento * getDTDepartamento();
        DTZona ** listarZonasDepartamento();
        Zona * elegirZona(int);
};

#endif
