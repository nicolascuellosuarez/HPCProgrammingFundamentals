# Trabajo Práctio #1 - HPC

## Requisitos

### Linux / WSL:

Tener instalado:

* gcc
* git

Instalar en la distro:

sudo apt update
sudo apt install git

---

### Windows:

Tener instalado:

* MSYS2 o WSL
* gcc (MinGW64 si usas MSYS2)

Compilar desde la terminal **MinGW64**, no desde MSYS.

---

## Clonar el repositorio:

git clone https://github.com/nicolascuellosuarez/HPCProgrammingFundamentals

cd TP1_HPC

---

## Compilar

### Linux / WSL:

gcc -Wall -O2 ejercicio1.c -o ejercicio1 -lm

gcc -Wall -O2 ejercicio2.c -o ejercicio2 -lm

gcc -Wall -O2 ejercicio3.c -o ejercicio3 -lm

Ejecutar:

./ejercicio1

./ejercicio2

./ejercicio3

---

### Windows:

gcc -Wall -O2 ejercicio1.c -o ejercicio1.exe -lm

gcc -Wall -O2 ejercicio2.c -o ejercicio2.exe -lm

gcc -Wall -O2 ejercicio3.c -o ejercicio3.exe -lm

Ejecutar:

ejercicio1.exe

ejercicio2.exe

ejercicio3.exe

---

## Nota sobre rand_r

rand_r no existe en Windows.
Se agregó una implementación compatible usando:

#ifdef _WIN32

Esto funciona con cualquier compilador de Windows.

---

## Autor

Nicolás Cuello

Computación de Alto Desempeño - Carlos Álvarez

Insitituto de Ciencias Básicas - Universidad de Medellín