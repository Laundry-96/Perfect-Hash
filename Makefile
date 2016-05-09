LD = $(shell which g++)
CXX = $(shell which g++)
CXXFLAGS = -Wall -ansi -g
EXE = Project5.out	
OBJS = Project5.o City.o SecondaryHash.o PrimaryHash.o
EC_EXE = Project5EC.out	
EC_OBJS = Project5EC.o City.o SecondaryHash.o PrimaryHash.o
DEPS = $(addprefix .,$(OBJS:.o=.d))

$(EXE): $(DEPS) $(OBJS)
	$(LD) $(LDFLAGS) $(LDLIBS) $(OBJS) -o $@

.%.d: %.cpp
	@$(RM) $@; \
	$(CXX) -MM -MF $@ -MT "$(<:.cpp=.o) $@" -c $(CPPFLAGS) $<

$(OBJS): %.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(EC_OBJS): %.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

serialize: 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) Project5ToBin.cpp -o Project5ToBin.out

EC: $(DEPS) $(EC_OBJS)
	$(LD) $(LDFLAGS) $(LDLIBS) $(EC_OBJS) -o Project5EC.out

runbin: EC
	./Project5EC.out $(FILE)

-include $(DEPS)

run: $(EXE)
	./$(EXE) $(FILE)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(DEPS) $(EXE) $(EX_EXE) $(EC_OBJS)
