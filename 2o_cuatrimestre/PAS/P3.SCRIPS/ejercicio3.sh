#!/bin/bash

if [ $# != 1 ]
then
	echo "Error de sintaxis, debe escribirse ./ejercicio3.sh <nombrefichero>"
	exit 1
fi
FICH=$1

rm -f /tmp/i42segedp33.tmp
#lista ficheros ocultos
for f in $(ls -a $HOME | grep -E '\..*')
do
	
	echo $( echo -n $f | wc -c) $HOME"/"$f >> /tmp/i42segedp33.tmp
	
done
echo "======="
echo "Listado de ficheros ocultos del directorio "$HOME
	cat /tmp/i42segedp33.tmp | sort -n | sed -r -e 's/[0-9]+ \/home\/david\/(.*)/\1/g'
echo "======="
echo "El fichero a tratar es" $FICH
if [ -e $FICH ]
then
	FICHVAC=$FICH."sinLineasVacias"
	cat $FICH | sed -r -e '/^$/d' > $FICHVAC
	echo "El fichero sin lineas vacias se ha guardado en "$FICHVAC
	echo "======="
else
	echo "El fichero debe existir"
fi
echo "Listado de procesos ejecutados por el usuario "$USER

ps -ef | sed -r -e 's/[^ ]+[ ]+([^ ]+)[ ]+[^ ]+[ ]+[^ ]+[ ]+([^ ]+)[ ]+[^ ]+[ ]+[^ ]+[ ]+(.*)/PID:\1 HORA: \2 EJECUTABLE: "\3"/g'



