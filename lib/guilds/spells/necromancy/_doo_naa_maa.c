#define MASTERY_D "/daemons/mastery_d"
#define DIR "/guilds/necro/obj/"

status filtteri(object ob) {
        if(ob->query_horde_master()) {
                if(lower_case(ob->query_horde_master()) == lower_case(this_player()->query_name()))return 1;
        }

        return 0;
}

/* raise skeleton */
resolve(bonus) {
  int i;
  object horde, corpse, locate_ob;
  object *obs;

  obs = all_inventory(environment(this_player()));
  obs = filter_array(obs,"filtteri");

 if(!obs || sizeof(obs) < 1) {
    horde = clone_object(DIR+"horde");
    horde->set_controller(lower_case(this_player()->query_name()));
    write("You create a new horde starting from this skeleton.\n");
    locate_ob = clone_object("/guilds/necro/obj/locate_ob");
    move_object(locate_ob, this_player());
    locate_ob->start(horde);

 }

  if(!horde)horde = obs[0];

  corpse = present("corpse", environment(this_player()));
  if(!corpse) {
    write("You need to be by a corpse to perform your vile act.\n");
    return 1;
  }
  if(!call_other(DIR+"necro_data", "valid_corpse", corpse,
    "skeleton")) { return 1; }
  destruct(corpse);

  MASTERY_D->mastery("Mastery of dark arts",this_player());

  horde->add_undead("skeleton");
  move_object(horde, environment(this_player()));
  say(this_player()->query_name()+" animates a corpse to the horde of "+
        "undeads.\n");
  return 1;
}
