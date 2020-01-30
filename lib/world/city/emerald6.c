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

        add_exit("south","/world/city/emerald7.c");
        add_exit("north","/world/city/mainstr3.c");
        add_exit("west","/guilds/mage/apprmage.c");

    short_desc = "On the central part of Emerald street";
    long_desc = "########### You are on Emerald street next to the Mainstreet street of\n" +
		"# Ms |    # Duranghom. This street is home to most of the rich\n" +
		"#  Mg*    # people of Duranghom. The Mainstreet of Duranghom is located\n" +
		"# Ps |  L # just north of here. This old street has all kinds of shops\n" +
		"########### scattered to each side of the street. A famous building, The\n" +
		"Mages Guild, towers over you in the west.\n";
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
