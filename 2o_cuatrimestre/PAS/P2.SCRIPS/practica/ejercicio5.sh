#!/bin/bash

if [ $# != 2 ]
then
	if [ $# != 1 ]
	then
		echo "Syntax error, debes escribir ./ejercicio5.sh <ResumenContraseña> (NumeroDeCaracteres)"
		echo "Si no incluyes el numero de caracteres se hará por la fuerza"
		exit 1
	fi
	echo "Si no conocemos su tamaño..... ¡Solo podemos luchar con toda nuestra fuerza!"
fi
RES=$1
NUM=$2
for STRONG in 1 2 3
do
	if [ $# == 1 ]
	then
		NUM=$STRONG
	fi

	case $NUM in
		1)
			echo "Buscando contraseña de 1 caracter..."
			for f in {a..z}
			do
				
				SOL=$( echo $f | sha1sum)
				SOL=$(echo $SOL | tr -d '-')
				if [ $SOL == $RES ]
				then			
					echo "La contraseña es "$f
					exit 0
				fi
			done
			echo "La contraseña no es de un caracter"
			if [ $# == 2 ]
			then
				exit 1
			fi
		;;
		2)
			echo "Buscando contraseña de 2 caracteres....."
			for f in {a..z}{a..z}
			do
				SOL=$( echo $f | sha1sum)
				SOL=$(echo $SOL | tr -d '-')
				if [ $SOL == $RES ]
				then
					echo "La contraseña es "$f
					exit 0
				fi
			done
			echo "La contraseña no es de dos caracteres"
			if [ $# == 2 ]
			then
				exit 1
			fi
		;;
	
		3)
			echo "Buscando contraseña de 3 caracteres.Este proceso se puede demorar unos minutos......."	
			for f in {a..z}{a..z}{a..z}
			do		
				
				SOL=$( echo $f | sha1sum)
				SOL=$(echo $SOL | tr -d '-')		
				if [ $SOL == $RES ]
				then			
					echo "La contraseña es "$f
					exit 0
				fi
			done
			echo "La contraseña no es de tres caracteres"
			if [ $# == 2 ]
			then
				exit 1
			fi
		;;
	
		*)
	
		;;
	esac	
done
