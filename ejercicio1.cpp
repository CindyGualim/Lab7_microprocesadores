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

vector<Producto> productos = {
    {"Porcion pastel de chocolate", 60, 300, 280, 40},
    {"White mocha", 32, 400, 380, 20},
    {"Café americano 8onz", 22, 250, 230, 15},
    {"Latte 8onz", 24, 220, 210, 18},
    {"Toffee coffee", 28, 260, 240, 25},
    {"Cappuccino 8onz", 24, 280, 270, 19},
    {"S'mores Latte", 32, 150, 140, 28},
    {"Café tostado molido", 60, 120, 110, 50}
};

double total_ventas_julio = 0, total_ventas_agosto = 0;
double total_utilidad_julio = 0, total_utilidad_agosto = 0;

mutex mtx;

void calcular_ventas_utilidad(const Producto& producto, bool es_julio) {
   
    this_thread::sleep_for(chrono::seconds(1));
    
    int unidades = es_julio ? producto.unidades_julio : producto.unidades_agosto;
    double ventas = unidades * producto.precio;
    double utilidad = ventas - (unidades * producto.costo_fijo);

    
    mtx.lock();
    if (es_julio) {
        total_ventas_julio += ventas;
        total_utilidad_julio += utilidad;
        cout << "Producto: " << producto.nombre << " (Julio) - Ventas: Q" << ventas 
             << " - Utilidad: Q" << utilidad << endl;
    } else {
        total_ventas_agosto += ventas;
        total_utilidad_agosto += utilidad;
        cout << "Producto: " << producto.nombre << " (Agosto) - Ventas: Q" << ventas 
             << " - Utilidad: Q" << utilidad << endl;
    }
    mtx.unlock();
}

int main() {
    vector<thread> hilos;

   
    for (const auto& producto : productos) {
        hilos.push_back(thread(calcular_ventas_utilidad, producto, true));
    }

   
    for (auto& hilo : hilos) {
        hilo.join();
    }

    
    cout << "------------------------------------------" << endl;
    cout << "REPORTE DEL MES DE JULIO" << endl;
    cout << "Monto Total Ventas del Mes: Q" << total_ventas_julio << endl;
    cout << "Utilidad Total del Mes: Q" << total_utilidad_julio << endl;

    hilos.clear();  

    
    for (const auto& producto : productos) {
        hilos.push_back(thread(calcular_ventas_utilidad, producto, false));
    }

    
    for (auto& hilo : hilos) {
        hilo.join();
    }

    
    cout << "------------------------------------------" << endl;
    cout << "REPORTE DEL MES DE AGOSTO" << endl;
    cout << "Monto Total Ventas del Mes: Q" << total_ventas_agosto << endl;
    cout << "Utilidad Total del Mes: Q" << total_utilidad_agosto << endl;

    return 0;
}