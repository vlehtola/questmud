#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

TWO_EXIT("/world/city/inn", "inn",
          "/world/city/cs", "cs",
          "Da WoRkRoOm O'gReAt SiGgY.",
          "It's a huge hall. There is worktable in the middle of hall.\n"+
          "In the table is a large pile of papers and many pencils.\n"+
          "In wall is beatiful grafits. In the table you can see a Intel\n"+
          "Pentium with huge speakers, mouse like rat and keybord from\n"+  
          "Commodore 64. And also a HUGE pile of coke cans.\n",1) 

extra_reset() { return 1; }
