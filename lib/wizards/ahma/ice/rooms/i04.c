inherit "room/room";
int i, h, time;

reset(arg) {
  add_exit("out", "311");
  short_desc = "A spacious igloo made of frozen snow";
  long_desc = "You are in a spacious and cosy-looking igloo. The bottom-diameter of\n" +
              "this igloo must be some fifteen feet. The floor is covered with soft\n" +
              "furs. Some furs are hanging also on the walls. The walls look very\n" +
              "intact, thus making the air inside the igloo feel almost comfortably\n" +
              "warm. A small tea table is sitting by the western wall. The doorway\n" +
              "leads out to south.\n";
  items = allocate(2);
  items[0] = "table";
  items[1] = "A small tea table is sitting by the western wall. The table is very low,\n" +
             "four small legs hold it firmly in its position. On the table there seems\n" +
             "to be a white, furry cloth but no dishes at all. From the ground, the\n" +
             "table is surrounded by thick furs, making it comfortable to sit around it";

  if(!i) {
    if(!present("gordon")) {
      move_object(clone_object("/wizards/ahma/ice/mob/dwarf04"), this_object());
      if(h) { present("gordon")->disablequest(); }
    }
  }
  else { call_out("ticktime", 1); }
}

nopop() {
  i = 1;
}

yespop() {
  i = 0;
  h = 1;
}

ticktime() {
  time++;
  if(time > 2) {
    i = 0;
    call_other("/wizards/ahma/ice/rooms/311", "add_exit", "enter", "/wizards/ahma/ice/rooms/i04");
    if(present("dooris")) {
      destruct(present("dooris"));
      "/wizards/ahma/ice/rooms/i05"->yespop();
      "/wizards/ahma/ice/rooms/i05"->reset(0);
    }
    if(present("gordon")) {
      destruct(present("gordon"));
      yespop();
      reset(0);
    }
    tell_room("/wizards/ahma/ice/rooms/311", "The magical shimmer fades away from the doorway leading into the igloo.\n");
    "/wizards/ahma/ice/rooms/311"->reset(0);
    "/wizards/ahma/ice/rooms/311"->pantaken();
  }
}