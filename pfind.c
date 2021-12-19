#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <dirent.h>
#include <pthread.h>

typedef struct DIRECTORY {
    char path[PATH_MAX];
    struct DIRECTORY *next;
} DIRECTORY;

typedef struct LIST {
    DIRECTORY *head;
    DIRECTORY *tail;
} LIST;

void enqueue(DIRECTORY *directory, LIST *list) {
    if(list->head == NULL) {
        list->head = directory;
        list->tail = directory;
    }
    else{
        list->tail->next = directory;
        list->tail = directory;
    }
}

DIRECTORY* dequeue(LIST *list) {
    DIRECTORY *head;
    if(list->head == NULL) {
        return NULL;
    }
    head = list->head;
    list->head = list->head->next;
    return head;
}

bool isEmpty(LIST *list) {
    if(list->head == NULL) {
        return true;
    }
    return false;
}

void searchValidate(char *directoryPath) { //can I crash the program without freeing all allocated memory?
    DIR *dir;
    dir = opendir(directoryPath);
    if(dir == NULL) {
        perror("Directory %s: Permission denied.\n", directoryPath);
        exit(1);
    }
}


int main(int argc, char** argv) {
    char *rootDirectory, *searchTerm;
    int i, rc, numOfThreads;
    LIST *list;
    DIRECTORY *directory;

    if(argc != 4) {
        perror("invalid input");
        exit(1);
    }
    rootDirectory = argv[1];
    searchTerm = argv[2];
    numOfThreads = atoi(argv[3]);

    searchValidate(rootDirectory);
    
    directory = (DIRECTORY*)malloc(sizeof(DIRECTORY));
    if(directory == NULL) {
        perror("malloc failed");
        exit(1);
    }

    directory->path = rootDirectory;
    directory->next = NULL;

    list = (LIST*)malloc(sizeof(LIST));
    if(list == NULL) {
        perror("malloc failed");
        exit(1);
    }

    list->head = NULL;
    list->tail = NULL;

    enqueue(directory,list);

    for(i = 0; i < numOfThreads; i++) {
        rc = pthread_create()
    }





    




}