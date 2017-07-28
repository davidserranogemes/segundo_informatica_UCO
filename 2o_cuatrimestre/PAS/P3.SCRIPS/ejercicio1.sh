#!/bin/bash

FICH=$1
if [ $# != 1 ]
then 
	echo "Error de sintaxis, ./ejercicio1.sh <nombrefichero>"
	exit 1
fi

echo "********************************************************************************"
#1. nombres de series
echo "1) Titulo de las series:"
grep -E '^[0-9]+\.' $FICH

echo "********************************************************************************"
#2. nombre de cadenas
echo "2)Cadenas que producen las series:"
grep -E '\* [A-Z]+ \*' $FICH

echo "********************************************************************************"
#3. nombre de cadenas sin asteriscos ni espacios en blanco
echo "3) Cadenas que producen las series sin asteriscos ni espacios:"
grep -E '\* [A-Z]+ \*' $FICH | tr -d \* | tr -d ' '

echo "********************************************************************************"
#4. eliminar la sinopsis
echo "4) Eliminar la linea de la sinopsis:"
grep -v 'SINOPSIS' $FICH

echo "********************************************************************************"
#5. eliminar lineas en blanco
echo "5) Eliminar las lineas vacias:"
grep -E '.+' $FICH 

echo "********************************************************************************"

#6. contar series que produce cada cadena
echo "6) Contar cuantas series produce cada cadena:"
OLDIFS=$IFS #IFS es el caracter separador de un array, es lo que indica al FOR donde cortar, al cambiarlo hacemos que coja hasta un \n
IFS=$'\n'
for f in $(grep -E '\* [A-Z]+ \*' $FICH | tr -d \* | tr -d ' ' | tr -d \* | tr -d ' ' | sort | uniq -c) #>> /tmp/i42seged1.6.tmp #falta darle formato correcto
do
	echo "La cadena "$(echo $f | grep -o -E '[A-Z]+') " produce " $(echo $f | grep -o -E '[0-9]+') " series: "
done
IFS=$OLDIFS

echo "********************************************************************************"
#7. Buscar palabras en mayusculas entre parentesis, no me convence nada como lo he hehco
echo "7) Lineas que contengan una palabra en mayusculas entre parentesis"
grep -E '\([^)]*[A-Z][^)]*\)' $FICH

echo "********************************************************************************"
#8. Buscar palabras repetidas
echo "8) Emparejamientos de palabras repetidas en la misma linea: "
grep -E -o ' ([^ ]+) .* \1 ' $FICH 

echo "********************************************************************************"
#9. ES una chapuza, pero funciona xD
echo "9) Lineas que contienen veintiocho aes o mas:"
grep -E -i '(.*a.*){28,}' $FICH

echo "********************************************************************************"
#10. Nombre de la serie y temporadas
echo "10) Nombre de la serie y temporadas:"
grep -E '.+' $FICH  | grep -E -C 1 '=+'

