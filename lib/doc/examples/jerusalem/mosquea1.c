inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/mosqueb1");
  short_desc = "A shadowy corner of the mosque";
  long_desc =
"It is quite dark here, and a pleasant smell fills the air. This\n" +
"seems to be a place where people can ponder and think\n" +
"in peace. The chanting reaches your ears, but not as loud\n" +
"as in the other rooms. The stone walls add a melancholic echo\n" +
"to it and make you feel thoughtful. \n";
}

