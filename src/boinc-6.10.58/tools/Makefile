# Makefile.in generated by automake 1.11.1 from Makefile.am.
# tools/Makefile.  Generated from Makefile.in by configure.

# Copyright (C) 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002,
# 2003, 2004, 2005, 2006, 2007, 2008, 2009  Free Software Foundation,
# Inc.
# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.



# Note: MYSQL_CFLAGS and MYSQL_LIBS set by configure from mysql_config



pkgdatadir = $(datadir)/boinc
pkgincludedir = $(includedir)/boinc
pkglibdir = $(libdir)/boinc
pkglibexecdir = $(libexecdir)/boinc
am__cd = CDPATH="$${ZSH_VERSION+.}$(PATH_SEPARATOR)" && cd
install_sh_DATA = $(install_sh) -c -m 644
install_sh_PROGRAM = $(install_sh) -c
install_sh_SCRIPT = $(install_sh) -c
INSTALL_HEADER = $(INSTALL_DATA)
transform = $(program_transform_name)
NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
build_triplet = x86_64-unknown-linux-gnu
host_triplet = arm-unknown-linux-gnu
target_triplet = arm-unknown-linux-gnu
DIST_COMMON = $(dist_bin_SCRIPTS) $(dist_sched_SCRIPTS) \
	$(srcdir)/Makefile.am $(srcdir)/Makefile.in \
	$(top_srcdir)/Makefile.incl \
	$(top_srcdir)/py/boinc_path_config.py.in
bin_PROGRAMS = create_work$(EXEEXT) sign_executable$(EXEEXT) \
	dir_hier_path$(EXEEXT) dir_hier_move$(EXEEXT)
subdir = tools
ACLOCAL_M4 = $(top_srcdir)/aclocal.m4
am__aclocal_m4_deps = $(top_srcdir)/m4/acx_pthread.m4 \
	$(top_srcdir)/m4/ax_check_gl.m4 \
	$(top_srcdir)/m4/ax_check_glu.m4 \
	$(top_srcdir)/m4/ax_check_glut.m4 \
	$(top_srcdir)/m4/ax_lang_compiler_ms.m4 \
	$(top_srcdir)/m4/ax_winsock.m4 \
	$(top_srcdir)/m4/boinc_check_cygwin.m4 \
	$(top_srcdir)/m4/boinc_check_fcgi.m4 \
	$(top_srcdir)/m4/boinc_check_flags.m4 \
	$(top_srcdir)/m4/boinc_check_lib_with.m4 \
	$(top_srcdir)/m4/boinc_getsockopt.m4 \
	$(top_srcdir)/m4/boinc_gtk.m4 \
	$(top_srcdir)/m4/boinc_platform.m4 \
	$(top_srcdir)/m4/boinc_set_compile_flags.m4 \
	$(top_srcdir)/m4/boinc_wxwidgets.m4 \
	$(top_srcdir)/m4/check_ssl.m4 $(top_srcdir)/m4/kc_mysql.m4 \
	$(top_srcdir)/m4/libtool.m4 $(top_srcdir)/m4/sah_check_lib.m4 \
	$(top_srcdir)/m4/sah_header_stdcxx.m4 \
	$(top_srcdir)/m4/sah_largefile_breaks_cxx.m4 \
	$(top_srcdir)/m4/sah_libext.m4 $(top_srcdir)/m4/sah_links.m4 \
	$(top_srcdir)/m4/sah_namespace.m4 \
	$(top_srcdir)/m4/sah_select_bitness.m4 \
	$(top_srcdir)/m4/sah_staticize_ldflags.m4 \
	$(top_srcdir)/m4/sqlite3.m4 $(top_srcdir)/m4/wxWidgets.m4 \
	$(top_srcdir)/configure.ac
am__configure_deps = $(am__aclocal_m4_deps) $(CONFIGURE_DEPENDENCIES) \
	$(ACLOCAL_M4)
mkinstalldirs = $(SHELL) $(top_srcdir)/mkinstalldirs
CONFIG_HEADER = $(top_builddir)/config.h
CONFIG_CLEAN_FILES = boinc_path_config.py
CONFIG_CLEAN_VPATH_FILES =
am__installdirs = "$(DESTDIR)$(bindir)" "$(DESTDIR)$(bindir)" \
	"$(DESTDIR)$(scheddir)"
PROGRAMS = $(bin_PROGRAMS)
am_create_work_OBJECTS = create_work.$(OBJEXT)
create_work_OBJECTS = $(am_create_work_OBJECTS)
am__DEPENDENCIES_1 =
am__DEPENDENCIES_2 = $(LIBSCHED) $(LIBBOINC_CRYPT) $(LIBBOINC) \
	$(am__DEPENDENCIES_1) $(am__DEPENDENCIES_1) \
	$(am__DEPENDENCIES_1) $(am__DEPENDENCIES_1)
create_work_DEPENDENCIES = $(am__DEPENDENCIES_2)
am_dir_hier_move_OBJECTS = dir_hier_move.$(OBJEXT)
dir_hier_move_OBJECTS = $(am_dir_hier_move_OBJECTS)
dir_hier_move_DEPENDENCIES = $(am__DEPENDENCIES_2)
am_dir_hier_path_OBJECTS = dir_hier_path.$(OBJEXT)
dir_hier_path_OBJECTS = $(am_dir_hier_path_OBJECTS)
dir_hier_path_DEPENDENCIES = $(am__DEPENDENCIES_2)
am_sign_executable_OBJECTS = sign_executable.$(OBJEXT)
sign_executable_OBJECTS = $(am_sign_executable_OBJECTS)
sign_executable_DEPENDENCIES = $(am__DEPENDENCIES_2)
am__vpath_adj_setup = srcdirstrip=`echo "$(srcdir)" | sed 's|.|.|g'`;
am__vpath_adj = case $$p in \
    $(srcdir)/*) f=`echo "$$p" | sed "s|^$$srcdirstrip/||"`;; \
    *) f=$$p;; \
  esac;
am__strip_dir = f=`echo $$p | sed -e 's|^.*/||'`;
am__install_max = 40
am__nobase_strip_setup = \
  srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*|]/\\\\&/g'`
am__nobase_strip = \
  for p in $$list; do echo "$$p"; done | sed -e "s|$$srcdirstrip/||"
am__nobase_list = $(am__nobase_strip_setup); \
  for p in $$list; do echo "$$p $$p"; done | \
  sed "s| $$srcdirstrip/| |;"' / .*\//!s/ .*/ ./; s,\( .*\)/[^/]*$$,\1,' | \
  $(AWK) 'BEGIN { files["."] = "" } { files[$$2] = files[$$2] " " $$1; \
    if (++n[$$2] == $(am__install_max)) \
      { print $$2, files[$$2]; n[$$2] = 0; files[$$2] = "" } } \
    END { for (dir in files) print dir, files[dir] }'
am__base_list = \
  sed '$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;s/\n/ /g' | \
  sed '$$!N;$$!N;$$!N;$$!N;s/\n/ /g'
SCRIPTS = $(dist_bin_SCRIPTS) $(dist_sched_SCRIPTS)
DEFAULT_INCLUDES = -I. -I$(top_builddir)
depcomp = $(SHELL) $(top_srcdir)/depcomp
am__depfiles_maybe = depfiles
am__mv = mv -f
CXXCOMPILE = $(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) \
	$(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CXXFLAGS) $(CXXFLAGS)
LTCXXCOMPILE = $(LIBTOOL) --tag=CXX $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) \
	--mode=compile $(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) \
	$(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CXXFLAGS) $(CXXFLAGS)
CXXLD = $(CXX)
CXXLINK = $(LIBTOOL) --tag=CXX $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) \
	--mode=link $(CXXLD) $(AM_CXXFLAGS) $(CXXFLAGS) $(AM_LDFLAGS) \
	$(LDFLAGS) -o $@
SOURCES = $(create_work_SOURCES) $(dir_hier_move_SOURCES) \
	$(dir_hier_path_SOURCES) $(sign_executable_SOURCES)
DIST_SOURCES = $(create_work_SOURCES) $(dir_hier_move_SOURCES) \
	$(dir_hier_path_SOURCES) $(sign_executable_SOURCES)
ETAGS = etags
CTAGS = ctags
DISTFILES = $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST)
ACLOCAL = ${SHELL} /home/mat/docs/src/android/native-boinc-for-android/src/boinc-6.10.58/missing --run aclocal-1.11
ALLOCA = 
AMTAR = ${SHELL} /home/mat/docs/src/android/native-boinc-for-android/src/boinc-6.10.58/missing --run tar
AR = ar
AS = as
AUTOCONF = ${SHELL} /home/mat/docs/src/android/native-boinc-for-android/src/boinc-6.10.58/missing --run autoconf
AUTOHEADER = ${SHELL} /home/mat/docs/src/android/native-boinc-for-android/src/boinc-6.10.58/missing --run autoheader
AUTOMAKE = ${SHELL} /home/mat/docs/src/android/native-boinc-for-android/src/boinc-6.10.58/missing --run automake-1.11
AWK = gawk
BOINC_EXTRA_LIBS =  -L/data/local/tmp/lib -lcurl -L/home/mat/docs/dev/mobile/android-ndk-r5b/platforms/android-8/arch-arm//usr/lib -lssl -lcrypto -ldl -ldl -lz
BOINC_MAJOR_VERSION = 6
BOINC_MINOR_VERSION = 10
BOINC_RELEASE = 58
BOINC_VERSION_STRING = 6.10.58
CC = /home/mat/docs/dev/mobile/android-ndk-r5b/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/bin//arm-linux-androideabi-gcc
CCDEPMODE = depmode=gcc3
CFLAGS = --sysroot=/home/mat/docs/dev/mobile/android-ndk-r5b/platforms/android-8/arch-arm/ -Wall -O2 -funroll-loops -I/data/local/tmp/include
CLIENTGUIFLAGS = 
CLIENTGUILIBS =   
CLIENTLIBS = -lm 
CLIENT_BIN_FILENAME = boinc
CLIENT_CMD_BIN_FILENAME = boinccmd
CLIENT_GUI_BIN_FILENAME = boincmgr
CPP = /lib/cpp
CPPFLAGS = -I/data/local/tmp/include -DANDROID=1 -I/home/mat/docs/dev/mobile/android-ndk-r5b/sources/cxx-stl/gnu-libstdc++/include/ -I/home/mat/docs/dev/mobile/android-ndk-r5b/sources/cxx-stl/gnu-libstdc++/libs/armeabi/include/ -I/data/local/tmp/include
CXX = /home/mat/docs/dev/mobile/android-ndk-r5b/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/bin//arm-linux-androideabi-g++
CXXCPP = /lib/cpp
CXXDEPMODE = depmode=gcc3
CXXFLAGS = --sysroot=/home/mat/docs/dev/mobile/android-ndk-r5b/platforms/android-8/arch-arm/ -Wall -O2 -funroll-loops -fexceptions
CYGPATH_W = echo
DEFS = -DHAVE_CONFIG_H
DEPDIR = .deps
DLLEXT = so
DLLTOOL = dlltool
DOCBOOK2X_MAN = 
ECHO = echo
ECHO_C = 
ECHO_N = -n
ECHO_T = 
EGREP = /bin/grep -E
EXEEXT = 
F77 = gfortran
FFLAGS = -g -O2
FULLNAME = mat
GLUT_CFLAGS = 
GLUT_LIBS = 
GLU_CFLAGS = 
GLU_LIBS = 
GL_CFLAGS = 
GL_LIBS = 
GREP = /bin/grep
GTK_CONFIG = 
GTK_LIBS = 
INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_STRIP_PROGRAM = $(install_sh) -c -s
LDFLAGS = -L/home/mat/docs/dev/mobile/android-ndk-r5b/platforms/android-8/arch-arm//usr/lib -L/data/local/tmp/lib -L/home/mat/docs/dev/mobile/android-ndk-r5b/sources/cxx-stl/gnu-libstdc++/libs/armeabi
LD_EXPORT_DYNAMIC = 
LIBBOINC_VERSION = 6:10:58
LIBEXT = a
LIBOBJS = 

# ignore any LIBS set by configure
LIBS = 
LIBTOOL = $(SHELL) $(top_builddir)/libtool
LN = /bin/ln
LN_S = ln -s
LOGNAME = mat
LTLIBOBJS = 
MAKEINFO = ${SHELL} /home/mat/docs/src/android/native-boinc-for-android/src/boinc-6.10.58/missing --run makeinfo
MKDIR_P = /bin/mkdir -p
MYSQL_CFLAGS = 
MYSQL_CONFIG = 
MYSQL_LIBS = 
OBJC = /home/mat/docs/dev/mobile/android-ndk-r5b/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/bin//arm-linux-androideabi-gcc
OBJCDEPMODE = depmode=none
OBJCFLAGS = -ObjC
OBJDUMP = objdump
OBJEXT = o
PACKAGE = boinc
PACKAGE_BUGREPORT = 
PACKAGE_NAME = BOINC
PACKAGE_STRING = BOINC 6.10.58
PACKAGE_TARNAME = boinc
PACKAGE_URL = 
PACKAGE_VERSION = 6.10.58
PATH_SEPARATOR = :
PICFLAGS =  -fPIC -DPIC
PKGCONFIG = /usr/bin/pkg-config
PTHREAD_CC = /home/mat/docs/dev/mobile/android-ndk-r5b/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/bin//arm-linux-androideabi-gcc
PTHREAD_CFLAGS = 
PTHREAD_LIBS = 
RANLIB = ranlib
RDATE = 2011.07.08
REV = 
SET_MAKE = 
SHELL = /bin/sh
SQLITE3_CPPFLAGS = 
SQLITE3_LIBS = 
SSLDIR = /usr
SSL_CFLAGS =  
SSL_CXXFLAGS =  
SSL_LIBS = -lssl -lcrypto -ldl
STRIP = strip
TOP_BUILD_DIR = /home/mat/docs/src/android/native-boinc-for-android/src/boinc-6.10.58
VERSION = 6.10.58
WHOAMI = /usr/bin/whoami
WX_CFLAGS = 
WX_CFLAGS_ONLY = 
WX_CONFIG_PATH = 
WX_CPPFLAGS = 
WX_CXXFLAGS = 
WX_CXXFLAGS_ONLY = 
WX_LIBS = 
WX_LIBS_STATIC = 
WX_VERSION = 
XMKMF = 
X_CFLAGS = 
X_EXTRA_LIBS = 
X_LIBS =  -L/usr/lib
X_PRE_LIBS = 
abs_builddir = /home/mat/docs/src/android/native-boinc-for-android/src/boinc-6.10.58/tools
abs_srcdir = /home/mat/docs/src/android/native-boinc-for-android/src/boinc-6.10.58/tools
abs_top_builddir = /home/mat/docs/src/android/native-boinc-for-android/src/boinc-6.10.58
abs_top_srcdir = /home/mat/docs/src/android/native-boinc-for-android/src/boinc-6.10.58
ac_ct_CC = 
ac_ct_CXX = 
ac_ct_F77 = gfortran
acx_pthread_config = 
am__include = include
am__leading_dot = .
am__quote = 
am__tar = ${AMTAR} chof - "$$tardir"
am__untar = ${AMTAR} xf -
bindir = ${exec_prefix}/bin
boinc_alt_platform = 
boinc_platform = arm-unknown-linux-gnu
build = x86_64-unknown-linux-gnu
build_alias = 
build_cpu = x86_64
build_os = linux-gnu
build_vendor = unknown
builddir = .
datadir = ${datarootdir}
datarootdir = ${prefix}/share
docdir = ${datarootdir}/doc/${PACKAGE_TARNAME}
dvidir = ${docdir}
exec_prefix = /data/local/tmp
host = arm-unknown-linux-gnu
host_alias = arm-linux
host_cpu = arm
host_os = linux-gnu
host_vendor = unknown
htmldir = ${docdir}
includedir = ${prefix}/include
infodir = ${datarootdir}/info
install_sh = ${SHELL} /home/mat/docs/src/android/native-boinc-for-android/src/boinc-6.10.58/install-sh
libdir = ${exec_prefix}/lib
libexecdir = ${exec_prefix}/libexec
localedir = ${datarootdir}/locale
localstatedir = ${prefix}/var
mandir = ${datarootdir}/man
mkdir_p = /bin/mkdir -p
oldincludedir = /usr/include
pdfdir = ${docdir}
prefix = /data/local/tmp
program_transform_name = s,x,x,
psdir = ${docdir}
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
srcdir = .
sysconfdir = /data/local/tmp/etc
target = arm-unknown-linux-gnu
target_alias = 
target_cpu = arm
target_os = linux-gnu
target_vendor = unknown
top_build_prefix = ../
top_builddir = ..
top_srcdir = ..
RSA_LIBS = -lcrypto
AM_LIBTOOLFLAGS = 
AM_CPPFLAGS = \
        -I$(top_srcdir)/lib			\
        -I$(top_srcdir)/api			\
        -I$(top_srcdir)/db			\
        -I$(top_srcdir)/client			\
        -I$(top_srcdir)/tools			\
        -I$(top_srcdir)/sched			\
        -I$(top_srcdir)/lib/mac			\
	$(PTHREAD_CFLAGS)

AM_CFLAGS = 
AM_CXXFLAGS = $(MYSQL_CFLAGS)
AM_LDFLAGS = -static

# dependencies to make sure libs gets compiled before
# programs linking to them:
LIBSCHED = $(top_builddir)/sched/libsched.la
LIBSCHED_FCGI = $(top_builddir)/sched/libsched_fcgi.la
LIBBOINC = $(top_builddir)/lib/libboinc.la
LIBBOINC_CRYPT = $(top_builddir)/lib/libboinc_crypt.la
LIBBOINC_FCGI = $(top_builddir)/lib/libboinc_fcgi.la
LIBAPI = $(top_builddir)/api/libboinc_api.la
SERVERLIBS = $(LIBSCHED) $(LIBBOINC_CRYPT) $(LIBBOINC) $(MYSQL_LIBS) $(PTHREAD_LIBS) $(RSA_LIBS) $(SSL_LIBS)
SERVERLIBS_FCGI = $(LIBSCHED_FCGI) $(LIBBOINC_CRYPT) $(LIBBOINC_FCGI) -lfcgi $(MYSQL_LIBS) $(PTHREAD_LIBS) $(RSA_LIBS) $(SSL_LIBS)
APPLIBS = $(LIBAPI) $(LIBBOINC)
scheddir = $(libexecdir)/sched
dist_bin_SCRIPTS = \
		calculate_credit_multiplier \
		dbcheck_files_exist \
		grep_logs \
		make_project \
		parse_config \
		update_versions \
		upgrade \
		vote_monitor \
		xadd

dist_sched_SCRIPTS = \
		cleanlogs.sh \
		makelog.sh \
		run_in_ops

create_work_SOURCES = create_work.cpp
create_work_LDADD = $(SERVERLIBS)
sign_executable_SOURCES = sign_executable.cpp
sign_executable_LDADD = $(SERVERLIBS)
dir_hier_path_SOURCES = dir_hier_path.cpp
dir_hier_path_LDADD = $(SERVERLIBS)
dir_hier_move_SOURCES = dir_hier_move.cpp
dir_hier_move_LDADD = $(SERVERLIBS)
all: all-am

.SUFFIXES:
.SUFFIXES: .cpp .lo .o .obj
$(srcdir)/Makefile.in:  $(srcdir)/Makefile.am $(top_srcdir)/Makefile.incl $(am__configure_deps)
	@for dep in $?; do \
	  case '$(am__configure_deps)' in \
	    *$$dep*) \
	      ( cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh ) \
	        && { if test -f $@; then exit 0; else break; fi; }; \
	      exit 1;; \
	  esac; \
	done; \
	echo ' cd $(top_srcdir) && $(AUTOMAKE) --foreign tools/Makefile'; \
	$(am__cd) $(top_srcdir) && \
	  $(AUTOMAKE) --foreign tools/Makefile
.PRECIOUS: Makefile
Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@case '$?' in \
	  *config.status*) \
	    cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh;; \
	  *) \
	    echo ' cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__depfiles_maybe)'; \
	    cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__depfiles_maybe);; \
	esac;

$(top_builddir)/config.status: $(top_srcdir)/configure $(CONFIG_STATUS_DEPENDENCIES)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh

$(top_srcdir)/configure:  $(am__configure_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(ACLOCAL_M4):  $(am__aclocal_m4_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(am__aclocal_m4_deps):
boinc_path_config.py: $(top_builddir)/config.status $(top_srcdir)/py/boinc_path_config.py.in
	cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@
install-binPROGRAMS: $(bin_PROGRAMS)
	@$(NORMAL_INSTALL)
	test -z "$(bindir)" || $(MKDIR_P) "$(DESTDIR)$(bindir)"
	@list='$(bin_PROGRAMS)'; test -n "$(bindir)" || list=; \
	for p in $$list; do echo "$$p $$p"; done | \
	sed 's/$(EXEEXT)$$//' | \
	while read p p1; do if test -f $$p || test -f $$p1; \
	  then echo "$$p"; echo "$$p"; else :; fi; \
	done | \
	sed -e 'p;s,.*/,,;n;h' -e 's|.*|.|' \
	    -e 'p;x;s,.*/,,;s/$(EXEEXT)$$//;$(transform);s/$$/$(EXEEXT)/' | \
	sed 'N;N;N;s,\n, ,g' | \
	$(AWK) 'BEGIN { files["."] = ""; dirs["."] = 1 } \
	  { d=$$3; if (dirs[d] != 1) { print "d", d; dirs[d] = 1 } \
	    if ($$2 == $$4) files[d] = files[d] " " $$1; \
	    else { print "f", $$3 "/" $$4, $$1; } } \
	  END { for (d in files) print "f", d, files[d] }' | \
	while read type dir files; do \
	    if test "$$dir" = .; then dir=; else dir=/$$dir; fi; \
	    test -z "$$files" || { \
	    echo " $(INSTALL_PROGRAM_ENV) $(LIBTOOL) $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=install $(INSTALL_PROGRAM) $$files '$(DESTDIR)$(bindir)$$dir'"; \
	    $(INSTALL_PROGRAM_ENV) $(LIBTOOL) $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=install $(INSTALL_PROGRAM) $$files "$(DESTDIR)$(bindir)$$dir" || exit $$?; \
	    } \
	; done

uninstall-binPROGRAMS:
	@$(NORMAL_UNINSTALL)
	@list='$(bin_PROGRAMS)'; test -n "$(bindir)" || list=; \
	files=`for p in $$list; do echo "$$p"; done | \
	  sed -e 'h;s,^.*/,,;s/$(EXEEXT)$$//;$(transform)' \
	      -e 's/$$/$(EXEEXT)/' `; \
	test -n "$$list" || exit 0; \
	echo " ( cd '$(DESTDIR)$(bindir)' && rm -f" $$files ")"; \
	cd "$(DESTDIR)$(bindir)" && rm -f $$files

clean-binPROGRAMS:
	@list='$(bin_PROGRAMS)'; test -n "$$list" || exit 0; \
	echo " rm -f" $$list; \
	rm -f $$list || exit $$?; \
	test -n "$(EXEEXT)" || exit 0; \
	list=`for p in $$list; do echo "$$p"; done | sed 's/$(EXEEXT)$$//'`; \
	echo " rm -f" $$list; \
	rm -f $$list
create_work$(EXEEXT): $(create_work_OBJECTS) $(create_work_DEPENDENCIES) 
	@rm -f create_work$(EXEEXT)
	$(CXXLINK) $(create_work_OBJECTS) $(create_work_LDADD) $(LIBS)
dir_hier_move$(EXEEXT): $(dir_hier_move_OBJECTS) $(dir_hier_move_DEPENDENCIES) 
	@rm -f dir_hier_move$(EXEEXT)
	$(CXXLINK) $(dir_hier_move_OBJECTS) $(dir_hier_move_LDADD) $(LIBS)
dir_hier_path$(EXEEXT): $(dir_hier_path_OBJECTS) $(dir_hier_path_DEPENDENCIES) 
	@rm -f dir_hier_path$(EXEEXT)
	$(CXXLINK) $(dir_hier_path_OBJECTS) $(dir_hier_path_LDADD) $(LIBS)
sign_executable$(EXEEXT): $(sign_executable_OBJECTS) $(sign_executable_DEPENDENCIES) 
	@rm -f sign_executable$(EXEEXT)
	$(CXXLINK) $(sign_executable_OBJECTS) $(sign_executable_LDADD) $(LIBS)
install-dist_binSCRIPTS: $(dist_bin_SCRIPTS)
	@$(NORMAL_INSTALL)
	test -z "$(bindir)" || $(MKDIR_P) "$(DESTDIR)$(bindir)"
	@list='$(dist_bin_SCRIPTS)'; test -n "$(bindir)" || list=; \
	for p in $$list; do \
	  if test -f "$$p"; then d=; else d="$(srcdir)/"; fi; \
	  if test -f "$$d$$p"; then echo "$$d$$p"; echo "$$p"; else :; fi; \
	done | \
	sed -e 'p;s,.*/,,;n' \
	    -e 'h;s|.*|.|' \
	    -e 'p;x;s,.*/,,;$(transform)' | sed 'N;N;N;s,\n, ,g' | \
	$(AWK) 'BEGIN { files["."] = ""; dirs["."] = 1; } \
	  { d=$$3; if (dirs[d] != 1) { print "d", d; dirs[d] = 1 } \
	    if ($$2 == $$4) { files[d] = files[d] " " $$1; \
	      if (++n[d] == $(am__install_max)) { \
		print "f", d, files[d]; n[d] = 0; files[d] = "" } } \
	    else { print "f", d "/" $$4, $$1 } } \
	  END { for (d in files) print "f", d, files[d] }' | \
	while read type dir files; do \
	     if test "$$dir" = .; then dir=; else dir=/$$dir; fi; \
	     test -z "$$files" || { \
	       echo " $(INSTALL_SCRIPT) $$files '$(DESTDIR)$(bindir)$$dir'"; \
	       $(INSTALL_SCRIPT) $$files "$(DESTDIR)$(bindir)$$dir" || exit $$?; \
	     } \
	; done

uninstall-dist_binSCRIPTS:
	@$(NORMAL_UNINSTALL)
	@list='$(dist_bin_SCRIPTS)'; test -n "$(bindir)" || exit 0; \
	files=`for p in $$list; do echo "$$p"; done | \
	       sed -e 's,.*/,,;$(transform)'`; \
	test -n "$$list" || exit 0; \
	echo " ( cd '$(DESTDIR)$(bindir)' && rm -f" $$files ")"; \
	cd "$(DESTDIR)$(bindir)" && rm -f $$files
install-dist_schedSCRIPTS: $(dist_sched_SCRIPTS)
	@$(NORMAL_INSTALL)
	test -z "$(scheddir)" || $(MKDIR_P) "$(DESTDIR)$(scheddir)"
	@list='$(dist_sched_SCRIPTS)'; test -n "$(scheddir)" || list=; \
	for p in $$list; do \
	  if test -f "$$p"; then d=; else d="$(srcdir)/"; fi; \
	  if test -f "$$d$$p"; then echo "$$d$$p"; echo "$$p"; else :; fi; \
	done | \
	sed -e 'p;s,.*/,,;n' \
	    -e 'h;s|.*|.|' \
	    -e 'p;x;s,.*/,,;$(transform)' | sed 'N;N;N;s,\n, ,g' | \
	$(AWK) 'BEGIN { files["."] = ""; dirs["."] = 1; } \
	  { d=$$3; if (dirs[d] != 1) { print "d", d; dirs[d] = 1 } \
	    if ($$2 == $$4) { files[d] = files[d] " " $$1; \
	      if (++n[d] == $(am__install_max)) { \
		print "f", d, files[d]; n[d] = 0; files[d] = "" } } \
	    else { print "f", d "/" $$4, $$1 } } \
	  END { for (d in files) print "f", d, files[d] }' | \
	while read type dir files; do \
	     if test "$$dir" = .; then dir=; else dir=/$$dir; fi; \
	     test -z "$$files" || { \
	       echo " $(INSTALL_SCRIPT) $$files '$(DESTDIR)$(scheddir)$$dir'"; \
	       $(INSTALL_SCRIPT) $$files "$(DESTDIR)$(scheddir)$$dir" || exit $$?; \
	     } \
	; done

uninstall-dist_schedSCRIPTS:
	@$(NORMAL_UNINSTALL)
	@list='$(dist_sched_SCRIPTS)'; test -n "$(scheddir)" || exit 0; \
	files=`for p in $$list; do echo "$$p"; done | \
	       sed -e 's,.*/,,;$(transform)'`; \
	test -n "$$list" || exit 0; \
	echo " ( cd '$(DESTDIR)$(scheddir)' && rm -f" $$files ")"; \
	cd "$(DESTDIR)$(scheddir)" && rm -f $$files

mostlyclean-compile:
	-rm -f *.$(OBJEXT)

distclean-compile:
	-rm -f *.tab.c

include ./$(DEPDIR)/create_work.Po
include ./$(DEPDIR)/dir_hier_move.Po
include ./$(DEPDIR)/dir_hier_path.Po
include ./$(DEPDIR)/sign_executable.Po

.cpp.o:
	$(CXXCOMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $<
	$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po
#	source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXXCOMPILE) -c -o $@ $<

.cpp.obj:
	$(CXXCOMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ `$(CYGPATH_W) '$<'`
	$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po
#	source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXXCOMPILE) -c -o $@ `$(CYGPATH_W) '$<'`

.cpp.lo:
	$(LTCXXCOMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $<
	$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Plo
#	source='$<' object='$@' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(LTCXXCOMPILE) -c -o $@ $<

mostlyclean-libtool:
	-rm -f *.lo

clean-libtool:
	-rm -rf .libs _libs

ID: $(HEADERS) $(SOURCES) $(LISP) $(TAGS_FILES)
	list='$(SOURCES) $(HEADERS) $(LISP) $(TAGS_FILES)'; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '{ files[$$0] = 1; nonempty = 1; } \
	      END { if (nonempty) { for (i in files) print i; }; }'`; \
	mkid -fID $$unique
tags: TAGS

TAGS:  $(HEADERS) $(SOURCES)  $(TAGS_DEPENDENCIES) \
		$(TAGS_FILES) $(LISP)
	set x; \
	here=`pwd`; \
	list='$(SOURCES) $(HEADERS)  $(LISP) $(TAGS_FILES)'; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '{ files[$$0] = 1; nonempty = 1; } \
	      END { if (nonempty) { for (i in files) print i; }; }'`; \
	shift; \
	if test -z "$(ETAGS_ARGS)$$*$$unique"; then :; else \
	  test -n "$$unique" || unique=$$empty_fix; \
	  if test $$# -gt 0; then \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      "$$@" $$unique; \
	  else \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      $$unique; \
	  fi; \
	fi
ctags: CTAGS
CTAGS:  $(HEADERS) $(SOURCES)  $(TAGS_DEPENDENCIES) \
		$(TAGS_FILES) $(LISP)
	list='$(SOURCES) $(HEADERS)  $(LISP) $(TAGS_FILES)'; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '{ files[$$0] = 1; nonempty = 1; } \
	      END { if (nonempty) { for (i in files) print i; }; }'`; \
	test -z "$(CTAGS_ARGS)$$unique" \
	  || $(CTAGS) $(CTAGSFLAGS) $(AM_CTAGSFLAGS) $(CTAGS_ARGS) \
	     $$unique

GTAGS:
	here=`$(am__cd) $(top_builddir) && pwd` \
	  && $(am__cd) $(top_srcdir) \
	  && gtags -i $(GTAGS_ARGS) "$$here"

distclean-tags:
	-rm -f TAGS ID GTAGS GRTAGS GSYMS GPATH tags

distdir: $(DISTFILES)
	@srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	topsrcdirstrip=`echo "$(top_srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	list='$(DISTFILES)'; \
	  dist_files=`for file in $$list; do echo $$file; done | \
	  sed -e "s|^$$srcdirstrip/||;t" \
	      -e "s|^$$topsrcdirstrip/|$(top_builddir)/|;t"`; \
	case $$dist_files in \
	  */*) $(MKDIR_P) `echo "$$dist_files" | \
			   sed '/\//!d;s|^|$(distdir)/|;s,/[^/]*$$,,' | \
			   sort -u` ;; \
	esac; \
	for file in $$dist_files; do \
	  if test -f $$file || test -d $$file; then d=.; else d=$(srcdir); fi; \
	  if test -d $$d/$$file; then \
	    dir=`echo "/$$file" | sed -e 's,/[^/]*$$,,'`; \
	    if test -d "$(distdir)/$$file"; then \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    if test -d $(srcdir)/$$file && test $$d != $(srcdir); then \
	      cp -fpR $(srcdir)/$$file "$(distdir)$$dir" || exit 1; \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    cp -fpR $$d/$$file "$(distdir)$$dir" || exit 1; \
	  else \
	    test -f "$(distdir)/$$file" \
	    || cp -p $$d/$$file "$(distdir)/$$file" \
	    || exit 1; \
	  fi; \
	done
check-am: all-am
check: check-am
all-am: Makefile $(PROGRAMS) $(SCRIPTS)
installdirs:
	for dir in "$(DESTDIR)$(bindir)" "$(DESTDIR)$(bindir)" "$(DESTDIR)$(scheddir)"; do \
	  test -z "$$dir" || $(MKDIR_P) "$$dir"; \
	done
install: install-am
install-exec: install-exec-am
install-data: install-data-am
uninstall: uninstall-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am

installcheck: installcheck-am
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	  install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	  `test -z '$(STRIP)' || \
	    echo "INSTALL_PROGRAM_ENV=STRIPPROG='$(STRIP)'"` install
mostlyclean-generic:

clean-generic:

distclean-generic:
	-test -z "$(CONFIG_CLEAN_FILES)" || rm -f $(CONFIG_CLEAN_FILES)
	-test . = "$(srcdir)" || test -z "$(CONFIG_CLEAN_VPATH_FILES)" || rm -f $(CONFIG_CLEAN_VPATH_FILES)

maintainer-clean-generic:
	@echo "This command is intended for maintainers to use"
	@echo "it deletes files that may require special tools to rebuild."
clean: clean-am

clean-am: clean-binPROGRAMS clean-generic clean-libtool mostlyclean-am

distclean: distclean-am
	-rm -rf ./$(DEPDIR)
	-rm -f Makefile
distclean-am: clean-am distclean-compile distclean-generic \
	distclean-tags

dvi: dvi-am

dvi-am:

html: html-am

html-am:

info: info-am

info-am:

install-data-am: install-dist_schedSCRIPTS

install-dvi: install-dvi-am

install-dvi-am:

install-exec-am: install-binPROGRAMS install-dist_binSCRIPTS

install-html: install-html-am

install-html-am:

install-info: install-info-am

install-info-am:

install-man:

install-pdf: install-pdf-am

install-pdf-am:

install-ps: install-ps-am

install-ps-am:

installcheck-am:

maintainer-clean: maintainer-clean-am
	-rm -rf ./$(DEPDIR)
	-rm -f Makefile
maintainer-clean-am: distclean-am maintainer-clean-generic

mostlyclean: mostlyclean-am

mostlyclean-am: mostlyclean-compile mostlyclean-generic \
	mostlyclean-libtool

pdf: pdf-am

pdf-am:

ps: ps-am

ps-am:

uninstall-am: uninstall-binPROGRAMS uninstall-dist_binSCRIPTS \
	uninstall-dist_schedSCRIPTS

.MAKE: install-am install-strip

.PHONY: CTAGS GTAGS all all-am check check-am clean clean-binPROGRAMS \
	clean-generic clean-libtool ctags distclean distclean-compile \
	distclean-generic distclean-libtool distclean-tags distdir dvi \
	dvi-am html html-am info info-am install install-am \
	install-binPROGRAMS install-data install-data-am \
	install-dist_binSCRIPTS install-dist_schedSCRIPTS install-dvi \
	install-dvi-am install-exec install-exec-am install-html \
	install-html-am install-info install-info-am install-man \
	install-pdf install-pdf-am install-ps install-ps-am \
	install-strip installcheck installcheck-am installdirs \
	maintainer-clean maintainer-clean-generic mostlyclean \
	mostlyclean-compile mostlyclean-generic mostlyclean-libtool \
	pdf pdf-am ps ps-am tags uninstall uninstall-am \
	uninstall-binPROGRAMS uninstall-dist_binSCRIPTS \
	uninstall-dist_schedSCRIPTS

$(LIBSCHED):
	cd $(top_builddir)/sched; ${MAKE} libsched.la
$(LIBSCHED_FCGI):
	cd $(top_builddir)/sched; ${MAKE} libsched_fcgi.la
$(LIBBOINC):
	cd $(top_builddir)/lib; ${MAKE} libboinc.la
$(LIBBOINC_CRYPT):
	cd $(top_builddir)/lib; ${MAKE} libboinc.la
$(LIBBOINC_FCGI):
	cd $(top_builddir)/lib; ${MAKE} libboinc_fcgi.la
$(LIBAPI):
	cd $(top_builddir)/api; ${MAKE} libboinc_api.la

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
