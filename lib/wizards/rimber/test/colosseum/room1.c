inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 set_not_out(1);
 short_desc = "Colosseum entrance";
 long_desc = "A big corridor which separates in two smaller corridors. The northwest\n"+
 "corridor is red and the northeast corridor is blue.\n";
 add_exit("northwest", "/wizards/rimber/test/colosseum/red.c");
 add_exit("northeast", "/wizards/rimber/test/colosseum/blue.c");
}
