
inherit "room/room";

reset(arg) {

  add_exit("forest", "/wizards/proge/suunnitelmat/forest/enter");

  short_desc = "Laboratory";
  long_desc = "This is a lab where wizards test their unholy creations\n";
  
  set_not_out(1);
  set_light(3);
}
