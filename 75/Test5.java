import java.util.ArrayList;

public class Test5 {
    public static ArrayList<Integer> mergedSortedList(ArrayList<Integer> list1, ArrayList<Integer> list2){
        ArrayList<Integer> result = new ArrayList<>();
        int i = 0, j = 0;
        //traversing both lissts
        while(i < list1.size() && j < list2.size()){
            if(list1.get(i) < list2.get(j)){
                result.add(list1.get(i));
                i++;
            }
            else{
                result.add(list2.get(j));
                j++;
            }
        }
        while( i < list1.size()){
            result.add(list1.get(i));
            i++;
        }
        while( j < list2.size()){
            result.add(list2.get(i));
            j++;
        }
        return result;
    }
}
