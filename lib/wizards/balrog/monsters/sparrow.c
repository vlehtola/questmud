inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("sparrow");
    set_alias("");
    set_short("a sparrow");
    set_long("The most common of birds, the sparrow. A white belly and a set of black and\n" +
             "brown speckled dorsal feathers, gives it it's characteristic look. It's head\n" +
             "twitches around in an attempt to see everything that moves and an occasional worm.\n");
}
