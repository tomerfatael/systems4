#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <dirent.h>
#include <pthread.h>

pthread_mutex_t lock;

typedef struct DIRECTORY {
    char path[PATH_MAX];
    struct DIRECTORY *next;
} DIRECTORY;

typedef struct LIST {
    DIRECTORY *head;
    DIRECTORY *tail;
} LIST;

typedef struct THREAD {
    int threadNum;
    struct THREAD *next;
} THREAD;

typedef struct THREADSLIST {
    THREAD *head;
    THREAD *tail;
} THREADSLIST;

/*directories queue functions*/
void enqueueD(DIRECTORY *directory, LIST *list) {
    if(list->head == NULL) {
        list->head = directory;
        list->tail = directory;
    }
    else{
        list->tail->next = directory;
        list->tail = directory;
    }
}

DIRECTORY* dequeueD(LIST *list) {
    DIRECTORY *head;
    if(list->head == NULL) {
        return NULL;
    }
    head = list->head;
    list->head = list->head->next;
    return head;
}

/*threads queue functions*/
void enqueueT(THREAD *thread, THREADSLIST *list) {
    if(list->head == NULL) {
        list->head = thread;
        list->tail = thread;
    }
    else{
        list->tail->next = thread;
        list->tail = thread;
    }
}

THREAD* dequeueT(THREADSLIST *list) {
    THREAD *thread;
    if(list->head == NULL) {
        return NULL;
    }
    thread = list->head;
    list->head = list->head->next;
    return thread;
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
    int i, rc, numOfThreads, counter;   
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

    enqueueD(directory,list);

    pthreat_t theardsArr[numOfThreads];

    for(i = 0; i < numOfThreads; i++) {
        rc = pthread_create(&theardsArr[i], NULL, /*func*/, (void*)i);
        if(rc) {
            perror("pthread_create failed");
            exit(1);
        }
    }








    




}