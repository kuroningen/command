bin/command: src/*.c src/*.h
	$(CC) $? -o $@
