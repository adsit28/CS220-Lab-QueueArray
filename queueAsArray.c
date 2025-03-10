/** 
 * ===========================================================
 * Name: 
 * Section: 
 * Project: Queue ADT implemented with C array
 * //Coded entirely by chatgpt
 * ===========================================================
 */

 // queueAsArray.c

#include "queueAsArray.h"
#include <stdio.h>
#include <stdlib.h>

/** enqueue() - adds an element to the back of the queue
 * @param queue - a ptr to the queue structure
 * @param element - the item to add to the queue
 * @return 1 on success, -1 on failure
 */
int enqueue(QueueAsArray* queue, int element) {
    if (queueIsFull(queue)) {
        return -1;  // Queue is full, cannot add element
    }
    
    // Add the element to the queue at the current back index
    queue->number[queue->back] = element;
    
    // Update the back index in a circular manner
    queue->back = (queue->back + 1) % QUEUE_MAX_SIZE;
    
    // Increment the size of the queue
    queue->size++;
    
    return 1;  // Success
}

/** dequeue() - removes an element from the front of the queue
 * @param queue - a ptr to the queue structure
 * @return - the front of the queue on success, -1 on failure
 */
int dequeue(QueueAsArray* queue) {
    if (queueIsEmpty(queue)) {
        return -1;  // Queue is empty, cannot dequeue
    }
    
    // Get the element from the front of the queue
    int element = queue->number[queue->front];
    
    // Update the front index in a circular manner
    queue->front = (queue->front + 1) % QUEUE_MAX_SIZE;
    
    // Decrement the size of the queue
    queue->size--;
    
    return element;  // Return the dequeued element
}

/** queueIsEmpty() - determines if the queue is empty
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is empty or false
 */
bool queueIsEmpty(QueueAsArray* queue) {
    return queue->size == 0;
}

/** queueIsFull() - determines if the queue is full
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is full or false
 */
bool queueIsFull(QueueAsArray* queue) {
    return queue->size == QUEUE_MAX_SIZE;
}

/** queueInit() - initializes the queue structure
 * @param queue - a ptr to the queue structure
 */
void queueInit(QueueAsArray* queue) {
    queue->front = 0;
    queue->back = 0;
    queue->size = 0;
}

/** queuePeek() - returns the item on the front of the
 * queue but doesn't remove it
 * @param queue - a ptr to the queue structure
 * @return - the item at the front of the queue or -1 on failure
 */
int queuePeek(QueueAsArray* queue) {
    if (queueIsEmpty(queue)) {
        return -1;  // Queue is empty, cannot peek
    }
    
    return queue->number[queue->front];  // Return the front element
}

/** queueSize() - determines the size of the queue
 * @param queue - a ptr to the queue structure
 * @return - number of items in the queue
 */
int queueSize(QueueAsArray* queue) {
    return queue->size;
}

/** queuePrint() - outputs the queue to the console
 * @param queue - ptr to the queue structure
 */
void queuePrint(QueueAsArray* queue) {
    if (queueIsEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    
    int i = queue->front;
    for (int count = 0; count < queue->size; count++) {
        printf("%d ", queue->number[i]);
        i = (i + 1) % QUEUE_MAX_SIZE;  // Circular increment
    }
    printf("\n");
}
