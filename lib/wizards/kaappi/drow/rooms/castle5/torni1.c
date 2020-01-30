inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("stairs", "r5.c");
  add_exit("east", "b1.c");

  short_desc = "The Tower";
  long_desc = "You have a very bad feeling about this room.\n"+
              "There is a big round symbol on the floor and\n"+
              "some unknown runes to you, are made around it.\n"+
              "One half burn candle is placed on the each\n"+
              "corner of this room.\n";
              
  set_light(1);
}
