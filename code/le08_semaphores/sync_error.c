/*
  Program: Synchronization error

  Compile:
      gcc -o sync_error.out sync_error.c -lpthread
*/

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t file1_lock, file2_lock;

void *t1();
void *t2();

int main() { 
    pthread_t threads[2];
    
    pthread_mutex_init(&file1_lock, NULL);
    pthread_mutex_init(&file2_lock, NULL);
    
    pthread_create(&threads[0], NULL, t1, NULL);
    pthread_create(&threads[1], NULL, t2, NULL);
    
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    
    return 0;
}

void *t1() {
    FILE *file1, *file2;
    
    pthread_mutex_lock(&file2_lock);
    pthread_mutex_lock(&file1_lock);
    
    file1 = fopen("file1.txt", "w");
    printf("Thread 1: Writting to file1.txt\n");
    fputs("1 2 3 4 5\n", file1);
    fclose(file1);
    
    file2 = fopen("file2.txt", "w");
    printf("Thread 1: Writting to file2.txt\n");
    fputs("A B C D E\n", file2);
    fclose(file2);
    
    pthread_mutex_unlock(&file2_lock);
    pthread_mutex_unlock(&file1_lock);
}

void *t2() {
    FILE *file1, *file2;
    
    pthread_mutex_lock(&file1_lock);
    pthread_mutex_lock(&file2_lock);
    
    file1 = fopen("file1.txt", "w");
    printf("Thread 2: Writting to file1.txt\n");
    fputs("6 7 8 9 10\n", file1);
    fclose(file1);
    
    file2 = fopen("file2.txt", "w");
    printf("Thread 2: Writting to file2.txt\n");
    fputs("F G H I J\n", file2);
    fclose(file2);
    
    pthread_mutex_unlock(&file1_lock);
    pthread_mutex_unlock(&file2_lock);
}

