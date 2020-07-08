/*
    Convert a decimal number lying between 1-3999 to roman numerals
*/

/*
    Solution
    Time Complexity: O(log10(n))
    Space Complexity: O(1)
*/
string convertToRoman(int n) 
{
    switch(n) {
        case 1: return "I";
        case 4: return "IV";
        case 5: return "V";
        case 9: return "IX";
        case 10: return "X";
        case 40: return "XL";
        case 50: return "L";
        case 90: return "XC";
        case 100: return "C";
        case 400: return "CD";
        case 500: return "D";
        case 900: return "CM";
        case 1000: return "M";
        default: break;
    }

    int divisor = 1000;

    string roman_equivalent = "";
    
    while(n) {
        int q = n / divisor;
        if(q == 9) roman_equivalent += convertToRoman(9 * divisor);
        else if(q >= 5) roman_equivalent += convertToRoman(5 * divisor) + convertToRoman((q - 5) * divisor);
        else if(q == 4) roman_equivalent += convertToRoman(4 * divisor);
        else for(int k=0; k<q; ++k) roman_equivalent += convertToRoman(divisor);
        n = n % divisor;
        divisor /= 10;
    }
    
    return roman_equivalent;
}