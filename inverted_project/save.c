#include "inv.h"

int save(main_node_t **Hash_table,int size,char *output_file){
    FILE *fptr=fopen(output_file,"w");
    if(fptr==NULL){
        red();
        printf("> File %s not created!!\n","backup.txt");
        reset();
    }
    /*run a loop until size times*/
    for(int i=0;i<size;i++){
        /*if Hashtable not NULL we have to print the data*/
        main_node_t *temp_hash=Hash_table[i];
        if(temp_hash!=NULL){
            /*print the data*/
            fprintf(fptr,"#[%d],%s,%d",i,temp_hash->word,temp_hash->f_count);
            /*traverse through sublinks*/
            sub_node_t *temp_sublink=temp_hash->sub_link;
            while(temp_sublink){
                fprintf(fptr,",%s,%d",temp_sublink->file_name,temp_sublink->w_count);
                temp_sublink=temp_sublink->link;
            }
            fprintf(fptr,"#\n");
            main_node_t *temp=temp_hash->link;
            while(temp){
                /*print all the words it present*/
                fprintf(fptr,"#[%d],%s,%d",i,temp->word,temp->f_count);
                /*traverse through the subnodes*/
                sub_node_t *temp1_sublink=temp->sub_link;
                while(temp1_sublink){
                    fprintf(fptr,",%s,%d",temp1_sublink->file_name,temp1_sublink->w_count);
                    temp1_sublink=temp1_sublink->link;
                }
                fprintf(fptr,"#\n");
                temp=temp->link;   
            }
        }
    }
    fclose(fptr);
}