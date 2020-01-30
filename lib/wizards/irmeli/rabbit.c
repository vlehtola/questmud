inherit "obj/monster";

reset(arg) {
  ::reset(arg);   
  if(arg) { return; }
  set_level(5);
  set_animal(1);
  set_name("rabbit");
  set_alias("animal");
  set_short("An albino rabbit eating grass");
  set_long("The white, thick fur is covering the rabbit, giving shelter from the cold.\n"+
           "The rabbit has fluffy, white ears, pitch black eyes, small, thin limbs\n"+
           "and stubby tail.\n");
  set_al(0);
}
