#include <iostream>
#include <string>

#include "utilerias.h"
#include "ticket.h"

int main() {
    std::cout << "Bienvenido al ticket" << std::endl;

    std::string nombre = leerCadena("¿Cuál es el producto?: ");

    double precio = leerDecimal("Precio: ");
    while (precio <= 0) {
        std::cout << "El precio debe ser mayor que 0." << std::endl;
        precio = leerDecimal("Precio: ");
    }

    int cantidad = leerEntero("Cantidad: ");
    while (cantidad <= 0) {
        std::cout << "La cantidad debe ser mayor que 0." << std::endl;
        cantidad = leerEntero("Cantidad: ");
    }

    double porcentajeDescuento = leerDecimal("Descuento (%): ");
    while (porcentajeDescuento < 0 || porcentajeDescuento > 100) {
        std::cout << "El descuento debe estar entre 0 y 100." << std::endl;
        porcentajeDescuento = leerDecimal("Descuento (%): ");
    }

    double subtotal = calcularSubtotal(precio, cantidad);
    double descuento = calcularDescuento(subtotal, porcentajeDescuento);
    double base = subtotal - descuento;
    double iva = calcularIVA(base);
    double total = base + iva;

    imprimirTicket(nombre, cantidad, precio, subtotal, descuento, iva, total);

    return 0;
}
