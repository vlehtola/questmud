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

        add_exit("north","/world/city/diamond1.c");
        add_exit("south","/world/city/diamond3.c");

    short_desc = "On the northern part of Diamond street";
    long_desc = "########### You are on Diamond street running north-south next to\n" +
                "# W |     # the west wall. This street is home to most of the richest\n" +
                "# W *   Gu# people of Duranghom. The large city wall rises very high\n" +
                "# W |     # over your head, as the city does not want to have any \n" +
                "########### unexpected visitors. The Mainstreet of Duranghom is located\n" +
                "much south of here. You notice the north wall some distance away in\n" +
                "the north. All kinds of shops are scattered by the sides of this street.\n";
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

