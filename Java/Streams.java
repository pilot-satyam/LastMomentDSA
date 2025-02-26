import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * GYAAN : map() transforms each element of the stream to another object.
           flatMap() flattens a stream of collections into a single stream.
 */

public class Streams {
   public static void main(String[] args){
    ArrayList<String> list = new ArrayList<String>();
    list.add("Adding Element");
    list.add("New Element");
    list.add("Again addimg a");
    List<String> filteredList =  list.stream()
                                .filter(s -> s.startsWith("A"))
                                .collect(Collectors.toList());
    System.out.println(filteredList);

    List<Integer> newList = Arrays.asList(1,2,3,4,5,6,7,8,9,10);
   //for finding even number sum greater than 5
      int sum = newList.stream()
            .filter(n -> n > 5)
            .filter(n -> n%2 == 0)
            .mapToInt(Integer :: intValue)//converting stream to integer
            .sum();
            System.out.println(sum);

                                    newList.stream()
                                   .map(n -> n*n)
                                   .forEach(y -> System.out.println(y));
                                //    .collect(Collectors.toList());

   /**
    * Grouping Elements
    */

    List<String> words = Arrays.asList("apple", "banana", "cherry", "avocado", "blueberry");
    Map<Character,List<String>> groupByFirstLetter = 
                              words.stream().collect(Collectors.groupingBy(word->word.charAt(0)));
      groupByFirstLetter.forEach((key,value) -> System.out.println(key + ": " + value));  
      
   /**
    * Sorting Example
    */

    List<String> names = Arrays.asList("DEEU", "ISHU", "AASHIQ");
    names.stream().sorted().forEach(System.out::println); //Comparator.naturalOrder() u can use this too

    //flatMap() ka kaam hai jab ek element ke liye tumhe multiple elements milte hain aur tumhe un sabko ek hi stream mein combine karna hai.
      // Ek-to-bahut (one-to-many) transformation hota hai.
      //flatMap(): Agar tumhare paas list of lists hai, aur tum chahte ho ki sab lists ko ek
      //  hi list mein combine karna (e.g., list of sentences ko words mein todhna).

    List<String> sentences = Arrays.asList("Hello world", "Java streams", "FlatMap example");

        // Using flatMap to split sentences into words and flatten the result
        List<String> words2 = sentences.stream()
                                      .flatMap(sentence -> Arrays.stream(sentence.split(" ")))  // Flattening the array of words
                                      .collect(Collectors.toList());
                                      words2.forEach(System.out::println);
   // Output: Hello, world, Java, streams, FlatMap, example
   }
}
