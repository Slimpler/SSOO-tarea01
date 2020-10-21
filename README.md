---
title: "Nicolás Delgado Oyarce"
metaTitle: "nicolas.delgado@alumnos.uv.cl"
metaDescription: "SSOO-tarea01"
---

# NICOLAS DELGADO OYARCE - NICOLAS.DELGADO@ALUMNOS.UV.CL

# Código

    - El código una vez terminado consta de tres funciones, dos encargadas del manejo de señales, que son, void signal_handler(int signal_num), que es donde se maneja el funcionamiento que esperamos para ctrl+C, en este caso se realiza un contador llamado intentos que es una suma de las veces que se presiona ctrl+C, para luego dentro de una condición if comprobar que se presione dos veces y llegar a la funcion perteneciante a la libreria de C, exit(), que finaliza el proceso.

    - Y la otra función para manejar señales es void signal_sigusr1(int sig), donde se entra una vez enviada la señal SIGUSR1, en esta última función es tambien donde se logra la impresión de la hora del sistema en pantalla; para esto se recure a la función perteneciente a la libreria de C, time(), luego de un manejo de la fecha con las opciones de la función la hora es mostrada en pantalla.

    - Finalmente llegamos a la funcion principal main(), esta funcion es la primera en ejecutarse, en este caso las dos primeras acciones que realiza son la impresion por pantalla de las siguientes frases, "Programa hora ejecutandose. PID=%i.\n" y "Listo para recibir la signal SIGUSR1.\n", una vez se muestra esto en pantalla, se hacen un llamado a las dos funciones anteriores, para que en caso de ser enviada la señal SIGUSR1 o ctrl+C, puedan ser manejadas. Para terminar hay un while(1) que se usa para esperar que se reciban alguna de las señales, y que la ejecución no termine, sino hasta que se presionen dos veces ctrl+C.