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

        add_exit("west","/world/city/gold1.c");
        add_exit("east","/world/city/silver1.c");

    short_desc = "On the eastern part of Fire street";
    long_desc = "########### You are on Fire street running east-west next to the north\n" + 
		"#T=TTTWWWW# wall. This street is home to most of the richest travellers\n" +
		"#-+--*--+ # who pass through Duranghom. This street is mostly filled with\n" + 
		"# |     | # high quality rent-rooms which the travellers can rent for the\n" +
		"########### night. Gold Street is located west, Silver street is located\n" + 
		"east and Emerald street is to the west. The north gate is located in\n" +
		"northwest.\n";
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
