inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("mouse");
    set_alias("");
    set_short("a mouse");
    set_long("Covered in brown speckled fur the mouse looks like a common rodent\n" +
             "for the area. It's natural brown colors protects it from the keen\n" +
             "eyes of it's predators.\n");
}
