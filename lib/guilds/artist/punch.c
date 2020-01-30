int dam,i,tmp,roll;
int skill;
string at,text;
object ob, target;

resolve_hit(o) {
  ob = o;
  at = call_other(ob->query_attack(), "query_name");

  get_type();
  if(!dam) {
    tell_object(ob, text+".\n");
    return 0;
  }
  skill = ob->query_skills("elbow blow");
  if(roll*3 < skill) {
    dam += 60;
    text += " and continue your hit with an elbow blow.\n";
  } else {
    text = text+".\n";
  }
  ob->set_text(text);
  return dam;
}

get_type() {
  roll = random(100)+11;
  roll -= ob->query_dex()/10;
  dam = 0;
  text = "You don't manage to hit "+at;

  skill = ob->query_skills("fast punch");
  if(roll > skill) { return 0; }
  text = "You punch "+at+" quickly";
  dam = 50;

  skill = ob->query_skills("armored fist");
  if(roll > skill) { return 0; }
  text = "You instantly punch "+at+" with sheer force";
  dam = 70;

  skill = ob->query_skills("cutter hand");
  if(roll > skill) { return 0; }
  text = "You direct a puncturing cutter hand blow towards "+at+"'s neck";
  dam = 100;

  return 0;
}  

