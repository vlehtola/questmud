/* original reincob modified to ressob by Celtron */

string name, cleric;
int effect, exp;
object room; /* mihin targetti ressataan */

start(object ob, string arg, int eff, int xp) {
  string tmp;
  exp = xp;
  effect = eff;
  cleric = lower_case(arg);
  name = ob->query_real_name();
  move_object(this_object(), ob);
  room = environment(find_player(cleric));
  if(file_name(room)[0..10] == "/world/city") tmp = "You will be resurrected into city (Duranghom).\n";
  else tmp = "You will not be resurrected into city.\n";
  tell_object(ob, capitalize(arg)+" has offered to resurrect you.\n"+tmp+
	"Type: 'accept ress from "+lower_case(arg)+"' or 'decline ress from "+lower_case(arg)+"'\n");
}

init() {
  add_action("accept", "accept");
  add_action("decline", "decline");
}

decline(string str) {
  string tmp;
  if(!find_player(name)->query_dead()) {
    stop();
    return 0;
  }
  if(!str) return 0;
  if(sscanf(str, "ress from %s", tmp) != 1) return 0;
  if(lower_case(tmp) != cleric) return 0;
  tell_object(find_player(name), "You decline "+cleric+"'s resurrection.\n");
  tell_object(find_player(cleric), "Your offer was turned down.\n");
  return 1;
}

accept(string str) {
  string tmp;
  object target, caster;

  target = find_player(name);
  if(!target || !target->query_dead()) {
    stop();
    return 0;
  }
  if(!str) return 0;
  if(sscanf(str, "ress from %s", tmp) != 1) return 0;
  if(lower_case(tmp) != cleric) return 0;
  /* process ress */
  caster = find_player(cleric);
  if(caster)
	tell_object(caster, "Your resurrection spell activates on "+name+" as "+target->query_pronoun()+" grants "+
	target->query_possessive()+" approval. You resurrect "+name+"!\n");
  tell_object(target, capitalize(cleric)+" resurrects you.\n");
  target->remove_ghost(effect, room);
  if(caster && exp)
    caster->add_party_exp(exp);
   log_file("RESS_LOG", cleric+" got "+
        exp+" exp from ressing "+name+", "+effect+"% save. [33<=save<=66]\n");
  stop();
  return 1;
}


stop() {
  destruct(this_object());
}

id(str) { return str == "ressobject"; }

