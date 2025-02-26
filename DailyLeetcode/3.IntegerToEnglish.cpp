#include<bits/stdc++.h>
using namespace std;

/*
* Ques: https://leetcode.com/problems/integer-to-english-words/
*/

//New Solution : 
//Using Java
//T.C ==> O(log(n))
//S.C ==> O(1)
	public String numberToWords(int num){
	    if(num == 0) return "Zero";
	    String[] ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	    String[] tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        String[] thousands = {"", "Thousand", "Million", "Billion"};
        
        //For accumulating result
        StringBuilder result = new StringBuilder();
        int groupIdx= 0;
        //processing numbers in terms of chunks (1000)
        while(num > 0){
            
            //last 3 digits
            if(num % 1000 != 0){
                StringBuilder sb = new StringBuilder();
                int part = num % 1000;
                
                //Handling hundreds
                if(part >= 100){
                    sb.append(ones[part/100]).append("Hundred");
                    part %= 100;
                }
                
                //Handling tens and ones
                if(part >= 20){
                    sb.append(tens[part/10]).append("");
                    part %= 10;
                }
                
                //Handling units
                if(part > 0){
                    sb.append(ones[part]).append("");
                }
                
                //appending the scale (Thousand,Million,Billion)
                sb.append(thousands[groupIdx]).append("");
                
                //Inserting group result at beginning of final result
                result.insert(0,sb);
            }
            //next chunk of 1000
            num /= 1000;
            groupIdx++;
        }
        return result.toString().trim();
	}

//using c++

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return intToString(num).substr(1);
    }

private:
    vector<string> below_20{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands{"", "Thousand", "Million", "Billion"};

    string intToString(int num) {
        if (num == 0) return "";
        if (num < 20) return " " + below_20[num];
        else if (num < 100) return " " + tens[num / 10] + intToString(num % 10);
        else if (num < 1000) return " " + below_20[num / 100] + " Hundred" + intToString(num % 100);
        else {
            for (int i = 1; i < thousands.size(); i++) {
                if (num < pow(1000, i + 1))//for million,billion, eg for i = 1 ==> pow(1000,2)==>10,00,000
                 {
                    return intToString(num / static_cast<int>(pow(1000, i))) + " " + thousands[i] + intToString(num % static_cast<int>(pow(1000, i)));
                }
            }
        }
        return "";
    }
};

int main(){

}