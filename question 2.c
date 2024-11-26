#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q, int value) {
    struct Node* temp = newNode(value);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        q->rear->next = q->front;
    } else {
        q->rear->next = temp;
        q->rear = temp;
        q->rear->next = q->front;
    }
    printf("%d enqueued to queue\n", value);
}

int deQueue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int value;
    if (q->front == q->rear) {
        value = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        struct Node* temp = q->front;
        value = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
    return value;
}

int front(struct Queue* q) {
    if (q->front != NULL)
        return q->front->data;
    return -1;
}

int rear(struct Queue* q) {
    if (q->rear != NULL)
        return q->rear->data;
    return -1;
}

int main() {
    struct Queue* q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    enQueue(q, 40);
    printf("Front element: %d\n", front(q));
    printf("Rear element: %d\n", rear(q));
    printf("%d dequeued from queue\n", deQueue(q));
    printf("Front element: %d\n", front(q));
    printf("%d dequeued from queue\n", deQueue(q));
    printf("%d dequeued from queue\n", deQueue(q));
    printf("%d dequeued from queue\n", deQueue(q));
    printf("%d dequeued from queue\n", deQueue(q));
    return 0;
}