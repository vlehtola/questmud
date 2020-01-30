inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/morgoth/cave/npc/slave");
    move_object(monster, this_object());
   }
  if(arg) return;
 
  add_exit("north","/wizards/morgoth/cave/room/cave9");
  add_exit("south","/wizards/morgoth/cave/room/cave10");
  add_exit("west","/wizards/morgoth/cave/room/cave7");
  add_exit("east","/wizards/morgoth/cave/room/cave11");
  short_desc = "Nothing here yet...";
  long_desc = "Desc's not available yet.\n";
 
}
