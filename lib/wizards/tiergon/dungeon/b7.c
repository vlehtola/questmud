inherit "room/room";
object monster,monster2,monster3;

reset(arg) {
   if (!monster) {
   monster = clone_object("/wizards/tiergon/dungeon/monsters/bcpriest2");
   move_object(monster, this_object()); }
   if (!monster2) {
   monster2 = clone_object("/wizards/tiergon/dungeon/monsters/bchpriest");
   move_object(monster2, this_object()); }
   if (!monster3) {
   monster3 = clone_object("/wizards/tiergon/dungeon/monsters/bcpriest2");
   move_object(monster3, this_object()); }
set_not_out(3);
add_exit("east","/wizards/tiergon/dungeon/b6");
  short_desc = "The altar";
  long_desc = "This is the dark heart of the chapel. A smattering of offerings have been thrown on the altar.\n";
}
