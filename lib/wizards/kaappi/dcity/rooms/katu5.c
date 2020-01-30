inherit "room/room";
object mob;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/jannut.c");
  move_object(mob, this_object()); }
{
  if(arg) return;

  add_exit("leave", "citye.c");
  add_exit("west", "katu4");
  add_exit("east", "katu6");
  add_exit("north", "katu12.c");

  short_desc = "Entrance of the city";
  long_desc = "-+---o---+-  As you step in to the city from the\n"+
              " |   |   |   gates you nearly fall on your knees\n"+
              "H3  H4H  5H  from the astonishment. Far from the north\n"+
              " |   |   |   you can hear noises coming from\n"+
              "-+-1-*---+-  the central square. The road is leading\n"+
              "#####E#####  to east, west and north.\n";

  set_light(2);
}
}
