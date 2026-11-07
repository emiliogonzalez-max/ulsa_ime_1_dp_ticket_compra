# Receta: Ticket de compra

<!-- Escribe aquí tus recetas en pseudocódigo, ANTES de programar.
     Primero la receta del programa principal (main) y después una receta corta para cada módulo que vas a escribir tú.
     El primer paso de main es solo un ejemplo del formato; el resto es tuyo.
     Si las corriges después de probarlas a mano, deja aquí la versión final. -->

## Receta del programa principal (`main`)

<!-- Debe leerse casi igual que tu árbol de análisis descendente (sección 6 del README). -->

```text
1. MOSTRAR "Bienvenido a mi programa"
2. PEDIR el nombre del producto
   MIENTRAS el nombre esté vacío:
       MOSTRAR un mensaje de error
       VOLVER A PEDIR el nombre
3. PEDIR el precio
   MIENTRAS el precio sea menor o igual a 0:
       MOSTRAR un mensaje de error
       VOLVER A PEDIR el precio
4. PEDIR la cantidad
   MIENTRAS la cantidad sea menor o igual a 0:
       MOSTRAR un mensaje de error
       VOLVER A PEDIR la cantidad
5. PEDIR el descuento (en porcentaje)
   MIENTRAS el descuento sea menor que 0 o mayor que 100:
       MOSTRAR un mensaje de error
       VOLVER A PEDIR el descuento
6. CALCULAR subtotal = calcularSubtotal(precio, cantidad)
7. CALCULAR descuento = calcularDescuento(subtotal, porcentajeDescuento)
8. CALCULAR base = subtotal - descuento
9. CALCULAR iva = calcularIVA(base)
10. CALCULAR total = base + iva
11. LLAMAR imprimirTicket(nombre, cantidad, precio, subtotal, descuento, iva, total)
12. TERMINAR el programa
```

## Recetas de los módulos

<!-- Para cada módulo: qué recibe, qué hace y qué devuelve. -->

### `calcularIVA`

```text
MODULO calcularIVA(base)
  RECIBE: base = el dinero sobre el que se cobra el IVA
          (el subtotal ya sin el descuento)
  1. iva = base * 16 / 100
  2. DEVOLVER iva
FIN MODULO
```

### `imprimirTicket`

```text
MODULO imprimirTicket(nombre, cantidad, precio, subtotal, descuento, iva, total)
  RECIBE: todos los datos que se van a mostrar
  (no calcula nada y no devuelve nada, solo muestra el ticket)
  1. MOSTRAR una línea de guiones
  2. MOSTRAR "TICKET DE COMPRA"
  3. MOSTRAR una línea de guiones
  4. MOSTRAR el nombre del producto
  5. MOSTRAR la cantidad y el precio
  6. MOSTRAR "Subtotal" y su valor
  7. MOSTRAR "Descuento" y su valor
  8. MOSTRAR "IVA (16%)" y su valor
  9. MOSTRAR "Total" y su valor
  10. MOSTRAR una línea de guiones
  11. MOSTRAR "Le atendio: " y mi nombre
FIN MODULO
```

### `calcularPorcentaje` (Fase 4)

```text
MODULO calcularPorcentaje(cantidad, porcentaje)
  RECIBE: una cantidad de dinero y un porcentaje (por ejemplo 16 o 10)
  1. resultado = cantidad * porcentaje / 100
  2. DEVOLVER resultado
FIN MODULO
```

Después de este módulo, `calcularDescuento` y `calcularIVA` llaman a `calcularPorcentaje` en lugar de repetir la fórmula.

### Otros módulos que agregues (por ejemplo, para tu reto)

```text
MODULO calcularSubtotal(precio, cantidad)
  RECIBE: el precio de una pieza y cuántas piezas se compran
  1. subtotal = precio * cantidad
  2. DEVOLVER subtotal
FIN MODULO

MODULO calcularDescuento(subtotal, porcentaje)
  RECIBE: el subtotal y el porcentaje de descuento
  1. descuento = subtotal * porcentaje / 100
  2. DEVOLVER descuento
FIN MODULO
```
