inherit "room/room";
object monster,monster2;
init() {
   ::init();
   add_action("map", "map");
   add_action("south", "south");
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

        add_exit("west","/world/city/wood3.c");
        add_exit("east","/world/city/wood5.c");
        add_exit("north","/world/city/gold8.c");
        add_exit("south","/world/city/southgate.c");

    short_desc = "On the crossing of Wood street and Gold street";
    long_desc = "########### You are on the crossing of Wood street and Gold street.\n" + 
		"#    |    # Wood street crosses Emerald street west from here and \n" +
		"#-+--*--+-# the Silver streets some distance in east from here.\n" + 
		"#WTTT=TTTW# These two old streets have all kinds of shops scattered\n" +
		"########### to each side of their streets. The huge south gate lies\n" +
		"just south protecting the city.\n";
  set_light(3);
}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/w9");
   return 1;
}

status south() {
  if(this_player()) return 0;
  if(previous_object()->query_monster()) return 1;
}
