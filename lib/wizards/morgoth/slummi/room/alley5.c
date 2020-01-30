inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/morgoth/slummi/npc/dog");
    move_object(monster, this_object());
  }
  if(arg) return;
 
  add_exit("northeast","/wizards/morgoth/slummi/room/slum9");
  add_exit("northwest","/wizards/morgoth/slummi/room/alley6");
  short_desc = "A murky alley.";
  long_desc = "There is nothing special in this place.\n"+
              "This is just an ordinary dark alley.\n";
 
 }
