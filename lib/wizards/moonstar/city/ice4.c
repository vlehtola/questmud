inherit "/room/room";
object monster;

reset(arg) {
if(arg) return;

if (!monster) {
                monster = clone_object("/world/monsters/citizen.c");
                move_object(monster, this_object());
  }

  add_exit("east", "world/city/ice5");
  add_exit("west", "world/city/emerald7");
  add_exit("north", "room/locker","north");
//  add_exit("south", "/daemons/auctioneer","south");

  set_light(3);

  short_desc = "On the western part of Ice street";
  long_desc =
"########### You are on Ice street running east and west through the city.\n" +
"# |  L    # This street is part of Duranghom's downtown. On both sides\n" +
"#-+--*--+-# of the road, there are big wooden houses, homes of many\n" +
"# | Au  Ar# families that have lived in Duranghom for centuries. The\n" +
"########### Emerald street with its rich houses is located in west.\n" +
"Duranghom's city Lockers are located in north.\n";
  set_light(3);
}


init() {
   ::init();
   add_action("map", "map");
}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/x/7");
   return 1;
}
