/*
    Universidad del Valle de Guatemala
    Facultad de Ingenieria
    CC3086 - Programacion de Microprocesadores
    Seccion 10
    Cindy Gualim
    Ana Laura Tschen
    Laboratorio 7 - Ejercicio 1
*/

//Librerias
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

using namespace std;

struct Producto {
    string nombre;
    double precio;
    int unidades_julio;
    int unidades_agosto;
    double costo_fijo;
};