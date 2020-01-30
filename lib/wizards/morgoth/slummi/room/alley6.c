inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/morgoth/slummi/npc/dude");
    move_object(monster, this_object());
  }
  if(arg) return;
 
  add_exit("southeast","/wizards/morgoth/slummi/room/alley5");
  short_desc = "End of alley.";
  long_desc = "There is nothing more than a brickwall at the north.\n"+
              "Only exit out from here is the southwest.\n";
 
 }
