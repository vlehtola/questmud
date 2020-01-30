#define MASTERY_D "/daemons/mastery_d"
#define DIR "/guilds/necro/obj/"

status filtteri(object ob) {
        if(ob->query_horde_master()) {
                if(lower_case(ob->query_horde_master()) == lower_case(this_player()->query_name()))return 1;
        }

        return 0;
}

/* raise wight */
resolve(bonus) {
  int i;
  object horde, corpse;
  object *obs;

  obs = all_inventory(environment(this_player()));
  obs = filter_array(obs,"filtteri");


if(!obs || sizeof(obs) < 1) {
        write("There's no horde nearby where you could add this undead.\n");
        return 1;
}

  horde = obs[0];
  corpse = present("corpse", environment(this_player()));
  if(!corpse) {
    write("You need to be by a corpse to perform your vile act.\n");
    return 1;
  }
  if(!horde) {
    write("There's no horde nearby where you could add this undead.\n");
    return 1;
  }
  if(!call_other(DIR+"necro_data", "valid_corpse", corpse,
        "wight")) { return 1; }
  destruct(corpse);

  MASTERY_D->mastery("Mastery of dark arts",this_player());

  horde->add_undead("wight");
  say(this_player()->query_name()+" animates a corpse to the horde of "+
        "undeads.\n");
  return 1;
}
