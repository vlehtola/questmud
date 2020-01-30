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
  set_door_dir("north", "/room/houses/rooms/house6", 6);
  set_door_link("/room/houses/rooms/house6", 6);
  set_door_label("house 6", 6);
  set_door_code(call_other("/room/house_shop_d", "query_code", 5), 6);
  set_locked(1, 6);

  add_exit("west", "world/city/wood4");
  add_exit("east", "world/city/wood6");
  short_desc = "On the central part of Wood street";
  long_desc =
"########### You are wandering on the eastern part of Wood street.\n" + 
"# |     | # Wood street crosses Emerald and Gold streets west\n" +
"#-+--*--+ # from here and Silver street east from here. This old\n" + 
"#T=TTTWWWW# street has all kinds of shops scattered to each side\n" +
"########### of the street. The big wall arises up over your head\n" +
"south from here. The tall guard towers are to the south.\n";
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
