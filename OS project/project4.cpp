#include <iostream>
#include <queue>
#include <thread>
#include <semaphore.h>
#include <unistd.h>  // for sleep()

using namespace std;

const int BUFFER_SIZE = 5;
queue<int> buffer;

// Semaphores
sem_t emptySlots;  // counts empty slots
sem_t fullSlots;   // counts filled slots
pthread_mutex_t mutexBuffer; // mutex lock for buffer

void producer(int id) {
    int item = 1;
    while (true) {
        sem_wait(&emptySlots); // wait for empty slot
        pthread_mutex_lock(&mutexBuffer);

        // Critical section
        buffer.push(item);
        cout << "Producer " << id << " produced item " << item << endl;
        item++;

        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&fullSlots); // increase filled slots

        sleep(1); // simulate time
    }
}

void consumer(int id) {
    while (true) {
        sem_wait(&fullSlots); // wait for filled slot
        pthread_mutex_lock(&mutexBuffer);

        // Critical section
        int item = buffer.front();
        buffer.pop();
        cout << "Consumer " << id << " consumed item " << item << endl;

        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&emptySlots); // increase empty slots

        sleep(2); // simulate time
    }
}

int main() {
    // Initialize semaphores and mutex
    sem_init(&emptySlots, 0, BUFFER_SIZE);
    sem_init(&fullSlots, 0, 0);
    pthread_mutex_init(&mutexBuffer, NULL);

    // Create producer and consumer threads
    thread p1(producer, 1);
    thread p2(producer, 2);
    thread c1(consumer, 1);
    thread c2(consumer, 2);

    p1.join();
    p2.join();
    c1.join();
    c2.join();

    return 0;
}
