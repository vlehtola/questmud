inherit "castle/obj/castle_room_d";
inherit "room/door";

int castle_id;

void init() {
  ::init();
  door_init();
  saveable = 1;
}

query_castle_id() {
  return castle_id;
}
query_startroom() { return 1; }

reset(arg) {
  if(arg) return;
  set_not_out(1);
  set_light(3);
  property = allocate(1);
  property[0] = "no_summon";
  castle_id = 1;
  door_reset();
  restore_room();
  generate_chests();
  generate_guards();
  short_desc = "chestroom";
  long_desc =   "The crude stone walls lay a dull atmosphere over the rectangular room. The room is not big, but "+
  "it has been stuffed full of various stuff. A small closet is located by the eastern wall. By the "+
  "other end of the wall is standing a small bed, and in the end of the bed is lying a "+
  "sturdy-looking iron chest. A tall candlestick is giving light to the room along with the window "+
  "carved into the wall. A doorway is leading out to the hallway."+
  "\n";
  add_exit("west", "/data/castle/castle_1/room0.c");
}
