inherit"obj/monster";

reset(arg) {
  :: reset(arg);
  if(arg) { reset(arg); }
  set_name("alister");
  set_level(30);
  set_gender(2);
  set_ep(1230);
  set_al(10);
  set_al_aggr(200);
  set_alias("wizard");
  set_alt_name("apprentice");
  set_race("human");
  set_short("Kuohujuoma Koff");
  set_long("Lady wizard dressed in sexy red robe. She looks very beatiful. The robe\n"
         + "glimmers. She has a mirror in her hand. The name of the wizard is Alister.\n"
         + "Rincewind is in love with her, well who wouldn't be.\n");
  set_aggressive(0);
  set_dead_ob(0);
}

