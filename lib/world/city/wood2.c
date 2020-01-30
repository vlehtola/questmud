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
  set_door_dir("north", "/room/houses/rooms/house8", 8);
  set_door_link("/room/houses/rooms/house8", 8);
  set_door_label("house 8", 8);
  set_door_code(call_other("/room/house_shop_d", "query_code", 7), 8);
  set_locked(1, 8);

  add_exit("west", "world/city/emeral10");
  add_exit("east", "world/city/wood3");
  short_desc = "On the western part of Wood street";
  long_desc =
"########### You are wandering on the western part of Wood street.\n" + 
"# |       # Wood street crosses Emerald street west from here and \n" +
"# +--*--+-# Gold and Silver streets much east from here. This old street \n" + 
"#WWWWWWWTT# has all kinds of shops scattered to each side of the street.\n" +
"########### The high wall arises up over your head in south from here.\n";
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
