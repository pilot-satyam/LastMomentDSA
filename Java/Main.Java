import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        String str = "stress";
        HashMap<Character, Integer> m = new HashMap<>();

        // Count the frequency of each character
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            m.put(c, m.getOrDefault(c, 0) + 1);
        }

        // Find the first character with frequency 1 in the order of appearance
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (m.get(c) == 1) {
                System.out.println(c);  // This is the first non-repeating character
                return;
            }
        }

        System.out.println("No unique characters found");
    }
}
