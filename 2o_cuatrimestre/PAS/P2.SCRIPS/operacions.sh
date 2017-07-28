#!/bin/bash

echo -n "Introduzca el primer numero: " 
read n1
echo -n "Introduzca el segundo numero "
read n2
echo "Suma: $((n1+n2))"
echo "Resta: $((n1-n2))"
echo "Multiplicacion: $((n1*n2))"
echo "Division: $((n1/n2))"
echo "Modulo: $((n1%n2))"
