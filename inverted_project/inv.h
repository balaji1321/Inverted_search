#ifndef INVERT
#define INVERT
#define NAMELENGTH 25
#define SUCCESS 0
#define FAILURE -1
#define DATA_NOT_FOUND -2

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*struct for file node*/
typedef struct sub_node{
    char file_name[NAMELENGTH];
    int w_count;
    struct sub_node *link;
}sub_node_t;

/*struct for main node*/
typedef struct node
{
    char word[NAMELENGTH];
    struct node *link;
    sub_node_t *sub_link;
    int f_count;
}main_node_t;



/*file count*/
typedef struct file_node
{
    char f_name[NAMELENGTH];
    struct file_node *link;
}file_node_t;

//validate function
int validate_arguments(char *argv[],file_node_t **file_head);
//checking file exist 
int check_file_exist(char *argv);
/*insert the data into first node*/
int insert_last(file_node_t **file_head,char *argv);
/*check file extn*/
int check_file_extn(char *argv);
/*create database*/
void create_db(main_node_t **Hash_table,file_node_t *file_head);
/*insert hash table*/
int insert_ht(main_node_t **Hash_table,char *buffer,char *temp_fname);
/*insert data*/
main_node_t *insert_data(main_node_t **Hash_table,char *buffer,char *temp_fname);
/*display the data*/
void display_db(main_node_t **Hash_table,int size);
/*check file*/
int check_files(main_node_t **prev_main,char *temp_fname);
/*search data*/
int search_DB(main_node_t **Hash_table, char *word);
/*save*/
int save(main_node_t **Hash_table,int size,char *output_file);
/*update data*/
int update(main_node_t **Hash_table,char *backup, file_node_t **file_head);
/*delete head*/
int delete1(file_node_t **head,const char *file_name);
/*colors*/
void red ();
void yellow ();
void reset ();
void white();
void green();

#endif