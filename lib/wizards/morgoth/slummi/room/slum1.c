inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/morgoth/slummi/npc/child");
    move_object(monster, this_object());
  }
  if(arg) return;
 
  add_exit("west","/world/city/silver7");
  add_exit("east","/wizards/morgoth/slummi/room/slum2.c");
  short_desc = "Entrance to the slums.";
  long_desc = "You are about to enter in the town slums.\n"+
              "The smell of death lingers in the air.\n"+
              "Maybe you should turn back.\n";
 }
