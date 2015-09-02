dnl aclocal.m4 generated automatically by aclocal 1.4

dnl Copyright (C) 1994, 1995-8, 1999 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY, to the extent permitted by law; without
dnl even the implied warranty of MERCHANTABILITY or FITNESS FOR A
dnl PARTICULAR PURPOSE.

AC_DEFUN(AC_PROG_PCCTS,
[
AC_SUBST(ANTLR)
AC_SUBST(DLG)

AC_PATH_PROG(ANTLR, antlr, no)
if test $ANTLR = no; then
AC_MSG_ERROR( Configure could not locate the program \"antlr\" in your
path.  This program is needed to build the warped system.  It should
be installed as part of the PCCTS system which is available for free
via anonymous ftp from ftp.parr-research.com in the directory
/pub/pccts.  If you have installed PCCTS please verify that \"antlr\"
is in your path which is currently:
$PATH)
fi

AC_PATH_PROG(DLG, dlg, no)
if test $DLG = no; then
AC_MSG_ERROR( Configure could not locate the program \"dlg\" in your
path.  This program is needed to build the warped system.  It should
be installed as part of the PCCTS system which is available for free
via anonymous ftp from ftp.parr-research.com in the directory
/pub/pccts.  If you have installed PCCTS please verify that \"dlg\"
is in your path which is currently:
$PATH)
fi
])

