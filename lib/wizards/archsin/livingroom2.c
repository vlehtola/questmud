inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("west","/wizards/archsin/livingroom");
  short_desc = "garage";
  long_desc = "The walls of this garage are stockpiled with probaply very usefull junk.\n";
  set_not_out(1);
  set_light(3);
}






