string at;
object ob,aob;
int skill;

resolve_hit(o) {
  int roll;
  ob = o;
  aob = ob->query_attack();
  if(!aob) return;
  at = aob->query_name();
  roll = random(100)+11;
  roll -= ob->query_dex() / 10;
  
  skill = ob->query_skills("fatal blow");
  skill -= aob->query_level()*2;

  if(skill > 2*roll) {
    tell_object(ob, "You aim a FATAL hit in "+at+"'s undefended throat!\n");
    tell_object(aob, ob->query_name()+" hits you in the throat CRUSHING your windpipe!\n");
    aob->death();
    return 1;
  }
  skill = ob->query_skills("headbang");
  if(skill > roll*2) {
    tell_object(ob,"You pull "+at+"'s head closer and give "+aob->query_objective()+
	" a CRUEL headbang!\n");
    tell_object(aob, ob->query_name()+" rips your head forward and gives you a CRUEL headbang!\n");
    aob->hit_with_spell(skill*4-roll,0, ob);
    return 1;
  }
}
