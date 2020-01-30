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

        add_exit("west","/world/city/silcop1.c");
        add_exit("east","/world/city/copper1.c");

    short_desc = "On a street Between Copper and Silver";
    long_desc = "########### This is a small crossing street between Copper and Silver\n" + 
		"#WWWWWWWWW# streets. This is the poorest place in the city. There are\n" +
		"#-+--*--+W# only old and broken buildings. The poorest people of the\n" + 
		"# Qw    |W# city are living in these buildings. Silver street is located\n" +
		"########### west from here and Copper street is to the east. The large\n" +
		"north-east wall is next to you, proudly guarding the city from bandits\n" +
		"and thieves.\n";
  set_light(3);

}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/x/20");
   return 1;
}
