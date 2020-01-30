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
   int *coords;
   string file;
   object map;

   if (arg) {
        return 0;
   }

   map = (object) "/wizards/moonstar/muut/map";

   file = file_name(environment(this_player()));
   coords = map->to_coords(file);
   map->drawmap(coords[0], coords[1]);

   return 1;
}