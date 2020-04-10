/*Question no. 14
//Chandan Sharma (11812766)
//CSE_316 Assignment

//If a teacher is being served at the food mess and during the period when he is being served,
//another teacher comes, then that teacher would get the service(food) next.
//This process might continue leading to increase in the waiting time of students to get food. 
//Ensure in your program that the waiting time of student is minimized.
*/


//start
#include <iostream>    //explicitly using iostream to make more fast the basic input out put service
#include <bits/stdc++.h> //for including every standard library for easy running

using namespace std; 

int t_request; //t_request is total number of teacher and student and combindily consider it the total number of request
  

struct person //to hold inputs
{ 
//initialization
int arr_time,bru_time,priority,process_no; 
}; 

person serve[30]; 

//if arival time same, comparing to sort as per priority
bool comp(person a,person b) 
{ 
if(a.arr_time == b.arr_time) 
{ 
return a.priority<b.priority; 
} 
else
{ 
	return a.arr_time<b.arr_time; 
} 
} 

//temp waiting time and temp turnaround time is for calculating starting time and complition time
//find temp waiting time by FCFS 
void get_temp1_time(int temp1[]) 
{ 

int cum_burst[30]; //cum_burst array to store cummatative burst time


cum_burst[0]=0; 
temp1[0]=0; 


for(int i=1;i<t_request;i++) 
{ 
cum_burst[i]=serve[i-1].bru_time+cum_burst[i-1]; 

temp1[i]=cum_burst[i]-serve[i].arr_time; 

	
	if(temp1[i]<0) 
	{ 
	temp1[i]=0; //if temp waiting chage to 0 if negative
	} 
} 

} 

void get_temp_time(int temp[],int temp1[]) 
{ 


for(int i=0;i<t_request;i++) //temp turnaround array
{ 
	temp[i]=temp1[i]+serve[i].bru_time; 
} 
	
} 

void calculation() 
{ 

int temp1[30],tarr_time[30],temp[30]; //declaring temp waiting time and turnaround around time

double wait_avg=0,tarr_avg=0,student_wt=0; 

//temp1=temprory waiting time
//temp=temprory turnaround time
//temp2=temprorary variable
get_temp1_time(temp1); //function call for temp waiting time for starting and complition time calculation 
 
get_temp_time(temp,temp1); //function call to find temp turnaround time

int temp2;	
int strt_time[30],comp_time[30]; 
 
for(int i=1;i<t_request;i++) 
	{ 
	     if(serve[i].arr_time==0)
	     {
	     	strt_time[0]=0; 
            comp_time[0]=strt_time[0]+temp[0];
	        strt_time[i]=comp_time[i-1]; 
		    comp_time[i]=strt_time[i]+temp[i]-temp1[i];	
		 }
		 else
		 {
		 	strt_time[0]=1; 
            comp_time[0]=strt_time[0]+temp[0];
	     	strt_time[i]=comp_time[i-1]; 
	    	comp_time[i]=strt_time[i]+temp[i]-temp1[i];
	     }

	} 
int wait[30];
for(int i=0;i<t_request;i++)
{
		    
	tarr_time[i]=comp_time[i]-serve[i].arr_time;   //filling turnaround array
	
	if(t_request==1)  //special case, if there is only 1 request
	{
		 if(serve[i].arr_time==0)
	     {
	     	strt_time[0]=0; 
            comp_time[0]=strt_time[0]+temp[0];
	  }
		 else
		 {
		 	strt_time[0]=1; 
            comp_time[0]=strt_time[0]+temp[0];
	     }
		wait[i]=0;      //filling waiting array
	}
	else
	{
	wait[i]=tarr_time[i]-serve[i].bru_time;  //filling waiting array
	}
}
	
//displaying output
cout<<"OUTPUT :-"<<endl;
cout<<endl;
cout<<"PROCESS_NUMBER      PRIORITY_QUEUE       START_TIME    COMPLITION_TIME      TURNARIUND_TIME       WAITING_TIME"<<endl; 
	
	
for(int i=0;i<t_request;i++) 
	{ 
		wait_avg += wait[i]; 
		tarr_avg += tarr_time[i]; 
		
		if(serve[i].priority<serve[i+1].priority)
		{
			temp2=serve[i].priority;
			serve[i].priority=serve[i+1].priority;
			serve[i+1].priority=temp2;
		}
		
		if(serve[i].priority==1)
		{
			student_wt=student_wt+wait[i];
		}
		
		cout<<"     "<<serve[i].process_no<<"\t\t\t   "<<serve[i].priority<<"    \t\t"<< 
			strt_time[i]<<"\t\t  "<<comp_time[i]<<"      \t\t"<< 
			tarr_time[i]<<"\t\t  "<<wait[i]<<endl; 
	} 
	
	cout<<endl;
	cout<<"\tOVERALL AVERAGE WAITING TIME IN THIS FOOD SERVING PROCESS : "; 
	cout<<wait_avg/(float)t_request<<endl;   //average waiting time
	cout<<"\tOVERALL AVERAGE TURNAROUND TIME IN THIS FOOD SERVING PROCESS : "; 
	cout<<tarr_avg/(float)t_request<<endl;  //average turnaround time

	cout<<"\tTHE OVERALL MINIMUM TIME TILL STUDENTS WAIT UNTIL THEY ALL BEING SERVED IS : ";
	cout<<student_wt<<endl;    //student waiting time

 
}
int main()   //main method
{ 
int arrivaltime[30],bursttime[30],priority[30],p;

//taking input
cout<<"INPUT :-"<<endl;

cout<<"ENTER TOTAL NUMBER OF PROCESS(TEACHER AS WELL AS STUDENT) :  ";
cin>>t_request;
cout<<endl;

for(p=0;p<t_request;p++)
{
cout<<"ENTER THE ARRIVAL TIME FOR "<<p+1<<" :  ";
cin>>arrivaltime[p];
cout<<"ENTER THE BURST TIME FOR "<<p+1<<" :  ";
cin>>bursttime[p]; 
cout<<"ENTER THE PRIORITY OF PROCESS "<<p+1<<"(TEACHER=2 & STUDENT=1)"" :  ";  //teachers are respective so they will be given more 
cin>>priority[p];    //higher the number higher the priority                   //priority in case arrival time is same         
cout<<endl; 
}
for(int i=0;i<t_request;i++) 
    { 
    	serve[i].arr_time=arrivaltime[i]; 
    	serve[i].bru_time=bursttime[i]; 
    	serve[i].priority=priority[i]; 
    	serve[i].process_no=i+1; 
	}
	  
sort(serve,serve+t_request,comp);  //using inbuilt sort function
	
calculation(); //calling calculation function

return 0; 

} 

//Done
//End of program
 


