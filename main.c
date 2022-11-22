#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void password();
void heading();
void mainMenu();
void addBook();
void viewBook();
void searchBook();
void editeBook();
void deleteBook();
void help();
void exits();


struct Book_info {
  int id;
  char name[10];
  char author[10];
  int quanty;
  int rack;
};

struct Book_info a;
FILE *file, *file2;

int main() {
  password();
}

void mainMenu(){
  system ("cls");
  int n;

  printf ("\n\n \t\t***************Main menu************\n");
   printf ("\n \t\t 1.Add Book\n");
   printf ("\t\t 2.View Book List\n");
   printf ("\t\t 3.Search Book\n");
   printf ("\t\t 4.Edite Book\n");
   printf ("\t\t 5.Delete Book\n");
   printf ("\t\t 6.Help\n");
   printf ("\t\t 7.Exit\n");

   printf ("\t\t *****************************************\n");
   printf ("\t\t Enter Your Choice:");
   scanf("%d", &n);

   if (n==1){

     addBook();
   }
   else if(n==2)
   {
       viewBook();
   }
    else if(n==3)
   {
       searchBook();
   }
   else if(n==4)
   {
       editeBook();
   }
   else if(n==5)
   {
       deleteBook();
   }
   else if(n==6)
   {
       help();
   }
   else if(n==7)
   {
       exits();
   }
 else{
   printf("\t\tYou have enetred an Wrong Choice\n");
   printf("\t\tPlease enter option again\n");

   fflush(stdin);
   getchar();
   mainMenu();
 }


}

void addBook(){
      system ("cls");
      int d, count=0;
      printf ("\n\n \t\t****************ADD Book**************\n");

      file = fopen("book.bat","ab+");

      printf("\n\t\t Enter Book id:");
      scanf("%d", &d);


      rewind(file);
      while(fread(&a, sizeof(a), 1, file)==1){

        if(d == a.id){
            printf ("\n\n \t\t This book is already index..........");
            count=1;
        }

      }


      if( count == 1){
      fflush(stdin);
      getchar();
      mainMenu();
       }

      a.id = d;


      printf("\t\t Enter Book Name:");
      fflush(stdin);
      scanf("%s", a.name);

      printf("\t\t Enter Book Author:");
      fflush(stdin);
      scanf("%s", a.author);

      printf("\t\t Enter Book Quanty:");
      fflush(stdin);
      scanf("%d", &a.quanty);

      printf("\t\t Enter Book rack:");
      fflush(stdin);
      scanf("%d", &a.rack);


      fseek(file, 0, SEEK_END);
      fwrite(&a, sizeof(a), 1, file);
      fclose(file);

      printf ("\n\n \t\t This book is Add sucessfully");
      printf("\n\n\t\tPlease enter Any key To main menu....");

      fflush(stdin);
      getchar();
      mainMenu();


}


void viewBook(){
      system ("cls");

      int count=0;

      printf ("\n\n \t\t****************View Book List**************\n\n");
      printf ("\t\tID\tName\tAuthor\tQunt\tRack\n\n");

      file = fopen("book.bat","rb");
        while(fread(&a, sizeof(a), 1, file)==1){
            printf("\t\t%d",a.id);
            printf("\t%s",a.name);
            printf("\t%s",a.author);
            printf("\t%d",a.quanty);
            printf("\t%d",a.rack);
            printf("\n");

            count= count+a.quanty;


        }
        fclose(file);

        printf("\n\t\tTotal Book: %d", count);

        printf("\n\n\t\tPlease enter Any key To main menu....");



          fflush(stdin);
          getchar();
          mainMenu();

}


void searchBook(){

      system ("cls");

      int d,count=0;

      printf ("\n\n \t\t****************Search Book List**************\n\n");
      printf ("\n\t\tSearch...............\n\n");

      file = fopen("book.bat","rb");
      printf ("\n\t\tEnter your ID:");
      scanf("%d",&d);

      while(fread(&a, sizeof(a), 1, file)==1){

        if(d == a.id){
        printf ("\n\n \t\tBook Is Found...\n");

        printf("\t\tID: %d",a.id);
        printf("\n\t\tName: %s",a.name);
        printf("\n\t\tAuthot: %s",a.author);
        printf("\n\t\tQunt: %d",a.quanty);
        printf("\n\t\tRack: %d",a.rack);

        count=1;

        }

      }

      if(count == 0){
        printf ("\n\n \t\tBook Is not in List...\n");
      }

        printf("\n\n\t\tPlease enter Any key To main menu....");
        fflush(stdin);
        getchar();
        mainMenu();


}


void editeBook(){

      system ("cls");

      int d,count=0;

      printf ("\n\n \t\t****************Edite Book List**************\n\n");

      file = fopen("book.bat","rb+");
      printf ("\n\t\tEnter your ID:");
      scanf("%d",&d);


      while(fread(&a, sizeof(a), 1, file)==1){

        if(d == a.id){
        printf ("\n\n \t\tBook Is Avaiable...\n");

        printf("\t\tID: %d",a.id);

        printf("\n\t\tEnter your name:");
        scanf("%s",a.name);

        printf("\n\t\tEnter your Autor:");
        scanf("%s",a.author);

        printf("\n\t\tEnter your Quanty:");
        scanf("%d",&a.quanty);

        printf("\n\t\tEnter your RackNo:");
        scanf("%d",&a.rack);


          fseek(file, ftell(file)-sizeof(a),0);
          fwrite(&a, sizeof(a), 1, file);
          fclose(file);

        count=1;

        }

      }

        if(count == 0){
        printf ("\n\n \t\tBook Is not in List...\n");
      }

        printf("\n\n\t\tUpdated Book Suceesful....");
        printf("\n\n\t\tPlease enter Any key To main menu....");
        fflush(stdin);
        getchar();
        mainMenu();


}

void deleteBook(){

      system ("cls");

      int d,count=0;

      printf ("\n\n \t\t****************Delete Book List**************\n\n");

      file = fopen("book.bat","rb+");
      printf ("\n\t\tEnter your ID:");
      scanf("%d",&d);

        rewind(file);
        while(fread(&a, sizeof(a), 1, file)==1){

            if(d == a.id){
                printf ("\n\n \t\tBook Is Found...\n");

                printf("\t\tID: %d",a.id);
                printf("\n\t\tName: %s",a.name);
                printf("\n\t\tAuthot: %s",a.author);
                printf("\n\t\tQunt: %d",a.quanty);
                printf("\n\t\tRack: %d",a.rack);

                count=1;

            }

        }

        if(count == 0){
        printf ("\n\n \t\tBook Is not in List...\n");
        }
        else{
              file2 = fopen("update.bat","wb+");
              rewind(file);
              while(fread(&a, sizeof(a), 1, file)==1){

                  if( d != a.id){

                      fseek(file2,0,SEEK_CUR);

                      fwrite(&a, sizeof(a), 1, file2);

                  }
              }

              fclose(file);
              fclose(file2);

              remove("book.bat");
              rename("update.bat","book.bat");

              file = fopen("book.bat","rb+");
              fclose(file);


        }



        printf("\n\n\t\tDeleted Book Suceesful....");
        printf("\n\n\t\tPlease enter Any key To main menu....");
        fflush(stdin);
        getchar();
        mainMenu();


}

void help(){

   system ("cls");

   printf ("\n\n \t\t***************Libary Help ****************\n");
   printf ("\n \t\t 1.This simple Mangment system\n");
   printf ("\t\t 2.Admin use is: hasan and passwore is: hasan\n");
   printf ("\t\t 3.Admin can Book\n");
   printf ("\t\t 4.Admin can view Book List\n");
   printf ("\t\t 5.Admin can Search Book\n");
   printf ("\t\t 6.Admin can Edite Book\n");
   printf ("\t\t 7.Admin can Delete Book\n\n");
   printf ("\t\t\t\t Thank You....\n\n");

   printf("\n\n\t\tPlease enter Any key To main menu....");

    fflush(stdin);
    getchar();
    mainMenu();

}

void exits(){

   system ("cls");
   int i;

   printf ("\n\n \t\t***************This simple Mangment system****************\n");

   printf ("\t\t\t\t Thank You....\n\n");

   printf ("\t\t\t\t Wait....\n\n");

   for (i=1; i < 1e9; i++){

   }

    exit(0);



}



void heading(){
  system ("cls");
  printf ("\n\n \t\t***************Diu Libary Mangment system************\n");

}
void password(){
   heading();
   char id[50];

    User:

      printf("\n\n \t\tEnter your id:");

      scanf("%s", &id);

    if (strcmp(id,"hasan")==0)

    {

      printf("\t\tId is correct\n");


    }

    else

    {

      printf("\t\tYou have enetred an invalid user id\n");
      printf("\t\tPlease enter id again\n");

      goto User;


    }

    char pass[70];

    pass:

    printf("\t\tEnter your password: ");

    scanf("%s", &pass);

    if(strcmp(pass,"hasan")==0)

    {

      printf("\t\tYou have successly loged in into\n");
      printf("\t\tPress any key To Go Main Menu......");

    }

    else

    {

      printf("\t\tYou have entered a wrong password\n");
      printf("\t\tPlease enter password again\n");
      goto pass;

      fflush(stdin);
      getchar();


    }

   fflush(stdin);
   getchar();
   mainMenu();

}
