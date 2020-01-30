#define MASTERY_D "/daemons/mastery_d"
#define UNDEAD "wraith"

status filtteri(object ob) {
        if(ob->query_horde_master()) {
                if(lower_case(ob->query_horde_master()) == lower_case(this_player()->query_name()))return 1;
        }
        
        return 0;
}

resolve(bonus) {
  int i;
  object horde;
  object *obs;
  
  obs = all_inventory(environment(this_player()));
  obs = filter_array(obs,"filtteri");
  
  
if(!obs || sizeof(obs) < 1) {
        write("There's no horde nearby where you could add this undead.\n");
        return 1;
}
  
  horde = obs[0];
  if(!horde) {
    write("There's no horde nearby where you could add this undead.\n");
    return 1;
  }
  if(horde->add_undead(UNDEAD)) {
   write("You add the animated "+UNDEAD+" to the horde.\n");
   say(this_player()->query_name()+" animates a "+UNDEAD+" to the growing horde of "+
        "undeads.\n");
   MASTERY_D->mastery("Mastery of dark arts",this_player());
  }
  return 1;
}
