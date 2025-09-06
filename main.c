#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<MMsystem.h>

 struct node
{
  int data;
  struct node *next;
 }*head=NULL;

  void delay(unsigned int mseconds)
 {
     clock_t goal = mseconds + clock();
     while (goal > clock());
 }

 void insertatbeginning(int n)
 {
     struct node *newnode,*temp;
     newnode=malloc(sizeof(struct node));
     newnode->data=n;
     if(head==NULL)
        {
            head=newnode;
            newnode->next=head;
        }
     else
        {
            temp=head;
     while(temp->next!=head)
        {
            temp=temp->next;
        }
        newnode->next=head;
        temp->next=newnode;
        head=newnode;
        }
        printf("Song inserted at the beginning\n");

 }

 void insertatmiddle(int x)
 {
     int a,f=0;
     struct node *newnode=malloc(sizeof(struct node));
     newnode->data=x;
     printf("After which song would you like to insert:");
     scanf("%d",&a);
     struct node* temp=head;
      while(temp->data!=a)
        {
            if(temp->next==head)
            {
                printf("The song isn't available in the Queue!\n");
                 f=1;
                 break;
            }
        else
            {
                 temp=temp->next;
            }
        }
        if(f==0)
            {
                newnode->next=temp->next;
                temp->next=newnode;
            }
            printf("The song has been added to the playlist!\n");
 }

 void insertatlast(int n)
 {
     struct node *newnode,*temp;
     newnode=malloc(sizeof(struct node));
     newnode->data=n;
     if(head==NULL)
        {
            head=newnode;
            newnode->next=head;
        }
        else
            {
               temp=head;
               while(temp->next!=head)
                {
                    temp=temp->next;
               }
               temp->next=newnode;
               newnode->next=head;
            }
            printf("Song added to the end of queue\n");

}

 void insertnext(int x)
 {
     struct node *temp1=head;
     struct node *newnode=malloc(sizeof(struct node));
     if(head==NULL)
        printf("The Queue is empty\n");
     else
        {
            newnode->data=x;
            newnode->next=head->next;
            head->next=newnode;
        }
}

void del(int x)
{
    struct node *temp;
    if(head==NULL)
        {
            printf("The Queue is empty!\n");
        }
    else if(head->data==x)
            {
                struct node* temp=head;
                head=temp->next;
                free(temp);
                }
    else
        {
            int f=0;
    struct node* p=head;
    while(p->next->data!=x)
        {
            if(p->next->next==head)
            {
                printf("\nThe song is not present in the Queue!\n");
                f=1;
                break;
            }
            else
            {
                p=p->next;
            }
        }
        if(f==0)
            {
                struct node* temp=p->next;
                p->next=temp->next;
                free(temp);
            }
        }
        printf("The song has been removed from the playlist!\n");
}


int display()
{
    struct node *temp;
    int arr1[20],i=0;
    temp=head;
    if(temp==NULL)
    {
        printf("No songs playing currently\n");
        conclusion();
    }
    else
    {
        printf("\nQueue: \n");
        while(temp->next!=head)
            {
                printf("%d\n",temp->data);
                arr1[i]=temp->data;
                temp=temp->next;
                i=i+1;
            }
            printf("%d\n",temp->data);
            arr1[i]=temp->data;
    }
    printf("\n");
    return arr1;
}

void insert(int n)
{
    int b;
    printf("\nChoose an option: \n");
    printf("\n1.Add it at the beginning\n2.Add it at the end of the Queue\n3.Add it after a song\n4.Remove the song\n");
    printf("\nEnter your choice: ");
    scanf("%d",&b);
    switch(b)
    {
        case 1:
            insertatbeginning(n);
            break;
        case 2:
                insertatlast(n);
                break;
        case 3:
            insertatmiddle(n);
            break;
        case 4:
             del(n);
             break;
        default:
            printf("Choose one of the given numbers please!\n");
            insert(n);
            break;
      }

}
 void songlist()
 {
     printf("\n");
    FILE *fptr;
    fptr = fopen("note.txt ","r");
    int line = 0;
    char songs[300];
    while(!feof(fptr))
    {
        fgets(songs,300,fptr);
        puts(songs);
    }
    fclose(fptr);
}

int count()
{
    int c=0;
    struct node *temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
        c=c+1;
    }
    return c+1;

}
void play3(struct node *temp)
{
    char arr[][50]={"BirdsChirping.wav","CatMeow.wav","Sirensound.wav","Smallriverstream.wav","Motorbikesound.wav","Drinkingwater.wav","DingDongBell.wav","GongSchoolBell.wav","Fireworks.wav","Lighteningandthunder.wav"};
    PlaySound(arr[temp->data-1],NULL,SND_SYNC);
}


void intro()
{

    printf("\t\t\t\t\t\tTHE MUSIC PLAYER IS ON \n\n");
    delay(1000);
    printf("Create your personalized play list below: \n");
    delay(1000);
    printf("Enter the serial number associated with the song you want to choose!\n");
    delay(1000);
    printf("Enter 0 if you are done with creating your Queue!\n");
    delay(1000);
    printf("If you want to remove a song from the play list, first enter the serial number of the song and then choose to delete it\n");
    delay(1000);

}
 void body()
 {

     int a=99;
     while(a!=0)
     {
         printf("\nEnter the serial number: ");
        scanf("%d",&a);
        switch(a)
        {
            case 0:
                break;
            case 1:
                insert(1);
                break;
            case 2:
                insert(2);
                break;
            case 3:
                insert(3);
                break;
            case 4:
                insert(4);
                break;
            case 5:
                insert(5);
                break;
            case 6:
                insert(6);
                break;
            case 7:
                insert(7);
                break;
            case 8:
                insert(8);
                break;
            case 9:
                insert(9);
                break;
            case 10:
                insert(10);
                break;
            default:
                printf("Please enter a valid serial number!\n");
                body();


         }
   }

 }


 void playsong()
 {
     struct node *temp=head;
    for(int i=0;i<count();i++)
    {
        play3(temp);
        temp=temp->next;
    }
 }

  void conclusion()
{
    int j=99,k=99;
    printf("Enter 0 if you want to close the player!\n");
    delay(500);
    printf("Enter 1 if you want to create a new playlist!\n");
    delay(500);
    printf("Enter 2 if you want to play the same playlist again!\n");
    delay(500);
    printf("Enter: ");
    scanf("%d",&j);
    if(j==1)
    {
        head=NULL;
        main();
    }
    else if(j==0)
    {
        printf("Are you sure?\n");
        printf("Final Chance!\n");
        delay(500);
        printf("One to stay,zero to go away!\n");
        printf("Your choice: \n");
        scanf("%d",&k);
        if(k==1)
        {
            printf("I knew you would change your mind!\n");
            head=NULL;
            main();
        }
        else if(k==0)
        {
            printf("Okay Bye!");
        }
        else
        {
            printf("Choose a proper number!\n");
            delay(500);
            printf("-__-");
            conclusion();
        }
    }
    else if(j==2)
    {
        display();
        playsong();
        conclusion();
    }
    else
    {
        printf("Choose a proper number!\n");
        delay(500);
        printf("-__-");
        conclusion();
    }

}
void main()
{

    intro();
    songlist();
    body();
    display();
    playsong();
    conclusion();


}


