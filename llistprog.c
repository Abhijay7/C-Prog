/* program to add a new node at the desired position */
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;

};

void main()
{
    int i, n, pos;
    printf("Enter the no. of nodes you want:");
    scanf("%d",&n);

    struct node *head, *p, *tmp, *new;
    tmp=(struct node *)malloc(sizeof(struct node));
    if(tmp==NULL)
    {
        printf("No space available");
    }

    printf("enter the data for head node");
    scanf("%d",&tmp->data);

    tmp->next=NULL;

    head=tmp;
    p=head;

    for(i=1; i<n; i++)
    {
        tmp=(struct node *)malloc(sizeof(struct node));
        if(tmp==NULL)
        {
            printf("No space available");
        }

        printf("enter the data for next node:");
        scanf("%d",&tmp->data);

        tmp->next=NULL;

        p->next=tmp;

        p=p->next;
    }

    p=head;
    printf("\n");
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }

    p=head;
    new=(struct node *)malloc(sizeof(struct node));
    if(new==NULL)
    {
        printf("cannot allocate memory");
    }

    printf("\nEnter the data for new node");
    scanf("%d",&new->data);

    new->next=NULL;

    printf("\nEnter the position for new element:");
    scanf("%d",&pos);

   
    while(pos!=2)
    {
        p=p->next;
        pos--;
    }

    new->next=p->next;
    p->next=new;

    p=head;
    printf("\n");
    while(p!=NULL)
    {
        printf("\n%d\n",p->data);
        p=p->next;
    }


}

    