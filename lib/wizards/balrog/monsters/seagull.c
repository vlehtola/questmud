inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("seagull");
    set_alias("");
    set_short("a seagull");
    set_long("A squaking and dumb looking seagull looks around for something to eat. Totally\n" +
             "unaware of your presence it keeps a steady look out for anything edible. The\n" +
             "seagull squaks in desperation. No Food!\n");
}
