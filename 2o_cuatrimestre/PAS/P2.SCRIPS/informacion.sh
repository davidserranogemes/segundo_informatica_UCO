#!/bin/bash -x

PS1="\u:(\t)&" # hay que ponerlo en la shell no aqui

echo "Bienvenido $USER !,tu identificador es $UID."
echo "Esta es la shell numero $SHLVL, que lleva $SECONDS segundos arrancada."
echo "La arquitectura de esta maquina es $MACHTYPE y el cliente de terminal es $TERM "


