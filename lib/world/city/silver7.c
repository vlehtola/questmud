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
  set_door_dir("west", "/room/houses/rooms/house5", 5);
  set_door_link("/room/houses/rooms/house5", 5);
  set_door_label("house 5", 5);
  set_door_code(call_other("/room/house_shop_d", "query_code", 4), 5);
  set_locked(1, 5);

  add_exit("north", "world/city/silver6");
  add_exit("south", "world/city/wood6");
  add_exit("east", "/wizards/morgoth/slummi/room/slum1");

  short_desc = "On the southern part of Silver street";
  long_desc =
"########### You are on the on Silver street running north-south across \n" + 
"#    |    # the big city of Duranghom. This street is home to most of the\n" +
"#    *--  # citizens of Duranghom. This street is mostly filled with good\n" + 
"#    |    # quality houses in which the citizens can spend their nights.\n" +
"########### There are also some houses for rent. Wood street can be located\n" + 
"in some distance to south. The Mainstreet of Duranghom is lying after a\n" +
"distance in north. The slums of Duranghom are located in east.\n";
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
