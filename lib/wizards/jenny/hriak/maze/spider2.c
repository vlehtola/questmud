#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
	extra_reset();

extra_reset() {
  object ob;  
  int i;
  set_not_out(1);
  if(present("spider 3")) return;
  i = random(3)+1;
  while(i>0) {
    move_object(clone_object("/wizards/celtron/maze/monsters/spider"),
	this_object());
    i -= 1;
  }
}

ONE_EXIT("/wizards/celtron/maze/6", "east",
	   "Inside the cave",
	   "There are some spider webs hanging from the ceiling.\n"+
	   "Cave's walls, ceiling and floor are all rough stone.\n" +
	   "The light fades into the darkness of the cave in east.\n", 0)
