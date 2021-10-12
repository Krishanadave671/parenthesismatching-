#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define maxsize 5

int Queue[maxsize];

int Front = -1;

int Rear = -1;

void enqueue()

{

    int ele;

    if (Rear == maxsize - 1)

    {

        printf("Queue is overflow \n\n");
    }

    else

    {

        printf("Enter an element:");

        scanf("%d", &ele);

        Rear = Rear + 1;

        Queue[Rear] = ele;

        if (Front == -1)

        {

            Front = 0;
        }
    }
}

void deletion()

{

    if (Front == -1)

    {

        printf("Queue is under flown\n\n");
    }

    else

    {

        printf(" Deleted element is: %d \n\n", Queue[Front]);

        if (Front == Rear)

        {

            Front = -1;

            Rear = -1;
        }

        else

        {

            Front = Front + 1;
        }
    }
}

void display()

{

    int i;

    if (Front == -1)

    {

        printf("Queue is under flow \n\n");
    }

    else

    {

        printf("Queue:");
        for (i = Front; i <= Rear; i++)
        {
            printf("%3d", Queue[i]);
        }
        printf("\n\n");
    }
}

int main()

{
    // clrscr();

    int choice = 0;

while(choice != 4){
    printf("1.Enqueue \n");

    printf("2.Dequeue  \n");

    printf("3.DISPLAY  \n");

    printf("4.EXIT \n");

    printf("Enter your choice:");

    scanf("%d", &choice);

    switch (choice)

    {

    case 1:
        enqueue();
        break;

    case 2:
        deletion();
        break;

    case 3:
        display();
        break;

    case 4:
        break;

    default:
        printf("Invalid Input\n\n");
        break;
    }
}
    return 0; 
}