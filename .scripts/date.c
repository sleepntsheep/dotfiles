#include <time.h>
#include <unistd.h>

int
main(int argc, char *argv[]) {
    time_t epoch;
    char buf[50];
    struct tm *info;

    time(&epoch);
    info = localtime(&epoch);

    strftime(buf, 50, "%b %d %a %H:%M:%S", info);
    write(STDOUT_FILENO, buf, 19);
    
    return 0;
}
