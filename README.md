## Operating System(course code 316)

### A.] Write a C/C++ program to solve the following problem:
Suppose that a disk drive has 5,000 cylinders, numbered 0 to 4999. The drive is currently serving a request at cylinder 143, and the previous request was at cylinder 125. The queue of pending requests, in FIFO 
order, is: 
86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130 
Starting from the current head position, what is the total distance (in cylinders) that the disk arm moves to satisfy all the pending requests for each of the SCAN disk-scheduling algorithms?
### Description:
This question consists of SCAN disk scheduling algorithm, a scheduling technique that selects the waiting process by scanning on its way like a elevator, hence also called as elevator algorithm. Here, head starts from one end of the disk and moves towards the other end, serving request between one by one and reach the other end. Then the direction of the head is reversed and the process continues as the head continuously scan back and forth to access the disk. In above problem a disk is provided with 5000 cylinders on which the requests are being carried out. The algorithm has to be design in such a way that the user needs to calculate how much total distance(in terms of cylinder ) the user needs to travel.
### Steps:
- Take the current and the previous request from the user, it will give us direction current head to move.
- Take a queue ‘que’ and take the pending request as input.
- Take a queue ‘left’ to separate the request lesser then current head.
- Take a queue ‘right’ to separate the request bigger than current head.
- Shorting the request in queue ‘left’ in descending order as it helps in easy pick-up of request.
- Shorting the request on queue ‘right’ in ascending order as it helps in easy pick-up of request.
- Take a final queue ‘final’ to store the scanned request (satisfied through scanning).
- Previous request – current head gives the direct to move
- If the above value<0, then moves toward right first. Else if above value>0, then moves toward left first.
- Start with the current head traverse through the ‘right’ queue and the ‘left’ by popping request one by one, if above value<0. Push one by one in ‘final’ queue.
- Start with the current head traverse through the ‘left’ queue and the ‘right’ by popping request one by one, if above value>0. Push one by one in ‘final’ queue.
- Calculate the distance by its moves from one request to another. Subtracting next request-current request and taking absolute value and adding it to one another.
- The total distance is the final summation of all the moves.
### Deep Complexity Analysis: 
- In taking pending request = 9
- Checking if the pending request is> or lesser than current head = 9
- If ‘t’ elements is lesser than current head then for shorting it = t(t-1)
- Then n-t elements is greater than current head, then for shorting it = (n-t)(n-t-1)
- For pushing scanned request in final queue = n
- For calculating distance = n-1

 Total = 9+9+t^2-t+n^2-2nt-n+t+n+2n-1 = (17+2t^2)+3n+n^2 = n^2+3n (ignoring smaller terms)
#### Complexity = O(n^2)
### Boundary Condition :-
- Number of requests : 0 < = N < = 4999
- Value of the cylinders : 0 < C < 5000

### B.] Write a C/C++ program to solve the following problem
If a teacher is being served at the food mess and during the period when he is being served, another teacher comes, then that teacher would get the service(food) next. This process might continue leading to increase in the waiting time of students to get food. Ensure in your program that the waiting time of student is minimized.
### Decription
- This question consists of a combination of FCFS with Non-Preemptive nature and also with Priority scheduling due to the problem constraint. 
- Non preemptive scheduling algorithm, a scheduling technique in which once the resource is allocated to a process, the process holds the CPU till it get terminated.
- FCFS, a scheduling technique that automatically executes queued requests in order of there arrival.
- Priority Scheduling, a scheduling that is based on priority means a scheduler selects the tasks to work as per the priority.
Here, as per the problem above.to minimize the waiting time of students, each request(either teacher or student) is served on the basis of their first come first serve with non preemptive scheduling implementation…means after serving on the basis of FCFS, with the non preemptive approach it serve on the basis of as teacher/student, one by one. It also calculate the minimum time students require to wait until each student being served.
### Steps:
Steps:
- First make a queue for the total number of process request (Teacher+student).
- Then for each process assign a priority(1 for teacher/2 for student) which signify whether it is a teacher request or a student request.
- T0 minimise the waiting time for the student we make sure that the one who came first will be served 1st on the basis of their arrival time.
- If arrival time of two process request is same then we go through the priority.
- If priority is even same (means either two student or two teacher will came at the same time then as per request process Id number the will be assigned FCFS.
- Assign the arrival time, burst time and priority for each of the process.
- Calculate the turnaround time, waiting time, average waiting time, and average turnaround time.
- Also calculate the minimum time students should wait until they whole get served.
### Deep Complexity Analysis:
For any burst time>0, this program will work. But as per our question, burst time should be same as the time to serve each one should be equal.
- In taking arrival time, burst time and priority in array for n requests= 3n
- Sorting the arrival time, burst time = 2n
- Sorting ‘T’ teacher out of n according to priority if arrival time will same=t
- Calculating start time for each=n
- Calculating completion time for each=n
- Calculating turnaround time for each=n
- Calculating waiting time for each=n
- Calculating n-t students waiting time due to teacher or other student=n-t

Total = 3n+2n+t+n+n+n+n+n-t = 10n (ignoring constant complexities of program)
#### Complexity = O(n)
### Boundary Condition
- Number of requests : Total number of teacher + students.
- As they all are served equally so their burst time will be same.
- If teacher and student has the same arrival time, teacher will be given more preference.
- Only two members are there so priority is either 1 for teacher or1 for the student.
- Student waiting time is the total time waited by student until they all get served.
- Higher the number higher the priority

## END


