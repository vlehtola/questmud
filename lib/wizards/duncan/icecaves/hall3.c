inherit "room/room";
object monster;

reset(arg) {
  if(!present("animal 2")) { 
    move_object(clone_object("/wizards/duncan/icecaves/monsters/animal.c"),
    this_object());
    move_object(clone_object("/wizards/duncan/icecaves/monsters/animal.c"),
    this_object());
}

  if(arg) return;

  add_exit("north", "/wizards/duncan/icecaves/tunnel2.c");

  short_desc = "A collapsed ice-hall";
  long_desc = "The ice-hall is in disorder the ceiling has collapsed as well as the ground.\n"+ 
              "A huge and deep pitch black gorge is dividing the hall in two parts. The gorge\n"+
              "is more than three metres in width. There are big boulders of stones around\n"+
              "the hall covered with ice and snow. A rough and deep crack is on the ceiling.\n"+
              "Everything is covered with thick layer of ice and snow. A strange blue light\n"+
              "shimmers from the walls under the thick layer of ice. The cold air forces you\n"+ 
              "to leave as soon as possible. The main tunnel is towards north.\n";

   set_not_out(1);
   set_light(3);

   items = allocate(4);
   items[0] = "gorge";
   items[1] = "The gorge is deep and pitch black. It was formed when the ground collapsed. It's more than three metres in width, dividing the hall in two parts";
   items[2] = "boulders";
   items[3] = "Huge stone boulders has fell on the ground when the ceiling collapsed. Scattered all over the hall, in both sides of the gorge. The stones are covered with ice and snow as well as everything in here";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
