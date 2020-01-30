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
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/x/13");
   return 1;
}
