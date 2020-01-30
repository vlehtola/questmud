int dam,i,tmp,roll;
int skill;
string at,text;
object ob, target;

resolve_hit(o) {
  ob = o;
  at = call_other(ob->query_attack(), "query_name");
  get_type();
  if(!dam) {
    tell_object(ob, text+"\n");
    return 0;
  }
  ob->set_text(text);
  return dam;
}

get_type() {
  roll = random(100)+11;
  roll -= ob->query_dex()/10;
  text = "You miss "+at+" with your kick.";
  dam = 0;

  skill = ob->query_skills("snapkick");
  if(roll > skill) return 0;
  dam = 50;
  text = "You hear a short snap as your kick hits "+at+".";

  skill = ob->query_skills("sidekick");
  if(roll > skill) return 0;
  dam = 70;
  text = "You turn your hip and send out a mighty sidekick towards "+at+"!";

  skill = ob->query_skills("turnkick");
  if(roll > skill) return 0;
  dam = 100;
  text = "You spin around and complete your turnkick aiming "+at+"'s temple with your heel!";

  return 0;
}  

