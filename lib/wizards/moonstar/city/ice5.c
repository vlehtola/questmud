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

        add_exit("east","/world/city/gold6.c");
        add_exit("west","/world/city/ice4.c");
        add_exit("south","/world/arena/entrance.c");

    short_desc = "On the central part of Ice street";
    long_desc = "########### You are on Ice street running east and west through the city.\n" +
		"# L     | # This street is part of Duranghom's downtown. On both sides\n" +
		"#-+--*--+-# of the road, there are big wooden houses, homes of many\n" +
		"# Au Ar | # families that have lived in Duranghom for centuries. The\n" +
		"########### Emerald street with its rich houses is located in west and\n" +
		"the gold street in east. Duranghom's city Battle Arena is located in south.\n";
  set_light(3);

}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/x/11");
   return 1;
}
