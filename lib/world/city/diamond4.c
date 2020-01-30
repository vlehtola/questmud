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

        add_exit("north","/world/city/diamond3.c");
        add_exit("south","/world/city/mainstr1");

    short_desc = "On the central part of Diamond street";
    long_desc = "########### You are on Diamond street running north-south next to\n" + 
		"# W |  A  # the west wall. This street is home to most of the richest\n" +
		"# T *   We# people of Duranghom. The large city wall rises very high\n"+ 
		"#TT |     # over your head, as the city does not want to have any \n" +
		"########### unexpected visitors. The Mainstreet of Duranghom is located\n" +
		"just south of here. You notice the north wall far away in the north.\n" + 
		"All kinds of shops are scattered by the sides of this street.\n";
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