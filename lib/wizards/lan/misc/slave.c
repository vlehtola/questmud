// Following slave version 0.1 AlphaBetaDeltaGamma by: Gheldor
// Added example emotes for Torspo to create more. ++Gheldor

// License: Use, modify, but keep the creators on the top of
//          this file _ALWAYS_ or you are using this ILLEGALY!
// ++Gheldor the funny one =)

inherit "obj/monster";
#define OWNER "Lan"

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(100);
    set_name("wolf");
    set_alias("lan");
    set_short("A Wolf is here to follow "+OWNER);
    set_long("A big Wolf, you don't need to know more than that.\n");
    set_al(0);
    set_exp(0);
    set_aggressive(0);
}

heart_beat() {
object ob; 
ob = find_player(lower_case(OWNER));

if(ob) {
  if(environment(ob) != environment(this_object())) {
    tell_room(environment(this_object()), "Wolf follows "+OWNER+".\n");
    move_object(this_object(), environment(ob));
    tell_room(environment(this_object()),"Wolf trudges in after "+OWNER+".\n");  
  }
}
}

hit_player(int i) {
i = 0;
return ::hit_player(i);
}

void catch_tell(string str) {
  string tmp, command, omistaja;
  if(sscanf(str,"%s says 'Wolf, %s'", omistaja, command) != 2) return;
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
