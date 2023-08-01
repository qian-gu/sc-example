############################### Customise #####################################
CURDIR := $(shell pwd)
src_dir := $(CURDIR)/src
inc_dir := $(CURDIR)/include
build_dir := $(CURDIR)/build
target := out

############################### Variables #####################################

CXX := g++
CXXFLAGS := -O3 -I$(inc_dir) -I$(SYSTEMC_HOME)/include
CXXFLAGS += -I$(VCML_HOME)/include
ifdef debug
CXXFLAGS += -g -Wall -DDEBUG
endif
LDLIBS := -lvcml -lmwr
LDLIBS += -lm -lsystemc
LDFLAGS := -L$(VCML_HOME)/lib
LDFLAGS += -L$(SYSTEMC_HOME)/lib-linux64

depdir := $(build_dir)/.deps
DEPFLAGS = -MT $@ -MMD -MP -MF $(depdir)/$*.d

COMPILE.c = $(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c

srcs := $(foreach dir, $(src_dir), $(wildcard $(dir)/*.cpp))
objs := $(addprefix $(build_dir)/, $(addsuffix .o, $(notdir $(basename $(srcs)))))

vpath %.cpp $(src_dir)
vpath %.h $(inc_dir)

############################### Rules #########################################

.PHONY: all rebuild clean

all: $(build_dir)/$(target)

rebuild: clean all

$(build_dir)/$(target): $(objs)
	$(CXX) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(build_dir)/%.o: %.cpp $(depdir)/%.d | $(depdir)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(depdir): ; @mkdir -p $@

DEPFILES := $(addprefix $(depdir)/, $(addsuffix .d, $(notdir $(basename $(srcs)))))
$(DEPFILES):
include $(wildcard $(DEPFILES))

clean:
	$(RM) -rf $(build_dir)
