/* Specialboost */
#define MASTERY_D "/daemons/mastery_d"

status filtteri(object ob) {
        if(ob->query_horde_master()) {
                if(lower_case(ob->query_horde_master()) == lower_case(this_player()->query_name()))return 1;
        }
        
        return 0;
}

resolve(bonus) {
  int i;
  
  string aura;
  object horde;
  object *obs;
  
  obs = all_inventory(environment(this_player()));
  obs = filter_array(obs,"filtteri");
  
  
if(!obs || sizeof(obs) < 1) {
        write("There's no horde nearby which you could enchant.\n");
        return 1;
}
  
  horde = obs[0];
  if(!horde) {
    write("Your horde is not present.\n");
    return 1;
  }
  if(horde->query_specialboost()) {
        write("The horde is already surrounded by unnatural blue glow.\n");
        return 1;
        }

 i = this_player()->query_int()/4;
 i+= this_player()->query_wis()/4;
 i+= this_player()->query_skills("cast unholy enchantments");
 i+= this_player()->query_skills("cast dark power");
 
 if(i > 300)i=300;

 i+= MASTERY_D->mastery("Mastery of dark arts",this_player())*2/3;
 
 horde->start_specialboost(i*2,i);
 
 write("The horde is surrounded by unnatural blue glow.\n");
  
say(this_player()->query_name()+" creates a blue aura to surround "+this_player()->query_possessive()+" horde.\n");
  
return 1;
}
