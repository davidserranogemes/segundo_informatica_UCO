#!/bin/bash

FICH=$1

if [ $# != 1 ]
then
	echo "Error de sintaxis, se debe escribir ./ejercicio2.sh <nombreFichero>"
	exit 1
fi
#(\([0-9]+\-[0-9]+|\?\)) pilla la  fecha
#La funcion esta hecha a trocitos:
#La primera parte formatea la primera linea (titulo y fecha)
#El segundo elimina los =
#El tercero recoloca las temporadas
#El cuarto recoloca la productora
#El quito recoloca la sinopsis
#EL sexto recoloca los puntos
#El septimo elimimina las lineas vacias ^$ (No hay nada entre inicio de linea y final de linea)
#El ultimo elimina los "Ver mas"
sed  -r -e 's/([0-9]+\.)([^(]+)\(([0-9]+\-[[0-9?]+)\)/\1\2'\\n'\|-> Año de la serie: \3/g' $FICH | sed -r -e '/=+/d' | sed -r -e 's/([0-9]+) TEMPORADAS.*/\|-> Numero de temporadas: \1/g' | sed -r -e 's/\* ([A-Z]+) \*/\|->Productora de la serie: \1/g' | sed -r -e 's/.*SINOPSIS:(.*)/\|->Sinopsis:\1/g' | sed -r -e 's/[^0-9]*([0-9]+)[^0-9]*puntos/\|->Numero de puntos: \1/g' | sed -r -e '/^$/d ' | sed -r -e 's/(.*)Ver mas/\1/g' 
