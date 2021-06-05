CXX = g++
CXXFLAGS = -Wall -Werror -I src
CXXFLAGS_T = -Wall -Werror -I thirdparty
CPPFLAGS = -MMD

ANAME = keyn.exe
TNAME = keyntest.exe

#Directories
BIND = bin
SRCD = src
OBJD = obj
TSTD = test
NAMEDIR = keyn
NAMEDIRLIB = keynlib

#EXE PATHS
APATH = $(BIND)/$(ANAME)
TSTPATH = $(BIND)/$(TNAME)

#CPP/HPP/OBJ PATHS
CPPPATH = $(wildcard src/keyn/*.cpp)
CPPTSTPATH = $(wildcard test/*.cpp)
HPPPATH = $(SRCD)/$(NAMEDIRLIB)
#PATSUBST : что меняет, на что меняет, у чего (где) меняет (откуда берёт данные, чтобы их изменить)
OBJPATH = $(patsubst $(SRCD)/$(NAMEDIR)/%.cpp, $(OBJD)/$(NAMEDIR)/%.o, $(CPPPATH))
OBJTSTPATH = $(patsubst $(TSTD)/%.cpp, $(OBJD)/$(TSTD)/%.o, $(CPPTSTPATH))

MLPATH = $(OBJD)/$(NAMEDIR)/mainlib.a

.PHONY : all

all : $(APATH)

$(APATH) : $(MLPATH)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(MLPATH) : $(OBJPATH)
	ar r $@ $^

$(OBJPATH) : $(OBJD)/$(NAMEDIR)/%.o : $(SRCD)/$(NAMEDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : test

test : $(TSTPATH)

$(TSTPATH) : $(OBJTSTPATH) $(MLPATH)
	$(CXX) $(CXXFLAGS_T) $^ -o $@

$(OBJTSTPATH) : $(OBJD)/$(TSTD)/%.o : $(TSTD)/%.cpp
	$(CXX) $(CXXFLAGS_T) -c $(CPPFLAGS) $^ -o $@

.PHONY : clean

clean : 
	$(RM) $(APATH) $(TSTPATH) $(MLPATH)
	find $(OBJD) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJD)/$(TSTD) -name '*.d' -exec $(RM) '{}' \;