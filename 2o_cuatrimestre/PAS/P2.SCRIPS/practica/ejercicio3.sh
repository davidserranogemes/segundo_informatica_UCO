#!/bin/bash 

if [ $# != 2 ]
then
	echo "Syntax error, debe escribir: ./ejercicio3.sh <ORIGEN> <DESTINO>"
	exit 1
fi


ORIGEN=$1
DESTINO=$2
if [ -d $DESTINO ]
then 
	echo "La carpeta de destino " $DESTINO " ya existe."
	echo "La carpeta "$DESTINO" ya existe, ¿desea borrarla? (s/n)"
	read BORRAR

	if [ $BORRAR == "s" ] 
	then	
		echo "Borrando "$DESTINO" ......"
		rm $DESTINO -R	
	else
		exit 1
	fi
fi

for f in $( find $ORIGEN  -type d)
do
	g=$( echo ${f/$ORIGEN} | tr -s / | tr  'a-z' 'A-Z')
	
	mkdir $DESTINO/$g
	echo "Creado "$DESTINO/$g
done

for f in $( find $ORIGEN  -type f)
do
	g=$(dirname $f)
	NAME=$(basename $f)

	FICH=$( echo ${f/$ORIGEN} | tr  'a-z' 'A-Z' )
	DIR=$( echo ${g/$ORIGEN} | tr  'a-z' 'A-Z' )

	cp $f $DESTINO/$DIR
	mv $DESTINO/$DIR/$NAME $DESTINO/$FICH 
	echo "Copiando "$DESTINO/$DIR"/"$NAME" como " $DESTINO/$FICH 
	
done


