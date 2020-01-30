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

  skill = ob->query_skills("double bear strike");
  skill -= aob->query_level();

  if(skill > 2*roll) {
    tell_object(ob, "You stand up and strike, strike and STRIKE "+at+"!\n");
    tell_object(aob, ob->query_name()+" strikes you in the head making your vision to blur!\n");
    aob->hit_with_spell(skill*7-roll,0, ob);
    return 1;
  }
  skill = ob->query_skills("bear strike");
  if(skill > roll*2) {
    tell_object(ob,"You run towars "+at+" and strike with your razor sharp claws!\n");
    tell_object(aob, ob->query_name()+" strikes you with razor sharp claws!\n");
    aob->hit_with_spell(skill*4-roll,0, ob);
    return 1;
  }
}

