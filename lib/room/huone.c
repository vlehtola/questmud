#include "room.h"

ONE_EXIT("/world/city/cs", "north",
	 "gruntroom",
	 ".\n", 1)

init() {
  ::init();
  add_action("act", "grunt");
}

act() {
  write("You grunt.\n");
  return 1;
}
