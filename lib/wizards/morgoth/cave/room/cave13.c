inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/morgoth/cave/npc/slave");
    move_object(monster, this_object());
   }
  if(arg) return;
 
  add_exit("west","/wizards/morgoth/cave/room/cave1");
  add_exit("north","/wizards/morgoth/cave/room/cave4");
  add_exit("south","/wizards/morgoth/cave/room/cave5");
  add_exit("east","/wizards/morgoth/cave/room/cave7");
  short_desc = "Nothing here yet...";
  long_desc = "Desc's not available yet.\n";
}
