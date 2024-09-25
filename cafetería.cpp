#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

mutex mtx; // Mutex para proteger el acceso a las variables compartidas
condition_variable cv; // Condición para sincronizar la empacadora

int cafeEnSilo = 0; // Libras de café en el silo
int cafeEnBodega = 0; // Libras de café en la bodega

const int CAPACIDAD_SILO = 5; // Capacidad máxima del silo antes de empacar
const int CANTIDAD_PRODUCIDA = 400; // Cantidad de bolsas a producir

// Función para la tostadora 1
void tostadora1() {
    int produccion = 0;
    while (cafeEnBodega < CANTIDAD_PRODUCIDA) {
        this_thread::sleep_for(chrono::seconds(1)); // Simula la producción de 1 libra por segundo
        unique_lock<mutex> lock(mtx);
        cafeEnSilo++;
        produccion++;
        cout << "Tostadora 1 produjo: 1 lb de café tostada" << endl;
        cout << "Lbs de café en silo: " << cafeEnSilo << endl;
        cv.notify_all(); // Notifica a la empacadora que puede empacar si hay suficiente café en el silo
    }
}

// Función para la tostadora 2
void tostadora2() {
    int produccion = 0;
    while (cafeEnBodega < CANTIDAD_PRODUCIDA) {
        this_thread::sleep_for(chrono::seconds(1)); // Simula la producción de 1 libra por segundo
        unique_lock<mutex> lock(mtx);
        cafeEnSilo++;
        produccion++;
        cout << "Tostadora 2 produjo: 1 lb de café tostada" << endl;
        cout << "Lbs de café en silo: " << cafeEnSilo << endl;
        cv.notify_all(); // Notifica a la empacadora que puede empacar si hay suficiente café en el silo
    }
}

// Función para la empacadora
void empacadora() {
    while (cafeEnBodega < CANTIDAD_PRODUCIDA) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return cafeEnSilo >= CAPACIDAD_SILO || cafeEnBodega >= CANTIDAD_PRODUCIDA; });

        if (cafeEnSilo >= CAPACIDAD_SILO) {
            // Empaca 5 libras de café
            cafeEnSilo -= CAPACIDAD_SILO;
            cafeEnBodega += CAPACIDAD_SILO;

            cout << "Empacadora produjo: " << CAPACIDAD_SILO << " bolsas de 1 lb de café" << endl;
            cout << "Lbs de café en silo: " << cafeEnSilo << endl;
            cout << "Lbs de café en bodega: " << cafeEnBodega << endl;
        }
    }
}

int main() {
    // Crear los hilos para las tostadoras y la empacadora
    thread t1(tostadora1);
    thread t2(tostadora2);
    thread empaq(empacadora);

    // Esperar a que los hilos terminen su trabajo
    t1.join();
    t2.join();
    empaq.join();

    return 0;
}
