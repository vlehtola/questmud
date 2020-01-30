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

        add_exit("west","/world/city/fire4.c");
        add_exit("south","/world/city/silver2.c");

    short_desc = "On the crossing of Fire street and silver street";
    long_desc = "########### You are on Fire street crossing Silver street running north-\n" + 
		"#TTTWWWW  # south. These street are homes to most of the travellers and\n" +
		"#-+--* W  # citizens of Duranghom. These streets are mostly filled with \n" + 
		"#    | WWW# high and good quality houses in which the travellers can spend\n" +
		"########### the night and where the citizens live. Gold Street is located\n" + 
		"some distance in west and Emerald street is much to the west. The Main-\n" + 
		"street of Duranghom is located some distance in south.\n";
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
