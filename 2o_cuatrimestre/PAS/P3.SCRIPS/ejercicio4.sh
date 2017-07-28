#!/bin/bash

if [ $# != 1 ]
then
	echo "Error de sintaxis, debe escribirse ./ejercicio4.sh <nombrefichero>"
	exit 1
fi
FICH=$1
#quitar la extension a $FICH
HTML=$(echo $FICH | sed -r -e 's/(.+)\..+/\1.html/g')

cat $FICH | sed -r -e '/^$/d' | sed -r -e 's/(.*)/<p> \1 <\/p>/g' | sed -r -e 's/<p> (.*): <\/p>/<title> \1 <\/title>\n<body>/g' > /tmp/i42segedp34.tmp

echo "<html>" > $HTML
cat /tmp/i42segedp34.tmp >> $HTML
echo "</body>" >> $HTML
echo "</html>" >> $HTML
rm -f /tmp/i42segedp34.tmp 
