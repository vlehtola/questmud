inherit "obj/monster";

reset(arg) {
  object weapon;
  ::reset(arg);

  set_name("Stokie");
  set_level(8);
  set_al(60);
  set_alias("baker");
  set_race("gnome");
 set_short("Stokie the baker");
  set_long("Stokie is always busy, baking bread and cleaning.\n"+
                "He wears a dusty old cloth tunic and is holding a rolling.\n"+
              "pin.\n");

weapon = clone_object("/wizards/phoebus/areas/ja-tora/eq/pin");
move_object(weapon, this_object());
init_command("wield pin");

}
