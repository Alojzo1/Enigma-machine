typedef struct zakladni
        {
        //    JEDENKUS * dopredu;   ...tohle nejde
        //    JEDENKUS * zpatky;
            struct zakladni * dopredu;
            char data;
        } ulozeno;
void display_list( ulozeno *head);
void delete_list( ulozeno *head);
void add_node( ulozeno *head, char  value);
ulozeno* novyprostor();
void display_list_num( ulozeno *head);
