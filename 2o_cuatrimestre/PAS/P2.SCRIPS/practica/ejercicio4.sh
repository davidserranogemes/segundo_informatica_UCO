#!/bin/bash

FICH=$1
if [ $# != 1 ]
then
	echo "Syntax error, debe escribirse ./ejercicio4.sh <fichero/directorio>"
	exit 1
fi

if [ -e $FICH ]
then
	if [ -d $FICH ]
	then 
	#es un fichero
	echo "Procesando carpeta....."
	tar zcvf $(pwd)/$(basename $FICH)"i42seged.tar.gz" $FICH
	
	COD=$(basename $FICH)"i42seged.tar.gz"
	else	
		if [ -f $FICH ]
		then
			#es un fichero
			echo "Procesando fichero....."
			COD=$FICH
		else
			echo "Error raro, que eres y que haces en mi computadora?"
			exit 1
		fi
	fi
	
else
		echo "No existe " $FICH
		exit 1
fi


if [ -d $FICH ]
then 
	gpg --output $(basename $FICH)"i42seged.tar.gz.gpg" --symmetric  $COD
	rm $(pwd)/$(basename $FICH)"i42seged.tar.gz"
else
	gpg --output $(basename $FICH)."i42seged.gpg" --symmetric  $COD
fi
