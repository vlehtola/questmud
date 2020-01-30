inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/morgoth/slummi/npc/bum");
    move_object(monster, this_object());
  }
  if(arg) return;
 
  add_exit("south","/wizards/morgoth/slummi/room/alley3");
  short_desc = "A smelling place.";
  long_desc = "This is a home of some old bum.\n"+              
              "There is a horrible stench.\n";
 
 }
