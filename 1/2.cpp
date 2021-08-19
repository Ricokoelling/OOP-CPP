#include <iostream>
#include <stdio.h>
#include <limits>

int main()
{
    //Speichergröße hat bei der Ausgabe komisch ausgesehen deswegen habe ich Speichergroesze verwendet
    //char
    printf("Der Datentyp %s hat die Speichergroesze %d Byte und liegt im Zahlenbereich zwischen %d und %d \n\r", "char", sizeof(char), std::numeric_limits<char>::min(), std::numeric_limits<char>::max());

    //unsigned char

    printf("Der Datentyp %s hat die Speichergroesze %d Byte und liegt im Zahlenbereich zwischen %u und %llu \n\r", "unsigned char", sizeof(unsigned char), std::numeric_limits<unsigned char>::min(), std::numeric_limits<unsigned char>::max());

    //signed char

    printf("Der Datentyp %s hat die Speichergroesze %d Byte und liegt im Zahlenbereich zwischen %d und %d \n\r", "signed char", sizeof(signed char), std::numeric_limits<signed char>::min(), std::numeric_limits<signed char>::max());

    //short

    printf("Der Datentyp %s hat die Speichergroesze %d Byte und liegt im Zahlenbereich zwischen %d und %d \n\r", "short", sizeof(short), std::numeric_limits<short>::min(), std::numeric_limits<short>::max());

    //unsigned short

    printf("Der Datentyp %s hat die Speichergroesze %d Byte und liegt im Zahlenbereich zwischen %u und %llu \n\r", "unsigned short", sizeof(unsigned short), std::numeric_limits<unsigned short>::min(), std::numeric_limits<unsigned short>::max());

    // int

    printf("Der Datentyp %s hat die Speichergroesze %d Byte und liegt im Zahlenbereich zwischen %d und %d \n\r", "int", sizeof(int), std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

    //unsigned int

    printf("Der Datentyp %s hat die Speichergroesze %d Byte und liegt im Zahlenbereich zwischen %u und %llu \n\r", "unsigned int", sizeof(unsigned int), std::numeric_limits<unsigned int>::min(), std::numeric_limits<unsigned int>::max());

    //long int

    printf("Der Datentyp %s hat die Speichergroesze %d Byte und liegt im Zahlenbereich zwischen %d und %d \n\r", "long int", sizeof(long int), std::numeric_limits<long int>::min(), std::numeric_limits<long int>::max());

    //unsigned long int

    printf("Der Datentyp %s hat die Speichergroesze %d Byte und liegt im Zahlenbereich zwischen %u und %llu \n\r", "unsigned long int", sizeof(unsigned long int), std::numeric_limits<unsigned long int>::min(), std::numeric_limits<unsigned long int>::max());

    //long long int

    printf("Der Datentyp %s hat die Speichergroesze %d Byte und liegt im Zahlenbereich zwischen %lld und %lld \n\r", "long long int", sizeof(long long int), std::numeric_limits<long long int>::min(), std::numeric_limits<long long int>::max());

    //unsigned long ing

    printf("Der Datentyp %s hat die Speichergroesze %d Byte und liegt im Zahlenbereich zwischen %llu und %llu \n\r", "unsigned long long int", sizeof(unsigned long long int), std::numeric_limits<unsigned long long int>::min(), std::numeric_limits<unsigned long long int>::max());

    return 0;
}