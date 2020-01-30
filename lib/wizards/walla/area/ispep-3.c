#include "room.h" 
#undef EXTRA_RESET
#define EXTRA_RESET\
        set_not_out(1);
 
int dust_blown, manhole_open;
 
init() {
  ::init();
  add_action("blow", "move");
  add_action("blow", "blow");
  add_action("open", "open");
  add_action("eat", "kick");
  add_action("jump", "jump");
  add_action("close", "close");
}
 close(str) {
  if(str == "manhole") {
    if(manhole_open) {
      write("You carefully close the manhole.\n");
      say(this_player()->query_name()+" closes the manhole.\n");
      manhole_open = 0;
      return 1;
    } else {
      write("It's already closed.\n");
      return 1;
    }
  }
}
 
jump(str) {
            
   if(manhole_open) {
    write("You jump down into the hole, and hear the lid slamming behind you.\n");
    say(this_player()->query_name()+" jumps in a hole and the lid closes behind "+
        "it.\n");
    manhole_open = 0;
    move_object(this_player(), "/wizards/walla/area/testi/lebi");
    say(this_player()->query_name()+" falls out of the air.\n");
    return 1;
  }
}
 
open(str) {
  if(dust_blown) {
    write("You open the manhole and discover another big hole in it.\n");
    manhole_open = 1;
    return 1;
   }
}
 
long(str) {
  ::long(str);
  if(str == "manhole") {
    if(manhole_open) {
      write("A big, dark, unexplored hole. It's very deep, but I think one could JUMP there to "+
            "get where it leads.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "manhole") {
  if(dust_blown) {   
      write("A dirty manhole. A rusty handle is attached to it.\n");
      return 1;
    } else {
      write("say what?\n");
      return 1;
    }
  }
  if(str == "handle") {
    if(dust_blown) {
      write("This is a handle. "+
            "It's rusty, but one could still open the hole with it.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
     }
  }
  if(str == "dust" || str == "sand") {
    if(dust_blown) {
      write("The dust covered that hole completly... "+
            "I think you should do it again!\n");
      return 1;
    } else {
      write("Just dust, and wait a minute, it looks like there is something under it.\n");     
return 1;
    }
  }
}
 
id(str) {
  if(str == "manhole") { return 1; }
  if(str == "handle") { return 1; }                 
  if(str == "hole") { return 1; }
  if(str == "dust" || str == "sand") { return 1; }
}
 
blow(str) {
  if(str == "dust" || str == "sand") {
    if (dust_blown) { hide("manhole"); return 1; }
    write("You blow the dust away and discover to your surprise ... a manhole.\n");
    say(capitalize(this_player()->query_name())+" gently blows the dust away only to reveal "+
            "a manhole under it.\n");
    dust_blown = 1;
    return 1;
  }
}
  
 hide(str) {
  if(str == "manhole") {
    if (dust_blown) {
      write("You smear the dust back to it's place.\n");
      say(capitalize(this_player()->query_name())+ " quickly puts the dust back "+
          "from where it came.\n");
      dust_blown = 0;
      return 1;
    } else {
      write("The manhole is now securely hidden. No one will know you went here.\n");
      return 1;
    }
  }
}
 
 TWO_EXIT( "/wizards/walla/area/ispep-2", "east",
           "wizards/walla/area/ispep-4", "west",
           "On Ispep Street",
           "You are at the old sewer entrance. It seems\n" +         
           "that someone has been here recently. At least the \n" +
           "dust has been recently moved. \n", 3)



