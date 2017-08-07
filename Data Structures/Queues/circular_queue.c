#include <stdio.h>
#include <stdlib.h>

typedef struct circqueue {
	int front, rear, capacity, *array;
} que;

typedef que *QuePtr;

QuePtr q(int size) {
	QuePtr q = malloc(sizeof(QuePtr));
	if (!q)
		return NULL;
	q->capacity = size;
	q->front = -1;
	q->rear = -1;
	q->array = malloc(q->capacity * sizeof(int));
	if (!q->array)
		return NULL;
	return q;
}

int isemptyqueue(QuePtr q) {
	return (q->front == -1);
}

int isfullqueue(QuePtr q) {
	return ((q->rear + 1) % q->capacity == q->rear);
}

int queuesize(QuePtr q) {
	return (q->capacity - q->rear + q->front + 1) % q->capacity;
}

void enqueue(QuePtr q, int x) {

	if (isfullqueue(q))
		printf("queue overflow\n");
	else {
		q->rear = (q->rear + 1) % q->capacity;
		q->array[q->rear] = x;
		if (q->front == -1) {
			q->front = q->rear;
		}
	}
}

int dequeue(QuePtr q) {
	int data = 0;

	if (isemptyqueue(q)) {
		printf("queue underflow");
		return 0;
	} else {
		data = q->array[q->front];
		if (q->front == q->rear)
			q->front = q->rear = -1;
		else
			q->front = (q->front + 1) % q->capacity;
	}

	return data;
}

void printQueue(QuePtr q) {
	int aux, aux1;
	aux = q->front;
	aux1 = q->capacity;
	while (aux1 > 0) {
		printf("Element #%d = %d\n", aux, q->array[aux]);
		aux = (aux + 1) % 10;
		aux1--;
	}
	return;
}

int main() {
	QuePtr queue = q(10);

	enqueue(queue, 0);
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);
	enqueue(queue, 5);
	enqueue(queue, 6);
	enqueue(queue, 7);
	enqueue(queue, 8);
	enqueue(queue, 9);

	printQueue(queue);
	free(queue->array);
	free(queue);
}

