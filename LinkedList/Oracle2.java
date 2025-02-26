import java.util.*;

public class Oracle2<T> extends ArrayList<T>{
    //checking if the element already exists
    @Override
    public boolean add(T element){
        if(this.contains(element)){
            System.out.println("Duplicate element not added:" + element);
            return false; //rejecting duplicate
        }
        //add non duplicate vallue
        return super.add(element);
    }
    //preventing addind duplicates at specific index
    @Override
    public void add(int index, T element){
        if(this.contains(element)){
            System.out.println("Duplicate element not added in the index :" + index + ":" + element);
            return;//rejecting
        }
        super.add(element); //adding non duplicate element
    }

    public static void main(String[] args){
        Oracle2<String> customList = new Oracle2<>();
        customList.add("Java");
        customList.add("Spring");
        customList.add("Java"); //duplicate
        customList.add(0,"Spring Boot"); //adding at index
        customList.add(1,"Spring"); //it is duplicate, should not add
        System.out.println("Final List:" + customList);
    }   
}