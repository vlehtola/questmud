inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("cobra");
    set_alias("");
    set_short("a cobra");
    set_long("It's scales have a black oily shimmer to it. Reflecting whatever light there\n" +
             "currently exists. Upon noticing you it raises up instantly into defensive position\n" +
             "trying to make itself look large and dangerous.\n");
}
