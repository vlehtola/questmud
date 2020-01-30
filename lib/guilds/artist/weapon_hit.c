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
    return;
  }
  skill = ob->query_skills("dancing edge");
  if(dam && roll*2 < skill) {
    dam += 60;
    text += " and make a quick slash aiming eyes.\n";
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

  skill = ob->query_skills("slit sweep");
  if(roll > skill) { return 0; }
  text = "";
  dam = 50;

  skill = ob->query_skills("deep thrust");
  if(roll+10 > skill) { return 0; }
  text = "You thrust your sword towards "+at+"'s stomach";
  dam = 70;

  skill = ob->query_skills("slaughter slash");
  if(roll+20 > skill) { return 0; }
  text = "You aim a vile slash to "+at+"'s ribs trying to puncture the ribcage";
  dam = 100;

  return 0;
}  

