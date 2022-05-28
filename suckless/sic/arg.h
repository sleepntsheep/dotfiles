/*
 * Copy me if you can.
 * by 20h
 * Modifyed by sleepntsheep, i find old one too complicated and hard to understand
 */

#ifndef ARG_H__
#define ARG_H__

#define ARGBEGIN for (; ++argv && argv[0]; ) {\
                 if (argv[0][0] != '-' || !(argv[0][1])) continue;\
                 switch(argv[0][1])

#define ARGEND }

/* next arg, if NULL then (x) and abort() */
#define NXARG(x) ((argv[1]) ?\
        (*(++argv)) : ((x), abort(), NULL))

#endif
