string at;
object ob,aob;
int skill;

resolve_hit(o) {
  int roll;
  ob = o;
  aob = ob->query_attack();
  if(!aob) return;
  at = aob->query_name();
  skill = ob->query_skills("knowledge of the fists");

  if(ob->query_skills("tigers punch") > random(600)); {
    tell_object(ob, "You aim a CRUSHING punch in "+at+"'s undefended throat!\n");
    tell_object(aob, ob->query_name()+" hits you in the throat CRUSHING your windpipe!\n");
    aob->hit_with_spell(200 + skill,0, ob);
    return 1;
  }
    if(ob->query_skills("head bang") > random(400)); {
    tell_object(ob,"You pull "+at+"'s head closer and give "+aob->query_objective()+
        " a CRUEL headbang!\n");
    tell_object(aob, ob->query_name()+" rips your head forward and gives you a CRUEL headbang!\n");
    aob->hit_with_spell(100 + skill,0, ob);
    return 1;
  }
    if(ob->query_skills("flying kick") > random(500)); {
    tell_object(ob,"You jump towards "+at+" and kick him BRUTALLY in head!\n");
    tell_object(aob, ob->query_name()+" kicks you BRUTALLY in head!\n");
    aob->hit_with_spell(300 + skill,0, ob);
    return 1;
  }
    if(ob->query_skills("Razor wings") > random(1000)); {
    tell_object(ob,"You run towards "+at+" and TEAR "+aob->query_objective()+" body!\n");
    tell_object(aob, ob->query_name()+" runs towards you and TEARS your body brutally!\n");
    aob->hit_with_spell(500 + skill*2,0, ob);
    return 1;
  }
}

