/*
bitové operace, Ano
bitová pole,    Ano
struktury,      Ano
dynamická alokace paměti v kombinaci s datovou strukturou (spojový seznam), Ano
členění kódu do více souborů, 2 knihovny Ano
funkce s různým proměnlivým počtem parametrů,   Ne
práce s časem (knihovna)    Ano
*/

// include
#include <stdio.h>
#include "enigma.h"
#include "list.h"
#include <stdbool.h>
#include <windows.h>
#include <time.h>

// pocet znaku = 36 index 0 - 35
// definition
    #define ESC 27
    #define pocetDisku 5

// Interní nastavení 
    #define language "EN"
    //  optons CZ , EN
    //  default EN

int main(int argc, char const *argv[])
{
    system("cls");
    ulozeno * head = novyprostor();
    head -> data = '\n';
    head -> dopredu = NULL;
    // deklarace 
        int
            //bool
            error = 0,
            // disky
            disk1,disk2,disk3,
            // pozice disků
            pozice1,pozice2,pozice3,
            // propojovací deska
            deska[36]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};
        
    // deska
    while(true){
    char
        // nactene
        vstup1 = 0,
        vstup2 = 0;

        if (language == "CZ"){
            printf("zadejte dvojici pismen ktere chcete propojit pokud zadne dalsi zadejte ESC\n");
        }else{
            printf("enter 2 characters to connect or pres ESC to end selection \n");
        }
    // vstup read
        error = 0;
        vstup1 = getch();
        
        printf("%c\n",vstup1);
        
        if (vstup1 == ESC)
        {
            break;
        }
        else if(vstup1 > '0' -1 &&vstup1 < '9' +1){
            vstup1 = vstup1 - '0';
        }else if (vstup1 > 'A' -1 &&vstup1 < 'Z' +1)
        {
            vstup1 = vstup1 - ('A' - 10);
        }else if (vstup1 > 'a' -1 &&vstup1 < 'z' +1)
        {
            vstup1 = vstup1 - ('a' - 10);
        }else{
            error = error | 1;
            if (language == "CZ"){
                printf("\nzadejte pismeno / cislo\n");
            }else{
                printf("\nenter leather / number\n");
            }
        }
        
        if (error == 0)
        {            

            vstup2 = getch();
            
            printf("%c\n",vstup2);
            
            if (vstup2 == ESC)
            {
                break;
            }else if(vstup2 > '0' -1 &&vstup2 < '9' +1){
                vstup2 = vstup2 - '0';
            }else if (vstup2 > 'A' -1 &&vstup2 < 'Z' +1)
            {
                vstup2 = vstup2 - ('A' - 10);
            }else if (vstup2 > 'a' -1 &&vstup2 < 'z' +1)
            {
                vstup2 = vstup2 - ('a' - 10);
            }else{
                error = error | 2;
                system("cls");
                if (language == "CZ"){
                    printf("\nzadejte pismeno / cislo\n");
                }else{
                    printf("\nenter leather / number\n");
                }
            }
        }
    // if table is free
        if(error == 0){
            if (deska[vstup1] == vstup1 && deska[vstup2] == vstup2)
            {
                deska[vstup1] = vstup2;
                deska[vstup2] = vstup1;
            }else if (deska[vstup1] != vstup1)
            {
                if (language == "CZ"){
                    printf("\nprvni vstup je jiz zabrany\n");
                }else{
                    printf("\nfirst input is alredy full\n");
                }
            }else if (deska[vstup2] != vstup2)
            {
                if (language == "CZ"){
                    printf("\ndruhy vstup je jiz zabrany\n");
                }else{
                    printf("\nsecond input is alredy full\n");
                }
            }
        }
    }    
    // nacteni disku 
    system("cls");
    {   
        if (language == "CZ"){
            printf("zadejte jaky disk je na pozici 1. min 1 max %i\n",pocetDisku);
            INp(&disk1,1,pocetDisku);
        
            printf("zadejte jaky disk je na pozici 2. min 1 max %i\n",pocetDisku);
            INp(&disk2,1,pocetDisku);
        
            printf("zadejte jaky disk je na pozici 3. min 1 max %i\n",pocetDisku);
            INp(&disk3,1,pocetDisku);
        }
        else {
            printf("Enter disk number on first pozition min 1 max %i\n",pocetDisku);
            INp(&disk1,1,pocetDisku);
        
            printf("Enter disk number on second pozition min 1 max %i\n",pocetDisku);
            INp(&disk2,1,pocetDisku);
        
            printf("Enter disk number on third pozition min 1 max %i\n",pocetDisku);
            INp(&disk3,1,pocetDisku);
            }
    }    
        system("cls");
    // nacteni pozic
    {   
        if (language == "CZ"){
            printf("zadejte na jake pozici je disk 1 min 0 max 35\n");
            INp(&pozice1,0,35);

            printf("zadejte na jake pozici je disk 2 min 0 max 35\n");
            INp(&pozice2,0,35);

            printf("zadejte na jake pozici je disk 2 min 0 max 35\n");
            INp(&pozice3,0,35);
        }
        else{
            
        
        
            printf("Enter on what pozition si the first disk min 0 max 35\n");
            INp(&pozice1,0,35);

            printf("Enter on what pozition si the second disk min 0 max 35\n");
            INp(&pozice2,0,35);

            printf("Enter on what pozition si the third disk min 0 max 35\n");
            INp(&pozice3,0,35);
            }
        system("cls");
    }
    // sifrovani
    while (true)
    {
        char
            // nactene
            vstup = 0,
            Ch;

        // nacteni
            vstup = getch();
            system("cls");
            if (language == "CZ")
            {
                printf("pro ukonceni zadejte ESC\n");
            }
            else
            {
                printf("to exit press ESC\n");
            }
            
            
            printf("%c\n",vstup);
            if (vstup == ESC)
            {
                system("cls");
                time_t current_time;
                current_time = time(NULL);
                struct tm *tm_local = localtime(&current_time);
                if (language == "CZ")
                {
                    printf("\nCas napsani spravy nani zasifrovan z bezpecnostniho hlediska\n%d:%d:%d %d.%d.%d",tm_local->tm_hour,tm_local->tm_min,tm_local->tm_sec,tm_local->tm_mday,tm_local->tm_mon +1,tm_local->tm_year + 1900);
                }
                else
                {
                    printf("\nTime is not encoded it is a security procosion\n%d:%d:%d %d.%d.%d",tm_local->tm_hour,tm_local->tm_min,tm_local->tm_sec,tm_local->tm_mon +1,tm_local->tm_mday,tm_local->tm_year + 1900);
                }

                printf("\n");
                display_list(head);
                delete_list(head);
                printf("\n press any key to end\n");                
                
                getch();
                system("cls");
                return 1;
            }else if(vstup > '0' -1 &&vstup < '9' +1){
                Ch = vstup - '0';
                error = error | (1<<2);
            }else if (vstup > 'A' -1 &&vstup < 'Z' +1)
            {
                Ch = vstup - 'A'  +10;
                error = error | (1<<2);
            }else if (vstup > 'a' -1 &&vstup < 'z' +1)
            {
                Ch = vstup - 'a'  +10;
                error = error | (1<<2);
            }else{
                error = error & ~(1<<2);
                system("cls");
                if (language == "CZ"){
                    printf("zadejte pismeno / cislo\n");
                }else{
                    printf("enter leather / number\n");
                }
            }
            
        if (((error >> 2) & 1) == 1)
        {   
            // deska    
                Ch = deska[Ch];
            // disky
                Ch =  diskyvse(disk1,disk2,disk3,&pozice1,&pozice2,&pozice3,Ch);
            // deska
                Ch = deska[Ch];
            // vypis pismene
            Ch = printch(Ch);

            add_node(head,Ch);            
        }
    }
}
