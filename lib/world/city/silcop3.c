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
  set_door_dir("north", "/room/houses/rooms/house2", 2);
  set_door_dir("south", "/room/houses/rooms/house3", 3);
  set_door_link("/room/houses/rooms/house2", 2);
  set_door_link("/room/houses/rooms/house3", 3);
  set_door_label("house 2", 2);
  set_door_label("house 3", 3);
  set_door_code(call_other("/room/house_shop_d", "query_code", 1), 2);
  set_door_code(call_other("/room/house_shop_d", "query_code", 2), 3);
  set_locked(1, 2);
  set_locked(1, 3);

  add_exit("west", "world/city/silver4");
  add_exit("east", "world/city/silcop4");
  short_desc = "On a street Between Copper and Silver";
  long_desc = 
"########### This is a small crossing street between Copper and Silver\n" +
"# |       # streets. This is the poorest place in the city. There are\n" +
"# +--*--+-# only old and broken buildings. The poorest people of the\n"+
"# |     | # city are living in these buildings. Silver street is located\n" +
"########### west from here and Copper street is to the east. The large\n" +
"east wall is located in a little distance to east from here.\n";
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

