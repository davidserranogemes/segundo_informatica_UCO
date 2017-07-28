c#!/bin/bash



#Muestra el modelo del procesador

cat /proc/cpuinfo | grep -E 'model name' | sed -r -e '1s/model name.*:(.*)/Modelo del procesador: \1/g' | grep -E 'Modelo'
cat /proc/cpuinfo | grep -E 'cpu MHz' | sed -r -e '1s/cpu MHz.*:(.*)/Megahercios: \1/g' | grep -E 'Megahercios'

HILOS=$(cat /proc/cpuinfo | grep -E 'processor' | wc -l)
echo "Numero de hilos maximos en ejecucion: "$HILOS

echo "Puntos de montaje:"
cat /proc/mounts | sort -k3 | sed -r -e 's/([^ ]+)[ ]([^ ]+)[ ]([^ ]+)[ 
][^ ]+[ ][^ ]+[ ][^ ]+/->Punto de montaje: \2, Dispositivo: \1, Tipo de 
Dispositivo: \3/g'

# sed -n -e '1!p' pone en modo silencioso y dice que se imprima la linea 
1, con ! lo negamos por lo que imprime todas menos esa. Asi eliminamos 
las indicaciones de a que se refiere cada numero
echo "Particiones:"
cat /proc/partitions | sed -n -e '1!p' | sort -k3 -nr | sed -r -e 's/[ 
]+[^ ]+[ ]+[^ ]+[ ]+([^ ]+)[ ]+([^ ]+)/-> Partición: \2, Numero 
Bloques: \1/g' | sed -r -e '/^$/d'
