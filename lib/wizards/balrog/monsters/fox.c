inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("fox");
    set_alias("");
    set_short("a fox");
    set_long("A small dog-like creature runs in the vincinity of you. It's clear orange\n" +
             "and white fur makes it evident that it's a fox in question. Apprehensive\n" +
             "as it is about your presence, it seems rather curious about you..\n");
}
