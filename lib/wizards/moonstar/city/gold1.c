inherit "room/room";
object monster,monster2;
init() {
   ::init();
   add_action("map", "map");
   add_action("north", "north");
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

        add_exit("east","/world/city/fire4.c");
        add_exit("west","/world/city/fire3.c");
        add_exit("south","/world/city/gold2.c");
        add_exit("north","/world/city/northgate.c");

    short_desc = "On the crossing of Fire street and Gold street",
    long_desc = "########### You are on Fire street Crossing the big Gold street running \n" + 
		"#WTTT=TTTW# north-south. These streets are homes to rich merchants as well as\n" +
		"#-+--*--+-# the common folk of Duranghom. These two streets are mostly filled\n" + 
		"#    |    # with high quality houses in which travellers can spend the\n" +
		"########### night and where the citizens live. Silver street is located\n" +
		"east of here, Emerald street is to the west and the Mainstreet of Duranghom\n" +
		"is much south from here. The North gate is located in north.\n";
  set_light(3);
}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/w1");
   return 1;
}

status north() {
  if(this_player()) return 0;
  if(previous_object()->query_monster()) return 1;
}
