'''
   Este programa PiPorSerieThreads lleva a cabo calculos de aproximación de PI usando threads
   Author	Programacion Concurrente
   Version	2020/Abr/11
        __
       \
  pi =  >  (-1)^i x 4/(2xi + 1)
       /__
       i=0

'''

import sys
import threading

'''
   Esta clase valores es necesaria para obtener los valores de la suma de los terminos de PI que realiza cada hilo
   En Python los parametros de los metodos son por valor y no pueden ser cambiados
'''
class valores:
	pass

# Cada hilo ejecuta este metodo que realiza la suma parcial de sus terminos y acumula el resultado en la instancia "total"
def calcula( inicio, terminos, total ):
	miSuma=0.0
	alterna = 4.0 if ( 0 == (inicio % 2) ) else -4.0
	for i in range( int(terminos) ):
		pos = i + inicio
		miSuma += alterna/(2 * pos + 1)
		alterna *= -1.0
	total.suma += miSuma


def main():
	threads = []
	valor = valores
	valor.suma = 0
	terminos = 1000000
	if ( len( sys.argv ) > 1 ):
		terminos = int( sys.argv[ 1 ] )
	else:
		print( "Uso: " + "\033[1m" + sys.argv[ 0 ] + " n (para n un entero)" + "\033[0m" )
	fin = terminos/10
	x = float( 0 )
	for i in range( 10 ):
		inicio = i * terminos/10
		t = threading.Thread( target=calcula, args=( inicio, fin, valor ) )
		threads.append( t )
		t.start()

	for t in threads:
		t.join()

	print( "Valor aproximado de PI: " + '\033[91m' + str( valor.suma ) + '\033[0m' + " para " + str( terminos ) + " elementos")


if __name__ == "__main__":
	main()

