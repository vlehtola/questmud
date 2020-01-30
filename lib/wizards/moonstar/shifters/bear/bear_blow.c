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

  skill = ob->query_skills("double blow");
  skill -= aob->query_level();

  if(skill > 2*roll) {
    tell_object(ob, "You give a multiple blows at "+at+" body!\n");
    tell_object(aob, ob->query_name()+" punches you multiple times making your body to start bleeding!\n");
    aob->hit_with_spell(skill*7-roll,0, ob);
    return 1;
  }
  skill = ob->query_skills("bear blow");
  if(skill > roll*2) {
    tell_object(ob,"You direct a powerful bear blow "+at+"'s neck\n");
    tell_object(aob, ob->query_name()+" powerfully punches you in the neck!\n");
    aob->hit_with_spell(skill*4-roll,0, ob);
    return 1;
  }
}

