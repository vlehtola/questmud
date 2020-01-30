#include "room.h" 
#undef EXTRA_RESET
#define EXTRA_RESET\
        set_not_out(1);
 
int painting_moved, panel_open;
 
init() {
  ::init();
  add_action("push", "break");
  add_action("push", "push");
  add_action("open", "open");
  add_action("descend", "go");
  add_action("descend", "descend");
  add_action("close", "close");
}
close(str) {
  if(str == "panel") {
    if(panel_open) {
      write("You carefully close the panel.\n");
      say(this_player()->query_name()+" slams the panel shut.\n");
      panel_open = 0;
      return 1;
    } else {
      write("What panel ?\n");
      return 1;
    }
  }
}
 
descend(str) {
            
  if(panel_open) {
    write("You grab hold of the staircase that is under the panel, and gently climb down.\n");
    say(this_player()->query_name()+" goes down on the staircase, and  "+
        "dissappears, and closes the panel.\n");
    panel_open = 0;
    move_object(this_player(), "/wizards/walla/kkk/7");
    say(this_player()->query_name()+" climbs down from the staircase.\n");
    return 1;
  }
}
 
open(str) {
  if(painting_moved) {
    write("You open the panel, and see a ladder in it.\n");
    panel_open = 1;
    return 1;
  }
}
 
long(str) {
  ::long(str);
  if(str == "panel") {
    if(panel_open) {
      write("Under this hidden panel door is a ladder. It looks like many people have used"+
            "that ladder, so maybe it isn't dangerous after all to go there.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "painting") {
 if(painting_moved) {   
      write("After you moved that painting, a panel has revealed itself.\n");
      return 1;
    } else {
      write("A beautiful photograph of a Buddish monk burning in the streets of Calcutta.\n");
      return 1;
    }
  }
  if(str == "handle") {
    if(painting_moved) {
      write("This is a handle. "+
            "It's rusty, but one could still open the hole with it.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "painting" || str == "photo") {
    if(painting_moved) {
      write("You should put the painting back as it was."+
            "Otherwise there might be trouble.\n");
      return 1;
    } else {
      write("A beautiful photo, of a buddish monk burning in the streets. But as you touch it, it\n" +
"moves, and a panel pops out from nowhere.\n");      
return 1;
    }
  }
}
 
id(str) {
  if(str == "painting") { return 1; }
 if(str == "panel") { return 1; }                 
  if(str == "ladder") { return 1; }
  if(str == "painting" || str == "photo") { return 1; }
}
 
push(str) {
  if(str == "painting" || str == "photo") {
    if (painting_moved) { hide("panel"); return 1; }
    write("As you touch the painting, it suddenly moves a bit, and a panel pops out of nowhere.\n");
    say(capitalize(this_player()->query_name())+" touches the painting, hands the whole thing, and\n" +
            "finds a panel.\n");
    panel_open = 1;
    return 1;
  }
}
 
 hide(str) {
  if(str == "painting") {
    if (painting_moved) {
      write("You put the painting back in an upright position.\n");
      say(capitalize(this_player()->query_name())+ " skillfully corrects the place of the"+
          "painting, making it look like when you arrived.\n");
      painting_moved = 0;
      return 1;
    } else {
      write("The painting is allready ok.\n");
      return 1;
    }
  }
}
 
TWO_EXIT( "/wizards/walla/kkk/gather_room_23", "south",
           "wizards/walla/kkk/gather_room_22", "southwest",
           "In the northeastern corner of the room",                         
           "This is the northwestern corner, the big stage is right up left to you, and it really is huge.\n" +
           "It looks like someone is going to speak soon, and if they found you here it would be\n" +
           "disasterous. Paintings cover these walls to.\n", 1)

 
