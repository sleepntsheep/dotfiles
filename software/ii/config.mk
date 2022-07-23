# Customize to fit your system
VERSION = 1.9

# paths
PREFIX    = /usr/local
MANPREFIX = ${PREFIX}/share/man
DOCPREFIX = ${PREFIX}/share/doc

# on systems which provide strlcpy(3),
# remove NEED_STRLCPY from CFLAGS and
# remove strlcpy.o from LIBS
CFLAGS   = -DNEED_STRLCPY -Os
LDFLAGS  = -s
LIBS     = strlcpy.o
