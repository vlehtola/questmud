inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("badger");
    set_alias("");
    set_short("a badger");
    set_long("A sturdy looking creature covered with black fur and white spots lumbers\n" +
             "along the lands. A closer look reveals that it is a common badger. They\n" +
             "have a nasty reputation about their powerful jaws.\n");
}
