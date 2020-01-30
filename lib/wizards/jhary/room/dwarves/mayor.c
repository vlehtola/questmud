inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("north","/wizards/jhary/room/dwarves/dwarf5");
  short_desc = "In a mayors office";
  long_desc = "The first thing, that catches your eyes is the town map,\n"+
              "pinned at the wall. The mayor of Thalahamisar fixed it \n"+
              "above his armchair right behind the desk. As you look \n"+
              "through the room you recognise, that there is a huge window \n"+
              "at the east side. The carpet on the floor of this offical \n"+
              "room is really cozy and you enjoy the atmosphere given of \n"+
              "the soft illumination. To the north you'll get out in the cave.\n";
}
                                        
