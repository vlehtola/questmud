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

        add_exit("west","/world/city/wood5.c");
        add_exit("north","/world/city/silver7.c");

    short_desc = "On the crossing of Wood street and Silver street";
    long_desc = "########### You are on the crossing of Wood street and Silver street.\n" + 
		"#|     | W# Wood street crosses Emerald street much west from here and\n" +
		"#+--+--* W# the Gold streets some distance in west from here. These two\n" + 
		"#=TTTWWWWW# old streets have all kinds of shops scattered to each side\n" +
		"########### of their streets. The huge walls lie south and east from here,\n" +
		"protecting the city.\n";
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
