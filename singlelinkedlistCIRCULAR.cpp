#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void creation(int);
void display();
void insertion(int,int);
void deletion(int);

struct list
{
int num;
struct list *next;
}*head, *l;

 void clrscr(){
 system("cls");
}

int main()
{
  int n1,ch,pos,val;
  clrscr();
  printf("program single linked list circular\n\n");

  do
  {

              printf("\n1.pembuatan\n2.menyisipkan\n3.menghapuskan\n4.menampilkan\n5.keluar\n\n");
              printf("\masukkan pilihan anda : ");
              scanf("%d",&ch);
              switch(ch)
              {
            case 1:
                        creation(n1);
                        break;
            case 2:
                        printf("\n\nmasukkan posisi yang akan di sisipkan : ");
                        scanf("%d",&pos);
                        printf("\n\nmasukkan nilai : ");
                        scanf("%d",&val);
                        insertion(pos,val);
                        break;
            case 3:
                        printf("\n\masukkan posisi yang akan di hapus : ");
                        scanf("%d",&pos);
                        deletion(pos);
                        break;
            case 4:
                        display();
                        getch();
                        break;
            case 5:
                        exit(0);
              }
  }while(ch!=5);

  getch();
}

/*  CREATION   */
/*  --------   */


void creation(int n1)
{
  int i,n;
  head=((struct list *)malloc(sizeof(struct list)));
  l=head;
  for(i=0;i<n1;i++)
  {
              printf("masukkan nilai node : ",i+1);
              scanf("%d",&n);
              l->num=n;
              l->next=((struct list *)malloc(sizeof(struct list)));
              l=l->next;
  }
  l->next=0;

}

/*  DISPLAY   */
/*  -------   */


void display()
{
  l=head;
  printf("\nnode yang telah dimasukkan adalah : ");

  while(l->next>0)
  {
             printf("%d\t",l->num);
             l=l->next;
  }
 }


/*  INSERTION   */
/*  ---------   */

void insertion(int pos, int val)
{
  int i;
  struct list *x,*y;
  l=head;
  i=2;
  if(pos==1)
  {
             x=((struct list *)malloc(sizeof(struct list)));
             x->num=val;
             x->next=l;
             head=x;
  }
  else
  {
            while(l->next>0)
            {
                         if(pos==i-1)
                         {
                                    x=((struct list *)malloc(sizeof(struct list)));
                                    x->num=val;
                                    x->next=l;
                                    y->next=x;
                         }
                         y=l;
                         l=l->next;
                         i++;
            }
  }
}

/*  DELETION   */
/*  --------   */


void deletion(int pos)
{
  int i;
  struct list *y;
  l=head;
  i=1;
  if(pos==1)
  {   head=l->next;  }
  else
  {
             while(l->next>0)
             {
                        if(pos==i)
                        { l=l->next;
            y->next=l;
            break;
                        }
                        y=l;
                        l=l->next;
                        i++;
             }
  }
}
