inherit "castle/obj/castle_room_d";

int castle_id;

void init() {
  ::init();
  saveable = 1;
}

query_castle_id() {
  return castle_id;
}
reset(arg) {
  if(arg) return;
  set_not_out(1);
  set_light(3);
  property = allocate(1);
  property[0] = "no_summon";
  castle_id = 1;
  restore_room();
  generate_chests();
  generate_guards();
  short_desc = "entrance";
  long_desc =   "The large entrance hall is at least thirty feet high. A wooden chandelier is hanging high up in "+
  "the ceiling. The castle walls have been made of rough, gray stones. On the floor is lying a thin, "+
  "red carpet. Carpet continues from here further through the hallways of the castle. Guards' weapon "+
  "cabinets are located in an alcove in the eastern wall. Two giant, open doors are located in the "+
  "doorway leading out."+
  "\n";
  add_exit("out", "virtual /room/out/outmap 95 116");
  add_exit("west", "/data/castle/castle_1/room1.c");
  add_exit("east", "/data/castle/castle_1/room2.c");
}
