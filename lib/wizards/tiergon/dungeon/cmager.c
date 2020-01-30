inherit "room/room";
inherit "room/door"; 
object monster;

reset(arg) {
  if(!monster) {
  monster = clone_object("/wizards/tiergon/dungeon/monsters/bccmage");
  move_object(monster, this_object()); }
if (arg) return;  
  set_door_dir("west","/wizards/tiergon/dungeon/c4");
  set_door_link("/wizards/tiergon/dungeon/cmager");
  set_door_desc("massive bronze "); 
  short_desc = "The Magist's office";  
  long_desc = "The appearance of this room is quite similar to that of the anteroom."+
              "The walls gave been made from a black marble with eerily glowing veins.\n"+
              "The ensemble is rather disconcerting, to say the least.";
  set_not_out(3);
}
init() {
 ::init();
 door_init();
} 

