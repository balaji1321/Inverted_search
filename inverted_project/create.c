#include "inv.h"

void create_db(main_node_t **Hash_table,file_node_t *file_head){
      while(file_head!=NULL){  
        /*store file name*/
        char *temp_fname=file_head->f_name;
        /*open the file*/
        FILE *temp_fptr=fopen(temp_fname,"r");
        /*check it is created or not*/
        if(temp_fptr==NULL){
            red();
            printf("> File %s not opened!!\n",temp_fname);
            reset();
        }
        /*declare a buffer*/
        char buffer[NAMELENGTH];
        /*store the first word into buffer*/
        while(fscanf(temp_fptr,"%s",buffer)>0){
            /*insert into the table*/
            //printf("%s\n",buffer);
            insert_ht(Hash_table,buffer,temp_fname);
        }
        fseek(temp_fptr,0,SEEK_SET);
        file_head=file_head->link;
      }
}

/*insert data into hash table*/
int insert_ht(main_node_t **Hash_table,char *buffer,char *temp_fname){
    /*generate index*/
    int index=(buffer[0]>='A'&&buffer[0]<='Z')?buffer[0]-'A':(buffer[0]>='a'&&buffer[0]<='z')?buffer[0]-'a':26;
    if(Hash_table[index]==NULL){
        
        /*store into hash table*/
        Hash_table[index]=insert_data(Hash_table,buffer,temp_fname);
        // printf("%s\n",Hash_table[index]->word);
        return SUCCESS;
    }
    /*declare a temparory*/
    main_node_t *temp_main=Hash_table[index];
    main_node_t *prev_main=NULL;
    // printf("%s\n",temp_main->word);
    /*traverse through the nodes*/
    while(temp_main!=NULL){
        /*update prev with temp*/
        prev_main=temp_main;
        /*if both are same*/
        if(!strcmp(temp_main->word,buffer)){
            /*check file*/
            check_files(&prev_main,temp_fname);
            return SUCCESS;
        }
        temp_main=temp_main->link;
    }
    prev_main->link=insert_data(Hash_table,buffer,temp_fname);
    return SUCCESS;
    
}

main_node_t *insert_data(main_node_t **Hash_table,char *buffer,char *temp_fname){
    /*create a main node*/
        main_node_t *new_main = malloc(sizeof(main_node_t));
        /*copy the data into node*/
        strcpy(new_main->word,buffer);
        new_main->f_count=1;
        new_main->link=NULL;
        /*create a file node*/
        sub_node_t *sub_node = malloc(sizeof(sub_node_t));
        /*update the data*/
        sub_node->w_count=1;
        strcpy(sub_node->file_name,temp_fname);
        sub_node->link=NULL;
        new_main->sub_link=sub_node;
        return new_main;
}

int check_files(main_node_t **prev_main,char *temp_fname){
    /*declare a temp*/
    sub_node_t *temp=(*prev_main)->sub_link;
    sub_node_t *prev=NULL;
    /*traverse through the nodes*/
    while(temp){
        prev=temp;
        /*check given file and existing file same or not*/
        
        if(!strcmp(temp->file_name,temp_fname)){
            /*increment word count*/
            temp->w_count++;
            return SUCCESS;
        }
        /*update temp*/
        temp=temp->link;
    }
    /*if not equal create a new file node*/
    sub_node_t *new=malloc(sizeof(sub_node_t));
    if(new==NULL){
        printf("Node not created\n");
    }
    /*update data*/
    strcpy(new->file_name,temp_fname);
    new->link=NULL;
    new->w_count=1;
    /*link with prev file node*/
    prev->link=new;
    (*prev_main)->f_count++;
    return SUCCESS;
}