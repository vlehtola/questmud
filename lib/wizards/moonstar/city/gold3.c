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

        add_exit("south","/world/city/cs.c");
        add_exit("north","/world/city/gold2.c");
        add_exit("west","/guilds/fighter/fighter.c");

    short_desc = "On the central part of Gold street";
    long_desc = "########### You are on the Gold street running north and south through\n" + 
		"#    |    # the city. This large street is part of Duranghom's downtown.\n" +
		"#   F*    # On both sides of the road, there are big wooden houses, homes\n" +
		"# B  |    # of many families that have lived in Duranghom for centuries.\n" +
		"########### The Central Square lies in south and the North gate in north.\n" +
		"Duranghom's famous Fighters Guild lies to the west.\n";
  set_light(3);

}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/w3");
   return 1;
}
