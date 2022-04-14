#include <unistd.h>
#include <stdio.h>

#define TEMP_FILEPATH "/sys/class/thermal/thermal_zone0/temp"

int
main(int argc, char *argv[]) {
    FILE *fp = fopen(TEMP_FILEPATH, "r");

    char buf[6];

    fscanf(fp, "%s", buf);
    fclose(fp);
    write(STDOUT_FILENO, buf, 2);

    return 0;
}
