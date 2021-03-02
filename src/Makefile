# Syntax help from: https://ca282.computing.dcu.ie/06-make.html#_the_final_step

# for building
dst = ../bin

targets = $(addprefix $(dst)/, $(patsubst %.c, %, $(wildcard *.c)))

build: $(targets)
	@true

$(dst)/%: %.c
	gcc -Wall -o $@ $<

# for debug purposes
echo:
	echo $(targets)

clean:
	rm -f $(targets)

.PHONY: echo, clean
