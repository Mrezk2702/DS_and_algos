
#define MAX_SIZE 10

typedef int QueueMember;
typedef int QueueEntry;


typedef struct queue
{
    QueueMember front;
    QueueMember rear;
    QueueMember size;
    QueueEntry Entry[MAX_SIZE];
}Queue;


 void createQueue(Queue * PStr_Queue);
 void Enqueue(Queue * PStr_Queue,QueueEntry E);
 void Dequeue(QueueEntry* PE,Queue * PStr_Queue);
 void traverseQueue(Queue *ps,void(*pf)(QueueEntry e));
 int queueEmpty(Queue * PS);
 void queueFront(Queue * PS,QueueEntry* PE);
 int queueFull(Queue*PS);
 int queueSize(Queue *PS);
 void clearQueue(Queue*PS);