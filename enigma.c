#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

/* Direction constants */
#define tam 0
#define zpet 1


char printch(char Ch) {
    char result;

    if (Ch >= 0 && Ch <= 9) {
        /*0-9 */
        result = '0' + Ch;
    } else if (Ch >= 10 && Ch <= 35) {
        /*A-Z (10-35) */
        result = 'A' + (Ch - 10);
    } else {
        /* Handle invalid input */
        printf("Unknown character\n");
        return '?';
    }

    /* Print and return the character */
    printf("%c\n", result);
    return result;
}

char kontrola(char Ch) {
    if (Ch > 35) {
        return Ch - 36;
    } else if (Ch < 0) {
        return Ch + 36;
    } else {
        return Ch;
    }
}

char urSmer(char Ch, char* disk, bool smer) {
    if (smer == tam) {
        /* Forward direction: direct mapping */
        Ch = disk[Ch];
    } else {
        /* Backward direction: inverse mapping */
        char poz = 0;
        while (Ch != (disk[poz])) {
            poz++;
        }
        Ch = poz;
    }
    return Ch;
}

char disk5(short pozice, char Ch, bool smer) {

    char disk[36] = {
        30, 1, 24, 35, 17, 19, 26, 15, 6, 9, 20, 22, 27, 31, 32, 0, 12, 16, 8, 29,
        14, 28, 2, 23, 3, 4, 18, 25, 10, 34, 13, 21, 33, 5, 11, 7
    };

    Ch += pozice;
    Ch = kontrola(Ch);

    Ch = urSmer(Ch, disk, smer);

    Ch -= pozice;
    Ch = kontrola(Ch);

    return Ch;
}

char disk4(short pozice, char Ch, bool smer) {

    char disk[36] = {
        17, 14, 12, 21, 2, 24, 28, 35, 16, 1, 25, 9, 32, 23, 19, 27, 5, 30, 33, 10,
        22, 6, 20, 29, 31, 0, 8, 7, 26, 3, 4, 11, 15, 18, 34, 13
    };

    Ch += pozice;
    Ch = kontrola(Ch);

    Ch = urSmer(Ch, disk, smer);

    Ch -= pozice;
    Ch = kontrola(Ch);

    return Ch;
}

char disk3(short pozice, char Ch, bool smer) {

    char disk[36] = {
        15, 8, 30, 27, 0, 25, 1, 16, 32, 12, 28, 35, 5, 2, 26, 17, 3, 6, 19, 34,
        14, 18, 9, 10, 22, 21, 4, 7, 24, 11, 33, 20, 23, 13, 31, 29
    };

    Ch += pozice;
    Ch = kontrola(Ch);

    Ch = urSmer(Ch, disk, smer);

    Ch -= pozice;
    Ch = kontrola(Ch);

    return Ch;
}

char disk2(short pozice, char Ch, bool smer) {
    char disk[36] = {
        20, 5, 13, 8, 35, 29, 11, 26, 17, 24, 32, 31, 33, 3, 4, 7, 0, 16, 19, 15,
        27, 22, 10, 6, 30, 12, 34, 2, 14, 9, 21, 18, 25, 28, 1, 23
    };

    Ch += pozice;
    Ch = kontrola(Ch);

    Ch = urSmer(Ch, disk, smer);

    Ch -= pozice;
    Ch = kontrola(Ch);

    return Ch;
}

char disk1(short pozice, char Ch, bool smer) {

    char disk[36] = {
        35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20,
        19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
    };

    Ch += pozice;
    Ch = kontrola(Ch);

    Ch = urSmer(Ch, disk, smer);

    Ch -= pozice;
    Ch = kontrola(Ch);

    return Ch;
}

void input(int *num) {
    int check = scanf("%d", num);
    getchar(); /* Clear the input buffer */

    if (check != 0) {
        return; /* Valid input received */
    } else {
        /* Invalid input, try again */
        input(num);
        return;
    }
}

void INp(int *num, int min, int max) {
    do {
        input(num);
    } while (*num < min || *num > max);
}

char disky(int disk, int pozice, char Ch, short *zach, bool smer) {
    switch (disk) {
    case 1:
        Ch = disk1(pozice, Ch, smer);
        *zach = 0;
        return Ch;

    case 2:
        Ch = disk2(pozice, Ch, smer);
        *zach = 23;
        return Ch;

    case 3:
        Ch = disk3(pozice, Ch, smer);
        *zach = 10;
        return Ch;

    case 4:
        Ch = disk4(pozice, Ch, smer);
        *zach = 22;
        return Ch;

    case 5:
        Ch = disk5(pozice, Ch, smer);
        *zach = 15;
        return Ch;

    default:
        /* Invalid disk number */
        printf("Invalid disk number: %d\n", disk);
        *zach = 0;
        return Ch;
    }
}

char diskyvse(int disk1, int disk2, int disk3, int *pozice1, int *pozice2, int *pozice3, char Ch) {
    /* Reflector */
    short head[36] = {
        16, 8, 27, 14, 35, 17, 7, 6, 1, 33, 25, 22, 30, 19, 3, 34, 0, 5, 20, 13,
        18, 28, 11, 29, 26, 10, 24, 2, 21, 23, 12, 32, 31, 9, 15, 4
    };

    /* Store current positions */
    short poz1 = *pozice1,
          poz2 = *pozice2,
          poz3 = *pozice3;

    /* Variables to store notch positions */
    short zachitka1, zachitka2, zachitka3;

    /* Forward path through rotors */
    Ch = disky(disk1, poz1, Ch, &zachitka1, tam);
    Ch = disky(disk2, poz2, Ch, &zachitka2, tam);
    Ch = disky(disk3, poz3, Ch, &zachitka3, tam);

    /* Through the reflector */
    Ch = kontrola(Ch);
    Ch = head[Ch];
    Ch = kontrola(Ch);

    /* Backward path through rotors */
    Ch = disky(disk3, poz3, Ch, &zachitka3, zpet);
    Ch = disky(disk2, poz2, Ch, &zachitka2, zpet);
    Ch = disky(disk1, poz1, Ch, &zachitka1, zpet);

    /* Display current positions */
    printf("\npozice\n%i,%i,%i\n", *pozice1, *pozice2, *pozice3);

    /* Rotor 3 - steps when rotor 2 and rotor 1 reach their notches */    
    if (*pozice3 >= 36 && *pozice2 == zachitka2 && *pozice1 == zachitka1) {
        *pozice3 = 0;
    } else if (*pozice2 == zachitka2 && *pozice1 == zachitka1) {
        *pozice3 = *pozice3 + 1;
    }

    /* Rotor 2 - steps when rotor 1 reaches its notch */    
    if (*pozice2 >= 36 && *pozice1 == zachitka1) {
        *pozice2 = 0;
    } else if (*pozice1 == zachitka1) {
        *pozice2 = *pozice2 + 1;
    }

    /* Rotor 1 - always steps */
    if (*pozice1 >= 36) {
        *pozice1 = 0;
    } else {
        *pozice1 = *pozice1 + 1;
    }

    return Ch;
}
