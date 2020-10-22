---
title: "Nicolás Delgado Oyarce"
metaTitle: "nicolas.delgado@alumnos.uv.cl"
metaDescription: "SSOO-tarea01"
---

**Autor:** Nicolás Delgado Oyarce

**Correo institucional:** nicolas.delgado@alumnos.uv.cl

El problema que se presenta al intentar solucionar la tarea, es que el código se programe de la tal forma que  se pueda reconocer las dos señales que recibibirá, según el enunciado de la tarea 01. Estas señales son:
- SIGUSR1: enviada desde otra consola conociendo el PID del proceso que se ejecuta.
- SIGINT: ctrl+c, que se deberá presionar dos veces para la finalizacion de la ejecición.

**Solución**

El código una vez terminado consta de tres funciones, dos encargadas del manejo de señales y la función main, que es la principal dentro del código. Las funciones detalladas son:


 **void signal_handler(int signal_num)**, es donde se maneja el funcionamiento que se necesita al presionar ctrl+C (señal SIGINT), en este caso se realiza un contador llamado "intentos", que como su nombre lo dice llevará un conteo de las veces que se presiona ctrl+C, para luego dentro de una condición if comprobar que se presione dos veces. Si esta condición if se cumple, es decir, que el la señal SIGINT ha sido recibida dos veces, se ejecutará la función perteneciente a la libreria de C, exit(), que finaliza el proceso.

**void signal_sigusr1(int sig)**, es donde se entra una vez enviada la señal SIGUSR1, en esta última función es tambien donde se logra la impresión de la hora del sistema en pantalla; para esto se recure a la función perteneciente a la libreria de C, time(), luego de un manejo de la fecha con las opciones de la función la hora es mostrada en pantalla. La señal SIGUSR1, es enviada desde otra consola y al ser recibida conociendo el PID del proceso, entramos en esta función para lograr mostrar por pantalla la hora en el formato que es requerido.

**main()**, esta funcion es la primera en ejecutarse, en este caso las dos primeras acciones que realiza son la impresion por pantalla de las siguientes frases, "Programa hora ejecutandose. PID=%i.\n" y "Listo para recibir la signal SIGUSR1.\n", una vez se muestra esto en pantalla, se hacen un llamado a las dos funciones anteriores, para que en caso de ser enviada la señal SIGUSR1 o ctrl+C, puedan ser manejadas. Para terminar hay un while(1) que se usa para esperar que se reciban alguna de las señales, y que la ejecución no termine, sino hasta que se presionen dos veces ctrl+C.