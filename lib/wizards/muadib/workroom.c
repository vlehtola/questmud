inherit "room/room";

reset(status arg) {
  if(arg) return;
  add_exit("north","/wizards/muadib/workroom/workroomN");
  add_exit("south","/wizards/muadib/workroom/workroomS");
  add_exit("east","/wizards/muadib/workroom/workroomE");
  add_exit("west","/wizards/muadib/workroom/workroomW");
  short_desc = "Muadib's room of wonders, or maby horrors";
  long_desc = "What a mess that's the first thing that comes to your mind\n" +
              "when you let your eyes wander around the room, there is an\n" +
              "enourmous amout of things lying about this room. Piles of \n" +
              "broken inventions, skeletons and things that borbably shouldn't\n" +
              "live but live, brobably only because the fact that these things\n" +
              "live fights against all rules of logic and reality. The second\n" +
              "thing that pops up in your mind is that the owner of this place\n" +
              "must be stark raving MAD! There's some light comming from the north.\n" ;
  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}

