public class Singleton{
    //creating constructor
    private Singleton(){

    } 

    private static Singleton instance;

    //method to provide access to insta9nce
    public static Singleton getInstance(){
        //checking if instance is null before creating it (Lazy)
        if(instance == null){
            synchronized(Singleton.class){
                instance = new Singleton();
            }
        }
        return instance;
    }

    public void show(){
        System.out.println("Singleton Instance: " + this.hashCode());
    }

    public static int reverse(int n){
        int reversed = 0;
        while(n!=0){
            //extract the last digit and add it to reverse
            int digit = n % 10;
            reversed = reversed * 10 + 10;
            //remove the last digit
            n/=10;
        }
        return reversed;
    }

    
}

