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

        add_exit("west","/world/city/diamond7.c");
        add_exit("east","/world/city/emerald7.c");
        add_exit("north","/guilds/psi/psiguild.c");

    short_desc = "On a street leading from Diamond street to Emerald Street";
    long_desc = "########### You are on a small crossing street running from Diamond\n" +
		"# |  Ps | # street to Emerald street. This street is so small it doesn't\n" +
		"# +--*--+ # even have a name. The old buildings around you rise high over\n" +
		"#WWWWWW | # your head, as you are located in the richest part of the city\n" +
		"########### of Duranghom. \n";
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