/*Question number 11.
//Chandan Sharma(11812766)
//CSE_316 Assignment
//Suppose that a disk has 5,000 cylinders, numbered 0 to 4999. The drive is currently serving a request at cylinder 143,
//and the previous request at cylinder 125. The queue of the pending requests, in FIFO.
*/

//start

#include<stdio.h>
#include<math.h>
int main()
{
//Declatation and Initialization
	int i=0,j=0,p=0,k=0,x=0,num,upr_limit,distance=0,cur_request,pre_request,r1_l0,dummy,q;
	int que[40],right[40],left[40],final[40];
	
//Input
	printf("\nINPUT-->");
	printf("\n\tENTER THE NUMBER OF CYLINDERS CONTAINED BY DISK DRIVE : \n\t--> ");
	scanf("\t%d",&upr_limit);
	printf("\tENTER THE CURRENT REQUEST(POSITION) : \n\t--> ");
	scanf("\t%d",&cur_request);
	printf("\tENTER THE PREVIOUS REQUEST(POSITION) : \n\t--> ");
	scanf("\t%d",&pre_request);
	printf("\tENTER THE NUMBER OF ELEMENTS IN THE QUEUE OF PENDING REQUEST, IN FIFO(HOW MANY) : \n\t--> ");
	scanf("\t%d",&num);
	
//Entering the pending request in queue to process
	printf("NOW ENTER THE REQUEST OF THE PENDING QUEUE ONE BY ONE AND TAP ENTER AFTER EACH ENTRY***\n");
	printf("REQUEST-->\n");
	for(i=0;i<num;i++)
	{
		scanf("\t%d",&que[i]);
	}
	
//Checking and seperating the request lesser than the current request into a another queue(array)
    for(i=0;i<num;i++)
    {
    	if(que[i]<cur_request)
    	{
    		left[j]=que[i];
    		j++;
		}
//Checking and seperating the request greater than the current request into a another queue(array)
		if(que[i]>cur_request)
		{
			right[k]=que[i];
			k++;
		}
	}
	
//Arranging requests in left side lower queue in decending order for easy pic up
	for(i=0;i<j;i++)
	{
		for(p=0;p<j-1;p++)
		{
			if(left[p]<left[p+1])
			{
				dummy=left[p];
				left[p]=left[p+1];
				left[p+1]=dummy;
			}
		}
	}
	
//Arranging requests in right side upper queue in ascending order for easy pic up
	for(i=0;i<=k;i++)
	{
		for(p=0;p<k-1;p++)
		{
			if(right[p]>right[p+1])
			{
				dummy=right[p];
				right[p]=right[p+1];
				right[p+1]=dummy;
			}
		}
	}
		
//Checking for direction where to move on the basis of previous and current request/position
if((pre_request-cur_request)<0)
r1_l0=1;//r1 means moving right(greater side) of current head -->1  
else
r1_l0=0;	//l0 mean moving left(lower side) of current head -->0
	switch(r1_l0)
	{
		case 0: //first move in left lower side of current position(head) and move till end i.e., 0 for left
			for(i=0;i<j;i++)
			{
				final[x]=left[i];
				x++;
			}
			final[x]=0;
			x++;
			for(i=0;i<k;i++) //Then move towars the right(upper side) till the max request in the queue get scanned
			{
				final[x]=right[i];
				x++;
			}
			break;
		case 1: //first move in right upper side of current posiyion(head) and move till end i.e., upper limit-1 for right
			for(i=0;i<k;i++)
			{
				final[x]=right[i];
				x++;
			}
			final[x]=upr_limit-1;
			x++;
			for(i=0;i<j;i++)  //Then move towards the left(lower side) till the min request in the queue get scanned
			{
				final[x]=left[i];
				x++;
			}
			break;
	}
	
printf("\nOUTPUT-->");
if(r1_l0==1)
printf("\n\tMOVES TOWARS RIGHT SATISFYING ALL REQUEST TILL END OF CYLINDER AND THEN MOVES TOWARD LEFT TILL THE MIN REQUEST(MOVE --->> THEN <<---)\n ");
if(r1_l0==0)
printf("\n\tMOVES TOWARS LEFT SATISFYING ALL REQUEST TILL END 0 AND THE MOVES TOWARD RIGHT TILL THE MAX REQUEST(MOVE <--- THEN --->)\n");
//Final queue with all the traversed request
printf("\n\n\tTHE FINAL QUEUE WITH SATISFIED AND SCANNED ALL REQUEST OF PENDING QUEUE IN ORDER IS : \n\n");
	distance=distance+abs(cur_request-final[0]);  //Calculating diatance
	printf("\t%d , %d",cur_request,final[0]);
	for(i=1;i<x;i++)
	    {
	    	distance=distance+abs(final[i]-final[i-1]);
	    	printf(" , %d",final[i]);
	    }	 
printf("\n\nTOTAL DISTANCE(IN CYLINDER) THE DISK ARM MOVES : %d\n",distance);
}

//Done
//End of program

