inherit "/room/room";
inherit "/room/door";
object monster;

init() {
   ::init();
   add_action("map", "map");
   door_init();
}

reset(arg) {
if(arg) return;

if (!monster) {
                monster = clone_object("/world/monsters/citizen.c");
                move_object(monster, this_object());
  }

  door_reset();
  set_door_dir("east", "/room/houses/rooms/house9", 9);
  set_door_link("/room/houses/rooms/house9", 9);
  set_door_label("house 9", 9);
  set_door_code(call_other("/room/house_shop_d", "query_code", 8), 9);
  set_locked(1, 9);

  add_exit("north", "world/city/emerald8");
  add_exit("south", "world/city/emeral10");
  short_desc = "On the southern part of Emerald street";
  long_desc =
"########### You are on Emerald street running north-south, next to a few\n" + 
"#  W |    # smaller streets. This street is home to most of the rich\n" +
"#  W *    # people of Duranghom. The Mainstreet of Duranghom is located\n" + 
"#  W |    # much north from here. This old street has all kinds of shops\n" +
"########### scattered to each side of the street. The high wall arises \n" +
"up over your head in west.\n";
  set_light(3);
}

map(arg) {
   int *coords;
   string file;
   object map;

   if (arg) {
        return 0;
   }

   map = (object) "/wizards/moonstar/muut/map";

   file = file_name(environment(this_player()));
   coords = map->to_coords(file);
   map->drawmap(coords[0], coords[1]);

   return 1;
}
