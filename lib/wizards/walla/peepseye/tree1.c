#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
        set_not_out(1);

int branch_broken, hole_stuffed;

init() 
  ::init();
  add_action("break", "break");
  add_action("stuff", "stuff");
  add_action("open", "open");
  add_action("climb", "climb");
  add_action("climb", "go");
  add_action("close", "close");
}
 close(str) {
  if(str == "lid") {
    if(lid_open) {
      write("You slam the lid close.\n");
      say(this_player()->query_name()+" slams the lid shut.\n");
      lid_open = 0;
      return 1;
    } else {
      write("What ?\n");
      return 1;
    }
  }
}

climb(str) {
  if(lid_open) {
    write("You grab hold of the rope, and start climbing up.\n");
    say(this_player()->query_name()+" hops up and catches the swinging rope "+
        "dissappears, and closes the lid.\n");
    lid_open = 0;
    move_object(this_player(), "/wizards/walla/peepseye/treeup");
    say(this_player()->query_name()+" pops a head up and hauls himself up on the ledge.\n");
    return 1;
  }
}

open(str) {
  if(hole_stuffed) {
    write("You open the lid above your head, and a rope falls down.\n");
    lid_open = 1;
    return 1;
  }
}

long(str) {
  ::long(str);
  if(str == "lid") {
    if(lid_open) {
      write("The lid has been opened and you see a climbing rope, filled with knots to climb "+
            "on. You see a small room up ahead wherefrom you hear commotion of some sort.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "branch") {
if(branch_broken) {
      write("Now that the branch is broken, goo flows out of the hole. It might be useful ?\n");
      return 1;
    } else {
      write("A small branch on the inside of the tree. Wait a minute, there are none inside ?\n");
      return 1;
    }
  }
  if(str == "hole") {
    if(branch_broken) {
      write("This is a hole, and you see some triggering mechanism in it. "+
            "Maybe one could stuff it with something.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
     }
  }
  if(str == "branch" || str == "branch") {
    if(branch_broken) {
      write("The branch has fallen to the ground and now some goo flows out of the" +
            "hole it left.\n");
      return 1;
    } else {
      write("a branch, where someone has hung his coat.\n");
return 1;
    }
  }
}

id(str) {
 if(str == "branch") { return 1; }
 if(str == "hole") { return 1; }
  if(str == "ladder") { return 1; }
  if(str == "branch" || str == "photo") { return 1; }
}

break(str) {
  if(str == "branch" || str == "branch") {
    if (branch_broken) { hide("lid"); return 1; 
    write("As you touch the branch, it suddenly moves a bit, and a falls to the ground.");
    say(capitalize(this_player()->query_name())+" touches the branch, hands the whole thing,
and brakes it.\n");
    lid_open = 1;
    return 1;
  }
}

 hide(str) {
  if(str == "branch") {
    if (branch_moved) {
      write("You put the branch back in an upright position.\n");
      say(capitalize(this_player()->query_name())+ " skillfully corrects the place of the"+
          "branch, making it look like when you arrived.\n");
      branch_moved = 0;
      return 1;
    } else {
      write("The branch is allready ok.\n");
      return 1;
    }
  }
}

 ONE_EXIT( "/wizards/walla/peepseye/3", "east",
           "At the bottom of a gigantesque oak",
           "This looks like a huge oak. The tree is filled with holes that some squirrel has\n" +
           "made, and there is a branch pointing directly at you.\n", 1)


