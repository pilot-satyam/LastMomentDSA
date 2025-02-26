import java.util.Arrays;
import java.util.Comparator;

class Person implements Comparable<Person> {
    String name;
    int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public int compareTo(Person other) { //since comparable hence compareTo method is used
        return Integer.compare(this.age, other.age); // Default sorting by age
    }

    @Override
    public String toString() {
        return name + " (" + age + ")";
    }
}

public class SortExample {
    public static void main(String[] args) {
        Person[] people = {
            new Person("Alice", 30),
            new Person("Bob", 25),
            new Person("Charlie", 35)
        };

        // Sort by age (using Comparable)
        Arrays.sort(people);
        System.out.println("Sorted by age:");
        for (Person person : people) {
            System.out.println(person);
        }

        // Sort by name (using Comparator)
        Arrays.sort(people, new Comparator<Person>() {
            @Override
            public int compare(Person p1, Person p2) { //compare method is used
                return p1.name.compareTo(p2.name); // Sort by name
            }
        });

        System.out.println("\nSorted by name:");
        for (Person person : people) {
            System.out.println(person);
        }
    }
}
