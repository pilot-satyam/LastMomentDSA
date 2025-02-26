public class ObjectCounter{
    //static counter to track the number of objects
    private static int count = 0;
    //constructor increments the count
    public ObjectCounter(){
        count++;
    }
    //method to get current count
    public static int getObjectCount(){
        return count;
    }

    //override to finalize the decrement the count
    // protected void finalize(){
    //     count--;
    //     super.finalize();
    // }

    public static void main(String[] args){
        System.out.println("Initial Object Count: " + getObjectCount());
        ObjectCounter obj1 = new ObjectCounter();
        ObjectCounter obj2 = new ObjectCounter();
        System.out.println("Object Count after creating 2 objects: "+ getObjectCount());
    }
}