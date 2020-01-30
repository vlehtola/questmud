inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("python");
    set_alias("");
    set_short("a python");
    set_long("A reticulated python slithers around in search for food. It has a beautiful pattern\n" +
             "consisting of swirls of black and brown creating occasionally shapes that look like\n" +
             "eyes. It's fully aware of you but ignores your presence.\n");
}
