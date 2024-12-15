#include "inv.h"

/*display the data*/
void display_db(main_node_t **Hash_table,int size){
    /*run a loop until size times*/
    for(int i=0;i<size;i++){
        /*if Hashtable not NULL we have to print the data*/
        main_node_t *temp_hash=Hash_table[i];
        if(temp_hash!=NULL){
            /*print the data*/
            printf("[%d] '%s' %d ",i,temp_hash->word,temp_hash->f_count);
            /*traverse through sublinks*/
            sub_node_t *temp_sublink=temp_hash->sub_link;
            while(temp_sublink){
                printf(" %s %d",temp_sublink->file_name,temp_sublink->w_count);
                temp_sublink=temp_sublink->link;
            }
            printf("\n");
            main_node_t *temp=temp_hash->link;
            while(temp){
                /*print all the words it present*/
                printf("[%d] '%s' %d",i,temp->word,temp->f_count);
                /*traverse through the subnodes*/
                sub_node_t *temp1_sublink=temp->sub_link;
                while(temp1_sublink){
                    printf(" %s %d",temp1_sublink->file_name,temp1_sublink->w_count);
                    temp1_sublink=temp1_sublink->link;
                }
                printf("\n");
                temp=temp->link;   
            }
        }
    }
}