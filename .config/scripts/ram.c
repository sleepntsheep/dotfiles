#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define KiB 1024.0

int
main(int argc, char *argv[]) {

    /* /proc/meminfo is in KiB (1024 bytes) despite the kB in the file */
    /* these 4 value are in KiB unit */
    unsigned int totalmem, freemem, cachedmem, buffermem;

	FILE *fp = fopen("/proc/meminfo", "r");
	char memtype[50];
	unsigned int mem;
	while (fscanf(fp, "%s %u kB%*[^\n]", memtype, &mem) != EOF) {
		if (strncmp(memtype, "MemTotal", 8) == 0)
			totalmem = mem;
		else if (strncmp(memtype, "MemFree", 7) == 0)
			freemem = mem;
		else if (strncmp(memtype, "Cached", 6) == 0)
			cachedmem = mem;
		else if (strncmp(memtype, "Buffers", 7) == 0)
			buffermem = mem;
	}

	unsigned int usedmem = totalmem-freemem-cachedmem-buffermem;

	//double totalmemMB = (double)totalmem / KiB;
	double usedmemMB = (double)usedmem / KiB;

    printf("%.0lf MiB", usedmemMB);
    return 0;
}
