#include "queue.h"




 void createQueue(Queue * PStr_Queue)
 {
    PStr_Queue->front=0;
    PStr_Queue->rear=-1;
    PStr_Queue->size=0;
 }



 void Enqueue(Queue * PStr_Queue,QueueEntry E)
 {
    PStr_Queue->rear=(PStr_Queue->rear+1)%MAX_SIZE;
    PStr_Queue->Entry[PStr_Queue->rear]=E;
    PStr_Queue->size++;
 }





 void Dequeue(QueueEntry* PE,Queue * PStr_Queue)
 {
    *PE=PStr_Queue->Entry[PStr_Queue->front];
    PStr_Queue->front=(PStr_Queue->front+1)%MAX_SIZE;
    PStr_Queue->size--;
 }




 int queueEmpty(Queue * PS)
 {
    /*if queue is empty then size is 0
    which will return true else it will return false*/
    return !PS->size;
 }


 int queueFull(Queue*PS)
 {
    return(PS->size==MAX_SIZE);
 }

 void queueFront(Queue * PS,QueueEntry* PE)
 {
    *PE=PS->Entry[PS->front];
 }



 QueueMember queueSize(Queue *PS)
 {
    return PS->size;
 }

 void clearQueue(Queue*PS)
 {
    PS->front=0;
    PS->rear=-1;
    PS->size=0;
    
 }


 void traverseQueue(Queue *ps,void(*pf)(QueueEntry e))
 {
    int size;
    QueueMember pos;
    for( size=0, pos=ps->front;size<ps->size;size++)
    {
        pf(ps->Entry[pos]);
        pos=(pos+1)%MAX_SIZE;

    }
    
 }
