#include "room.h" 
#undef EXTRA_RESET
#define EXTRA_RESET\
        set_not_out(1);
 
int wall_searched, wall_open;
 
init() {
  ::init();
  add_action("search", "search");
  add_action("pull", "pull");
  add_action("open", "open");
  add_action("eat", "kick");
  add_action("enter", "enter");
  add_action("close", "close");
}
 twist(str) {
  if(str == "pull") {
    if(wall_open) {
      write("You trigger the mechanism, closing the secret door.\n");
      say(this_player()->query_name()+" operates the mechanism, and closes the door.\n");
      wall_open = 0;
      return 1;
    } else {
      write("It's already closed.\n");
      return 1;
    }
  }
}
 
enter(str) {
            
   if(wall_open) {
    write("You step inside the wall, but accidentaly step on a button, and the wall closes behind you\n");
    say(this_player()->query_name()+" enters the wall, and suddenly the wall "+
        "quickly closes.\n");
    wall_open = 0;
    move_object(this_player(), "/wizards/walla/workroom");
    say(this_player()->query_name()+" arrives through the wall.\n");
    return 1;
  }
}
 
pull(str) {
  if(wall_searched) {
    write("You pull the lever, and a part of the wall moves.\n");
    wall_open = 1;
    return 1;
  }
}
 
long(str) {
  ::long(str);
  if(str == "wall") {
    if(wall_open) {
      write("The lever has revealed a secret passage in the wall. You cannot see through it"+
            "to figure out where it leads.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "wall") {
  if(wall_searched) {   
      write("The wall has a hole in it, with something that looks like a lever.\n");
      return 1;
    } else {
      write("The wall is made of tiles, and is completely solid, or is it?\n");
      return 1;
    }
  }
  if(str == "lever") {
    if(wall_searched) {
      write("It's a lever. "+
            "Apparently one may pull it.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "wall" || str == "wall") {
    if(wall_searched) {
      write("You have already searched the wall,"+
            "and found the lever\n");
      return 1;
    } else {
      write("You search the wall, and find a hidden lever, disguised as a chandelier.\n");     
return 1;
    }
  }
}
 
id(str) {
  if(str == "lever") { return 1; }

 if(str == "lever") { return 1; }                 
  if(str == "wall") { return 1; }
  if(str == "wall" || str == "wall") { return 1; }
}
 
search(str) {
  if(str == "wall" || str == "wall") {
    if (wall_searched) { hide("lever"); return 1; }
    write("As you search the wall, your eyes fall upon a lever disguised as a chandelier.\n");
    say(capitalize(this_player()->query_name())+" searches the wall, and starts inspecting "+
            "a lever.\n");
    wall_searched = 1;
    return 1;
  }
}
  
  hide(str) {
  if(str == "lever") {
    if (wall_searched) {
      write("You put the lever back into position.\n");
      say(capitalize(this_player()->query_name())+ " twists the lever back to an "+
          "upright position.\n");
      wall_searched = 0;
      return 1;
    } else {
      write("The chandelier is now just as it was.\n");
      return 1;
    }
  }
}
 
 TWO_EXIT( "/wizards/walla/workroom", "east",
           "wizards/walla/void", "west",
           "in the temple",
           "jeejee, sein�ss� on melkeen reik�\n" +         
           "that someone has been here recently. At least the \n" +
           "dust has been recently moved. \n", 3)



