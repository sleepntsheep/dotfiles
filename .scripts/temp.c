#include <unistd.h>
#include <fcntl.h>

#define TEMP_FILEPATH "/sys/class/thermal/thermal_zone0/temp"

int
main(int argc, char *argv[]) {
    //FILE *fp = fopen(TEMP_FILEPATH, "r");
    int file_desc = open(TEMP_FILEPATH, 0);

    char buf[6];

    read(file_desc, buf, 5);

    write(STDOUT_FILENO, buf, 2);

    close(file_desc);
    return 0;
}
