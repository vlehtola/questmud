offensive_boost(int boost, int texts, caster_ob) {
    int damage,skill,value,ratio,total_boost,va;
    if(!caster_ob)caster_ob=this_player();
    if(texts) tell_object(caster_ob, "Displayed values are relevant to your personal skill knowledge.\n");
    total_boost = boost;
    skill = caster_ob->query_skills("power concentration");
    value = (80 * skill) / 100;
    if (boost > value) {
      boost -= value;
      damage += (value * 9) / 2;
    } else { damage += (boost * 9) / 2; boost = 0; }
    if (texts) {
	va = value;
	tell_object(caster_ob, "Skill 'power concentration' affects the damage/sp ratio "+
		"between 0 and "+va+" sps.\n");
    }
    skill = caster_ob->query_skills("power focusing");
    value = (200 * skill) / 100;
    if (boost > value) {
      boost -= value;
      damage += value * 3;
    } else { damage += boost * 3; boost = 0; }
    if (texts) {
      tell_object(caster_ob, "Skill 'power focusing' affects the damage/sp ratio "+
	"between "+va);
	va += value;
      tell_object(caster_ob, " and "+va+" sps.\n");
    }

    skill = caster_ob->query_skills("power channeling");
    value = (400 * skill) / 100;
    if (boost > value) {
      boost -= value;
      damage += value * 2;
    } else { damage += boost * 2; boost = 0; }
    if (texts) {
      tell_object(caster_ob, "Skill 'power channeling' affects the damage/sp ratio "+
	"between "+va);
	va += value;
      tell_object(caster_ob," and "+va+" sps.\n");
    }
    damage += boost;

    if (texts && total_boost) {
	ratio = damage / total_boost;
	tell_object(caster_ob,"Your damage per spellpoint ratio is ");
	if (ratio < 2) { write("very low.\n"); }
	if (ratio == 2) { write("low.\n"); }
	if (ratio == 3) { write("average.\n"); }
	if (ratio == 4) { write("good.\n"); }
	if (ratio > 4) { write("excellent.\n"); }
    }
    return damage;
}
