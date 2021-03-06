#############################################################################
# Makefile for building: project1
# Generated by qmake (2.01a) (Qt 4.8.5) on: Sun Jul 2 12:47:20 2017
# Project:  project1.pro
# Template: app
# Command: /usr/local/Trolltech/Qt-4.8.5/bin/qmake -spec /usr/local/Trolltech/Qt-4.8.5/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile project1.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/local/Trolltech/Qt-4.8.5/mkspecs/linux-g++ -I. -I/usr/local/Trolltech/Qt-4.8.5/include/QtCore -I/usr/local/Trolltech/Qt-4.8.5/include/QtGui -I/usr/local/Trolltech/Qt-4.8.5/include/QtOpenGL -I/usr/local/Trolltech/Qt-4.8.5/include -I. -I/usr/X11R6/include -I.
LINK          = g++
LFLAGS        = -Wl,-rpath,/usr/local/Trolltech/Qt-4.8.5/lib
LIBS          = $(SUBLIBS)  -L/usr/local/Trolltech/Qt-4.8.5/lib -L/usr/X11R6/lib -lQtOpenGL -L/usr/local/Trolltech/Qt-4.8.5/lib -L/usr/X11R6/lib -lQtGui -lQtCore -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/local/Trolltech/Qt-4.8.5/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = addressview.cpp \
		bitslider.cpp \
		cachesimulator.cpp \
		graphicsview.cpp \
		main.cpp \
		mainwindow.cpp \
		parametersview.cpp \
		resultsview.cpp \
		simulationcontrolsview.cpp \
		traceview.cpp \
		plotview.cpp moc_addressview.cpp \
		moc_bitslider.cpp \
		moc_cachesimulator.cpp \
		moc_mainwindow.cpp \
		moc_parametersview.cpp \
		moc_resultsview.cpp \
		moc_traceview.cpp \
		moc_plotview.cpp
OBJECTS       = addressview.o \
		bitslider.o \
		cachesimulator.o \
		graphicsview.o \
		main.o \
		mainwindow.o \
		parametersview.o \
		resultsview.o \
		simulationcontrolsview.o \
		traceview.o \
		plotview.o \
		moc_addressview.o \
		moc_bitslider.o \
		moc_cachesimulator.o \
		moc_mainwindow.o \
		moc_parametersview.o \
		moc_resultsview.o \
		moc_traceview.o \
		moc_plotview.o
DIST          = /usr/local/Trolltech/Qt-4.8.5/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/gcc-base.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/gcc-base-unix.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/g++-base.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/g++-unix.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/debug.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/declarative_debug.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/shared.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/unix/opengl.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/include_source_dir.prf \
		project1.pro
QMAKE_TARGET  = project1
DESTDIR       = 
TARGET        = project1

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: project1.pro  /usr/local/Trolltech/Qt-4.8.5/mkspecs/linux-g++/qmake.conf /usr/local/Trolltech/Qt-4.8.5/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/gcc-base.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/gcc-base-unix.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/g++-base.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/g++-unix.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/debug.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/declarative_debug.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/shared.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/unix/opengl.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/include_source_dir.prf \
		/usr/local/Trolltech/Qt-4.8.5/lib/libQtOpenGL.prl \
		/usr/local/Trolltech/Qt-4.8.5/lib/libQtGui.prl \
		/usr/local/Trolltech/Qt-4.8.5/lib/libQtCore.prl
	$(QMAKE) -spec /usr/local/Trolltech/Qt-4.8.5/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile project1.pro
/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/unix.conf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/linux.conf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/gcc-base.conf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/gcc-base-unix.conf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/g++-base.conf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/g++-unix.conf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/qconfig.pri:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt_functions.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt_config.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/exclusive_builds.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/default_pre.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/debug.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/default_post.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/declarative_debug.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/shared.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/warn_on.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/unix/opengl.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/unix/thread.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/moc.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/resources.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/uic.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/yacc.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/lex.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/include_source_dir.prf:
/usr/local/Trolltech/Qt-4.8.5/lib/libQtOpenGL.prl:
/usr/local/Trolltech/Qt-4.8.5/lib/libQtGui.prl:
/usr/local/Trolltech/Qt-4.8.5/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/local/Trolltech/Qt-4.8.5/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile project1.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/project11.0.0 || $(MKDIR) .tmp/project11.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/project11.0.0/ && $(COPY_FILE) --parents addressview.h bitslider.h cachesimulator.h graphicsview.h mainwindow.h parametersview.h resultsview.h simulationcontrolsview.h traceview.h plotview.h .tmp/project11.0.0/ && $(COPY_FILE) --parents addressview.cpp bitslider.cpp cachesimulator.cpp graphicsview.cpp main.cpp mainwindow.cpp parametersview.cpp resultsview.cpp simulationcontrolsview.cpp traceview.cpp plotview.cpp .tmp/project11.0.0/ && (cd `dirname .tmp/project11.0.0` && $(TAR) project11.0.0.tar project11.0.0 && $(COMPRESS) project11.0.0.tar) && $(MOVE) `dirname .tmp/project11.0.0`/project11.0.0.tar.gz . && $(DEL_FILE) -r .tmp/project11.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_addressview.cpp moc_bitslider.cpp moc_cachesimulator.cpp moc_mainwindow.cpp moc_parametersview.cpp moc_resultsview.cpp moc_traceview.cpp moc_plotview.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_addressview.cpp moc_bitslider.cpp moc_cachesimulator.cpp moc_mainwindow.cpp moc_parametersview.cpp moc_resultsview.cpp moc_traceview.cpp moc_plotview.cpp
moc_addressview.cpp: addressview.h
	/usr/local/Trolltech/Qt-4.8.5/bin/moc $(DEFINES) $(INCPATH) addressview.h -o moc_addressview.cpp

moc_bitslider.cpp: bitslider.h
	/usr/local/Trolltech/Qt-4.8.5/bin/moc $(DEFINES) $(INCPATH) bitslider.h -o moc_bitslider.cpp

moc_cachesimulator.cpp: cachesimulator.h
	/usr/local/Trolltech/Qt-4.8.5/bin/moc $(DEFINES) $(INCPATH) cachesimulator.h -o moc_cachesimulator.cpp

moc_mainwindow.cpp: traceview.h \
		parametersview.h \
		bitslider.h \
		cachesimulator.h \
		simulationcontrolsview.h \
		resultsview.h \
		graphicsview.h \
		plotview.h \
		mainwindow.h
	/usr/local/Trolltech/Qt-4.8.5/bin/moc $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_parametersview.cpp: bitslider.h \
		cachesimulator.h \
		simulationcontrolsview.h \
		parametersview.h
	/usr/local/Trolltech/Qt-4.8.5/bin/moc $(DEFINES) $(INCPATH) parametersview.h -o moc_parametersview.cpp

moc_resultsview.cpp: cachesimulator.h \
		resultsview.h
	/usr/local/Trolltech/Qt-4.8.5/bin/moc $(DEFINES) $(INCPATH) resultsview.h -o moc_resultsview.cpp

moc_traceview.cpp: traceview.h
	/usr/local/Trolltech/Qt-4.8.5/bin/moc $(DEFINES) $(INCPATH) traceview.h -o moc_traceview.cpp

moc_plotview.cpp: plotview.h
	/usr/local/Trolltech/Qt-4.8.5/bin/moc $(DEFINES) $(INCPATH) plotview.h -o moc_plotview.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

addressview.o: addressview.cpp addressview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o addressview.o addressview.cpp

bitslider.o: bitslider.cpp bitslider.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bitslider.o bitslider.cpp

cachesimulator.o: cachesimulator.cpp cachesimulator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cachesimulator.o cachesimulator.cpp

graphicsview.o: graphicsview.cpp graphicsview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o graphicsview.o graphicsview.cpp

main.o: main.cpp mainwindow.h \
		traceview.h \
		parametersview.h \
		bitslider.h \
		cachesimulator.h \
		simulationcontrolsview.h \
		resultsview.h \
		graphicsview.h \
		plotview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		traceview.h \
		parametersview.h \
		bitslider.h \
		cachesimulator.h \
		simulationcontrolsview.h \
		resultsview.h \
		graphicsview.h \
		plotview.h \
		addressview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

parametersview.o: parametersview.cpp parametersview.h \
		bitslider.h \
		cachesimulator.h \
		simulationcontrolsview.h \
		addressview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o parametersview.o parametersview.cpp

resultsview.o: resultsview.cpp resultsview.h \
		cachesimulator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o resultsview.o resultsview.cpp

simulationcontrolsview.o: simulationcontrolsview.cpp simulationcontrolsview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o simulationcontrolsview.o simulationcontrolsview.cpp

traceview.o: traceview.cpp traceview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o traceview.o traceview.cpp

plotview.o: plotview.cpp plotview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o plotview.o plotview.cpp

moc_addressview.o: moc_addressview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_addressview.o moc_addressview.cpp

moc_bitslider.o: moc_bitslider.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_bitslider.o moc_bitslider.cpp

moc_cachesimulator.o: moc_cachesimulator.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_cachesimulator.o moc_cachesimulator.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_parametersview.o: moc_parametersview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_parametersview.o moc_parametersview.cpp

moc_resultsview.o: moc_resultsview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_resultsview.o moc_resultsview.cpp

moc_traceview.o: moc_traceview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_traceview.o moc_traceview.cpp

moc_plotview.o: moc_plotview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_plotview.o moc_plotview.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

