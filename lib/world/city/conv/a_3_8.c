inherit "/room/room";
inherit "/room/door";

init() {
   ::init();
   add_action("map", "map");
   door_init();
}

map(arg) {
   if (arg) { return 0; }
   cat("/world/city/map");
   return 1;
}

reset(arg) {
   if(random(10) && !present("citizen")) {
    move_object(clone_object("/world/monsters/citizen.c"),this_object());
   }

  if (arg) return;
  door_reset();
  set_door_dir("east", "/room/houses/rooms/house10", 10);
  set_door_link("/room/houses/rooms/house10", 10);
  set_door_label("house 10", 10);
  set_door_code(call_other("/room/house_shop_d", "query_code", 9), 10);
  set_locked(1, 10);

  add_exit("north", "world/city/emerald7");
  add_exit("south", "world/city/emerald9");
  short_desc = "On the southern part of Emerald street";
  long_desc =
"########### You are on Emerald street running north-south, next to a few\n" + 
"#WWW |    # smaller streets. This street is home to most of the rich\n" +
"#  W *    # people of Duranghom. The Mainstreet of Duranghom is located\n" + 
"#  W |    # some distance in north from here. This old street has all\n" +
"########### kinds of shops scattered to each side of the street.\n";
  set_light(3);
}

