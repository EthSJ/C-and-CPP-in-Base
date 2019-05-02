

CXX = g++
CXXFLAGS = -Wall -O
CPPFLAGS = -I ~/Linux/include

#item name
PROJECTNAME = HW6
#backup stuff
EXECFILE = HW6	#Name of the executable
OBJS = HW6.o #all required object files

#implicit rule
%.o:%.cc
	$(CXX) $(CPPFLAGS) -M -MF $*.P $<
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

all: $(EXECFILE)

#link object files
$(EXECFILE): $(OBJS)
	$(CXX) -o $@ $(OBJS) -pthread -L ~/Linux/lib -lcurses -lcdk -lboost_thread-mt -lboost_system 

clean:
	rm -f $(OBJS) *.P *~ \#*

#Tar. Errors will not display

backup:
	@mkdir -p ~/Linux/backups; chmod 700 ~/Linux/backups
	@$(eval CURDIRNAME := $(shell pwd))
	@$(eval MKBKUPNAME := ~/Linux/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H_%M_%S').tar.gz)
	@echo
	@echo Am working at: $(CURDIRNAME)
	@echo Writing Backup File to: $(MKBKUPNAME)
	@echo
	@-tar -zcf $(MKBKUPNAME) $(CURDIRNAME) --exclude="*~" 2> /dev/null
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!

tarball:
	make backup
	make clean
	tar -czvf ../tarballs/$(PROJECTNAME).tar.gz

-include $(OBJS:%.o=%.P)
