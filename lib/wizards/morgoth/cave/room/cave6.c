inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/morgoth/cave/npc/slave");
    move_object(monster, this_object());
   }
  if(arg) return;
 
  add_exit("northwest","/wizards/morgoth/cave/room/cave5");
  short_desc = "Nothing here yet...";
  long_desc = "Desc's not available yet.\n";
 
}
