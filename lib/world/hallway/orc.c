inherit "/obj/monster";

reset(arg) {
  object money, monsu;
  ::reset(arg);
  if (arg) { return; }
  monsu = this_object();
  set_race("orc");
  set_gender(1);
  call_other(monsu, "set_name", "guard");
  call_other(monsu, "set_alias", "orc");
  call_other(monsu, "set_level", 20);
  call_other(monsu, "set_short", "An orc guard");
  call_other(monsu, "set_long", "His red eyes glow in dark, his grumbling is boring.\n" +
                                "He is a true orc, one bastard of this nasty race.\n");
  call_other(monsu, "set_al",-30);
  call_other(monsu, "set_gender", 1);  
  move_object(clone_object("/wizards/celtron/forest/orc_sword"), monsu);
  monsu->init_command("wield sword");
  move_object(clone_object("/wizards/celtron/forest/orc_shield"), monsu);
 monsu->init_command("wield shield");
}

