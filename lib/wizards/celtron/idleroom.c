#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

int barrier;

extra_reset() {
  property = allocate(3);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
}

init() {
  add_action("check", "inn");
  add_action("activate", "touch");
}

activate(str) {
  if (str == "barrier") {
    if(lower_case(this_player()->query_name()) == "celtron") {
      if(barrier) {
	write("You banish the barrier.\n");
	barrier = 0;
	return 1;
      } else {
	write("You raise the barrier.\n");
	barrier = 1;
	return 1;
      }
    } else {
      write("You push the barrier with all your might, but cannot move it!\n");
      return 1;
    }
  }
}

check() {
  if (barrier) {
    write("A magical barrier blocks you way!\n");
    return 1;
  }
  move("inn");
  return 1;
}

ONE_EXIT("/world/city/inn", "inn",
	 "The idleroom",
	 "This is the idleroom.\n", 3)





