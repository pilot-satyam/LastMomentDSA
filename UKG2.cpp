int a()
{    
    try
    {        int a = 1/0;        return 1; 
    }   
 catch(Exception e){ return 2;    
}   
finally{        System.out.println("Test");        return 3;    }}


M1 M2 
p1 p2

http://m1/api/p1
m2 needs to call p1 from m1

@PostMapping("/p1")
public ResponseEntity<String>

String response  = service.call1fromP1(request)

String url = "http:/m1/api/p1"
return restTemplate.postForPbject(url,request)

nput: “ABCDEFGABEF”
Output: 7
Explanation: The longest substring without repeating characters are “ABCDEFG”, “BCDEFGA”, and “CDEFGAB” with lengths of 7.


int solve(vector<char> &input){
    unordered_set<char> s;
    int left = 0;
    int maxLen = 0;
    for(int right=0;right<input.size();i++){
        //if char exist in set then we will shrink form left
        while(s.find(input[right])!=s.end()){
            s.erase(input[left]);
            left++;
        }
        //add new characted
        s.insert(input[right]);
        //update malength
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}