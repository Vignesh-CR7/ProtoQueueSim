#include "queue.h"
#include <stdio.h>
#include <string.h>

// Initializing the queue
void initQueue(PacketQueue* q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Check if queue is full
int isFull(PacketQueue* q) {
    return q->count == MAX;
}

// Check if queue is empty
int isEmpty(PacketQueue* q) {
    return q->count == 0;
}

// Enqueue a packet
void enqueue(PacketQueue* q, Packet p) {
    if (isFull(q)) {
        printf("Queue is full! Packet dropped.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->packets[q->rear] = p;
    q->count++;
    printf("Packet with ID %d enqueued successfully.\n", p.packet_id);
}

// Dequeue a packet
Packet dequeue(PacketQueue* q) {
    Packet temp = {0, "", "", 0};
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return temp;
    }
    temp = q->packets[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    printf("Packet with ID %d dequeued.\n", temp.packet_id);
    return temp;
}

// Display all packets in queue
void displayQueue(PacketQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("\n--- Current Queue ---\n");
    int i, idx;
    for (i = 0; i < q->count; i++) {
        idx = (q->front + i) % MAX;
        Packet p = q->packets[idx];
        printf("ID: %d | From: %s | To: %s | Size: %d bytes\n",
               p.packet_id, p.src, p.dest, p.size);
    }
    printf("----------------------\n");
}
