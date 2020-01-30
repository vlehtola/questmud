#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "window";
    items[1] = "The grove and the impaled corpses of the mages are visible from here";
}

ONE_EXIT("wizards/nalle/area/darvroom","west",
"Eastern part of Darvox's workroom.",
"There is a large oaken desk in one corner of the room. There are\n" +
"miscellaneous magical items on it, with powers unknown. There\n" +
"is also a large mirror on the wall, behind a curtain.\n", 3)

int curtain_open;

init() {
  add_action("open", "open");
  add_action("enter", "enter");
  add_action("close", "close");
  ::init();
}

close(str) {
  if(str == "curtain") {
    if(curtain_open) {
      write("You close the curtain.\n");
      say(this_player()->query_name()+" closes the curtain.\n");
      curtain_open = 0;
      return 1;
    } else {
      write("It's already closed.\n");
      return 1;
    }
  }
}

open(str) {
    write("You open the curtain, and the mirror becomes completely visible.\n");
    curtain_open = 1;
    return 1;
}

enter(str) {
  if(curtain_open) {
    write("Multicolored light surrounds you and you move through in the fabric of space.\n");
    say(this_player()->query_name()+" enters the mirror, closing the curtain "+
        "at the same time.\n");
    curtain_open = 0;
    this_player()->set_quest("darvox_mirror", 3);
    move_object(this_player(), "/wizards/nalle/area/inn.c");
    say(this_player()->query_name()+" drops out of a rip in the fabric of space.\n");
    return 1;
  }
}

long(str) {
  ::long(str);
  if(str == "mirror") {
    if(curtain_open) {
      write("A large mirror, flashing with supernatural "+
            "colours. Maybe you could try entering it..\n");
      return 1;
    } else {
      write("You cannot see the mirror. It is behind the curtain!\n");
      return 1;
    }
  }
  if(str == "curtain") {
      write("A wine red satin curtain. Maybe you could try opening it.\n");
      return 1;
  }
}

id(str) {
  if(str == "mirror") { return 1; }
  if(str == "curtain") { return 1; }
}






