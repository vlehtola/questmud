inherit "room/room";
inherit "room/door";
object monster;

reset(arg) {
if (!monster) {
   monster = clone_object("/wizards/tiergon/dungeon/monsters/supervisor");
   move_object(monster, this_object()); }
 if(arg) return;
set_not_out(1);
set_door_dir("west","/wizards/tiergon/dungeon/barracks1");
set_door_link("/wizards/tiergon/dungeon/barracks1");
set_door_desc("ordinary wooden ");
short_desc = "Inside an old meat locker";
  long_desc = "Miscellaneous food stuffs were kept in here.\n"+
              "This must have been one of the only places left untouched by the Black Circle.\n";
}

init() {
  ::init();
  door_init();
}
