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

        add_exit("east","/world/city/fire3.c");
        add_exit("west","/world/city/emerald2.c");

    short_desc = "On the western part of Fire street";
    long_desc = "########### You are on Fire street running next to Emerald Street, which\n" + 
		"# | WWWWTT# is to east from here. This street is home to most of the richest\n" +
		"#u+--*--+-# travellers who pass through Duranghom. This street is mostly\n" + 
		"# |       # filled with high quality rent-rooms which the travellers can\n" +
		"########### rent for the night. Gold and Silver streets are located east of\n" +
		"here and Emerald street is to the west. The North gate is located behind a\n" + 
		"little distance in northest.\n";
  set_light(3);





}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/x/5");
   return 1;
}
