dnl Process this file with autoconf to produce a configure script.
AC_INIT(src/ConfigurationChoice.cpp)
AM_INIT_AUTOMAKE(clutils, 0.0)
AC_SUBST(PACKAGE, clutils)
AC_SUBST(VERSION, 0.0)

dnl AC_CONFIG_SUBDIRS(src)

dnl
AC_CANONICAL_HOST

AC_LANG(C++)

dnl Checks for programs.
AC_PROG_LIBTOOL
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_RANLIB
AC_PROG_INSTALL
dnl AC_PATH_PROG(AR, ar, :)
AC_PROG_PCCTS

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(unistd.h)
AC_CHECK_HEADERS(hash_map)
AC_CHECK_HEADERS(ext/hash_map)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_MODE_T
AC_STRUCT_TM

AC_CHECK_SIZEOF(long int)
AC_CHECK_SIZEOF(long long int)

dnl CPPFLAGS="$CPPFLAGS -DSIZEOF_LONG=$ac_cv_sizeof_long"
dnl CPPFLAGS="$CPPFLAGS -DSIZEOF_LONG=$ac_cv_sizeof_long_long"

dnl Checks for library functions.
AC_FUNC_MEMCMP
AC_TYPE_SIGNAL
AC_CHECK_FUNCS(mkdir strdup)

AM_CONFIG_HEADER(src/clutils-config.h)

AC_OUTPUT(Makefile \
	documentation/Makefile \
	src/Makefile \
	test/Makefile \
	test/modules/Makefile )

echo "Ready to build"

