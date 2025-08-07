#ifndef QUEUE_H
#define QUEUE_H

#define MAX 5

typedef struct {
    int packet_id;
    char src[20];
    char dest[20];
    int size;
} Packet;

typedef struct {
    Packet packets[MAX];
    int front;
    int rear;
    int count;
} PacketQueue;

void initQueue(PacketQueue* q);
int isFull(PacketQueue* q);
int isEmpty(PacketQueue* q);
void enqueue(PacketQueue* q, Packet p);
Packet dequeue(PacketQueue* q);
void displayQueue(PacketQueue* q);

#endif
