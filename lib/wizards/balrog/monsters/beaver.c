inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("beaver");
    set_alias("");
    set_short("a beaver");
    set_long("A slick orange-brown beaver is wandering carelessly here. Equipped with\n" +
             "a rather large set of teeth, it struts around as if it would be the king\n" +
             "of the lands.\n");
}
