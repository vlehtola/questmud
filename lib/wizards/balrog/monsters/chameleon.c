inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("chameleon");
    set_alias("");
    set_short("a chameleon");
    set_long("You almost pass this animal by without noticing it. But a movement in the corner of\n" +
             "your eye makes you aware of it. It's the legendary chameleon. It's skin changes colors\n" +
             "to match it's current surrounding texture. A beautiful specimen indeed..\n");
}
