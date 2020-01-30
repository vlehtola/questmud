check(type, class, caster_ob) {
  int modifier, pros, rnd;
  string skill;
  if (type == "min") { modifier = 30; }
  if (type == "les") { modifier = 50; }
  if (type == "mar") { modifier = 70; }
  skill = call_other("/guilds/obj/spellfun","get_skill_num", type);
  if (!skill) { return 0; }
  pros = caster_ob->query_skills(skill);
  rnd = random(modifier) / (random(2)+1) +1;
  if(caster_ob->query_tester())
    tell_object(caster_ob, "Chance>rnd:"+pros+">"+rnd+"\n");
  if (pros < rnd) {
    tell_object(caster_ob, "The complicity of the spell confounds you, causing you to fail. ("+(pros*100/rnd)+"%)\n");
    tell_room(environment(caster_ob), caster_ob->query_name()+" fails the spell.\n", ({caster_ob}));
    return 0;
  }
  return 1;
}
