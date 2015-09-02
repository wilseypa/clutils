noinst_LTLIBRARIES = FrenchGreeter.la
FrenchGreeter_la_LDFLAGS= \
	-module \
	-no-undefined \
	-avoid-version \
	-L$(top_builddir)/src

FrenchGreeter_la_LIBADD= \
	-lclutils

INCLUDES=-I$(top_srcdir)/src

FrenchGreeter_la_SOURCES =\
	FrenchGreeter.cpp \
	FrenchGreeter.h
