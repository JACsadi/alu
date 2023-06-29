   #include <stdlib.h>
   #include <stdio.h>
  struct student {
   int roll;
   char name[20];
   double grade = NULL;
   struct student *next;
  };
  int main() {
   struct student *start = NULL;
   printf("1 to add elemnt, 2 to print, 3 to delete the last element and 4 to add grade\n");
   int k;
   while(~scanf("%d", &k) < 5) {
   if(k == 1) {
      printf("input roll and firstName\n");
      if(start == NULL) {
         start = (struct student*) malloc(sizeof(struct student));
         scanf("%d" , &start->roll);
         scanf("%s", start->name);
         start->next = NULL;
      } else {
         struct student *temp = start;
         while(temp->next != NULL) {
            temp = temp->next;
         }
         temp->next = (struct student*) malloc(sizeof(struct student));
         temp = temp->next;
         scanf("%d" , &temp->roll);
         scanf("%s", temp->name);
         char c;
         while ((c = getchar()) != '\n' && c != EOF) {}
         temp->next = NULL;
      }
   } else if(k == 2){
      if(start == NULL) {
         printf("nothing in this shit\n");
      } else {
      struct student *temp = start;
      while(temp != NULL)
      {
         printf("%d: %s\n Gp - %.2lf\n", temp->roll, temp->name, temp->grade);
         temp = temp->next;
      }           
      }
   } else if(k == 3) {
            if(start == NULL) {
         printf("nothing in this shit\n");
      } else {
      struct student *temp = start;
      struct student *z;
      int ll;
      while(temp->next != NULL)
      { 
         z = temp;
         temp = temp->next;
         ll = temp->roll;
      }           
      free(temp);
      z->next = NULL;
      printf("%d was removed\n", ll);
      } 
   } else if(k == 4) {
      if(start == NULL) {
         printf("nothing in this shit\n");
      } else {
      printf("Input roll and grade\n");
      int troll;
      scanf("%d", &troll);
      struct student *temp = start;
      while (temp == NULL)
      {
        if(temp->roll == troll) break;
        else temp = temp->next;
      }
      if(temp == NULL) {
         printf("no such student exist\n");
         scanf("%*lf");
      } else {
         scanf("%lf", &temp->grade);
      }
      }
   }
   }
   return 0;
  }