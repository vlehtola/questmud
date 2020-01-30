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

        add_exit("west","/world/city/diamond1.c");
        add_exit("east","/world/city/emerald1.c");

    short_desc = "On a street leading from Diamond street to Emerald Street";
    long_desc = "########### You are on a small crossing street running from Diamond\n" + 
		"#WWWWWWWWW# street to Emerald street. This street is so small it does not\n" +
		"# +--*--+ # even have a name. The old and large north wall rises very high\n" + 
		"# |     | # over your head, as the city does not want to have any \n" +
		"########### unexpected visitors.\n";
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