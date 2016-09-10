lib_LTLIBRARIES = liblibdraw-@API_VERSION@.la

liblibdraw_@API_VERSION@_la_SOURCES = \
	libdraw-version.h \
	libdraw.h \
	$(NULL)

liblibdraw_@API_VERSION@_la_CFLAGS = \
	$(LIBDRAW_CFLAGS) \
	$(WARN_CFLAGS) \
	$(NULL)

liblibdraw_@API_VERSION@_la_LIBADD = \
	$(LIBDRAW_LIBS) \
	$(NULL)

liblibdraw_@API_VERSION@_la_LDFLAGS = \
	$(WARN_LDFLAGS) \
	$(NULL)

-include $(top_srcdir)/git.mk
