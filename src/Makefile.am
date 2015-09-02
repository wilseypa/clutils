lib_LTLIBRARIES = libclutils.la

INCLUDES = -I$(top_srcdir)/src/pccts

EXTRA_DIST = \
	ConfigurationParser.gg \
	config.h.in

BUILT_SOURCES=\
	ConfigurationLexer.cpp \
	ConfigurationLexer.h \
	parser.dlg \
	tokens.h \
	ConfigurationParserHandle.cpp \
	ConfigurationParser.cpp \
	ConfigurationParserHandle.h


library_includedir=$(includedir)/clutils-@VERSION@
library_include_HEADERS = \
	pccts/AParser.h \
	pccts/ATokPtr.h \
	pccts/ATokPtrImpl.h \
	pccts/AToken.h \
	pccts/ATokenBuffer.h \
	pccts/ATokenStream.h \
	pccts/pcctscfg.h \
	pccts/pccts_stdio.h \
	pccts/pccts_setjmp.h \
	pccts/ASTBase.h \
	pccts/BufFileInput.h \
	pccts/DLG_stream_input.h \
	pccts/DLexer.h \
	pccts/DLexerBase.h \
	pccts/PBlackBox.h \
	pccts/SList.h \
	pccts/antlr.h \
	pccts/ast.h \
	pccts/charbuf.h \
	pccts/charptr.h \
	pccts/dlgauto.h \
	pccts/dlgdef.h \
	pccts/err.h \
	pccts/int.h \
	pccts/pccts_assert.h \
	pccts/pccts_iostream.h \
	pccts/pccts_istream.h \
	pccts/pccts_stdarg.h \
	pccts/pccts_stdlib.h \
	pccts/pccts_string.h \
	clutils-config.h \
	ArgumentParser.h \
	ConfigurationParserHandle.h \
	ConfigurationScope.h \
	ConfigurationValue.h \
	ConfigurationChoice.h \
	ConfigurationLexer.h \
	FileManager.h \
	PosixFileManager.h \
	StringHashMap.h \
	StringUtilities.h \
	Debug.h \
	ModuleBase.h  \
	ModuleManager.h \
	tokens.h

libclutils_la_SOURCES = \
	pccts/AParser.cpp \
	pccts/ASTBase.cpp \
	pccts/ATokenBuffer.cpp \
	pccts/BufFileInput.cpp \
	pccts/DLexerBase.cpp \
	pccts/PCCTSAST.cpp \
	pccts/PCCTSAST.h \
	pccts/slist.cpp \
	ArgumentParser.cpp \
	ConfigurationLexer.cpp \
	parser.dlg \
	ConfigurationParserHandle.cpp \
	ConfigurationParser.cpp \
	ConfigurationChoice.cpp \
	ConfigurationScope.cpp \
	ConfigurationValue.cpp \
	Debug.cpp \
	FileManager.cpp \
	ModuleBase.cpp \
	ModuleManager.cpp \
	PosixFileManager.cpp \
	StringHashMap.cpp \
	StringUtilities.cpp

DO_ANTLR= $(ANTLR) -k 1 -CC ConfigurationParser.gg

DO_DLG= $(DLG) -C2 -CC parser.dlg -cl ConfigurationLexer

parser.dlg: ConfigurationParser.gg
	$(DO_ANTLR)

ConfigurationLexer.cpp: parser.dlg
	$(DO_DLG)

ConfigurationLexer.h: parser.dlg
	$(DO_DLG)

tokens.h: ConfigurationParser.gg
	$(DO_ANTLR)

ConfigurationParserHandle.cpp: ConfigurationParser.gg ConfigurationLexer.h
	$(DO_ANTLR)

ConfigurationParser.cpp: ConfigurationParser.gg
	$(DO_ANTLR)

ConfigurationParserHandle.h: ConfigurationParser.gg
	$(DO_ANTLR)

CLEANFILES=$(BUILT_SOURCES)
