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

    vector<int> divisors{1000, 500, 100, 50, 10, 5, 1};
    int i = 0;

    string roman_equivalent = "";
    
    while(n) {
        int q = n / divisors[i];
        if(q == 9 || q == 4) roman_equivalent += convertToRoman(q * divisors[i]);
        else for(int k=0; k<q; ++k) roman_equivalent += convertToRoman(divisors[i]);
        n = n % divisors[i];
        ++i;
    }

    return roman_equivalent;
}