inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("wolf");
    set_alias("");
    set_short("a wolf");
    set_long("A wolf, a little bit bigger than the common dog, with a beautiful grey fur\n" +
             "with silver and white linings, stands majestically infront of you. This might\n" +
             "very well be the leader of a wolf-pact..\n");
}
