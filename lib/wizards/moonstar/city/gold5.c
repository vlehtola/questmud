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

        add_exit("north","/world/city/cs.c");
        add_exit("south","/world/city/gold6.c");
        add_exit("west","/room/house_shop.c");

    short_desc = "On the central part of Gold street";
    long_desc = "########### You are on the Gold street running north and south through\n" + 
		"# I  |  Ba# the city. This large street is part of Duranghom's downtown.\n" +
		"#  Th*    # On both sides of the road, there are big wooden houses, homes\n"+
		"#    |    # of many families that have lived in Duranghom for centuries.\n" +
		"########### The Central Square lies in north and the south gate in south.\n";
  set_light(3);

}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/w5");
   return 1;
}