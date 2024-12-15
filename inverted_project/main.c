#include "inv.h"

int main(int argc,char* argv[])
{
    if(argc<2)
    {
        red();
        printf("Invalid Arguments\n");
        printf("Plese pass like: ./a.out <filename> ..........\n");
        reset();
        return 0;
    }
    //declare hash table
    main_node_t *Hash_table[27]={NULL};
    
    //declare head for file node
    file_node_t *file_head=NULL;
    
    //call validate function
    if(validate_arguments(argv,&file_head)==SUCCESS)
    {
        /*declare a choice*/
        int choice;
        char ch='y';
        int flag=1;
        int flag1=1;
        int flag2=1;

        printf("\n......................................................\n");
        white();
        printf("                 INVERTED SEARCH MENU\n");
        reset();
        printf("......................................................\n");
       
        do
        {
            /*read choice from the user*/
            printf("1. Create DB\n2. Search DB\n3. Save DB\n4. Display DB\n5. Update DB\n6. Exit\n\n-> Enter your Choice: ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1 : /*create database*/
                        if(flag){
                                create_db(Hash_table,file_head);
                                flag=0;
                                flag1=0;
                        }
                        green();
                        printf("> Info: Create DB Successful!!\n");
                        reset();
                        break;
                case 2 : /*search database*/
                        char word[NAMELENGTH];
                        printf("-> Enter the word: ");
                        scanf("%s",word);
                        if(search_DB(Hash_table,word) == DATA_NOT_FOUND){
                                red();
                                printf("Data not found!!\n");
                                reset();
                        }
                        break;
                case 3 : /*save database*/
                        char output_file[NAMELENGTH];
                        printf("-> Enter the file(.txt) name : ");
                        scanf("%s",output_file);
                        if(check_file_extn(output_file)==FAILURE){
                                break;
                        }
                        else{
                                save(Hash_table,27,output_file);
                        }
                        green();
                        printf("Save Data Successfully!!\n");
                        reset();
                        break;
                case 4 : /*display database*/
                        display_db(Hash_table,27);
                        break;
                case 5 : /*update database*/
                        if(flag1){
                                char backup[NAMELENGTH];
                                printf("-> Enter backup file(.txt) name : ");
                                scanf("%s",backup);
                                if(check_file_extn(backup)==FAILURE){
                                        break;
                                }
                                if(flag2){
                                        update(Hash_table,backup,&file_head);
                                        flag2=0;
                                }
                                else{
                                        red();
                                        printf("Update can work only once!!\n");
                                        reset();
                                }
                        }
                        else{
                                red();
                                printf("> Update can't done after create DATABASE!!\n");
                                reset();
                        }
                        break;
                case 6 : /*Exit*/
                        
                        char ch1;
                        printf("Do you want to save data Yy/Nn : ");
                        scanf(" %c",&ch1);
                        if(ch1=='Y'||ch1=='y'){
                                save(Hash_table,27,"backup.txt");
                                green();
                                printf("Save Data Successfully in \"backup.txt\" !!\n");
                                reset();
                        }
                        yellow();
                        printf("Bye buddy,See you again!!\n");
                        reset();
                        return SUCCESS;
                default : 
                        red();
                        printf("Please Enter Proper Choice!!\n\n");
                        reset();
                        continue;

            }
            /*if you want continue*/
            printf(" Do you want to continue Yy/Nn : ");
            scanf(" %c",&ch);
        }while(ch=='y'||ch=='Y');
    }

}