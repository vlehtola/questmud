inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/morgoth/slummi/npc/dude");
    move_object(monster, this_object());
  }
  if(arg) return;
 
  add_exit("southeast","/wizards/morgoth/slummi/room/alley1");
  short_desc = "A dead end.";
  long_desc = "You are standing at the end of alley.\n"+
              "There is a bloodstains on the walls and ground.\n"+
              "This place is so scary that you are pissing in\n"+
              "your pants\n";
 }
