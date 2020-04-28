/**
 * La clase PiPorSerie lleva a cabo calculos de aproximación 
 *
 * @author Programacion Concurrente
 * @version 2020/Abr/11
 *        __
 *      \
 * pi =  >  (-1)^i x 4/(2xi + 1)
 *      /__
 *      i=0
 *
 */

public class PiPorSeries {

    private long terminos;
    private long inicial;

/**
 * Constructor
 */
    public PiPorSeries( long terminos ) {
       this.terminos = terminos;
       this.inicial = 0;
    }

/**
 * Constructor
 */
    public PiPorSeries( long inicial, long terminos ) {
       this.terminos = terminos;
       this.inicial = inicial;
    }


/**
 * Realiza la operacion para el calculo de PI por medio de la serie 4/1 -4/3 + 4/5 - 4/7 ...
 * @return	double		devuelve el valor aproximado de PI
 */
    public double aproximacionPI( long inicial, long terminos ) {
       double casiPI = 0;
       double alterna = 4;

       for ( long i = inicial; i < terminos; i++ ) {
           casiPI += alterna/(2 * i + 1);
           alterna *= -1;
       }
       return casiPI;
    }

/**
 * Realiza las pruebas de la clase
**/
    public static void main( String[] args ) {
        long n = 100000;
        double x;

	if ( args.length > 0 ) {
           n = Long.parseLong( args[ 0 ] );
	}
        PiPorSeries pi = new PiPorSeries( n );
        x = pi.aproximacionPI( 0, n );
        System.out.println( "Valor calculado de PI: " + x );

    }
}

