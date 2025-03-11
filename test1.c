#include<stdio.h>
struct node
{ int data;
 struct node *next;
};
struct node *head,*temp,*new;
void display()
{ int a=1;
struct node *rev;
  rev=head;
  printf("\nDisplaying the Node Elements:");
  while(rev!=NULL)
  { printf("\n%d.%d",a,rev->data);
   rev=rev->next;
   a++;
  }  
}
void create()
{ 
  int a; 
  printf("\nEnter The Number of Nodes to be Created:");
  scanf("%d",&a);
  head= NULL ;
  while(a!=0)
  {
  new=(struct node *)malloc(sizeof(struct node));
  printf("\nEnter the Data for the node:");
  scanf("%d",&new->data);
  a--;
 
  if(head==NULL)
  { head=new;
    temp=new;
	temp->next=NULL;
  }
  else 
  { temp->next=new;
    temp=new;
	temp->next=NULL;
  }}
  display();
}

void insert()
{ struct node *new1,*ptr;
  int a,s;
  new1=(struct node *)malloc(sizeof(struct node));
  printf("\nEnter the Data for the node:");
  scanf("%d",&new1->data);
  new1->next=NULL;
  printf("\n1.Insert at Begin\n2.Insert at Middle\n3.Insert at Ending\nEnter Choice:");
  scanf("%d",&a);
  if(a==1)
  { new1->next=head;
    head=new1;
  }
  else if (a==2)
  {printf("\nEnter the value of node to inserted after that:");
   scanf("%d",&s);
   for(temp=head;temp!=NULL;temp=temp->next)
   { if(temp->data==s)
     {
	 ptr=temp->next; 
	 temp->next=new1;
	 new1->next=ptr;
	 break;
	 } 
   }
  }
  else if(a==3)
  {temp=head;
   while(temp->next!=NULL)
   { temp=temp->next;
   } 
   new1->next=NULL;
   temp->next=new1;
  }
  else 
  {printf("\nInvalid chice");}
  display();
}
void search()
{ int a,b=0;
 printf("\nEnter the element to be searched:");
 scanf("%d",&a);
  for(temp=head;temp!=NULL;temp=temp->next)
   {if(temp->data==a)
     {printf("\nThe element %d is found in the %d node",temp->data,b);}
	 b++;}
}
void del()
{ int a,s,i;
  struct node *d;
  printf("\n1.Delete at Begin\n2.Delete at Middle\n3.Delete at Ending\nEnter Choice:");
  scanf("%d",&a);
  if(a==1)
  {temp=head;
   printf("\nDelete Node is %d",temp->data);
   head=head->next;
   temp->next=NULL;
   free(temp);
   display();
  } 
  else if (a==2)
  { temp=head;
    printf("\nEnter pos:");
	scanf("%d",&s);
	for( i=0;i<s-1;i++)
	{temp=temp->next;}
	d=temp->next;
	printf("\nDeleted Node is %d",d->data);
	temp->next=d->next;
	d->next=NULL;
	free(d);
  }
  else if(a==3)
  {temp=head;
  while(temp->next->next!=NULL)
  {temp=temp->next;}
  d=temp->next;
  printf("\nDeleted node is %d ",d->data);
  temp->next=NULL;
  free(d);}
}
int main()
{
 int a;
 printf("\n1.Create\n2.Display\n3.Insert\n4.Search\n5.Delete\n6.Exit");
 l:
 printf("\nEnter Your Choice"); 
 scanf("%d",&a);
 switch(a)
 {case 1:
     {create();
	  printf("\n Nodes create Succesfully ");
	  goto l;
	  break;
	 }
 case 2:
     {display(); goto l;
	  break;	
	 }
 case 3:
     {insert();
	  display(); goto l;
	  break;
	  }
 case 4:
     {search(); goto l;
	 break;
	
	 }
  case 5:
  { del(); goto l;
  break;
  }	    
 case 6:
 {printf("\nExiting");
 break;}
 default:
 printf("\nInvalid Choice");	 	    
 }
 return 0;  
}

