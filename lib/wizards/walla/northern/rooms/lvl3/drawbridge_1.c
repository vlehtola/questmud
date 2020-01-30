inherit "room/room";
 
reset(arg) {
 
  add_exit("east","rampart_7");
  add_exit("west","drawbridge_2");
  short_desc = "On a sturdy drawbridge";
  long_desc = "You are standing on a drawbridge, carved into the western mountainface, that\n"+
              "leads into the mountain. The drawbridge is made of sturdy rocks, but the 200\n"+
              "feet drop, down to the bottom does not make you feel any more secure.\n";
  property = allocate(1);
  property[0] = "no_summon";
 }
joku_tuli(string str) {
        tell_object(find_player(lower_case(str)),"A gust of foul smelling air blasts towards you, and a creepy feeling\n"+
                                                 "creeps up your spine, almost making you wet yourself.\n");
        return 1;
       
}
