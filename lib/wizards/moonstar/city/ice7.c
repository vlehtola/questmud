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

        add_exit("west","/world/city/gold6.c");
        add_exit("east","/world/city/silver5.c");

    short_desc = "On the eastern part of Ice street";
    long_desc = "########### You are on Ice street running east and west through the city.\n" + 
		"# |     | # This street is part of Duranghom's downtown. On both sides\n" +
		"#-+--*--+ # of the road, there are big wooden houses, homes of many\n" +
		"# |     | # families that have lived in Duranghom for centuries. The\n" +
		"########### Gold street is located in west and the Silver street in east.\n";
  set_light(3);

}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/x/15");
   return 1;
}
