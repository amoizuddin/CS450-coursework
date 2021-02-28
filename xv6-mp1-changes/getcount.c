#include "types.h"
#include "user.h"
#include "syscall.h"

int main(int argc, char* argv[])
{

    printf(1, "initial forks: %d\n", getcount(SYS_fork));

    if(fork()==0)
    {
        printf(1,"child forks: %d\n", getcount(SYS_fork));
        printf(1,"child writes: %d\n", getcount(SYS_write));
    }

    else
    {
        wait();
        printf(1,"parent forks: %d\n", getcount(SYS_fork));
        printf(1,"parent forks: %d\n", getcount(SYS_write));
    }

    printf(1,"waits: %d\n", getcount(SYS_write));
    exit();

}