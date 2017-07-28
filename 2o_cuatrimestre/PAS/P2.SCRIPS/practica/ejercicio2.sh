#!/bin/bash 

DIR=$1
UMBRAL1=10000
UMBRAL2=100000
PEQ=pequeños
MED=medianos
GRD=grandes

if [ $# != 3 ]
then
	if [ $# != 2 ]
	then

		if [ $# != 1 ]
		then
			echo "Error de sintaxis, debe ser: ./ejercicio2.sh <dir> (umbral1) (umbral2)"
			exit 1
		fi
	fi
fi
if [ $# = 3 ]
then 
	UMBRAL1=$2
	UMBRAL2=$3	
	if [ $UMBRAL1 -gt $UMBRAL2 ]
	then
		echo "Error logico, el umbral mas bajo no puede ser superior al umbral mas alto"
		exit 1
	fi
fi

if [ $# = 2 ]
then 
	UMBRAL1=$2
fi

if [ -d $PEQ ]
then
	echo "Eliminando la carpeta " $PEQ
	rm -R $PEQ
fi
if [ -d $MED ]
then
	echo "Eliminando la carpeta " $MED
	rm -R $MED
fi
if [ -d $GRD ]
then
	echo "Eliminando la carpeta " $GRD
	rm -R $GRD
fi

#rm -f -R pequeños medianos grandes
mkdir $PEQ $MED $GRD

if [ -d $DIR ]
then
	echo "Copiando..."
	for f in $( find -L $DIR -type f -size +0'c') #-L permite que se copien los enlaces simbolicos. Si no, find utiliza dicho enlace para encontrar el archivo que referencia y no lo incluiria como fichero, a menos que el link estuviera roto
	do
		TAM=$(stat -c %s $f)
		#echo $f
		if [ $TAM -lt $UMBRAL1 ]
		then
		#menor que umbral1, a pequeños
		DEST=$PEQ

		else
			if [ $TAM -gt $UMBRAL2 ]
			then
			#mayor que UMBRAL 2, a grandes
			DEST=$GRD
			else
				#a medianos
				DEST=$MED
			fi
		fi
		
		cp $f $DEST
		#echo "El fichero "$f" que pesa " $TAM " enviado a " $DEST
	done
	echo "Terminado"	




fi
