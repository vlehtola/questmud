#define DIR "/guilds/necro/obj/"
#define MASTERY_D "/daemons/mastery_d"

status filtteri(object ob) {
        if(ob->query_horde_master()) {
                if(lower_case(ob->query_horde_master()) == lower_case(this_player()->query_name()))return 1;
        }

        return 0;
}

/* heal horde */
resolve(bonus) {
  int i;
  object horde, corpse;
  object *obs;

  obs = all_inventory(environment(this_player()));
  obs = filter_array(obs,"filtteri");

if(!obs || sizeof(obs) < 1) {
        write("There's no horde nearby.\n");
        return 1;
}

  horde = obs[0];

  corpse = present("corpse", environment(this_player()));
  if(!corpse) {
    write("You need to be by a corpse to perform your vile act.\n");
    return 1;
  }
  if(!horde) {
    write("There's no horde nearby.\n");
    return 1;
  }
  i = corpse->query_level()*100+this_player()->query_wis()+this_player()->query_int();
  if(i > 1500) i = 1500;
  i += MASTERY_D->mastery("Mastery of dark arts",this_player())*3;
  corpse->autoextract_obj(corpse);
  destruct(corpse);
  horde->heal_self(i);
  write("You drain the soul of corpse and use it to heal your horde.\n");
  say(this_player()->query_name()+" drains the soul of corpse and uses it to heal the horde.\n");
  return 1;
}
