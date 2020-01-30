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

        add_exit("west","/world/city/silcop2.c");
        add_exit("south","/world/city/copper2.c");

    short_desc = "On northern part of Copper street";
    long_desc = "########### This is the Copper street. This part of the city is the \n" + 
		"#WWWWWWWW # poorest. There are only old and broken buildings. The\n" +
		"#--+--* W # poorest people of Duranghom are living in these buildings.\n" + 
		"#     | W # The large Mainstreet of Duranghom is located a little south\n" +
		"########### of here, and unlike this street, it is crowded with travellers\n" +
		"and merchants. The large east wall, located next to you, is proudly\n" + 
		"guarding the city from bandits and thieves.\n";
  set_light(3);
}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/a1");
   return 1;
}
