get_time(str) {
  return 4;
}
ep_cost() { return 5; }
query_type() { return "offensive"; }

resolve_skill(target) {
        object *ob;
        int i;
        int damage;
        string str;
        ob = all_inventory(environment(this_player()));
        damage = this_player()->query_level()+this_player()->query_str()+this_player()->query_size();
        str = "You stomp all over the";
        for(i=0;i<sizeof(ob);i++) {
        if(living(ob[i]) && ob[i] != this_player()) {
                str+= " "+ob[i]->query_name();
                tell_object(ob[i], this_player()->query_name()+" STOMPS all over you!\n");
                ob[i]->hit_with_spell(damage, "physical");
                this_player()->attack_object(ob[i], 1);
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
