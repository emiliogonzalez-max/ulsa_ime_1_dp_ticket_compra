#include <iostream>
#include <string>

#include "utilerias.h"
#include "ticket.h"

int main() {
    std::string nombre = "";
    double precio = 0.0;
    int cantidad = 0;
    double porcentajeDescuento = 0.0;

    double subtotal = 0.0;
    double descuento = 0.0;
    double base = 0.0;
    double iva = 0.0;
    double total = 0.0;

    std::cout << "Bienvenido a mi programa" << std::endl;

    nombre = leerTexto("Nombre del producto: ");
    while (nombre == "") {
        std::cout << "El nombre no puede estar vacio." << std::endl;
        nombre = leerTexto("Nombre del producto: ");
    }

    precio = leerDouble("Precio: ");
    while (precio <= 0) {
        std::cout << "El precio debe ser mayor que 0." << std::endl;
        precio = leerDouble("Precio: ");
    }

    cantidad = leerEntero("Cantidad: ");
    while (cantidad <= 0) {
        std::cout << "La cantidad debe ser mayor que 0." << std::endl;
        cantidad = leerEntero("Cantidad: ");
    }

    porcentajeDescuento = leerDouble("Descuento (%): ");
    while (porcentajeDescuento < 0 || porcentajeDescuento > 100) {
        std::cout << "El descuento debe estar entre 0 y 100." << std::endl;
        porcentajeDescuento = leerDouble("Descuento (%): ");
    }

    subtotal = calcularSubtotal(precio, cantidad);
    descuento = calcularDescuento(subtotal, porcentajeDescuento);
    base = subtotal - descuento;
    iva = calcularIVA(base);
    total = base + iva;

    imprimirTicket(nombre, cantidad, precio, subtotal, descuento, iva, total);

    return 0;
}
