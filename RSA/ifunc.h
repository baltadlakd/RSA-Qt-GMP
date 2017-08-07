#ifndef IFUNC_H
#define IFUNC_H

#include <QMessageBox>
#include <QChar>
#include <QString>
#include <gmpxx.h>


mpz_class gcd(mpz_class a,mpz_class b)
{
    static mpz_class tmp;
    static bool tmp2;
    if(b>a) { tmp=a; a=b; b=tmp; }
    if((a%b) == 0)
    { tmp=0; tmp2=false; return ((tmp2) ? (tmp) : (b)); }
    tmp=a%b; tmp2=true; return gcd(b,a%b);
}


bool isPrimo(mpz_class num)
{
    bool primo=true;
    unsigned int divisor=2;
    if(num==2)
    { return true; }
    else
    {
        while((true==primo)&&(num!=divisor))
        {
            if(num%divisor==0)
            { primo=false; }
            else
            { divisor++; }
        }
        if(primo==true)
        { return true; }
    }
    return false;
}

bool isPrimo(unsigned int num)
{
    bool primo=true;
    unsigned int divisor=2;
    if(num==2)
    { return true; }
    else
    {
        while((true==primo)&&(num!=divisor))
        {
            if(num%divisor==0)
            { primo=false; }
            else
            { divisor++; }
        }
        if(primo==true)
        { return true; }
    }
    return false;
}

unsigned int ltoNumber(char a)
{
    switch(a)
    {
        case ' ': return 10;
        case 'A': return 11;
        case 'B': return 12;
        case 'C': return 13;
        case 'D': return 14;
        case 'E': return 15;
        case 'F': return 16;
        case 'G': return 17;
        case 'H': return 18;
        case 'I': return 19;
        //==================
        case 'J': return 20;
        case 'K': return 21;
        case 'L': return 22;
        case 'M': return 23;
        case 'N': return 24;
        case 'O': return 25;
        case 'P': return 26;
        case 'Q': return 27;
        case 'R': return 28;
        case 'S': return 29;
        //==================
        //==================
        case 'T': return 30;
        case 'U': return 31;
        case 'V': return 32;
        case 'W': return 33;
        case 'X': return 34;
        case 'Y': return 35;
        case 'Z': return 36;
        case 'a': return 37;
        case 'b': return 38;
        case 'c': return 39;
        //==================
        //==================
        case 'd': return 40;
        case 'e': return 41;
        case 'f': return 42;
        case 'g': return 43;
        case 'h': return 44;
        case 'i': return 45;
        case 'j': return 46;
        case 'k': return 47;
        case 'l': return 48;
        case 'm': return 49;
        //==================
        //==================
        case 'n': return 50;
        case 'o': return 51;
        case 'p': return 52;
        case 'q': return 53;
        case 'r': return 54;
        case 's': return 55;
        case 't': return 56;
        case 'u': return 57;
        case 'v': return 58;
        case 'w': return 59;
        //==================
        //==================
        case 'x': return 60;
        case 'y': return 61;
        case 'z': return 62;
        case '.': return 63;
        case ',': return 64;
        case ':': return 65;
        case ';': return 66;
        case '\'': return 67;
        case '"': return 68;
        case '`': return 69;
        //==================
        //==================
        case '!': return 70;
        case '@': return 71;
        case '#': return 72;
        case '$': return 73;
        case '%': return 74;
        case '^': return 75;
        case '&': return 76;
        case '*': return 77;
        case '-': return 78;
        case '+': return 79;
        //==================
        //==================
        case '(': return 80;
        case ')': return 81;
        case '[': return 82;
        case ']': return 83;
        case '{': return 84;
        case '}': return 85;
        case '?': return 86;
        case '/': return 87;
        case '<': return 88;
        case '>': return 89;
        //==================
        //==================
        case '0': return 90;
        case '1': return 91;
        case '2': return 92;
        case '3': return 93;
        case '4': return 94;
        case '5': return 95;
        case '6': return 96;
        case '7': return 97;
        case '8': return 98;
        case '9': return 99;
        //==================
    default: return 86;
    }
    return 1;
}
QChar ntoLetter(int a)
{
    switch(a)
    {
        case 10: return ' ';
        case 11: return 'A';
        case 12: return 'B';
        case 13: return 'C';
        case 14: return 'D';
        case 15: return 'E';
        case 16: return 'F';
        case 17: return 'G';
        case 18: return 'H';
        case 19: return 'I';
        //==================
        case 20: return 'J';
        case 21: return 'K';
        case 22: return 'L';
        case 23: return 'M';
        case 24: return 'N';
        case 25: return 'O';
        case 26: return 'P';
        case 27: return 'Q';
        case 28: return 'R';
        case 29: return 'S';
        //==================
        //==================
        case 30: return 'T';
        case 31: return 'U';
        case 32: return 'V';
        case 33: return 'W';
        case 34: return 'X';
        case 35: return 'Y';
        case 36: return 'Z';
        case 37: return 'a';
        case 38: return 'b';
        case 39: return 'c';
        //==================
        //==================
        case 40: return 'd';
        case 41: return 'e';
        case 42: return 'f';
        case 43: return 'g';
        case 44: return 'h';
        case 45: return 'i';
        case 46: return 'j';
        case 47: return 'k';
        case 48: return 'l';
        case 49: return 'm';
        //==================
        //==================
        case 50: return 'n';
        case 51: return 'o';
        case 52: return 'p';
        case 53: return 'q';
        case 54: return 'r';
        case 55: return 's';
        case 56: return 't';
        case 57: return 'u';
        case 58: return 'v';
        case 59: return 'w';
        //==================
        //==================
        case 60: return 'x';
        case 61: return 'y';
        case 62: return 'z';
        case 63: return '.';
        case 64: return ',';
        case 65: return ':';
        case 66: return ';';
        case 67: return '\'';
        case 68: return '"';
        case 69: return '`';
        //==================
        //==================
        case 70: return '!';
        case 71: return '@';
        case 72: return '#';
        case 73: return '$';
        case 74: return '%';
        case 75: return '^';
        case 76: return '&';
        case 77: return '*';
        case 78: return '-';
        case 79: return '+';
        //==================
        //==================
        case 80: return '(';
        case 81: return ')';
        case 82: return '[';
        case 83: return ']';
        case 84: return '{';
        case 85: return '}';
        case 86: return '?';
        case 87: return '/';
        case 88: return '<';
        case 89: return '>';
        //==================
        //==================
        case 90: return '0';
        case 91: return '1';
        case 92: return '2';
        case 93: return '3';
        case 94: return '4';
        case 95: return '5';
        case 96: return '6';
        case 97: return '7';
        case 98: return '8';
        case 99: return '9';
        //==================
    default: return '?';
    }
    return 1;
}


#endif // IFUNC_H
