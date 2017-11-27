ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

target=8iterator-adapter 8compose 8functor-adapter 8memfun-adapter



all:$(target)
	
8iterator-adapter : 8iterator-adapter.o
	$(CXX) $^ -o $@ 
	@echo "complie 三种 iterator adpter 大成..."

8functor-adapter : 8functor-adapter.o
	$(CXX) $^ -o $@ 
	@echo "complie 函数配接..."

8memfun-adapter : 8memfun-adapter.o
	$(CXX) $^ -o $@ 
	@echo "complie 成员函数配接..."

8compose : 8compose.o
	$(CXX) $^ -o $@ 
	@echo "complie 组合算法与配接器..."

3find : 3find.o
	$(CXX) $^ -o $@ 
	@echo "complie 通过迭代器进行查找..."




%.o:%.cpp
	$(CXX) -c $^ -o $@ -I./ -I/usr/include/c++/5
      
clean :
	rm $(target)
	rm *.o

.PHONY : all clean
