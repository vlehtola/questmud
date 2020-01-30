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

        add_exit("north","/world/city/silver2.c");
        add_exit("south","/world/city/mainstr7.c");

    short_desc = "On the northern part of Silver street";
    long_desc = "########### You are on Silver street running in north-south direction.\n" + 
		"#    |  Qw# This street is home to most of the citizens of Duranghom.\n" +
		"#    *Qa  # The streetsides are mostly filled with good quality houses\n" + 
		"#    |  Q # in where the citizens can spend their nights. There are also\n" +
		"########### some houses for rent. Copper street is located one block to\n" + 
		"east. The Mainstreet of Duranghom is located behind some distance in south.\n";
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
