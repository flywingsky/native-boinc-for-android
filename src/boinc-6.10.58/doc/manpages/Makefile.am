## -*- mode: makefile; tab-width: 4 -*-

## $Id: Makefile.am 16904 2009-01-13 23:06:02Z korpela $

include $(top_srcdir)/Makefile.incl

if ENABLE_CLIENT
  CLIENT_MANS = boinc.1 boinccmd.1
endif

if ENABLE_MANAGER
  CLIENTGUI_MANS = boincmgr.1
endif

if ENABLE_SERVER
  SERVER_MANS = 
endif

man_MANS = $(CLIENT_MANS) $(CLIENTGUI_MANS) $(SERVER_MANS)

SUFFIXES = .xml .1

.xml.1:
	$(DOCBOOK2X_MAN) $<

all-local: $(man_MANS)

CLEANFILES = $(man_MANS)
