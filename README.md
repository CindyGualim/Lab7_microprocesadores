Universidad del Valle de Guatemala
Facultad de Ingeniería
CC3086 - Programación de Microprocesadores
Sección 10

Integrantes:

Cindy Gualim

Ana Laura Tschen

Descripción
Este laboratorio aborda el uso de programación concurrente y mecanismos de sincronización para resolver problemas prácticos con el uso de hilos, mutexes y variables de condición. Se desarrollaron dos ejercicios:

- Cálculo de Ventas y Utilidades Mensuales de Productos.
- Simulación de Tostadoras y Empacadora de Café.


## Ejercicio 1: Cálculo de Ventas y Utilidades Mensuales

Determinar las ventas totales y las utilidades de un conjunto de productos para los meses de julio y agosto. Se utiliza programación concurrente para calcular simultáneamente las estadísticas de cada producto.

### Funcionalidades
- Cálculo de ventas y utilidad para cada producto.
- Generación de reportes consolidados para julio y agosto.
- Uso de mutex para garantizar acceso seguro a las variables compartidas.
### Estructura del Código
- Estructura Producto: Contiene información sobre nombre, precio, unidades vendidas, y costo fijo por unidad.
- Hilos: Cada producto se procesa en un hilo independiente.
- Mutex: Protege las operaciones de escritura en las variables compartidas.



## Ejercicio 2: Simulación de Tostadoras y Empacadora

Simular la operación de dos tostadoras que producen café tostado y una empacadora que lo procesa en bolsas. Se sincronizan las operaciones usando mutexes y variables de condición.

### Funcionalidades
- Dos tostadoras producen café tostado y lo colocan en un silo.
- Una empacadora procesa el café del silo en bolsas y las almacena en la bodega.
- Sincronización entre hilos para evitar accesos conflictivos al silo y bodega.
### Estructura del Código
- Constantes: Capacidad máxima del silo y cantidad total de producción objetivo.
- Tostadoras: Incrementan el contenido del silo a razón de 1 libra por segundo.
- Empacadora: Procesa el café en paquetes cuando el silo alcanza su capacidad máxima.
- Variables de condición: Coordinan las operaciones entre las tostadoras y la empacadora.

