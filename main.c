// Module: Foundation to Computer Science
// Name: Jiri Valcikevic
// Student number: 100422488
// Deadline date: 23/03/2018
// Program name: C program to sort issue with Farmer, Wolf, Duck and Cabbage.

    #include <stdio.h>
    #include<stdlib.h>
    #include<conio.h>
    #define true 1
    #define false 0
    #define RED   "\x1B[31m"
    #define GREEN   "\x1B[32m"
    #define CYAN   "\x1B[36m"
    #define YELLOW   "\x1B[33m"
    #define BLUE   "\x1B[34m"
    #define MAG   "\x1B[35m"
    #define RESET "\x1B[0m"
    
    typedef int bool;
    int maxtri[16][16];
    bool order[16];
    
    struct Status {
       bool  farmer;
       bool  wolf;
       bool  duck;
       bool  cabbage;
    };
    
    typedef struct node{
    struct node *next;
    int vertex;
   }node;
    
    
    struct Status s[16];
    node *G[20];
    int visited[20];
    int n;
    void read_graph(); 
    void insert(int,int);  
    void DFS(int);
    int getUnvisitedVetex(int);
    bool isConnected();
    void makeMaxtri();
    
int main()
{
    printf(YELLOW "Welcome to Farmer, Wolf, Duck and Cabbage Quiz \n" RESET);
    printf("\n");
    printf("Hint:" MAG "\t 1. Farmer must always across the river. \n"); 
    printf(MAG "\t 2. The Wolf can't be with duck together. \n"); 
    printf(MAG "\t 3. The Duck can't be with Cabbage together. \n");
	printf("\n");
	printf(BLUE "\tResult: \n" RESET);
	printf(CYAN "------------------------------ \n" RESET);
    
    s[0].farmer=0;
    s[0].wolf=0;
    s[0].duck=0;
    s[0].cabbage=0;
    
    s[1].farmer=1;
    s[1].wolf=0;
    s[1].duck=0;
    s[1].cabbage=0;
    
    s[2].farmer=1;
    s[2].wolf=1;
    s[2].duck=0;
    s[2].cabbage=0;
    
    s[3].farmer=1;
    s[3].wolf=0;
    s[3].duck=1;
    s[3].cabbage=0;
    
    s[4].farmer=1;
    s[4].wolf=0;
    s[4].duck=0;
    s[4].cabbage=1;
    
    s[5].farmer=0;
    s[5].wolf=0;
    s[5].duck=1;
    s[5].cabbage=0;
    
    s[6].farmer=1;
    s[6].wolf=1;
    s[6].duck=1;
    s[6].cabbage=0;
    
    s[7].farmer=0;
    s[7].wolf=1;
    s[7].duck=0;
    s[7].cabbage=0;
    
    s[8].farmer=1;
    s[8].wolf=1;
    s[8].duck=0;
    s[8].cabbage=1;
    
    s[9].farmer=0;
    s[9].wolf=1;
    s[9].duck=0;
    s[9].cabbage=1;
    
    s[10].farmer=1;
    s[10].wolf=1;
    s[10].duck=1;
    s[10].cabbage=1;
    
    int i;
    
    insert(0,1);
    insert(0,2);
    insert(0,3);
    insert(0,4);
    insert(3,4);
    insert(4,5);
    insert(5,6);
    insert(6,7);
    insert(7,8);
    insert(8,9);
    insert(9,10);
   
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    DFS(0);
}

void DFS(int i)
{
    node *p;
    getUnvisitedVetex(i);
    p=G[i];
    visited[i]=1;
    while(p!=NULL)
    {
       i=p->vertex;
       
       if(!visited[i])
            DFS(i);
        p=p->next;
    }
}

int getUnvisitedVetex(int x)
{
    if((s[x].wolf==s[x].duck&&s[x].wolf!=s[x].farmer)||(s[x].cabbage==s[x].duck&&s[x].cabbage!=s[x].farmer))
    {   
    }
    else
    {
            showResult(s[x]);
    }
}

void showResult(struct Status s)
{
    char type[12];
     
    if(s.farmer==false){
        printf("farmer""\t= " RED " (0) = Original side \n" RESET);
		}else {
    	    printf("farmer""\t= " GREEN " (1) = Other side \n" RESET);
    	}
    if(s.wolf==false){
		 printf("wolf""\t= " RED " (0) = Original side \n" RESET);
    	}else {
    	    printf("wolf""\t= " GREEN " (1) = Other side \n" RESET);
    	}
    if(s.duck==false){
		 printf("duck""\t= " RED " (0) = Original side \n" RESET);
    	}else {
    	    printf("duck""\t= " GREEN " (1) = Other side \n" RESET);
    	}
    if(s.cabbage==false){
		 printf("cabbage""\t= " RED " (0) = Original side \n" RESET);
    	}else {
    	    printf("cabbage""\t= " GREEN " (1) = Other side \n" RESET);
    	}
	printf(CYAN "------------------------------ \n" RESET);
 }
 
void read_graph()
{
    int i,vi,vj,no_of_edges;

    int n=11;
    for(i=0;i<n;i++)
    {
    G[i]=NULL;

        for(i=0;i<no_of_edges;i++)
        {
            printf("Enter an edge(u,v):");
            scanf("%d%d",&vi,&vj);
            insert(vi,vj);
        }
    }
}
 
void insert(int vi,int vj)
{
    node *p,*q;
    q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;
    
    if(G[vi]==NULL)
        G[vi]=q;
    else
    {
        p=G[vi];
        while(p->next!=NULL)
            p=p->next;
        p->next=q;
    }
}

bool isConnected(struct Status x,struct Status y)
{
        if(x.farmer==y.farmer)
    		return false;
    	else
    	  {
    	    if(x.wolf!=y.wolf&&x.duck!=y.duck&&x.cabbage!=y.cabbage)
    	  {
    		return false;
    	  }
    	    else if(x.wolf!=y.wolf&&x.duck!=y.duck)
    	  {
    		return false; 
    	  }
    	    else if(x.wolf!=y.wolf&&x.cabbage!=y.cabbage)
    	  {
    	 	return false;
    	  }
    	    else if(x.duck!=y.duck&&x.cabbage!=y.cabbage)
    	  {
    	 	return false; 
    	  }
            else if(((x.farmer!=x.wolf)&&(x.wolf!=y.wolf))||
            
                ((x.farmer!=x.duck)&&(x.duck!=y.duck))||
                
                ((x.farmer!=x.cabbage)&&(x.cabbage!=y.cabbage)))
          {
        			return false;
          }
    		return true;
    	}
    }

void makeMaxtri()
 {
	    int m=0;
	    int n=0;
	    struct Status s1;
	    struct Status s2;
	    
		for(int i=0;i< 2;i++)
		{
			for(int j=0;j< 2;j++)
			{
			    for(int a=0;a< 2;a++)
			    {
		        	for(int b=0;b< 2;b++)
		        	{
		        	    for(int i2=0;i2< 2;i2++)
		        	    {
			                for(int j2=0;j2< 2;j2++)
			                {
			                 for(int a2=0;a2< 2;a2++)
			                 {
		                    	for(int b2=0;b2< 2;b2++)
		                    	{
		                    	    s1.farmer=i;
		                    	    s1.wolf=j;
		                    	    s1.duck=a;
		                    	    s1.cabbage=b;
		                    	    
		                    	    s2.farmer=i;
		                    	    s2.wolf=j;
		                    	    s2.duck=a;
		                    	    s2.cabbage=b;
                    				if(isConnected(s1, s2))
                    				{	
                    				    maxtri[m][n]=1;
                    				}
				                  else maxtri[m][n]=0;
		                    	}
			                 }
			               }
			               i2++;
		        	    }
		        	}
			    }
			}
			m++;
		}
	}












