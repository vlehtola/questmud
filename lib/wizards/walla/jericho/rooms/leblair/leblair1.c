inherit "room/room";
 
reset(arg) {
 
  add_exit("north","leblair2");
  add_exit("south","entrance");
  short_desc = "In an underground lair";
  long_desc = "The room, that you have just entered, is surely one of the more frightening\n"+
              "places you've ever seen. The ground is covered with blood, and remainders of\n"+
              "brave adventurers can bee seen in heaps. On the walls, you can see chandeliers\n"+
              "that give some light to this room.\n";
  property = allocate(2);
  property[0] = "no_kill";
  property[1] = "no_summon";
 }
joku_tuli(string str) {
        write(str+"\n");
        tell_object(find_player(lower_case(str)),"The roaring laughter of Leb Kamar fills your head.");
        shout("Leb Kamar shouts: MUHAHAHHAHAHA, so "+str+" dares challenge me!\n");
        return 1;
}
 
