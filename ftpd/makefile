#
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the University of California, Berkeley.  The name of the
# University may not be used to endorse or promote products derived
# from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
# WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
#
#	@(#)Makefile	based on 5.10 (Berkeley) 4/20/89
#
CFLAGS=-DNUMBITS=64
LIBC=
CC=gcc 
SRCS=	ftpd.c ftpcmd.c glob.c popen.c vers.c\
	strtok.c strpbrk.c valid.c
OBJS=	ftpd.o ftpcmd.o glob.o popen.o vers.o  \
	strtok.o strpbrk.o valid.o
MAN=	ftpd.8

all: ftpd

ftpd: ${OBJS} ${LIBC}
	${CC} -o $@ ${OBJS} 

vers.o: ftpd.c ftpcmd.y
	sh newvers.sh
	${CC} ${CFLAGS} -c vers.c

dist: ${SRCS} README ftpcmd.y ${MAN}
	tar -cvf ../ftpd-lpmud.tar *
	compress ../ftpd-lpmud.tar

clean:
	rm -f ${OBJS} ftpd core ftpcmd.c

cleandir: clean
	rm -f ${MAN} tags .depend

depend: ${SRCS}
	makedepend ${CFLAGS} ${SRCS}

install: ${MAN}
	install -s -o bin -g bin -m 755 ftpd ${DESTDIR}/usr/libexec
	install -c -o bin -g bin -m 755 ftpd.0 ${DESTDIR}/usr/man/cat8

lint: ${SRCS}
	lint ${CFLAGS} ${SRCS}

tags: ${SRCS}
	ctags ${SRCS}
# DO NOT DELETE THIS LINE -- make depend depends on it.

