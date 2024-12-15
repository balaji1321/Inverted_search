#include "inv.h"

int validate_arguments(char *argv[],file_node_t **file_head){
    int i=1;
    while(argv[i]){
        //check file extn ".txt" or not
        if(check_file_extn(argv[i]) == SUCCESS){
            //ckecking file exist are not
            if(check_file_exist(argv[i])==SUCCESS){
                //insert the data
                if(insert_last(file_head,argv[i])==SUCCESS){
                    green();
                    printf("> Info: %s Inserted Successfully \n",argv[i]);
                    reset();
                }
            }
        }
        i++;
    }
    /*if file is empty*/
    if(*file_head==NULL){
        printf("> Info: No File Inserted in file_node!!\n");
        return FAILURE;
    }
    return SUCCESS;
}

int check_file_exist(char *argv){
    //open the file
    FILE *fptr= fopen(argv,"r");
    //check file is created or not
    if(fptr==NULL){
        red();
        printf("> File %s Not Exist!!\n",argv);
        reset();
        return FAILURE;
    }
    //move offset to end find empty or not 
    fseek(fptr,0,SEEK_END);
    //store offset position pos to pos
    int pos=ftell(fptr);
    //check file is opened or not
    if(!pos){
        red();
        printf("> File %s Not Exist!!☠️\n",argv);
        reset();
        return FAILURE;
    }
    fseek(fptr,0,SEEK_SET);
    //if it is opened print valid
    printf("> Info: %s is valid\n",argv);
    return SUCCESS;
}

/*insert the data into first node*/
int insert_last(file_node_t **file_head,char *argv){
    //create a node
    file_node_t *new=malloc(sizeof(file_node_t));
    //check node is created or not
    if(new==NULL){
        printf("Info: Node not created!\n");
        return FAILURE;
    }
    //update the data and link part with node
    strcpy(new->f_name,argv);
    new->link=NULL;
    //check head is empty or not
    if(*file_head==NULL){
        //if it is empty directly link
        *file_head=new;
        return SUCCESS;
    }
    //if it is not empty 
    file_node_t *temp=*file_head;//declare a temparory
    file_node_t *prev=NULL;
    /*traverse through the node*/
    while(temp!=NULL){
        prev=temp;
        if(!strcmp(temp->f_name,argv)){
            red();
            printf("> File %s already Exist!!\n",argv);
            reset();
            return FAILURE;
        }
        temp=temp->link;
    }
    prev->link=new;
    return SUCCESS;
}

/*check extn*/
int check_file_extn(char *argv){
    char *buffer=strchr(argv,'.');
    if(buffer==NULL){
        red();
        printf("> File %s not in '.txt' Extension\n",argv);
        reset();
        return FAILURE;
    }
    if(strcmp(buffer,".txt")){
        red();
        printf("> File %s not in '.txt' Extension\n",argv);
        reset();
        return FAILURE;
    }
    return SUCCESS;
}

