/* 	To convert an excel column number to the column name
	1 -> A
	27 -> Z
	51 -> AY
*/
string column_num_to_title(lld num) {
    string res = "";
    int rem;
    while(num) {
        --num; // We are decremening to convert num from 1 indexed to 0 indexed
        rem = num % 26;
        num /= 26; // After dividing it'll again become 1 indexed, so during th next iteration, we'll decrement it again
        res = (char)(rem + (int)'A') + res;
    }
    return res;
}


/* 	To convert an excel column title to its number
	A -> 1
	AA -> 27
*/
lld column_title_to_num(string s) {
    lld num = 0;
    for(int i = 0, place_value = pow(26, s.length()-1); 
    	i < s.length(); 
    	++i, place_value /= 26
    	) {

        num += ((int)(s[i] - 'A') + 1) * place_value; // We add 1 to convert from 0 indexed system to 1 indexed
    }
    return num;
}