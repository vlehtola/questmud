
#include "room.h" 
#undef EXTRA_RESET
#define EXTRA_RESET\
        set_not_out(2);
 
int box_found, box_open;
 
init() {
  add_action("search", "search");
  add_action("pull", "pull");
  add_action("open", "open");
  add_action("pull", "draw");
  add_action("search", "kick");
  add_action("close", "close");
  ::init();
}
close(str) {
  if(str == "box") {
    if(box_open) {
      write("You close the box.\n");
      say(this_player()->query_name()+" closes the box.\n");
      box_open = 0;
      return 1;
    } else {
      write("It's already closed.\n");
      return 1;
    }
  }
}
 
pull(str) {
            
  if(box_open) {
    write("You pull the lever and suddenly you find yourself andreswhere.\n");
    say(this_player()->query_name()+" pulls the lever, and leaving a puff of smoke behind "+
        "him, he is gone.\n");
    box_open = 0;
    move_object(this_player(), "/wizards/walla/strahd/mpath");
    say(this_player()->query_name()+" just suddenly is there.\n");
    return 1;
  }
}
 
open(str) {
  if(box_found) {
    write("You open the box, but a seal breaks, and drops to the floor.\n");
    box_open = 1;
    return 1;
  }
}
 
long(str) {
  ::long(str);
  if(str == "box") {
    if(box_open) {
      write("This red box, has a lever in it. On the lever is a sign, saying 'Caution Users, "+
            "Beware, I Strahd walk the land'.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "lever") {
 if(box_open) {   
      write("A red lever. I think one could pull it.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "handle") {
    if(box_found) {
      write("This is a handle. "+
            "It's rusty, but one could still open the box with it.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "box" || str == "sand") {
    if(box_found) {
      write("The Box is now found"+
            "Close it again, think of something, SCHMUCK.\n");
      return 1;
    } else {
      write("Just dust, and wait a minute, it looks like there is something under it.\n");
      return 1;
    }
  }
}
 
id(str) {
  if(str == "box") { return 1; }
 if(str == "handle") { return 1; }                 
  if(str == "lever") { return 1; }
  if(str == "dust" || str == "rocks") { return 1; }
}
 
search(str) {
  if(str == "box" || str == "sand") {
    if (box_found) { hide("box"); return 1; }
    write("You search the room, and see a red box, hidden on the wall.\n");
    say(capitalize(this_player()->query_name())+" searches stupidly around, and just before giving up"+
            "he sees a big red box on the wall.\n");
    box_found = 1;
    return 1;
  }
}
 
 hide(str) {
  if(str == "box") {
    if (box_found) {
      write("You try vaguely to hide that great red box.\n");
      say(capitalize(this_player()->query_name())+ " attempts to hide the box, "+
          "but fails miserably.\n");
      box_found = 0;
      return 1;
    } else {
      write("The box is well.. hidden.\n");
      return 1;
    }
  }
}
 
ONE_EXIT( "/wizards/walla/strahd/path1", "northeast",
   "In a small guardhouse.",        
         "This looks like a hunting cottage, although on the walls are skulls of dead persons\n" +
         "watching you. Also, strange spellbooks, and pentagons lie on the floor, scattered all\n" +
         "over the floor. There is a shelf, which is marked with a strange language.\n", 2)
