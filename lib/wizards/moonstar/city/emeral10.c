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

        add_exit("north","/world/city/emerald9.c");
        add_exit("east","/world/city/wood2.c");
      add_exit("down","/wizards/moonstar/areas/sewers/entrance.c");
    short_desc = "On the southern part of Emerald street";
    long_desc = "########### You are on the crossing of Emerald street and Wood street.\n" + 
		"#  W |    # Wood, Gold and Silver streets are located to east from\n" +
		"#  W *--+-# here. The Mainstreet of Duranghom is located much north\n" + 
		"#  WWWWWWW# from here. This old street has all kinds of shops scattered\n" +
		"########### to each side of the street. The high wall arises up over\n" +

                "your head in west and south from here. There is a small manhole on the ground.\n";
  set_light(3);

}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/s10");
   return 1;
}
