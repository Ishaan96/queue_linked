#include<stdio.h>
#include<stdlib.h>
void insertion();
void deletion();
void display();

struct queue{
    int num;
    struct queue *next;
}*head=NULL,*rear=NULL;
int main(){
    int ch;
    while(1){
        printf("\nenter your choice\n1.insertion\n2.deletion\n3.display\n4.exit\n");
    scanf("%d",&ch);
        switch(ch){
            case 1:insertion();
                break;
            case 2:deletion();
                break;
            case 3:display();
                break;
            case 4:exit(0);
            default:printf("wrong input\n");
        }
    }
    return 0;
}

void insertion(){
    struct queue *new;
    new=(struct queue *)malloc(sizeof(struct queue));
    printf("enter the number\n");
    scanf("%d",&new->num);
    new->next=NULL;
    if(head==NULL){
        head=new;
        rear=new;
    }
    else
    {
        rear->next=new;
        rear=new;
    }
    //rear->next=NULL;
        
}

void deletion(){
    struct queue *a;
    if(head==NULL)
        printf("operation not possible\n");
    else if(head==rear){
        a=head;
        head=NULL;
        rear=NULL;
        printf("popped element is %d\n",a->num);
        free(a);
    }
    else{
        a=head;
        head=head->next;
        printf("Popped element: %d",a->num);
        free(a);
    }
}

void display(){
    struct queue *a;
    if(head==NULL)
        printf("Queue is empty\n");
    else if(head==rear)
        printf("%d ",head->num);
    else{
        a=head;
        while(a!=NULL){
            printf("%d  ",a->num);
            a=a->next;
        }
    }
}
