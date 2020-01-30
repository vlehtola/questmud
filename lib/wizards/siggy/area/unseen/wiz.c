inherit"obj/monster";

reset(arg) {
  object armour;
  :: reset(arg);
  if(arg) { reset(arg); }
  set_name("guard");
  set_level(52);
  set_ep(5000);
  set_gender(1);
  set_al(10); 
  set_al_aggr(200);
  set_alias("guard");
  set_alt_name("man");
  set_race("human");
  set_short("Guard of the unseen university.");
  set_long("Guard is here standing and watching for strangers.\n");
  set_aggressive(0);
  set_dead_ob(0);

    armour = clone_object("/wizards/siggy/area/unseen/archrobe");
    move_object(armour, this_object());
    init_command("wear robe");

}
