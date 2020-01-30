
inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("south","/wizards/muadib/workroom");
  add_exit("cs","/world/city/cs");
  add_exit("inn","/world/city/inn");
  short_desc = "The portal room";
  long_desc = "This is Muadib's portal room.\n" +
              "You can see two portals wich\n" +
              "are smimering in blue light.\n" +
              "On the top of the two portals\n" +
              "are some runes say to where\n" +
              "these portals lead\n" ;
  set_light(3);
}
