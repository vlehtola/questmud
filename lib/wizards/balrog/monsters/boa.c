inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("boa");
    set_alias("constrictor");
    set_short("a boa constrictor");
    set_long("Not unlike it's relative, the python, the boa has a beautiful pattern consisting\n" +
             "of brown and black patterns and an occasional spot of black. As it's relative the\n" +
             "boa strangles it's victims. Perchance it might be a good idea to step back?\n");
}
