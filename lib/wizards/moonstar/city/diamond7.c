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

        add_exit("north","/world/city/diamond6.c");
        add_exit("east","/world/city/diaeme3.c");

    short_desc = "On the southern part of Diamond street";
    long_desc = "########### You are on Diamond street running north-east. There is a small\n" +
		"# W |  Ps # street to Emerald street east of here. Most of the rich people\n" +
		"# W *--+--# of Duranghom live along Diamon street. The large city wall\n" +
		"# WWWWWWWW# rises very high over your head, as the city does not want to\n" +
		"########### have any unexpected visitors. The Mainstreet of Duranghom is\n" +
		"located a little north of here. You notice the south wall just south from\n" +
		"this spot. All kinds of shops are scattered along this famous street.\n";
  set_light(3);

}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/7");
   return 1;
}
