resolve(string category, string class, string type, int effect_bonus, string target) {
  object ob, tgt, caster;
  string spell, file, tmp,desc,target2;
  caster = this_player();
  spell = class+" "+type;
  tmp = get_object(spell);
  if(!tmp) tmp = get_object(type);
  if(tmp) file = "/guilds/spell_obj/"+tmp;
  else return 0; /* spell.c continues the search for spell elsewhere */
  if(!target) { write("Cast at what?\n"); return 1; }
  tgt = present(target, environment(this_player()) );
  if(!tgt) {
    tell_object(this_player(), "No such target present.\n");
    return 1;
  }
  target2 = capitalize(target);
  target = capitalize(target);
  if(tgt == caster) {
         target = "yourself";
         target2 = this_player()->query_objective()+"self";

	// added by celtron 040107 to prevent selfcasting abuse
	if(tmp=="vulnerability") {
	  write("You fail the casting and hurt yourself!\n");
	  caster->hit_with_spell(500);
	  return 1;
	}
 }

  write("You cast a "+get_spell_desc(tmp)+" at "+target+".\n");
  say(this_player()->query_name()+" casts a "+get_spell_desc(tmp)+" at "+target2+".\n",tgt);
  if(caster != tgt) {
          tell_object(tgt, this_player()->query_name()+" casts a "+get_spell_desc(tmp)+" at you.\n");
  }
  ob = clone_object(file);
  ob->start(tgt,effect_bonus,class,caster);
  return 1;
}

get_object(string spell) {
  switch(spell) {
   case "sol tdr": return "shield";
   case "fla tdr": return "sphere_of_protection";
   case "zzt tdr": return "stone_skin";
   case "jht": return "protection";
   case "cvk": return "stat_boost";
   case "rhj": return "vulnerability";
  }
}

get_spell_desc(string str) {
        switch(str) {
                case "shield": return "shield";
                case "sphere_of_protection": return "sphere of protection";
                case "stone_skin": return "stone skin";
                case "protection": return "protection";
                case "stat_boost": return "stat boost";
                case "vulnerability": return "vulnerability";
        }
        return "no desc";
}
