inherit "/room/room";

reset(arg) {
  if (arg) return;
  set_not_out(1);
  set_light(3);

  add_exit("north", "/room/houses/rooms/house9");

  short_desc = "A luxurious bedroom";
  long_desc =
"This is a luxurious bedroom. There is a large double bed in the middle\n"+
"of the room. Candles light the room with soft red light.\n";

property = allocate(2);
property[0] = "no_kill";
property[1] = "no_summon";
}

