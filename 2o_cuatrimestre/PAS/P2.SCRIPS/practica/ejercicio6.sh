#!/bin/bash
###############################################################################
# VARIABLES USADAS:
#	FICH: lista de ficheros en los que se va a buscar
#	DIREJEC: directorio donde vamos a copiar los ejecutables
#	DIRLIB: directorio donde vaos a copiar las librerias
#	DIRIMG: directorio donde vamos a copiar las imagenes
#	DIRCAB: directorio donde vamos a copiar las imagenes de cabecera
#	
#	DIR: directorio de trabajo actual
#	PARAM: argumentos de la funcion, toma el valor de la capeta actual si no hay parametros
###############################################################################

function ExisteDir(){
if [ -d $1 ] #hacer esto con una funcion
then
	echo "La carpeta "$1" ya existe, ¿desea borrarla? (s/n)"
	read BORRAR

	if [ $BORRAR == "s" ] 
	then	
		echo "Borrando "$1" ......"
		rm $1 -R
		echo " $(date +%F--%R) Borrada la carpeta " $1 >> ./ejercicio6.log
		echo "Creando "$1"....."
		mkdir $1
		echo " $(date +%F--%R) Creada la carpeta " $1 >> ./ejercicio6.log
	else
		echo "Se actuara sobre esta carpeta, preguntando si sobreescribir archivos."
	fi
		
else
	echo "La carpeta "$1" no existe. Creando...."
	mkdir $1
	echo " $(date +%F--%R) Creada la carpeta " $1 >> ./ejercicio6.log
fi
}

function ExisteFich(){
#Requiere EXEC y DIR*
EXECF=$1
DIREND=$2
	AUXTRAT=$(basename $EXECF)
	AUXTRAT=$DIREND/$AUXTRAT
	if [ -e $AUXTRAT ]
	then
		echo "¿Desea sobreescribir " $AUXTRAT "(s/n)"
		read SOBRE
		if [ $SOBRE == s ]
		then
			rm $AUXTRAT
			echo " $(date +%F--%R) Borrado el fichero " $AUXTRAT >> ./ejercicio6.log

			cp $EXECF $DIREND
			echo " $(date +%F--%R) Copiado el fichero " $EXECF" a " $DIREND >> ./ejercicio6.log
			return 0
		else
			return 1
		fi
	else
		cp $EXECF $DIREND
		echo " $(date +%F--%r) Copiado el fichero " $EXECF" a " $DIREND >> ./ejercicio6.log
		return 0
	fi
}




START=$(date +%s)
PARAM=$(pwd)

EJECUTABLES=0
LIBRERIAS=0
IMAGENES=0
CABECERAS=0

echo -e "\n--------------------------------------------------------------------------------------------------------------------------------------\n $(date +%F--%R) Ejecucion de ./ejercicio6.sh \n--------------------------------------------------------------------------------------------------------------------------------------">> ./ejercicio6.log
if [ $# != 0 ]
then
	PARAM=$* #Si le pasamos parametros toma esos parametros para trabajar
fi

echo "Introduce el directorio donde copiar los ejecutables"
read -t 5 DIREJEC 
if [ $? != 0 ]
then
	DIREJEC="$HOME/bin"
fi

echo "Introduce el directorio donde copiar las imagenes"
read -t 5 DIRIMG
if [ $? != 0 ]
then
	DIRIMG="$HOME/img"
fi

echo "Introduce el directorio donde copiar los ficheros de cabecera"
read -t 5 DIRCAB 
if [ $? != 0 ]
then
	DIRCAB="$HOME/include"
fi

echo "Introduce el directorio donde copiar las librerias"
read -t 5 DIRLIB 
if [ $? != 0 ]
then
	DIRLIB="$HOME/lib"
fi


#fin func
ExisteDir $DIREJEC
ExisteDir $DIRIMG
ExisteDir $DIRCAB
ExisteDir $DIRLIB


for DIR in $PARAM
do 
	if [ -d $DIR ]
	then
		echo "Tratando el directorio "$DIR " ........"

		echo "Buscando ejecutables..."
		for EXEC in $( find $DIR -type f )
		do
			if [ -x $EXEC ]
			then
				#echo $EXEC " es un ejecutable." #tratamiento
				if ExisteFich $EXEC $DIREJEC #si se copia devuelve 0
				then
					EJECUTABLES=$((EJECUTABLES+1))
				fi
			fi
		done

		echo "Buscando librerias..."
		for LIB in $( find $DIR -type f -name lib\* | grep -e lib )
		do
			#echo $LIB " es una libreria." #tratamiento
			if ExisteFich $LIB $DIRLIB #si se copia devuelve 0
			then
			LIBRERIAS=$((LIBRERIAS+1))
			fi
		done

		echo "Buscando imagenes (.png .jpg .gif)...."
		for IMG in $( find $DIR -name '*.png' ) $( find $DIR -name '*.jpg' ) $( find $DIR -name '*.gif' ) 
		do
			#echo $IMG " es una imagen." #tratamiento
			NAME=$(basename $IMG)
			NAME=$(echo "${NAME%%.*}")
			ROUTE=$(dirname $IMG)
			convert $IMG $ROUTE/$NAME.pdf
			
			if ExisteFich $ROUTE/$NAME.pdf $DIRIMG #si se copia devuelve 0
			then
			IMAGENES=$((IMAGENES+1))
			fi
			rm $ROUTE/$NAME.pdf

			if ExisteFich $IMG $DIRIMG #si se copia devuelve 0
			then
			IMAGENES=$((IMAGENES+1))
			fi
		done

		echo "Bucando ficheros de cabecera (.h)..."
		for CAB in $( find $DIR -name '*.h' )
		do
			#echo $CAB " es un fichero de cabecera." #tratamiento
			if ExisteFich $CAB $DIRCAB #si se copia devuelve 0
			then
			CABECERAS=$((CABECERAS+1))
			fi
		done
	else
		echo $DIR " no es un directorio. No se hace nada para él."
	fi
	#sleep 5
	#echo -e "\n\n\n\n"
done

END=$(date +%s)
TIME=$(( $END - $START))
echo "Numero de directorios procesados: " $#
echo "Numero de ejecutables= "$EJECUTABLES
echo "numero de librerias= "$LIBRERIAS
echo "Numero de imagenes= "$IMAGENES
echo "Numero de cabeceras= "$CABECERAS 
echo "Duracion de la ejecucion $TIME segundos"

