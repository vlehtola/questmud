inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("lizard");
    set_alias("");
    set_short("a lizard");
    set_long("With it's webbed toes and slimy skin, the lizard has been the facination of many.\n" +
             "Some dispise this tiny creature, some adore it. Some fear it. Some love it. It\n" +
             "scurries along the ground towards new adventure..\n");
}
