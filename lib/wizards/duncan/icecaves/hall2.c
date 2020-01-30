inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("south", "/wizards/duncan/icecaves/tunnel2.c");

  short_desc = "A collapsed ice-hall";
  long_desc = "The ice-hall is in disorder the ceiling has collapsed as well as the ground.\n"+ 
              "A huge and deep pitch black gorge is dividing the hall in two parts. The gorge\n"+
              "is more than three metres in width. There are big boulders of stones around\n"+
              "the hall covered with ice and snow. A rough and deep crack is on the ceiling.\n"+
              "Everything is covered with thick layer of ice and snow. A strange blue light\n"+
              "shimmers from the walls under the thick layer of ice. The cold air forces you\n"+ 
              "to leave as soon as possible. A small and frail-looking wooden bridge is placed\n"+
              "over the gorge, connecting the both sides of the hall. The main tunnel is\n"+
              "towards south.\n";

   set_not_out(1);
   set_light(3);

   items = allocate(6);
   items[0] = "gorge";
   items[1] = "The gorge is deep and pitch black. It was formed when the ground collapsed. It's more than three metres in width, dividing the hall in two parts";
   items[2] = "boulders";
   items[3] = "Huge stone boulders has fell on the ground when the ceiling collapsed. Scattered all over the hall, in both sides of the gorge. The stones are covered with ice and snow as well as everything in here";
   items[4] = "bridge";
   items[5] = "The bridge is small, frail-looking and slippery. It's made of wood and about one and an half meters wide. The bridge is placed over the deep gorge";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}

init() {
  ::init(); 
  add_action("cross", "cross"); 
}

cross(str) {
  if(str == "gorge") {
    write("You doubt for an moment and gather your courage to cross the gorge.\n"+
          "You step on the bridge and start walking slowly on the bridge.\n"+
          "The bridge wobbles a bit.\n"+
          "WHEW! You take the last step on the bridge and step on ground at the other side of the gorge!\n");
    say(this_player()->query_name()+" crosses the gorge using the frail-looking bridge.\n");
    move_object(this_player(),"/wizards/duncan/icecaves/secret1.c");
    command("look",this_player());
     }
     return 1;
 }
