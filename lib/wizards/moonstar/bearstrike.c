  int dam,i,tmp,roll;
  int skill;
  string at,text;
  object ob, target;

resolve_hit(o) {
  ob = o;

  //Rag was here
  if (ob->query_attack()) {
    at = ob->query_attack()->query_name();
  } else {
   tell_object(ob,"No target.\n");
   return 1;
  }

  get_type();
  if(!dam) {
    tell_object(ob, text+".\n");
    return;
  }
  skill = ob->query_skills("double bear strike");
  if(dam && roll*2 < skill) {
    dam += 80;
    text += " and make another quick bear strike aiming eyes.\n";
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
  text = "You don't manage to strike "+at;

  skill = ob->query_skills("bear strike");
  if(roll+20 > skill) { return 0; }
  text = "You aim a vile strike to "+at+"'s ribs trying to puncture the ribcage";
  dam = 200;
     if(this_player()->query_wiz()) write("Damage: "+dam+"\n");
     this_player()->query_attack()->hit_with_spell(dam, "physical");
  return 0;
}

