inherit "obj/weapon";

start() {
  set_class(7);
  set_sub_type("flail");
  set_short("Flail of the orc commander");
  set_long("This flail is a very typical weapon for orcs, it is\n"+
           "efficient, crude and very deadly. It doesn't have any\n"+
           "ornaments. Pieces of flesh are hanging from the sharp,\n"+
           "cruel-looking spikes on the heavy ball hanging on a\n"+
           "chain. You feel a bit sick when you think of all the\n"+
           "horrors this weapon has caused.\n");

  set_stats("str",5);
}
