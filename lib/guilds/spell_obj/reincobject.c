#define DAYS_TO_FREE_REINC	5

string name, cleric;
int accept;

int loss_percent(object player) {

// Reinc is free. 15.02.04 Celtron

  return 0;

/*
  int t;
  t = time() - player->query_last_reinc_time();
  t = t / 60 / 60 / 24; // days
  t = DAYS_TO_FREE_REINC - t;
  if( t < 0 ) t = 0;
  return t;
*/
}

start(object ob, string arg) {
  cleric = lower_case(arg);
  name = ob->query_real_name();
  move_object(this_object(), ob);
  tell_object(ob, capitalize(arg)+" has offered to reincarnate you. This will allow you to re-generate your character.\n"+
	"BEWARE! It will also destroy all your equipment permanently!\n"+
	"Reincarnating now will cause you to lose "+loss_percent(ob)+"% of your total worth.\n"+
	"Type: 'accept reinc from "+lower_case(arg)+"' or 'decline reinc from "+lower_case(arg)+"'\n");
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
  if(sscanf(str, "reinc from %s", tmp) != 1) return 0;
  if(lower_case(tmp) != cleric) return 0;
  tell_object(find_player(name), "You decline "+cleric+"'s reincarnation.\n");
  return 1;
}

accept(string str) {
  string tmp;
  object target, ob, obje, caster;
  int i2;

  target = find_player(name);
  if(!target->query_dead()) {
    stop();
    return 0;
  }
  if(!str) return 0;
  if(sscanf(str, "reinc from %s", tmp) != 1) return 0;
  if(lower_case(tmp) != cleric) return 0;
  /* process reinc */

   caster = find_player(cleric);
   if(caster) 
   	tell_object(caster, "Your reincarnation spell activates on "+name+" as "+target->query_pronoun()+" grants "+
		target->query_possessive()+" approval. You reincarnate "+name+"!\n");

   tell_object(target, capitalize(cleric)+" reincarnated you.\n");
   log_file("REINC_LOG", capitalize(name)+" reinced by "+
                cleric+"\n");
        
  ob = target;
   obje = all_inventory(ob);
   while(i2<sizeof(obje)) {
      if(obje[i2] && obje[i2]->short()) { destruct(obje[i2]); }
      i2 += 1;
   }
   ob->remove_ghost(100, "/obj/race_selection");
 /* 8.3.2002 reinc cost // Celtron */
   ob->reinc(loss_percent(ob));
   stop();
   return 1;
}


stop() {
  destruct(this_object());
}

id(str) { return str == "reincobject"; }

