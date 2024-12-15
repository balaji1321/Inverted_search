#include "inv.h"

int search_DB(main_node_t **Hash_table, char *word){
    /*generate index*/
    int index = (word[0]>='A' && word[0]<='Z')?word[0] - 'A':(word[0]>='a'&&word[0]<='z')?word[0] - 'a':26;
    /*if index is equal to null return data not found*/
    if(Hash_table[index] == NULL){
        return DATA_NOT_FOUND;
    }

    /*create a temporary*/
    main_node_t *temp=Hash_table[index];
    /*traveserse through the nodes*/
    while(temp){
        /*data found*/
        if(!strcmp(temp->word,word)){
            green();
            printf("\nData Found!!\n");
            reset();
            /*print the data*/
            printf("'%s' found in %d files\n",temp->word,temp->f_count);
            /*traverse through sublinks*/
            sub_node_t *temp_sublink=temp->sub_link;
            while(temp_sublink){
                printf("%s %d times, ",temp_sublink->file_name,temp_sublink->w_count);
                temp_sublink=temp_sublink->link;
            }
            printf("\n\n");
            return SUCCESS;
        }
        temp = temp->link;
    }
    return DATA_NOT_FOUND;
}