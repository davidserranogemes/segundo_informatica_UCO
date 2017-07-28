#!/bin/bash

DIR=$1
BYTES=0
clear
if [ $# != 1 ]
then
	if [ $# != 2 ]
	then 
		echo "Error de sintaxis. ./ejercicio1.sh <fichero> (bytes)"
		exit 1
	fi
fi

if [ $# = 2 ]
then 
BYTES=$2
fi

echo "El directorio es $DIR y se busca con un peso minimo de $BYTES "

if [ -d $DIR ]
	then
	echo "El directorio existe"
	for f in $( find $DIR -type f -size +$BYTES'c' ) $( find $DIR -type f -size $BYTES'c') 
	do
			DIR=$(dirname $f)
			NAME=$(basename $f)
			TAM=$(stat -c %s $f)
			INODE=$(stat -c %h $f)
			PERMISSION=$(stat -c %A $f)
			if [ -x $f ]
			then
				EXECUTABLE=1
			else
				EXECUTABLE=0
			fi
			echo "$DIR;$NAME;$TAM;$INODE;$PERMISSION;$EXECUTABLE" >> /tmp/ejercicio01i42seged.tmp
	done
		if [ -e /tmp/ejercicio01i42seged.tmp ]
		then		
			cat /tmp/ejercicio01i42seged.tmp | sort  -r -k2 --field-separator=';' #Es posible que tengas que cambiarlo a orden alfabetico
			rm -f /tmp/ejercicio01i42seged.tmp
		fi

else
	echo "El directorio $DIR  no existe"
fi
