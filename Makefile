CC = clang

## Debug Options
DFLAGS = -fsanitize=address -g

## Optimization Options
OFLAGS  = -O1 -fstack-protector-all

## Code Generation Options
GFLAGS  = -ftrapv

## Preprocessor Options
PFLAGS  = -Wendif-labels -Wunused-macros

## Warning Options
WFLAGS  = -Wall -Wextra -Wpedantic # essential

WFLAGS += -Wformat=2

WFLAGS += -Waggregate-return -Wcast-align -Wcast-qual -Wconversion
WFLAGS += -Wdisabled-optimization -Wdouble-promotion -Wfloat-equal -Winit-self
WFLAGS += -Winline -Winvalid-pch -Wmissing-declarations
WFLAGS += -Wmissing-format-attribute -Wmissing-include-dirs -Wpacked -Wpadded
WFLAGS += -Wredundant-decls -Wstack-protector -Wstrict-overflow=5
WFLAGS += -Wswitch-default -Wswitch-enum -Wundef -Wvla -Wwrite-strings

# For testing only, comment out for production
WFLAGS += -Wshadow #-Werror

### C only
CWFLAGS  = -Wc++-compat

CWFLAGS += -Wbad-function-cast -Wdeclaration-after-statement
CWFLAGS += -Wmissing-prototypes -Wnested-externs -Wold-style-definition
CWFLAGS += -Wstrict-prototypes

### GNU only (enable manually if you switch to gcc/g++ as compiler)
GNUWFLAGS  = -Wlogical-op -Wnormalized=nfc -Wpacked-bitfield-compat -Wsync-nand
GNUWFLAGS += -Wtrampolines -Wunsafe-loop-optimizations

# GNU, C only (enable manually if you switch to gcc/g++ as compiler)
GNUCWFLAGS = -Wtraditional-conversion -Wunsuffixed-float-constants


COMMONFLAGS = $(OFLAGS) $(GFLAGS) $(PFLAGS) $(WFLAGS) $(DFLAGS)


CFLAGS    = -std=gnu11   $(COMMONFLAGS) $(CWFLAGS)
LDFLAGS	  = -lpthread

EXEC = broadcaster client getip ieee754 listener pack pack2 pack2b select \
       selectserver server showip talker

.PHONY: all clean
all: $(EXEC)

clean:
	rm -f $(EXEC)
