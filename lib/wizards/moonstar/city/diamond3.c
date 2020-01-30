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

        add_exit("north","/world/city/diamond2.c");
        add_exit("south","/world/city/diamond4.c");
        add_exit("east","/world/city/diaeme2.c");

    short_desc = "On the central part of Diamond street";
    long_desc = "########### You are on Diamond street running north-south next to\n" + 
		"# W |     # the west wall. This street is home to most of the richest\n" +
		"# W *--+--# people of Duranghom. The large city wall rises very high\n" + 
		"# W |  A  # over your head, as the city does not want to have any \n" +
		"########### unexpected visitors. The Mainstreet of Duranghom is located\n" +
		"just south of here. You notice the north wall far away in the north.\n" + 
		"All kinds of shops are scattered by the sides of this street.\n";
  set_light(3);

}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/3");
   return 1;
}
