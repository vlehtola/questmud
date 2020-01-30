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

        add_exit("east","/world/city/gold1.c");
        add_exit("west","/world/city/fire2.c");

    short_desc = "On the western part of Fire street";
    long_desc = "########### You are on Fire street running east-west next to the north\n" + 
		"#WWWWTTT=T# wall. This street is home to most of the richest travellers\n" +
		"#-+--*--+-# who pass through Duranghom. This street is mostly filled with\n" + 
		"#       | # high quality rent-rooms which the travellers can rent for the\n" +
		"########### night. Gold and Silver streets are located east of here and\n" +
		"Emerald street is to the west. The North gate is located in northeast.\n";
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
