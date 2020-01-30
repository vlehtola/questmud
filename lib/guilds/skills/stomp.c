#define INVIS_D "/daemons/invisibility_d"

get_time(str) {
  if(this_player()->query_npc()) return 4;
  return 4+random(3);
}
ep_cost() { return 5; }
query_type() { return "offensive"; }

resolve_skill(target) {
        object *ob;
        int i;
        int damage;
        string str;
        ob = all_inventory(environment(this_player()));
        if(this_player()->query_npc()) {
                damage = this_player()->query_level()+this_player()->query_str()+this_player()->query_size();
        } else {
                damage = this_player()->query_skills("stomp")+this_player()->query_str()+this_player()->query_size();
                if(damage > 250) damage = 250 + (damage-250)/2;
                if(damage > 400) damage = 400;
        } 
        str = "You stomp all over the";
        for(i=0;i<sizeof(ob);i++) {
        if(living(ob[i]) && ob[i] != this_player()) {
	  if(!INVIS_D->is_invis(this_player(),ob[i],ob[i]->query_invisibility_level())) {
                str+= " "+ob[i]->query_name();
                tell_object(ob[i], this_player()->query_name()+" STOMPS all over you!\n");
                ob[i]->hit_with_spell(damage, "physical");
                this_player()->attack_object(ob[i], 1);
	  }
        }
}
write(str+"\n");
  return 1;
}

fail_skill() {
  object *ob;
  int i;
  ob = all_inventory(environment(this_player()));
  write("You fail to stomp anything.\n");
  say(this_player()->query_name()+" fails to stomp anything!\n");
  for(i=0;i<sizeof(ob);i++) {
  if(living(ob[i]) && ob[i] != this_player()) {
  this_player()->attack_object(ob[i], 1);

}

 }
  return 1;
  }
