inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("rabbit");
    set_alias("");
    set_short("a rabbit");
    set_long("A rabbit hops along ahead of you, terrified for it's life. By looking at\n" +
             "the rabbit you can clearly see how it trembles when it stops to listen.\n" +
             "The rabbit hops on avoiding seemingly invisible enemies along the way.\n");
}
