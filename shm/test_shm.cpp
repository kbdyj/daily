#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

#define SHARED_MEM_KEY  "OS"
static const int SIZE = 4096;

int test_shm_write()
{
    const char* msg0 = "Hello, ";
    const char* msg1 = "Qt6";

    int fd = shm_open(SHARED_MEM_KEY, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SIZE);

    char* ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    sprintf(ptr, "%s", msg0);

    ptr += strlen(msg0);

    sprintf(ptr, "%s", msg1);

    return 0;
}

int test_shm_read()
{
    int fd = shm_open(SHARED_MEM_KEY, O_CREAT | O_RDWR, 0666);

    char* ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    printf("%s", ptr);

    shm_unlink(SHARED_MEM_KEY);

    return 0;
}

void test_shm()
{
    test_shm_write();
    test_shm_read();
}