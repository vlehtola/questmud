inherit "room/room";
object monster;

reset(arg) {
  add_exit("down","/wizards/rehti/dormund/rt3"); 
  short_desc = "At the tower";
  long_desc = "This is the northeast tower of the fortress Dormund. You can see that the whole\n"+
              "fort is surrounded by high and sturdy walls which seem to protect the inner city from\n"+
              "being assaulted. This place is high indeed and one really must have a good\n"+
              "vision to see smaller attackers.\n";
  if(!present("knight")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/scout"), this_object());
  if(arg) { return; }
}
}