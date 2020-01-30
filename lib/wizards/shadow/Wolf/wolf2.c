inherit "room/room";

object monster,monster2;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/shadow/Wolf/monsters/iceboy");
    move_object(monster, this_object());
}  

 if(!monster2) {
    monster2 = clone_object("/wizards/shadow/Wolf/monsters/icepet");
    move_object(monster2, this_object());
}
  if(arg) return;
  add_exit("north","/wizards/shadow/Wolf/wolf3");
  add_exit("east","/wizards/shadow/Wolf/wolf2a");
  add_exit("south","/wizards/shadow/Wolf/wolf1");
   short_desc = "Travelling in the Valley of the Frozen Wolf.";
  long_desc =
 "You are wondering in the valley of the frozen wolf.\n"+
  "South from here you can see a huge staircase leading up from \n" +
  "the valley. To your east you see a cave in the side of the mountain.\n" +
  "You think you saw something move in there, but your not sure about it\n" +
  "On the snow you spot foot prints all around. a distance to your \n" +
  "north you spot a large building with something on its roof. You can't\n" +
  "say what it is, but it's big.\n";
}

