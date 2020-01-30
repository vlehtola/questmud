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

        add_exit("south","/world/city/emerald2.c");
        add_exit("west","/world/city/diaeme1.c");

    short_desc = "On the northern part of Emerald street";
    long_desc = "########### You are on Emerald street running north-west. There is a small\n" + 
		"#WWWWWWWW # street leading to Diamond street west of here. The most of the\n" +
		"#--+--* W # rich people of Duranghom live along Emerald street. The large\n" + 
		"#     | W # city walls rise very high over your head, as the city does not\n" +
		"########### want to have any unexpected visitors. The Mainstreet of Duranghom\n" +
		"is located far away in south of here. The large north wall is just next to\n" + 
		"you as the north-east wall. All kinds of shops are scattered by the sides of\n" +
		"this street.\n";
  set_light(3);




}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/s1");
   return 1;
}
