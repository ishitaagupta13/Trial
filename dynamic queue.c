#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *f,*r,*next;
}node;
void enqueue(node **f,node **r,int x);
int dequeue(node **f,node **r);  
void display(node *f);
void main()
{
	node *f=NULL;
	node* r=NULL;
	int x,ch;
	do{
		printf("enter your choice\n 1-enqueue\n 2-dequeue\n 3-display\n 4-exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
					printf("Enter the element to enqueue\n");
					scanf("%d",&x);
			        enqueue(&f,&r,x);
					break;
			case 2: x=dequeue(&f,&r);
			        if(x!=-999)
			        	printf("dequeued element is %d\n",x);
					break;
			case 3: display(f);
					break;
			case 4: exit(0);
			default: printf("invalid choice\n");
			
		}
	}while(1);		
}
node * createnode(int x)
{
	node *nn;
	nn=(node*)malloc(sizeof(node));
	if(nn==NULL)
	   return NULL;
	nn->data=x;
	nn->next=NULL;
	return nn;   
}
void enqueue(node **f,node **r,int x)
{
	node * nn;
	nn=createnode(x);
	if(*r==NULL)
	   *f=*r=nn;
	else{
	
	   (*r)->next=nn;
	   *r=nn; 
    }
	
}
int dequeue(node **f, node **r)
{
	int x;
	node * temp;
	if(*f==NULL)
	{
	
	   printf("list is empty\n");
	   return -999;
	}
  temp=*f;
   if(*r==*f)
   {
   	   *r=*f=NULL;
   }
  	else 
	{
  		*f=(*f)->next;
	  
	}
  	x=temp->data;
	free(temp);
	return x;
}

void display(node *f)
{
	node* p=f;
	if(f==NULL){
	
	  printf("empty list\n");
	  return;
     } 
     else {
     	
     	while(p!= NULL)
		 {
     			
			printf("%d\n",p->data);
     		p=p->next;
     			
		 }
     
	 }
}
