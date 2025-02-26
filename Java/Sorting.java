import java.util.Arrays;
public class Sorting
{
	public static void main(String[] args) {
		String[] monthArray = {"Jan","Feb","April","august","december","December"};
		Arrays.sort(monthArray);
		for(String s : monthArray){
		    System.out.print(s + " ");
		}
				    System.out.println(" \n ");
		//correcting the case insensitive sort
		Arrays.sort(monthArray,String.CASE_INSENSITIVE_ORDER);
		for(String sorted : monthArray){
		    System.out.print(sorted + " ");
		}
	}
}