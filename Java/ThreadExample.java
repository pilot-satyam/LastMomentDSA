/**
 * Multithreading By Extending Thread class
 */

class MyThread extends Thread{

    public void run(){
        for(int i=0;i<5;i++){
            System.out.println("Thread class" + Thread.currentThread().getName() + "- Count::" + i);
            try{
                Thread.sleep(100);
            }catch(InterruptedException ex){
                ex.printStackTrace();
            }
        }
    }
}


public class ThreadExample{
    public static void main(String[] args) {
        MyThread thread1 = new MyThread();
        MyThread thread2 = new MyThread();
        thread1.start();
        thread2.start();

        //Using Runnable Interface
        MyRunnable mr1 = new MyRunnable();
        //here we need to create and use object from thread class
        Thread t1 = new Thread(mr1);
        Thread t2 = new Thread(mr1);
        t1.start();
        t2.start();
    }
}

/*
 *  Multithreading by implementing Runnable Interface
 */

class MyRunnable implements Runnable {
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println("Runnable IF" +Thread.currentThread().getName() + " - Count: " + i);
            try {
                Thread.sleep(100); // Sleep for 100ms
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}