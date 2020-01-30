inherit "room/room";
object monster,monster2;
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

if (!monster2) {
                monster2 = clone_object("/wizards/jenny/city/guards/cityguard.c");
                move_object(monster2, this_object());
 }

        add_exit("west","/world/city/diamond3.c");
        add_exit("east","/world/city/emerald3");
        add_exit("south","/world/shops/armour_shop.c");

    short_desc = "On a street leading from Diamond street to Emerald Street";
    long_desc = "########### You are on a small crossing street running from Diamond\n" + 
                "# |     | # street to Emerald street. This street is so small it doesn't\n" +
                "# +--*--+ # even have a name. The old building around you rise high over\n" + 
		"# |  A  | # your head, as you are located in the richest part of the city\n" +
		"########### of Duranhom. The city Armourer is located south of here.\n";
  set_light(3);

}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/x/2");
   return 1;
}
