inherit "room/room";
object monster;
init() {
   ::init();
   add_action("map", "map");
}

reset(arg) {
if(arg) return;

if (!monster) {
                monster = clone_object("/world/monsters/citizen.c");
                move_object(monster, this_object());
  }

        add_exit("south","/world/city/mainst10.c");
        add_exit("north","/world/city/copper1.c");
        add_exit("west","/clan/clan_room.c");

    short_desc = "On central part of Copper street";
    long_desc = "########### This is the Copper street. This part of the city is the \n" + 
		"#     | W # poorest. There are only old and broken buildings. The\n" +
		"#   Cl* T # poorest people of the city are living in these buildings.\n" + 
		"#  Me | TT# The large Mainstreet of Duranghom is located just south of\n" +
		"########### here, and unlike this street, it is crowded with travellers\n" +
		"and merchants. The large east wall, located next to you, is proudly\n" + 
		"guarding the city from bandits and thieves.\n";
  set_light(3);

}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/a2");
   return 1;
}
