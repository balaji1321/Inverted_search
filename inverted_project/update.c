#include "inv.h"

int update(main_node_t **Hash_table,char *backup,file_node_t **head){
    /*open file*/
    FILE *fptr=fopen(backup,"r");
    /*if it is not exist return failure*/
    if(fptr==NULL){
        red();
        printf("> File %s not exist!!\n",backup);
        reset();
        return FAILURE;
    }
    char ch=fgetc(fptr);
    fseek(fptr,-2,SEEK_END);
    char ch1=fgetc(fptr);
    fseek(fptr,0,SEEK_SET);
    if(ch!='#'||ch1!='#'){
        red();
        printf("> File %s is not a data file!!\n",backup);
        reset();
    }
    char str[100];
    /*read line by line from the file*/
    while(fscanf(fptr,"#%[^#]#\n",str) >0){
        char ret[NAMELENGTH];
        /*read index from the file*/
        char *ret1=strtok(str,",");
        sscanf(ret1,"[%[^]]",ret);
        int index=atoi(ret);
        if(Hash_table[index]==NULL){
            /*create a main node*/
            main_node_t *new_main=malloc(sizeof(main_node_t));
            /*update data into new node*/
            strcpy(new_main->word,strtok(NULL,","));
            new_main->f_count=atoi(strtok(NULL,","));
            /*create a sub node*/
            sub_node_t *sub_node=malloc(sizeof(sub_node_t));
            /*update the data*/
            strcpy(sub_node->file_name,strtok(NULL,","));
            delete1(head,sub_node->file_name);
            sub_node->w_count=atoi(strtok(NULL,","));
            sub_node->link=NULL;
            /*link sub_node with main node*/
            new_main->sub_link=sub_node;
            sub_node_t *temp1=sub_node;
            /*if multiple file node having connected with each other*/
            for(int i=1;i<new_main->f_count;i++){
                /*create one more subnode for linking subnodes*/
                sub_node_t *s_node=malloc(sizeof(sub_node_t));
                /*update the snode data*/
                strcpy(s_node->file_name,strtok(NULL,","));
                delete1(head,s_node->file_name);
                s_node->w_count=atoi(strtok(NULL,","));
                s_node->link=NULL;
                /*update subnode link part with s_node*/
                temp1->link=s_node;
                temp1=s_node;
            }
            new_main->link=NULL;
            Hash_table[index]=new_main;
            continue;
        }
        /*take one temporary */
        main_node_t *temp_hash=Hash_table[index];
        while(temp_hash->link!=NULL){
            temp_hash=temp_hash->link;
        }
        main_node_t *new_main=malloc(sizeof(main_node_t));
            /*update data into new node*/
            strcpy(new_main->word,strtok(NULL,","));
            new_main->f_count=atoi(strtok(NULL,","));
            /*create a sub node*/
            sub_node_t *sub_node=malloc(sizeof(sub_node_t));
            /*update the data*/
            strcpy(sub_node->file_name,strtok(NULL,","));
            delete1(head,sub_node->file_name);
            sub_node->w_count=atoi(strtok(NULL,","));
            sub_node->link=NULL;
            /*link sub_node with main node*/
            new_main->sub_link=sub_node;
            sub_node_t *temp1=sub_node;
            /*if multiple file node having connected with each other*/
            for(int i=1;i<new_main->f_count;i++){
                /*create one more subnode for linking subnodes*/
                sub_node_t *s_node=malloc(sizeof(sub_node_t));
                /*update the snode data*/
                strcpy(s_node->file_name,strtok(NULL,","));
                delete1(head,s_node->file_name);
                s_node->w_count=atoi(strtok(NULL,","));
                s_node->link=NULL;
                /*update subnode link part with s_node*/
                temp1->link=s_node;
                temp1=s_node;
            }
            new_main->link=NULL;
            temp_hash->link=new_main;

    }
    /*close file */
    fclose(fptr);
    
}


int delete1(file_node_t **head,const char *file_name){
    /*if head null return failure*/
    
    if((*head)==NULL){
        return FAILURE;
    }
    file_node_t *temp=*head;
    file_node_t *pre=temp;
    if(!strcmp(temp->f_name,file_name)){
        *head=temp->link;
        free(temp);
        return SUCCESS;
    }
    while(temp!=NULL){
        if(!strcmp(temp->f_name,file_name)){
            pre->link=temp->link;
            free(temp);
            return SUCCESS;
        }
        pre=temp;
        temp=temp->link;
    }
    return FAILURE;
}


