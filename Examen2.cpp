#include <iostream>
#include <fstream>
using namespace std;

double calcularTotal(double cantidad, double precio, char pago) {
    double subtotal = cantidad * precio;
    double descuento = 0;

    if (subtotal >= 500) {
        descuento += subtotal * 0.05;
    }

    if ((pago == 'E' || pago == 'e') && subtotal >= 300) {
        descuento += subtotal * 0.02;
    }

    return subtotal - descuento;
}

void mostrarMenu() {
    cout << "\n Sistema de Control de Ventas" << endl;
    cout << "1. Registrar una ventas" << endl;
    cout << "2. Mostrar todas las ventas" << endl;
    cout << "3. Generar reporte generarl" << endl;
    cout << "4. Buscar ventas por monto" << endl;
    cout << "5. Salir del sistema" << endl;
}

void registrarVentas() {
    ofstream archivo("Ventas.txt", ios::app);

    string cliente, producto;
    int cantidad, precio;
    char continuar;
    char pago;
    do {
        cin.ignore();

        cout << "Ingresa el nombre completo del cliente: ";
        getline(cin, cliente);

        cout << "Ingresa el producto: ";
        cin >> producto;

        cout << "Ingresa la cantidad de productos: ";
        cin >> cantidad;

        cout << "Ingresa el precio unitario de ventas: ";
        cin >> precio;

        cout << "Forma de pago (E=efectivo, T=tarjeta): ";
        cin >> pago;

        double total = calcularTotal(cantidad, precio, pago);

        if (pago == 'E' || pago == 'e') {
            cout << "Forma de pago: Efectivo" << endl;
        } else if (pago == 'T' || pago == 't') {
            cout << "Forma de pago: Tarjeta" << endl;
        } else {
            cout << "Forma de pago: Desconocida" << endl;
        }

        cout << "Total a pagar: Q" << total << endl;

        cout << "Desea continuar (s/n): ";
        cin >> continuar;

    } while(continuar == 's' || continuar == 'S');

    cout << "Datos registrados correctamente!\n";

    archivo.close();
}

int main() {
    int opcion;

    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarVentas();
                break;
            case 2:
                cout << "Salir" << endl;
                break;

        }

    }while (opcion != 2);

    cout << "\n Programa realizado por: Luis Fernando Cruz Franco";

    return 0;
}