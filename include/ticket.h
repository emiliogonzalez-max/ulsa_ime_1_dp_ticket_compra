#pragma once

#include <iostream>
#include <iomanip>
#include <string>

const int TASA_IVA = 16;
const int ANCHO_TICKET = 36;
const std::string ATENDIDO_POR = "Emilio";

inline double calcularPorcentaje(double cantidad, double porcentaje) {
    return cantidad * porcentaje / 100;
}

inline double calcularSubtotal(double precio, int cantidad) {
    return precio * cantidad;
}

inline double calcularDescuento(double subtotal, double porcentaje) {
    return calcularPorcentaje(subtotal, porcentaje);
}

inline double calcularIVA(double base) {
    return calcularPorcentaje(base, TASA_IVA);
}

inline void imprimirLinea() {
    std::cout << std::string(ANCHO_TICKET, '-') << std::endl;
}

inline void imprimirRenglon(std::string etiqueta, double monto) {
    std::cout << std::left << std::setw(12) << etiqueta;
    std::cout << "$" << std::right << std::setw(ANCHO_TICKET - 13) << monto << std::endl;
}

inline void imprimirTicket(std::string nombre, int cantidad, double precio,
                           double subtotal, double descuento, double iva, double total) {
    std::cout << std::fixed << std::setprecision(2);

    imprimirLinea();
    std::cout << "TICKET DE COMPRA" << std::endl;
    imprimirLinea();
    std::cout << "Producto: " << nombre << std::endl;
    std::cout << cantidad << " x $" << precio << std::endl;
    imprimirRenglon("Subtotal:", subtotal);
    imprimirRenglon("Descuento:", descuento);
    std::cout << std::left << std::setw(12) << ("IVA (" + std::to_string(TASA_IVA) + "%):");
    std::cout << "$" << std::right << std::setw(ANCHO_TICKET - 13) << iva << std::endl;
    imprimirRenglon("Total:", total);
    imprimirLinea();
    std::cout << "Le atendio: " << ATENDIDO_POR << std::endl;
}
