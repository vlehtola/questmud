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

  skill = ob->query_skills("power hug");
  skill -= aob->query_level();

  if(skill > 2*roll) {
    tell_object(ob, "You hug "+at+" with devastating force!\n");
    tell_object(aob, ob->query_name()+" hugs you with devastating force!\n");
    aob->hit_with_spell(skill*7-roll,0, ob);
    return 1;
  }
  skill = ob->query_skills("bear hug");
  if(skill > roll*2) {
    tell_object(ob,"You give a warm bear hug to "+at+"!\n");
    tell_object(aob, ob->query_name()+" graps you and hugs making you scream in pain!\n");
    aob->hit_with_spell(skill*4-roll,0, ob);
    return 1;
  }
}

