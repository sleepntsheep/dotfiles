# See LICENSE file for copyright and license details.
.POSIX:

include config.mk

SRC = ii.c
OBJ = $(SRC:.c=.o)

IICFLAGS = -DVERSION=\"$(VERSION)\" -D_DEFAULT_SOURCE $(CFLAGS)

all: ii

options:
	@echo ii build options:
	@echo "CFLAGS   = $(IICFLAGS)"
	@echo "LDFLAGS  = $(LDFLAGS)"
	@echo "CC       = $(CC)"

.c.o:
	$(CC) $(IICFLAGS) -c $<

ii: $(OBJ) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $(OBJ) $(LIBS)

$(OBJ): arg.h

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	mkdir -p $(DESTDIR)$(MANPREFIX)/man1
	mkdir -p $(DESTDIR)$(DOCPREFIX)/ii
	install -m 644 CHANGES README FAQ LICENSE $(DESTDIR)$(DOCPREFIX)/ii
	install -m 775 ii $(DESTDIR)$(PREFIX)/bin
	sed "s/VERSION/$(VERSION)/g" < ii.1 > $(DESTDIR)$(MANPREFIX)/man1/ii.1
	chmod 644 $(DESTDIR)$(MANPREFIX)/man1/ii.1

uninstall: all
	rm -f $(DESTDIR)$(MANPREFIX)/man1/ii.1 $(DESTDIR)$(PREFIX)/bin/ii
	rm -rf $(DESTDIR)$(DOCPREFIX)/ii

dist: clean
	mkdir -p ii-$(VERSION)
	cp -R Makefile CHANGES README FAQ LICENSE strlcpy.c arg.h \
		config.mk ii.c ii.1 ii-$(VERSION)
	tar -cf ii-$(VERSION).tar ii-$(VERSION)
	gzip ii-$(VERSION).tar
	rm -rf ii-$(VERSION)

clean:
	rm -f ii *.o
