#include<stdio.h>
#include<stdlib.h>

typedef struct zakladni
        {
        //    JEDENKUS * dopredu;   ...tohle nejde
        //    JEDENKUS * zpatky;
            struct zakladni * dopredu;
            char data;
        } ulozeno;

// alokování paměti členu
ulozeno* novyprostor()
{
    ulozeno * nove_misto = (ulozeno *) malloc(sizeof(ulozeno));
    return (nove_misto);
}

void display_list( ulozeno *head){
    struct zakladni* aktivni=head;
    while(aktivni!=NULL)
    {
    printf("%c",aktivni->data);
    aktivni=aktivni->dopredu;
    }
    printf("\n");

}
void display_list_num( ulozeno *head){
    struct zakladni* aktivni=head;
    while(aktivni!=NULL)
    {
    printf("%d, ",aktivni->data);
    aktivni=aktivni->dopredu;
    }
    printf("\n");

}
void delete_list( ulozeno *head){
    while (head->dopredu != NULL)
    {   
        ulozeno * pp0 = head,*pp1;
        while (pp0 -> dopredu != NULL)
        {
            pp1 = pp0; 
            pp0 = pp0 -> dopredu;
        }
        free(pp0);
        pp1 -> dopredu = NULL;
    }
    free(head);
}
void add_node( ulozeno *head, char  value){
        ulozeno* pp0 = head;
        while (pp0->dopredu != NULL)
        {
            pp0 = pp0->dopredu;
        } 
        // posledni prvek
        ulozeno* pp1= novyprostor();
        pp0->dopredu = pp1;
        pp1->dopredu = NULL;
        pp1->data = value;
        
}