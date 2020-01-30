inherit "room/room";
object monster,monster2;
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

if (!monster2) {
                monster2 = clone_object("/wizards/jenny/city/guards/cityguard.c");
                move_object(monster2, this_object());
 }

        add_exit("north","/world/city/emerald1.c");
        add_exit("south","/world/city/emerald3");
        add_exit("east","/world/city/fire2");
        add_exit("west","wizards/celtron/sinrad/guard_hq.c");

    short_desc = "On the northern part of Emerald street";
    long_desc = "########### You are on Emerald street crossing Fire Street located\n" + 
		"#    | WWW# east of here. This street is home to most of the rich\n" +
		"#  Gu*--+-# people of Duranghom. The large city wall rises very high\n" + 
		"#    |    # over your head, as the city does not want to have any \n" +
		"########### unexpected visitors. The Mainstreet of Duranghom is\n" +
		"located much south of here. You notice a wall away in the north. The\n" + 
		"cityguards' headquarters is west from here.\n";
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
