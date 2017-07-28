#!/bin/bash
#Con 14 caracteres tarda 733 veces la edad actual del universo (13.5 miles de millones de años)
if [ $# != 2 ]
then
	if [ $# != 1 ]
	then
		echo "Syntax error, debes escribir ./ejercicio5.sh <ResumenContraseña> (NumeroDeCaracteres)"
		echo "Si no incluyes el numero de caracteres se hará por la fuerza"
		exit 1
	fi
	echo "Si no conocemos su tamaño..... ¡Solo podemos luchar con toda nuestra fuerza!"
else
	NUM=$2
fi
CONTROL=$NUM
RES=$1


if [ $CONTROL -ge 1 ]
then
	for f in $( echo {a..z}) $( echo {0..9}) $( echo {A..Z})
	do
#		echo $f
		if [ $CONTROL -ge 2 ]
		then
			for g in  $( echo {a..z}) $( echo {0..9}) $( echo {A..Z})
			do
#				echo $f$g
				if [ $CONTROL -ge 3 ]
				then
					for h in $( echo {a..z}) $( echo {0..9}) $( echo {A..Z})
					do
#						echo  $f$g$h
						if [ $CONTROL -ge 4 ]
						then
							for i in $( echo {a..z}) $( echo {0..9}) $( echo {A..Z})
							do
#								echo  $f$g$h$i
								if [ $CONTROL -ge 5 ]
								then
									for j in $( echo {a..z}) $( echo {0..9}) $( echo {A..Z})
									do
#										echo  $f$g$h$i$j
						
									done
								fi
							done
						fi
					done
				fi
			done
		fi	
	done
fi

