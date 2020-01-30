inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/morgoth/cave/npc/slave");
    move_object(monster, this_object());
   }
  if(arg) return;
 
  add_exit("west","/wizards/morgoth/cave/room/cave8");
  add_exit("east","/wizards/morgoth/cave/room/cave12");
  short_desc = "Nothing here yet...";
  long_desc = "Desc's not available yet.\n";
 
}

