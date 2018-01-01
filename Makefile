%.o: %.c
	gcc -c -fPIC $^ -o $@
lib%.so: %.o
	gcc -shared $^ -o $@
lib%.a: %.o
	ar -rcs $@ $^

