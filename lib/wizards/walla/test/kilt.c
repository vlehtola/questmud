inherit "obj/armour";

start() {
set_class(15);
set_sub_type("leggings");
set_name("leggings");
set_alias("kilt");
set_short("Green kilt");
set_long("The kilt has a leather codpiece attached to it, and seems to be woven\n" +
         "from the finest cotton available. As you touch the fabric, you notice that\n" +
         "it has no flaws on it, and is almost as smooth as silk. The codpiece seems\n"+
         "to have a dial on it, which can be set to different elements");
set_value(5000);
set_stats("int",-3);
set_stats("wis",-2);
set_stats("hpr",8);
set_stats("str",6);
set_stats("con",3);
set_weight(4);
}


boost_fire() {
  write("The kilt starts to vibrate and grows cold.\n");
  set_resists("fire", 10);
  worn_by->update_stats();
  return 1;
}

boost_cold() {
  write("The kilt starts to vibrate and starts glowing hot.\n");
  set_resists("cold", 10);
  worn_by->update_stats();
  return 1;
}
boost_phys() {
  write("The kilt vibrates and seems thicker.\n");
  set_resists("physical", 10);
  worn_by->update_stats();
  return 1;
}

boost_elec() {
  write("The kilt vibrates and seems to become rubbery.\n");
  set_resists("elec", 10);
  worn_by->update_stats();
  return 1;
}

boost_pois() {
  write("The kilt vibrates and starts to emit a faint odour.\n");
  set_resists("poison", 10);
  worn_by->update_stats();
  return 1;
}

boost_psion() {
  write("The kilt vibrates and you see an image of the kilt in your mind.\n");
  set_resists("psionic", 10);
  worn_by->update_stats();
  return 1;
}

boost_acid() {
  write("The kilt vibrates, and you smell a pungent scent.\n");
  set_resists("acid", 10);
  worn_by->update_stats();
  return 1;
}

boost_off() {
  write("The kilt stops vibrating.\n");
  worn_by->update_stats();
  return 1;
}

init() {
::init();
add_action("boost_fire", "fire");
add_action("boost_cold", "ice");
add_action("boost_phys", "phys");
add_action("boost_elec", "elec");
add_action("boost_pois", "pois");
add_action("boost_psio", "psio");
add_action("boost_acid", "acid");
add_action("boost_off", "off");

}




