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

void enqueue(DIRECTORY *directory, DIRECTORY *head) {
    
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