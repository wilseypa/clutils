SUBDIRS= modules

INCLUDES = -I$(top_srcdir)/src/pccts -I$(top_srcdir)/src

bin_PROGRAMS = regressionTest

EXTRA_DIST = Greeter.h \
	configurationParserTest.cfg

regressionTest_SOURCES = \
	ConfigurationParserTest.h \
	ConfigurationParserTest.cpp \
	FileManagerTest.h \
	FileManagerTest.cpp \
	ModuleManagerTest.h \
	ModuleManagerTest.cpp \
	regressionTest.cpp

regressionTest_LDADD = \
	../src/libclutils.la \
	-lltdl
