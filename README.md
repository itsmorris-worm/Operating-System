# Operating System(course code 316)

## A.] Write a C/C++ program to solve the following problem:
Suppose that a disk drive has 5,000 cylinders, numbered 0 to 4999. The drive is currently serving a request at 
cylinder143, and the previous request was at cylinder 125. The queue of pending requests, in FIFO 
order, is: 
86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130 
Starting from the current head position, what is the total distance (in cylinders) that the disk arm moves to 
satisfy all the pending requests for each of the SCAN disk-scheduling algorithms?
## Description:
This question consists of SCAN disk scheduling algorithm, a scheduling technique that selects the waiting 
process by scanning on its way like a elevator, hence also called as elevator algorithm. Here, head starts from 
one end of the disk and moves towards the other end, serving request between one by one and reach the other 
end. Then the direction of the head is reversed and the process continues as the head continuously scan back 
and forth to access the disk. In above problem a disk is provided with 5000 cylinders on which the requests are 
being carried out. The algorithm has to be design in such a way that the user needs to calculate how much 
total distance(in terms of cylinder ) the user needs to travel.
## Steps:
-> Take the current and the previous request from the userit will give us direction to move and the 
current head.
-> Take a queue ‘que’ and take the pending request as input.
-> Take a queue ‘left’ to separate the request lesser then current head.
-> Take a queue ‘right’ to separate the request bigger than current head.
-> Shorting the request in queue ‘left’ in descending order as it helps in easy pick-up of request.
-> Shorting the request on queue ‘right’ in ascending order as it helps in easy pick-up of request.
-> Take a final queue ‘final’ to store the scanned request (satisfied through scanning).
-> Previous request – current head gives the direct to move
 If the above value<0, then moves toward right first.
 Else if above value>0, then moves toward left first.
-> Start with the current head traverse through the ‘right’ queue and the ‘left’ by popping request one 
by one, if above value<0. Push one by one in ‘final’ queue.
-> Start with the current head traverse through the ‘left’ queue and the ‘right’ by popping request one 
by one, if above value>0. Push one by one in ‘final’ queue.
-> Calculate the distance by its moves from one request to another. Subtracting next request-current 
request and taking absolute value and adding it to one another.
-> The total distance is the final summation of all the moves.

## Deep Complexity Analysis:- 
1.) In taking pending request = 9
2.) Checking if the pending request is> or lesser than current head = 9
3.) If ‘t’ elements is lesser than current head then for shorting it = t(t-1)
4.) Then n-t elements is greater than current head, then for shorting it = (n-t)(n-t-1)
5.) For pushing scanned request in final queue = n
6.) For calculating distance = n-1

TOTAL = 9+9+t^2-t+n^2-2nt-n+t+n+2n-1 = (17+2t^2)+3n+n^2 = n^2+3n(ignoring smaller terms)
### Complexity = O(n^2)

## Boundary Condition :-
1.) Number of requests : 0 < = N < = 4999
2.) Value of the cylinders : 0 < C < 5000

## B.] 

