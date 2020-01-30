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
  set_door_dir("west", "/room/houses/rooms/house4", 4);
  set_door_link("/room/houses/rooms/house4", 4);
  set_door_label("house 4", 4);
  set_door_code(call_other("/room/house_shop_d", "query_code", 3), 4);
  set_locked(1, 4);

  add_exit("north", "world/city/silver5");
  add_exit("south", "world/city/silver7");
  short_desc = "On the central part of Silver street";
  long_desc =
"########### You are on the on Silver street running north-south across\n" + 
"#    |    # the big city of Duranghom. This street is home to most of the\n" +
"#    *    # citizens of Duranghom. This street is mostly filled with good\n" + 
"#    |    # quality houses in which the citizens can spend their nights.\n" +
"########### There are also some houses for rent. Wood street can be located\n" + 
"behind some distance in south. The Mainstreet of Duranghom is much to north.\n";
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
