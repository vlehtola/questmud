inherit "room/room";
object monster;

reset(arg) {
if(!monster) {
    monster = clone_object("/wizards/tiergon/dungeon/monsters/bclord");
    move_object(monster, this_object()); } 
  if(arg) return;
set_not_out(3);
add_exit("west","/wizards/tiergon/dungeon/bclord1");
  short_desc = "The commmander's office";
  long_desc = "This is a brightly lit room, dominated by a large wooden and a map Deleria on north wall.\n";
}
