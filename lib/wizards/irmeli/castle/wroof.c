inherit "room/room";
object monster;
  int i;
reset(arg) {
  if(arg) return;
  i = (random(3) +1);
  if(i == 3)  {
  if(!present("lady")) {
    move_object(clone_object("/wizards/irmeli/castle/monsters/lady.c"),
    this_object());
}
}
else move_object(clone_object("/wizards/ahma/misc/sculpture.c"), this_object());

  add_exit("down", "/wizards/irmeli/castle/wtower3.c");

 short_desc = "On the top of the west tower";
  long_desc = "An incomprehensibly beautiful view opens from the top of the west tower. You\n"+
              "can see the blue sea, the valley, the city and the graveyard from here. The\n"+
              "tower is about fifty meters high. The east tower of the castle is eastwards.\n"+
              "A safety fence is built around the roof. A huge fireplace is in the middle of\n"+
              "the roof. It rises a thick smoke screen to the sky. The spiral stairs are\n"+
              "leading down from the southeast corner of the roof. A cold wind is blowing\n"+
              "here.\n";

   set_light(4);

   items = allocate(6);
   items[0] = "safety fence";
   items[1] = "It goes around the roof.";
   items[2] = "stairs";
   items[3] = "The spiral stairs are leading down from the southeast corner.";
   items[4] = "fireplace";
   items[5] = "It's placed in the middle of the roof. Thick smoke screen rises to the sky from it.";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}

