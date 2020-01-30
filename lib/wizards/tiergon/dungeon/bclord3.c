inherit "room/room";
object monster,monster2;

reset(arg) {
if(!monster) {
    monster = clone_object("/wizards/tiergon/dungeon/monsters/bcamazonian2");
    move_object(monster, this_object()); } 
if(!monster2) {
    monster2 = clone_object("/wizards/tiergon/dungeon/monsters/bcamazonian2");
     move_object(monster2, this_object()); }
  if(arg) return;
set_not_out(3);
add_exit("west","/wizards/tiergon/dungeon/bclord1");
  short_desc = "A guard room";
  long_desc = "This is a brightly lit room, designed to house the commander's private bodyguards.\n";
}
