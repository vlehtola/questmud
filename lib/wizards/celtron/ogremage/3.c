inherit "/room/room";

reset(arg) {
  if(arg) return;
  short_desc = "In the backroom";
  long_desc =
"It's quite dark in here. The light of the fireplace doesn't penetrate the\n"+
"heavy curtains that divide the two rooms. There isn't much furniture,\n"+
"just a bed and two chairs.\n";
  add_exit("east", "/wizards/celtron/ogremage/2");
}
