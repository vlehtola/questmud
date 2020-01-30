
inherit "obj/monster";
#define OWNER "Moonstar"

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(100);
    set_name("malystryx");
    set_alias("dragon");
    set_short("Malystryx, the huge red dragon is following "+OWNER);
    set_long("Malystryx, the huge red dragon is following Moonstar.\n");
    set_al(0);
    set_exp(666666666);
    set_aggressive(0);
}

heart_beat() {
object ob;
ob = find_player(lower_case(OWNER));

if(ob) {
  if(environment(ob) != environment(this_object())) {
    tell_room(environment(this_object()), "Malystryx follows "+OWNER+".\n");
    move_object(this_object(), environment(ob));
    tell_room(environment(this_object()),"Malystryx flies in after "+OWNER+".\n");
  }
}
}

hit_player(int i) {
i = 0;
return ::hit_player(i);
}

void catch_tell(string str) {
  string tmp, command, omistaja;
  if(sscanf(str,"%s says 'Malystryx, %s'", omistaja, command) != 2) return;
  if(omistaja != OWNER) return;

  if(sscanf(command,"smile %s",tmp)) {

  if(present(tmp,environment(this_object())))
      say(query_name()+" smiles happily at "+capitalize(tmp)+".\n");
    return;
  }

  if(sscanf(command,"hug %s",tmp)) {
    if(present(tmp,environment(this_object())))
      say(query_name()+" hugs "+capitalize(tmp)+" deeply.\n");
    return;
  }
}
