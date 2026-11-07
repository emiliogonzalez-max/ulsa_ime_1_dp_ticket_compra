# Práctica: Ticket de compra
 
> Llena cada sección en la fase que se indica. Las instrucciones completas están en `PRACTICA.md`.
> Si una pregunta no aplica (por ejemplo, no hiciste el Experimento C o no tuviste dudas), escribe `No aplica`. Si te sobran filas en una tabla, bórralas.
 
## 1. Descripción del problema (Fase 1)
 
Mi programa pide los datos de un producto (nombre, precio, cantidad y descuento), revisa que sean válidos y calcula cuánto debe pagar el cliente. Al final muestra un ticket con el subtotal, el descuento, el IVA y el total. Serviría en la caja de una tienda pequeña para no hacer las cuentas a mano.
 
## 2. Entradas y salidas (Fase 1)
 
**Entradas:**
 
| Entrada | Tipo de dato | Función de `utilerias.h` |
|---|---|---|
| Nombre del producto | `std::string` | `leerTexto` |
| Precio | `double` | `leerDouble` |
| Cantidad | `int` | `leerEntero` |
| Descuento (%) | `double` | `leerDouble` |
 
**Salida** (¿qué datos muestra el ticket?):
El nombre del producto, la cantidad, el precio, el subtotal, el descuento, el IVA, el total y la línea "Le atendio:" con mi nombre.
 
**¿El IVA se calcula sobre el subtotal o sobre lo que queda después del descuento? ¿Por qué?**
Sobre lo que queda después del descuento. El descuento baja el precio real de la venta, y el IVA es un impuesto sobre lo que de verdad se vende. Por ejemplo, con subtotal 100 y descuento 10, el IVA es el 16 % de 90, o sea 14.40, que coincide con la tabla de pruebas.
 
## 3. Restricciones e invariante (Fases 1 y 2)
 
**Restricciones** (¿qué debe cumplirse?):
 
| Dato | ¿Qué valores son válidos? | ¿Por qué? |
|---|---|---|
| Nombre del producto | Texto que no esté vacío | Un ticket sin nombre no dice qué se compró |
| Precio | Número mayor que 0 | Un producto no puede costar 0 ni tener precio negativo |
| Cantidad | Entero mayor que 0 | No se pueden comprar 0 piezas, ni piezas negativas, ni media pieza |
| Descuento (%) | Número de 0 a 100 | Menos de 0 sería un recargo, y más de 100 dejaría un total negativo |
 
**¿Qué hace mi programa si el usuario escribe un dato fuera de rango?**
Muestra un mensaje de error y vuelve a pedir el dato con un ciclo `while`. Lo repite hasta que el dato sea válido, y no sigue con el cálculo antes de eso.

**¿Puede el total salir negativo? ¿Por qué?**
No. El descuento máximo es 100 %, así que el descuento nunca es mayor que el subtotal. Entonces `subtotal - descuento` nunca baja de 0, y el IVA tampoco es negativo.
 
**Invariante 1** (después del ciclo que valida el precio, ¿qué es siempre cierto sobre `precio`?):
`precio > 0`. El ciclo no termina hasta que se cumple.
 
**Invariante 2** (¿qué relación se cumple siempre entre el subtotal, el descuento, el IVA y el total?):
`total = subtotal - descuento + IVA`
 
## 4. Casos resueltos a mano (Fase 1)
 
| Caso | Nombre | Precio | Cantidad | Descuento (%) | Subtotal | Descuento ($) | IVA | Total |
|---|---|---|---|---|---|---|---|---|
| 1 (sin descuento) | Cuaderno | 100.00 | 1 | 0 | 100.00 | 0.00 | 16.00 | 116.00 |
| 2 (con descuento) | Cuaderno | 50.00 | 2 | 10 | 100.00 | 10.00 | 14.40 | 104.40 |
| 3 (precio con centavos) | Lapiz | 19.99 | 1 | 0 | 19.99 | 0.00 | 3.20 | 23.19 |


## 5. Tipo de dato abstracto (Fase 1)
 
| TDA | Datos (¿qué tiene?) | Operaciones (¿qué se puede hacer con él?) |
|---|---|---|
| Producto | nombre (texto), precio (decimal), cantidad (entero) | calcular su subtotal |
| Ticket | producto, descuento (%), subtotal, descuento ($), IVA, total, quién atendió | calcular el descuento, calcular el IVA, calcular el total, imprimirse |
 
**Jerarquías:** una tienda vende productos por pieza (un cuaderno) y productos por peso (un kilo de tortillas). ¿Los dos son productos? ¿Qué datos tienen en común y cuál cambia?
Sí, los dos son productos. Tienen en común el nombre y el precio (por pieza o por kilo). Lo que cambia es la cantidad: en uno es un número entero de piezas y en el otro es un peso con decimales (por ejemplo 1.5 kg). El subtotal se calcula igual (precio por cantidad), pero el tipo de dato de la cantidad es distinto.
 
## 6. Análisis descendente (Fase 2)
 
```
Generar ticket de compra
├── 1. Mostrar bienvenida
├── 2. Pedir los datos
│     ├── 2.1 Pedir el nombre del producto (ya existe: función de utilerias.h)
│     ├── 2.2 Pedir el precio (y validar que sea mayor que 0) (ya existe: función de utilerias.h)
│     ├── 2.3 Pedir la cantidad (y validar que sea mayor que 0) (ya existe: función de utilerias.h)
│     └── 2.4 Pedir el descuento (y validar que esté entre 0 y 100) (ya existe: función de utilerias.h)
├── 3. Calcular los importes
│     ├── 3.1 Calcular el subtotal (ya existe: calcularSubtotal)
│     ├── 3.2 Calcular el descuento (ya existe: calcularDescuento)
│     ├── 3.3 Calcular el IVA sobre lo que queda tras el descuento (lo escribo yo: calcularIVA)
│     └── 3.4 Calcular el total (subtotal - descuento + IVA)
└── 4. Imprimir el ticket (lo escribo yo: imprimirTicket)
```
 
**Análisis ascendente: ¿qué partes del árbol ya estaban resueltas por una función que existe? ¿Cuáles?**
Pedir cada dato (las funciones de `utilerias.h`), calcular el subtotal (`calcularSubtotal`) y calcular el descuento (`calcularDescuento`). Las que me faltaba escribir eran `calcularIVA` e `imprimirTicket`.
 
**¿Alguna parte del árbol hacía más de una cosa? ¿Cómo la dividiste?**
"Pedir los datos" hacía cuatro cosas, así que la dividí en una rama por dato. "Calcular los importes" también, y la dividí en subtotal, descuento, IVA y total. Así cada rama tiene una sola tarea.
 
## 7. Módulos y receta (Fase 2)
 
| Módulo | ¿Qué recibe? | ¿Qué devuelve? | ¿Función o procedimiento? |
|---|---|---|---|
| `calcularSubtotal` | precio, cantidad | el subtotal | Función |
| `calcularDescuento` | subtotal, porcentaje | el monto del descuento | Función |
| `calcularIVA` | base (subtotal menos descuento) | el monto del IVA | Función |
| `imprimirTicket` | nombre, cantidad, precio, subtotal, descuento, IVA, total | nada (solo muestra en pantalla) | Procedimiento |
| `calcularPorcentaje` | cantidad, porcentaje | el porcentaje de esa cantidad | Función |
 
**¿Probé mi receta a mano con mis 3 casos?** Sí
**¿Tuve que corregirla? ¿Qué cambié?** Sí, un poco. Al principio calculaba el IVA sobre el subtotal. Al probar a mano el caso 2 el IVA no coincidía con 14.40, así que lo cambié para que se calcule sobre el subtotal menos el descuento.
 
## 8. Cómo compilar y ejecutar (Fase 3)
 
Compilar (desde la carpeta del proyecto):
 
```bash
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o ticket
```
 
Ejecutar en macOS:
 
```bash
./ticket
```
 
Ejecutar en Windows:
 
```bash
.\ticket.exe
```
 
**¿En qué sistema operativo trabajé?** Windows
 
## 9. Ejemplo de ejecución (Fase 3)
 
```
Bienvenido a mi programa
Nombre del producto: Cuaderno
Precio: 50
Cantidad: 2
Descuento (%): 10
------------------------------------
TICKET DE COMPRA
------------------------------------
Producto: Cuaderno
2 x $50.00
Subtotal:        $100.00
Descuento:        $10.00
IVA (16%):        $14.40
Total:           $104.40
------------------------------------
Le atendio: Tu Nombre
```
 
## 10. De la receta al código (Fase 3)
 
| Paso de la receta | Módulo o instrucción de C++ que lo implementa |
|---|---|
| 1. Mensaje de bienvenida | `std::cout << "Bienvenido a mi programa" << std::endl;` |
| 2. Pedir el nombre y validar que no esté vacío | `leerTexto` dentro de un `while (nombre == "")` |
| 3. Pedir el precio y validar que sea mayor que 0 | `leerDouble` dentro de un `while (precio <= 0)` |
| 4. Pedir la cantidad y validar que sea mayor que 0 | `leerEntero` dentro de un `while (cantidad <= 0)` |
| 5. Pedir el descuento y validar que esté entre 0 y 100 | `leerDouble` dentro de un `while (porcentajeDescuento < 0 \|\| porcentajeDescuento > 100)` |
| 6. Calcular el subtotal | `subtotal = calcularSubtotal(precio, cantidad);` |
| 7. Calcular el descuento | `descuento = calcularDescuento(subtotal, porcentajeDescuento);` |
| 8. Calcular la base | `base = subtotal - descuento;` |
| 9. Calcular el IVA | `iva = calcularIVA(base);` |
| 10. Calcular el total | `total = base + iva;` |
| 11. Imprimir el ticket | `imprimirTicket(nombre, cantidad, precio, subtotal, descuento, iva, total);` |
 
**¿Hubo algún paso de mi receta que me costó traducir a C++? ¿Cuál y por qué?**
Me costó el paso de volver a pedir el dato cuando está fuera de rango. En la receta decía "mientras el dato esté mal, vuelve a pedirlo" y tuve que entender que eso es un `while`: el programa revisa la condición y repite la pregunta hasta que el dato ya es válido.

**Formato del ticket: ¿qué ancho usé en `std::setw` y por qué? ¿Qué pasa si uso un número menor que el largo de la etiqueta más larga?**
Usé un ancho mayor que la etiqueta más larga ("Descuento"), para que todos los valores queden alineados en columna. Si uso un número menor que el largo de la etiqueta, `setw` no la recorta: la etiqueta se imprime completa, y esa línea se desalinea.
 
**¿Convertí el ancho de las líneas del ticket (36) en una constante? ¿Cómo la llamé? Si no, ¿por qué?**
Sí, la llamé `ANCHO_TICKET`. Así el 36 aparece en un solo lugar y, si el ticket cambia de ancho, se cambia una sola línea.
 
## 11. Experimentos y depuración (Fase 3)
 
**Experimento A: depuración de `calcularDescuento`**
 
| Paso de depuración | Lo que hice o encontré |
|---|---|
| 1. Reproduce: ¿con qué datos falló? | Con Cuaderno, 50, 2, 10 el descuento no salió 10.00 como en mi cálculo a mano. |
| 2. Aísla: ¿qué valor intermedio estaba mal? (salidas `[DEBUG]`) | Puse un `cout` con `[DEBUG]` dentro de `calcularDescuento` para ver el subtotal, el porcentaje y el resultado. El subtotal (100) y el porcentaje (10) estaban bien, pero el resultado no. |
| 3. Explica: ¿cuál era la causa? | La fórmula de la función estaba mal escrita: no calculaba `subtotal * porcentaje / 100`. |
| 4. Corrige: ¿qué cambiaste? | Corregí la fórmula a `subtotal * porcentaje / 100`. |
| 5. Limpia: ¿comentaste tus salidas `[DEBUG]`? | Sí |
 
**La prueba con 0 % pasó aunque la función tenía un error. ¿Qué me enseña eso sobre elegir mis casos de prueba?**
Con 0 % el descuento es 0 sin importar cómo esté hecha la fórmula, así que el error quedó escondido. Aprendí que no basta con probar el caso fácil: hay que probar valores "normales" (como 10 % o 15 %) y también los extremos (0 % y 100 %).
 
**Experimento B: al cambiar el IVA a 8 %, ¿cuántas líneas tuve que cambiar? ¿Qué mejoraría?**
Tuve que cambiar una sola línea, la de la constante `TASA_IVA`. Antes de usar la constante, el 16 estaba escrito en varios lugares, y eso era más fácil de equivocar. Lo mejoré guardando la tasa en un solo lugar.
 
**¿Mi ticket seguía diciendo `IVA (16%)`? ¿Qué hice al respecto?**
Sí, porque ese texto estaba escrito a mano y no cambiaba con la constante. Lo arreglé imprimiendo el valor de `TASA_IVA` dentro del texto, en lugar de escribir "16" directamente.
 
**Experimento C (opcional): al cambiar el parámetro dentro de `calcularIVA`, ¿cambió la variable de `main()`? ¿Por qué?**
No cambió. Los parámetros se reciben por valor, o sea que la función trabaja con una copia. Lo que se modifica adentro de la función no afecta a la variable original de `main()`.
 
## 12. La constante "Le atendio" (Fase 3)
 
**¿Dónde definí la constante con mi nombre?** (marca una)
- [ ] Constante local dentro de `imprimirTicket`
- [x] Constante a nivel de la librería, en `ticket.h`
- [ ] Función que siempre devuelve la misma cadena
**¿Por qué elegí esa opción?**
Porque así el nombre está escrito en un solo lugar y cualquier función de `ticket.h` lo puede usar, no solo `imprimirTicket`.
 
**¿Qué otras partes del programa podrían necesitar el nombre de quien atiende? (un mensaje de bienvenida, un ticket de devolución...)**
El mensaje de bienvenida ("Le atiende..."), un ticket de devolución, un reporte del día o un recibo de pago.
 
**Si mañana atiende otra persona, ¿en cuántos lugares tengo que cambiar el nombre?**
En uno solo: la línea de la constante en `ticket.h`.
 
**Si el nombre se leyera del teclado o de un archivo, ¿cuánto código tendría que cambiar con mi opción?**
Poco: cambiaría solo la línea donde se define el nombre (en vez de una constante sería una variable que se lee) y las funciones que lo usan recibirían ese valor. El resto del código quedaría igual.
 
## 13. Tabla de pruebas (Fase 4)
 
| # | Caso | Esperado (subtotal / descuento / IVA / total) | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| 1 | Sin descuento | 100.00 / 0.00 / 16.00 / 116.00 | 100.00 / 0.00 / 16.00 / 116.00 | Sí |
| 2 | Con descuento | 100.00 / 10.00 / 14.40 / 104.40 | 100.00 / 10.00 / 14.40 / 104.40 | Sí |
| 3 | Descuento de 15 % | 600.00 / 90.00 / 81.60 / 591.60 | 600.00 / 90.00 / 81.60 / 591.60 | Sí |
| 4 | Precio con centavos | 19.99 / 0.00 / 3.20 / 23.19 | 19.99 / 0.00 / 3.20 / 23.19 | Sí |
| 5 | Descuento total | 90.00 / 90.00 / 0.00 / 0.00 | 90.00 / 90.00 / 0.00 / 0.00 | Sí |
| 6 | Precio inválido | vuelve a pedir el precio dos veces; 40.00 / 0.00 / 6.40 / 46.40 | Pidió el precio otra vez dos veces; 40.00 / 0.00 / 6.40 / 46.40 | Sí |
| 7 | Cantidad inválida | vuelve a pedir la cantidad dos veces; 20.00 / 0.00 / 3.20 / 23.20 | Pidió la cantidad otra vez dos veces; 20.00 / 0.00 / 3.20 / 23.20 | Sí |
| 8 | Descuento inválido | vuelve a pedir el descuento dos veces; 100.00 / 20.00 / 12.80 / 92.80 | Pidió el descuento otra vez dos veces; 100.00 / 20.00 / 12.80 / 92.80 | Sí |
| 9 | Texto en el precio | vuelve a pedir el precio una vez; 100.00 / 0.00 / 16.00 / 116.00 | Pidió el precio otra vez una vez; 100.00 / 0.00 / 16.00 / 116.00 | Sí |
| 10 | Nombre con espacios | muestra el nombre completo; 25.50 / 0.00 / 4.08 / 29.58 | Mostró el nombre completo; 25.50 / 0.00 / 4.08 / 29.58 | Sí |
| 11 | Nombre vacío | vuelve a pedir el nombre una vez; 12.00 / 0.00 / 1.92 / 13.92 | Pidió el nombre otra vez una vez; 12.00 / 0.00 / 1.92 / 13.92 | Sí |
| 12 | Caso propio 1: precio 10.00, cantidad 3, descuento 50 % | 30.00 / 15.00 / 2.40 / 17.40 | 30.00 / 15.00 / 2.40 / 17.40 | Sí |
| 13 | Caso propio 2: precio 0.50, cantidad 1, descuento 0 % | 0.50 / 0.00 / 0.08 / 0.58 | 0.50 / 0.00 / 0.08 / 0.58 | Sí |
 
**En el caso 4 el IVA real es 3.1984. ¿Por qué mi ticket muestra 3.20?**
Porque el ticket está configurado para mostrar solo 2 decimales (`std::fixed` y `std::setprecision(2)`), que es como se manejan los pesos. El número se redondea al imprimirlo, pero el valor guardado sigue siendo 3.1984.
 
**En el caso 10, ¿el ticket siguió alineado? Si no, ¿qué corregí?**
Sí, siguió alineado, porque usé `setw` solo para los números y el nombre se imprime en su propia línea. Así un nombre largo o con espacios no mueve las columnas.
 

## 14. Generalización (Fase 4)
 
**¿Qué cálculo hacen `calcularDescuento` y `calcularIVA`? ¿Qué cambia entre una y otra?**
Las dos calculan un porcentaje de una cantidad (`cantidad * porcentaje / 100`). Cambian los datos que reciben: el descuento es un porcentaje del subtotal y el IVA es un porcentaje de la base (subtotal menos descuento), con 16 %.
 
**Receta de `calcularPorcentaje`** (también va en `RECETA.md`):
 
```text
MODULO calcularPorcentaje(cantidad, porcentaje)
  RECIBE: una cantidad de dinero y un porcentaje (por ejemplo 16 o 10)
  1. resultado = cantidad * porcentaje / 100
  2. DEVOLVER resultado
FIN MODULO
```
 
**¿Cómo quedaron el descuento y el IVA después del cambio?**
Ahora los dos usan `calcularPorcentaje`. El descuento es `calcularPorcentaje(subtotal, porcentajeDescuento)` y el IVA es `calcularPorcentaje(base, TASA_IVA)`. La fórmula está escrita una sola vez.
 
**¿Volví a correr toda la tabla de pruebas después del cambio? ¿Todo siguió pasando?**
Sí, volví a correr los 13 casos y todo siguió pasando.
 
**¿Agregué `calcularPorcentaje` a mi tabla de módulos (sección 7)?** Sí
 
**¿En qué otro programa podría reutilizar `calcularPorcentaje`?**
En un programa de propinas, de comisiones de ventas, de intereses de un préstamo o de calificaciones (por ejemplo, el porcentaje de aciertos de un examen).
 
## 15. Revisión de calidad (Fase 4)
 
| Principio | Pregunta | ¿Lo cumple? | Evidencia |
|---|---|---|---|
| Correcto | ¿Pasa todas las pruebas de la tabla? | Sí | Los 13 casos de la sección 13 pasan |
| Robusto | ¿Resiste datos inválidos sin fallar ni terminar? | Sí | Casos 6 a 11: vuelve a pedir el dato y no se cierra |
| Legible | ¿Otra persona entiende tu código sin que se lo expliques? | Sí | Nombres claros de variables y comentarios `// Paso N` |
| Modular | ¿Cada función hace una sola cosa? | Sí | Unas funciones calculan y otra imprime; `calcularIVA` no imprime |
| Sin números mágicos | ¿Los valores fijos tienen nombre? | Sí | `TASA_IVA` y `ANCHO_TICKET` |
| Fácil de mantener | Si cambia el IVA o quien atiende, ¿cuántas líneas cambias? | Sí | Una línea en cada caso (las constantes en `ticket.h`) |
| Reutilizable | ¿Alguna de tus funciones serviría en otro programa? | Sí | `calcularPorcentaje` |
 
## 16. Reto obligatorio (Fase 4)
 
**¿Qué reto elegí?** (número y nombre; el 4 no cuenta como obligatorio) [CAMBIA: pon el número y nombre del reto que elijas de PRACTICA.md]
 
**¿Por qué lo elegí?**
[CAMBIA: una o dos frases con tu razón, por ejemplo "porque me pareció el que más se parecía a lo que ya había practicado"]
 
**¿Cómo lo resolví? ¿Qué módulos agregué o cambié?**
[CAMBIA: di qué módulo agregaste o cambiaste]
 
**¿Hice algún otro reto opcional? ¿Cuál?**
No aplica
 
## 17. Bitácora de mejoras (Fase 4)
 
| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | La fórmula de `calcularDescuento` daba un resultado incorrecto | Corregí la fórmula a `subtotal * porcentaje / 100` | Sí |
| 2 | El 16 del IVA estaba escrito en varios lugares | Lo pasé a la constante `TASA_IVA` | Sí |
 
## 18. Dudas para el profesor (Fase 3)
 
| Duda | Lo que ya intenté |
|---|---|
| No aplica | No aplica |
 
## 19. Reflexión final
 
**¿Qué aprendí con esta práctica?**
Aprendí que es más fácil resolver un problema si lo divido en partes pequeñas, donde cada parte hace una sola cosa. También aprendí a escribir la receta en pseudocódigo antes de programar, y a revisar los datos antes de usarlos.
 
**Ahora que terminé, ¿qué cambiaría de mi proceso?**
Probaría cada módulo apenas lo escribo, y no hasta el final, y haría commits más seguido.
 
**¿Qué fue lo más difícil y cómo lo resolví?**
Lo más difícil fue encontrar el error de `calcularDescuento`, porque con 0 % todo parecía bien. Lo resolví probando con un descuento distinto de 0 y mostrando valores con `[DEBUG]` para ver en qué parte cambiaba el resultado.
 
**¿Qué pregunta me quedó sin responder?**
No aplica
 
**Comparado con las prácticas anteriores, donde todo estaba en `main()`, ¿dividir el programa en módulos me facilitó o me complicó el trabajo? ¿Por qué?**
Me facilitó el trabajo, porque cuando algo salía mal sabía en qué módulo buscar el error y podía probar cada parte por separado. Al principio fue más trabajo organizarlo, pero después fue más fácil de cambiar.
 
**¿Cómo encontré el error de `calcularDescuento`? ¿Lo habría encontrado si solo hubiera probado sin descuento?**
Lo encontré probando con un descuento de 10 % y mostrando valores intermedios con `[DEBUG]`. No lo habría encontrado probando solo sin descuento, porque con 0 % el resultado sale bien aunque la fórmula esté mal.

## 20. Commits (Fase 5)

**¿Cuántos commits hice durante la práctica?** 12

**Si hice menos de 3, ¿por qué?**
no 

## 21. Lista de verificación antes de entregar (Fase 5)

- [x] Llené las secciones 1 a 20 (no quedan `_____`; escribí `No aplica` donde corresponde)
- [x] Completé el árbol de análisis descendente y la tabla de módulos
- [x] Escribí en `RECETA.md` la receta de `main` y la de cada módulo, antes de programar
- [x] Cada bloque de `main.cpp` tiene su comentario `// Paso N`, de acuerdo con mi receta
- [x] Corregí el error de `calcularDescuento` y documenté cómo lo encontré
- [x] Hice los Experimentos A y B y dejé el código correcto al terminar
- [x] Mi ticket se ve alineado y termina con la línea "Le atendio:", leída de una constante
- [x] Justifiqué dónde definí la constante con mi nombre
- [x] Escribí `calcularPorcentaje` y volví a correr todas las pruebas
- [x] Hice al menos uno de los retos y lo documenté
- [x] No queda ninguna salida `[DEBUG]` activa
- [x] Mi programa compila sin advertencias
- [x] Probé todos los casos de la tabla
- [x] Revisé los principios de calidad de mi programa
- [x] No modifiqué `utilerias.h`
- [x] Tengo al menos 3 commits con mensajes claros (o justifiqué por qué no)
- [x] Hice `git push` y verifiqué mi fork en GitHub
- [x] Mi fork se llama `ulsa_ime_1_dp_ticket_compra`, mis módulos están en `include/ticket.h` y mi programa principal en `src/main.cpp`
- [x] Entregué el enlace de mi fork en Classroom
