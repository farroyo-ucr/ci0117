import java.util.concurrent.Semaphore;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.Random;

//A shared resource/class
class Shared {
    AtomicInteger cH;
    AtomicInteger cO;
    Semaphore SemH;
    Semaphore SemO;

    public Shared() {
       cH = new AtomicInteger();	// Inits variable in zero
       cO = new AtomicInteger();
       // creating a Semaphore object with number of permits 0
       SemH = new Semaphore(0);
       SemO = new Semaphore(0);
    }

    public int getH() {
       return cH.get();
    }

    public int getO() {
       return cO.get();
    }

    public void IncH() {
       cH.getAndIncrement();
    }

    public void DecH() {
       cH.getAndDecrement();
    }

    public void IncO() {
       cO.incrementAndGet();
    }

    public void DecO() {
       cO.decrementAndGet();
    }

    public void SignalH() {
       this.SemH.release();
    }

    public void SignalO() {
       this.SemO.release();
    }

    public void WaitH() {
       try {
          this.SemH.acquire();
       } catch ( InterruptedException e ) {
       }
    }

    public void WaitO() {
       try {
          this.SemO.acquire();
       } catch ( InterruptedException e ) {
       }
    }

}
  
class Particle extends Thread {
    Random r;
    int number;
    Shared resources;

    public Particle( int i, Shared res ) {
       this.number = i;
       this.r = new Random();
       this.resources = res;
    } 
  
    @Override
    public void run() {
       if ( r.nextBoolean() ) {		// Create a new particle, randomly select hydrogen and oxygen
          System.out.println("Starting O thread " + this.number + " ... cO(" + resources.getO() + "), cH(" + resources.getH() + ")" );
          this.O();
       } else {
          System.out.println("Starting H thread " + this.number + " ... cO(" + resources.getO() + "), cH(" + resources.getH() + ")" );
          this.H();
       }

    }

    public void O() {
       if ( resources.getH() > 1 ) {
          System.out.println("\t O particle making water :) ... cO(" + resources.getO() + "), cH(" + resources.getH() + ")" );
          resources.DecH(); resources.DecH();
          resources.SignalH();
          resources.SignalH();
       } else {
          resources.IncO();
          resources.WaitO();
       }
    }

    public void H() {
       if ( (resources.getH() > 0) && (resources.getO() > 0) ) {
          System.out.println("\t H particle making water :) ... cO(" + resources.getO() + "), cH(" + resources.getH() + ")" );
          resources.DecH();
          resources.DecO();
          resources.SignalH();
          resources.SignalO();
       } else {
          resources.IncH();
          resources.WaitH();
       }
    }

} 
  
// Driver class 
public class Agua {
    public static void main(String args[]) throws InterruptedException {
        Shared agua = new Shared();

        Thread particles[] = new Thread[ 100 ];

        for ( int i = 0; i < 100; i++ ) {
           particles[ i ]  = new Particle( i, agua );
           particles[ i ].start();
        }

        // waiting for threads
        for ( int i = 0; i < 100; i++ ) {
           try {
              particles[ i ].join();
           } catch ( InterruptedException e) {
           }
 
        }
    }

}

