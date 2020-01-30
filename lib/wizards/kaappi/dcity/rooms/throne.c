inherit "room/room";
object mosa;

reset(arg) {
  if(arg) return;

  if(!mosa) {
     mosa = clone_object("/wizards/kaappi/dcity/mobs/king.c");
     move_object(mosa, this_object());
}

  add_exit("south", "hall8.c");
  
  short_desc = "The city hall";
  long_desc = ""
              "You are standing in front of the throne of king. The throne is placed\n"+
              "against the northern wall. The throne is also made of rock, but it is still\n"+
              "very gorgeous looking. There are golden runes carved on both sides of it.\n"+
               "In this room the floor is made from marble as it is in the previous ones.\n";

  set_light(2);
}
