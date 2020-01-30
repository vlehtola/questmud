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
  set_door_dir("north", "/room/houses/rooms/house1",1);
  set_door_link("/room/houses/rooms/house1",1);
  set_door_label("house 1",1);
  set_door_code(call_other("/room/house_shop_d", "query_code", 0), 1);
  set_locked(1, 1);

  add_exit("west", "world/city/silcop3");
  add_exit("east", "world/city/copper3");
  add_exit("south","wizards/morgoth/slummi/room/slum10");
  short_desc = "On a street Between Copper and Silver";
  long_desc = 
"########### This is a small crossing street between Copper and Silver\n" +
"#       | # streets. This is the poorest place in the city. There are\n" +
"#-+--*--+ # only old and broken buildings. The poorest people of the city\n"+
"#    |    # are living in these buildings. Silver street is located west\n" +
"########### from here and Copper street is to the east. The large east\n" +
"wall is located in a little distance to east from here. Entrance to the\n" +
"slums of Duranghom lie in south.\n";
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

