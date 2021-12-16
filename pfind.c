#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


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

int main(int argc, char** argv) {
    char *rootDirectory, *searchTerm;
    int i,numOfThreads;
    if(argc != 4) {
        perror("invalid input");
        exit(1);
    }
    rootDirectory = argv[1];
    searchTerm = argv[2];
    numOfThreads = argv[3];

}