public class ProducerConsumerTest {
   public static void main(String[] args) {
      monitor y = new monitor();
       Consumer c1 = new Consumer(y, 1);
       Producer p1 = new Producer(y, 1);
   
      c1.start();
      p1.start(); 
   }
}
class monitor {
   private int buffer;
   private boolean available = false;
   public synchronized int get() {
      while (available == false) {
         try {
            wait();
         }
         catch (InterruptedException e) {
         }
      }
      available = false;
      notifyAll();
      return buffer;
   }
   public synchronized void put(int val) {
      while (available == true) {
         try {
            wait();
         }
         catch (InterruptedException e) { 
         } 
      }
      buffer = val;
      available = true;
      notifyAll();
   }
}

class Consumer extends Thread {
   private monitor monitor;
   private int number;
   public Consumer(monitor y, int number) {
      monitor = y;
      this.number = number;
   }
   public void run() {
      int value = 0;
        
            value = monitor.get();
            System.out.println("Consumer #" 
			+ this.number
+ " got: " + value);

}
}

class Producer extends Thread {
private monitor monitor;
private int number;

public Producer(monitor y, int number) {
monitor = y;
this.number = number;
}

public void run() {
monitor.put(this.number);
System.out.println("Producer #" + this.number
+ " put: " + this.number);
try {
sleep((int)(Math.random() * 100));
} catch (InterruptedException e) { }

}
}
