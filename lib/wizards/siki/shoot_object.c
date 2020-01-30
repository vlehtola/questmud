#define base_time 10
#define TP_NAME this_player()->query_name()
#define TAR_NAME target->query_name()
#define TAR_POS target->query_possessive()
#define TAR_PRO target->query_pronoun()

object target, with, p_ob;
int time, damage, hit_chance, crit_chance;
string damage_type;
string file_en;
id(str) {
  return str == "shoot_object";
}
drop() {
  return 1;
}
get() {
  return 1;
}
//command shoot, clones this object and calls start->shoot with 'bow' and 'target'
start_shoot(w, t) {
  int time;
  with = present(w, this_player());
  if(!with) { write("You don't have such thing as '"+w+"' to shoot with.\n"); stop_shoot(); return 1; }
  if(!with->is_shootable()) { write("You can't shoot with '"+w+"'.\n"); stop_shoot();  return 1; }
  target = present(t, environment(this_player()));
  if(!target) { write("No such target present as '"+t+"'\n");  stop_shoot(); return 1; }
  if(!living(target)) { write(t+" is not a valid target.\n");  stop_shoot(); return 1; }
  if(!with->query_reload()) { write("You can't shoot with the '"+w+"' because its not loaded!\n"); stop_shoot(); return 1; }
  p_ob = this_player()->query_party();
  if(this_player()->query_attack() && p_ob && p_ob->first_in_row(this_player())) {
  write("You can't shoot anything while attacking.\n");
  stop_shoot();
  return 1;
}
  if(this_player()->query_stunned()) {
  write("You are unable to shoot anything while stunned.\n");
  stop_shoot();
  return 1;
}

  time = get_shoot_time();
  if(this_player()->query_wiz())write("Shoot time is :"+time+".\n");
  write("You start aiming your "+w+" at the "+t+".\n");
  say(TP_NAME+" starts aiming "+this_player()->query_possessive()+" "+w+".\n");
  call_out("resolve_shoot", time);
  file_en = file_name(environment(this_player()));
  return 1;
}

resolve_shoot() {
  if(file_en != file_name(environment(this_player()))) {
	  write("Your movement has interrupted the shooting attempt!\n");
	  stop_shoot();
	  return 1;
  }
  if(!target) {
	  write("Your target is not present.\n");
	  stop_shoot();
	  return 1;
  }
  if(this_player()->query_stunned()) {
  write("You are unable to shoot anything while stunned.\n");
  stop_shoot();
  return 1;
  }
  hit_chance = this_player()->query_skills("shooting")+this_player()->query_skills("markmanship");
  hit_chance += with->query_hit_chance();
  crit_chance = with->query_crit_chance()+this_player()->query_skills("critical shots")/2;
  if(random(110) > this_player()->query_skills("shooting")) {
  write("You fail your shooting attempt.\n");
  say(TP_NAME+" fails to shoot anything.\n");
  this_player()->attack_object(target);
  if(!random(10)) { fumble_shot(random(100)); }
  if(with) { with->end_shoot(); }
  stop_shoot();
  return 1;
}
if(random(170) > hit_chance) {
  write("You release your hold from the "+with->query_name()+" and try to aim directly at the "+TAR_NAME+" but miss!\n");
  tell_object(target, TP_NAME+" try's to aim you with "+this_player()->query_possessive()+" "+with->query_name()+" but misses!\n");
  say(TP_NAME+" try's to aim at the "+TAR_NAME+" with "+this_player()->query_possessive()+" "+with->query_name()+" but misses!\n",target);
  if(!random(20)) { fumble_shot(random(80)); }
  this_player()->attack_object(target);
  if(with) { with->end_shoot(); }
  stop_shoot();
  return 1;
}

damage = with->query_quality()*with->query_damage()+with->query_arrow_quality();
damage += this_player()->query_skills("markmanship");
damage = damage+(random(damage)*2)/4;
if(damage > 500){ damage = 500; }
damage_type = "physical";
if(this_player()->query_wiz())write("Damage: "+damage+" and Damage_Type: "+damage_type+"\n");
write("You release your hand from the bowstring and try to hit "+TAR_NAME+".\n");
say(TP_NAME+" releases "+this_player()->query_possessive()+" hand from the bowstring and try's to hit "+TAR_NAME+".\n",target);
tell_object(target, TP_NAME+" releases "+this_player()->query_possessive()+" hand from the bowstring and try's to hit you!\n");
this_player()->attack_object(target);
  if(with) { with->end_shoot(); }
if(!random(50)) { fumble_shot(random(50)); stop_shoot(); return 1; }
write_messages(damage);
if(random(150) < random(crit_chance)) {
write("With your shot you SCORE CRITICAL HIT!\n");
damage = damage*3/2;
}
target->hit_with_spell(damage, damage_type);
with->end_shoot();
stop_shoot();
return 1;
}
get_hit_chance() {
	int i;
}
get_crit_chance() {
	int i;
}
get_damage() {
	int i;
}

get_shoot_time() {
	int i, tmp;
	i = base_time+with->query_shoot_time();
	tmp = (this_player()->query_skills("faster shots")+this_player()->query_skills("markmanship"))/15;
	i -= tmp;
	i = i/2;
	write("Shooting time is:"+i+"\n");
	if(i < 5) { i=5; }
	if(i > 30) { i=30; }
	return i;
}

//Stops the shooting attempt
stop_shoot() {
remove_call_out("resolve_shoot");
if(this_object()) { destruct(this_object()); }
return 1;
}

//displays the different messages
write_messages(int dam) {
		switch(dam) {
		case 0..29:
		tell_object(this_player(), "Your arrow almost bounces off the "+TAR_NAME+"'s body!");
		tell_object(target, TP_NAME+" shoots at you but the missile just bounces off your armour!");
		say(TP_NAME+" shoots at "+TAR_NAME+" but the missile just bounces off the "+TAR_NAME+" armour.\n", target);
		break;
		case 30..59:
		tell_object(this_player(), "The arrow sinks inside the "+TAR_NAME+"'s flesh!");
		tell_object(target, "The arrow shoot by "+TP_NAME+" sinks inside your flesh!");
		say(TP_NAME+" shoots at "+TAR_NAME+" and the arrow sinks deep in the flesh of "+TAR_NAME+".\n", target);
		break;
		case 60..89:
		tell_object(this_player(), "Your arrow sinks deep inside the "+TAR_NAME+"'s flesh making "+TAR_POS+" wounds to bleed little!");
		tell_object(target, "The arrow shoot by "+TP_NAME+" sinks deep inside your flesh making the wound bleed a little!");
		say("The arrow sinks deep inside the "+TAR_NAME+"'s flesh making the wound bleed little.\n", target);
		break;
		case 90..119:
		tell_object(this_player(), "Your arrow penetrates the "+TAR_NAME+"'s armour almost totaly making harmfully looking wound!");
		tell_object(target, "The arrow shoot by "+TP_NAME+" penetrates your armour almost totaly making harmfully looking wound!");
		say("The arrow penetrates the "+TAR_NAME+"'s armour making harmfully looking wound.\n", target);
		break;
		case 120..149:
		tell_object(this_player(), "The arrow PENETRATES the "+TAR_NAME+"'s armour and "+TAR_PRO+" drops on the ground holding the WOUND!");
		tell_object(target, "The arrow PENETRATES your armour and you drop on the ground holding the WOUND!");
		say("The arrow PENETRATES the "+TAR_NAME+"'s armour making "+TAR_POS+" drop on a ground holding the WOUND!\n", target);
		break;
case 150..179:
tell_object(this_player(), "Your shot goes wide and barely scrapes the "+TAR_NAME+" elbow!\n");
tell_object(target, "The arrow goes little wide and barely scrapes your elbow!\n");
say("The arrow goes wide and only makes a little scrapes at the "+TAR_NAME+" elbow.\n", target);
break;
case 180..209:
tell_object(this_player(), "You release your bow and the arrow hits "+TAR_NAME+" but does only mediocre looking wounds!.\n");
tell_object(target, "The arrow hits you directly but only makes mediocre looking wounds!\n");
say("The arrow hits directly at the "+TAR_NAME+" making mediocre looking wounds!\n", target);
break;
case 210..239:
tell_object(this_player(), "You stretch the bow for more power and manage to PLUNGE your arrow deep into "+TAR_NAME+" flesh!\n");
tell_object(target, "The arrow PLUNGE'S deep into your FLESH\n");
say("The arrow PLUNGE'S deep in the flesh of "+TAR_NAME+"\n", target);
break;
case 240..269:
tell_object(this_player(), "You hear the crunching sound of breaking bones as your precicely aimed arrow hits "+TAR_NAME+".\n");
tell_object(target, "You hear crunching sound of the breaking bones as the arrow hits your chest!\n");
say("As the arrow hits "+TAR_NAME+" a crunching sound of the breaking bones can be heard!\n", target);
break;
case 270..299:
tell_object(this_player(), "You release the arrow and watch it CUT its way DEEP into "+TAR_NAME+" torso!\n");
tell_object(target, "The arrow CUTS DEEP into your TORSO making bones to break!\n");
say("The arrow CUTS DEEP into the TORSO of "+TAR_NAME+" breaking bones!\n", target);
break;
case 300..329:
tell_object(this_player(), "The arrow CUTS it way DEEP into the "+TAR_NAME+" chest making bones to BREAK!\n");
tell_object(target, "The arrow CUTS its way DEEP into your chest making bones to BREAK!\n");
say("The arrow CUTS its way DEEP into the chest of "+TAR_NAME+" making BONES to BREAK!\n", target);
break;
case 330..359:
tell_object(this_player(), "Your precise shot goes deep in the "+TAR_NAME+" chest, making a FLOOD of BLOOD!\n");
tell_object(target, "The precise shot of "+TP_NAME+" goes deep in your chest, MAKING a FLOOD of BLOOD!");
say("The precise shot of "+TP_NAME+" goes deep in the chest of "+TAR_NAME+" and making a FLOOD of BLOOD!\n", target);
break;
case 360..399:
tell_object(this_player(), "Your POWERFUL and PRECISE shot goes DEEP in the "+TAR_NAME+"'s stomach, causing a MASSIVE FLOOD of blood and tissue!\n");
tell_object(target, "The arrow GOES DEEP into your stomach CAUSING MASSIVE FLOOD of blood and tissue!\n");
say("The arrow GOES DEEP into the stomach of "+TAR_NAME+" CAUSING MASSIVE LOOKING FLOOD of blood and TISSUE!\n", target);
break;
case 400..449:
tell_object(this_player(), "Your precise shot GOES directly in the eye of "+TAR_NAME+", MAKING a TOTAL MESS of the brains!\n");
tell_object(target, "The precise shot of "+TAR_NAME+" GOES DIRECTLY into your eye MAKING TOTAL MESS OF THE BRAINS!\n");
say("The precise shot of "+TP_NAME+" GOES DIRECTLY into "+TAR_NAME+"'s eye MAKING a TOTAL MESS of the BRAINS!\n", target);
break;
case 450..500:
tell_object(this_player(), "The arrow PENETRATES the "+TAR_NAME+" THROAT and "+TAR_PRO+" drops on the GROUND SCREAMING IN PAIN!\n");
tell_object(target, "The ARROW PENETRATES Your THROAT and you DROP ON THE GROUND SCREAMING in PAIN!\n");
say("The arrow PENETRATES "+TAR_NAME+"'s THROAT and "+TAR_PRO+" DROPS on the GROUND SCREAMING in PAIN!\n", target);
break;
}
}

fumble_shot(int what) {
	object ob;
	int i;
	ob = all_inventory(environment(this_player()));
	switch(what) {
	case 0..30:
	write("You fumble your shot and the bowstring hits directly at your fingers forcing you to drop your "+with->short()+".\n");
	say(TP_NAME+" accidently fumbles the shots and drops "+with->short()+".\n");
	move_object(with, environment(this_player()));
	break;
	case 31..60:
	write("You fumble your shooting attempt and the missile slowly drops to the ground.\n");
	say(TP_NAME+" fumbles the shooting attempt and the missile slowly drops to the ground.\n");
	break;
	case 61..75:
	for(i=0;i<sizeof(ob);i++) {
	if(living(ob[i]) && ob[i] != this_player()) {
	write("You fumble your shot and the arrow hits "+ob[i]->query_name()+".\n");
	tell_object(ob[i], TP_NAME+" fumbles a shot and the arrow hits directly at you!\n");
	say(TP_NAME+" fumbles the shot and the arrow hits at "+ob[i]->query_name()+".\n",ob[i]);
	ob[i]->hit_with_spell(random(100)*(random(3)+1), "physical");
	return 1;
}
}
	break;
	case 76..85:
	write("You fumble your shot and the "+with->short()+" breaks!\n");
	say(TP_NAME+" fumbles a shot and the "+with->short()+" breaks!\n");
	destruct(with);
	break;
	case 86..95:
	for(i=0;i<sizeof(ob);i++) {
	if(living(ob[i]) && ob[i] != this_player()) {
	write("You fumble your shot and the arrow hits "+ob[i]->query_name()+" critically piercing tendons!.\n");
	tell_object(ob[i], TP_NAME+" fumbles a shot and the arrow hits critically at you!\n");
	say(TP_NAME+" fumbles the shot and the arrow hits critically at "+ob[i]->query_name()+".\n",ob[i]);
	ob[i]->hit_with_spell(random(300)*(random(4)+1), "physical");
	return 1;
}
}
	break;
	case 96..100:
	write("You pull hard from the bowstring managing only to break the "+with->short()+" then the string hits your finger hard!\n");
	this_player()->set_stunned(random(2)+1);
	destruct(with);
	break;
}
}