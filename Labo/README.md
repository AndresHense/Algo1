# Labos

**https://campus.exactas.uba.ar/course/view.php?id=1854&section=9**

Ejercicios de los labos de la materia 
Algoritmos y estructura de datos I.

## Dependencias

- cmake make g++ perl gdb.
    ```
    sudo apt-get update
    sudo apt-get install cmake make g++ perl gdb
    ```

## Compilando el codigo

```
./prln.pl -cmk
cmake .
make
```

prln.pl es un script en perl que genera un CMakeLists.txt 
buscando recursivamente dentro del directorio por archivos
de tipo *.hpp y *.cpp.

### Corriendo gdb

Una vez compilado se puede debugear con 

```
gdb main
```

## Contribuyendo

Sentite libre de postear un Issue o hacer un Pull Request.
La rama `master` es en donde está la versión actual en
producción, `develop` es donde se hace el desarrollo. Cualquier
Pull Request o cambio debe ser mergeado primero a `develop` y
después a `master` cuando se suba a producción.
