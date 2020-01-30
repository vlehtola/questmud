inherit "room/room";

object monster;

reset(arg) {
  if(arg) return;
  add_exit("up","wizards/nalle/area2/hotel2nd1");
  add_exit("south","wizards/nalle/area2/hotel");
  add_exit("east","wizards/nalle/area2/lavatory");
  short_desc = "Bottom of a Staircase";
  long_desc =
"You are in the room located north from the \n" +
"reception. A staircase leads up into higher floors \n" +
"of the hotel. The furnishing here is fairly old,\n" +
"and worn. The floors are covered with thick old\n" +
"rugs and carpets.\n";
}

