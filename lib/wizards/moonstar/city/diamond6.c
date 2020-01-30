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

        add_exit("south","/world/city/diamond7.c");
        add_exit("north","/world/city/mainstr1.c");
        add_exit("east","/guilds/library/hallway.c");

    short_desc = "On the central part of Diamond street";
    long_desc = "########### You are on Diamond street running north-south next to\n" +
		"#TT |  Ms # the west wall. This street is home to most of the richest\n" +
		"# T *Lb   # people of Duranghom. The large city wall rises very high\n" +
		"# W |  Ps # over your head, as the city does not want to have any \n" +
		"########### unexpected visitors. The Mainstreet of Duranghom is located\n" +
		"just north of here. You notice the the south wall away in south.\n";
  set_light(3);
}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/6");
   return 1;
}
