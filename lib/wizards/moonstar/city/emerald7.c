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

        add_exit("south","/world/city/emerald8.c");
        add_exit("north","/world/city/emerald6.c");
        add_exit("east","/world/city/ice4.c");
        add_exit("west","/world/city/diaeme3.c");

    short_desc = "On the central part of Emerald street";
    long_desc = "########### You are on Emerald street running across Ice street, which\n" +
		"# Ps |  L # starts from here. This street is home to most of the rich\n" +
		"#-+--*--+-# people of Duranghom. The Mainstreet of Duranghom is located\n" +
		"#WWW | Au # some distance in north from here. This old street has all\n" +
		"########### kinds of shops scattered to each side of the street. There\n" +
		"is also a street leading east to Diamond street.\n";
  set_light(3);

}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/s7");
   return 1;
}
