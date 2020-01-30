#define BASECOST       12
#define STEP_MAX_COST   330000000 /* 330M maxcost*/

/* overtrain and race skill costs fixed by Celtron. last editted  2x.2.2001 */

/* Want_skill_max is used by functions that need to know if a skill
is spell skill or normal. */

skill_costs(string skill, int pros, arg, want_skill_max, object player) {
  int exp, cost, i, multi;
  string tmp;

  if(!player) player = this_player();

  if (!pros) { pros = player->query_skills(skill); }
  i = 1;

  while(want_skill_max && i<5) {
    if (skill_cost(skill, i)) { return i; }
    i += 1;
  }
  if(skill) {
    if(sscanf(skill, "%s to %s", skill, tmp) == 2) { }
  }

  exp = skill_cost(skill);
  multi = query_train_multiplier(skill, player);
  if (arg == "base_cost")
    return exp;
  if (!arg)
    return step_cost(pros, exp, multi);
  return get_next_exp(exp, multi);
}
/* multiplier is in percents */
query_train_multiplier(string skill, object player) {
  if(skill_cost(skill,1) || skill_cost(skill,2)) {
    return "/daemons/race_stats"->query_race_stat(player->query_race(), "skill_cost");
  } else if(skill_cost(skill,3) || skill_cost(skill,4)) {
    return "/daemons/race_stats"->query_race_stat(player->query_race(), "spell_cost");
  }
  return "error";
}

/*  returns the step_cost */
/*  cost = sk_cost * sk_cost * percent * percent * percent * multi * BASECOST /100 /100; */
    /* [1,10]^2 * [1,100]^3 * [1,20] / 100 * [70,400] / 100  = cost */
    /*    e2         e6         e1     -e2      e2      -e2  = e9 - e2 */
int step_cost(int percent, int sk_cost, int multi) {

  int part1, part2, cost;
  part1 = sk_cost * sk_cost;
  part2 = percent * percent * percent; /* max 100^3 = 1000000 = 1M */

  if(part2 > 10000) cost = (part1 * multi * BASECOST / 100) * (part2 / 100);
  else if(part2 > 1000) cost = (part1 * part2) / 100 * (multi * BASECOST) / 100;
  else cost = (part1 * part2 * multi * BASECOST) / 10000;
  if(cost > STEP_MAX_COST) cost = STEP_MAX_COST;
  if (cost < 10) { cost = percent+1; }
  return cost;
}

get_next_exp(int expa, int multi) {
  int exp_str;
  int i;
  exp_str = allocate(102);
   while (i < 101) {
    i += 1;
    exp_str[i] = step_cost(i,expa,multi);
  }
  return exp_str;
}

get_skill_cost_adjective(string skill) {
  int i;
  i = skill_cost(skill);
  if(i == 1) return "  very easy";
  if(i == 2) return "       easy";
  if(i == 3) return " quite easy";
  if(i == 4) return "challenging";
  if(i == 5) return "complicated";
  if(i == 6) return "complicated";
  if(i == 7) return "       hard";
  if(i == 8) return "       hard";
  if(i == 9) return "  very hard";
 if(i == 10) return "  very hard";
  return "No skillcost defined";
}

/* 1 - 10.
  1 useless
  2 almost useless
  3 newbie skill
  4 advanced newbie
  5 midbie skill
  6 adv midbie
  7 almost highbie
  8 highbie
  9 very expensive
 10 out-of-tune skill
*/


skill_cost(string skill, int class) {
  switch(skill) {
  case "first aid": return 4;
  case "consider demon": return 1;
  case "assault": return 6;
  case "first assault": return 8;
  case "focus power": return 10;
  case "anatomy": return 6;
  case "sharpen": return 6;
  case "repair weapon": return 5;
  case "polish": return 4;
  case "evaluate": return 1;
  case "bargain": return 4;
  case "hunting":return 1;
  case "hiking":return 3;
  case "torch creation":return 1;
  case "consider":return 1;
  case "meditate":return 3;
  case "fire building": return 1;
  case "calm down":return 1;
  case "camping":return 2;
  case "bravery":return 3;
  case "coordination":return 5;
  case "rage":return 5;
  case "fury":return 5;
  case "berserk":return 6;
  case "agility":return 10;
  case "tame animal":return 5;
  case "disarm":return 7;
  case "dark lore":return 2;
  case "defend":return 6;
  case "body building": return 6;
  case "endurance": return 8;
  case "freeze corpse": return 4;

case "seal wounds": return 4;
case "meditation": return 3;
case "focus elements": return 6;
case "power of ice": return 7;
case "power of fire": return 7;
case "power of thunder": return 7;
case "body anatomy": return 9;
case "mastery of meditation": return 4;

case "charm": return 2;
case "shake mind": return 3;
case "confuse": return 4;
case "iron will": return 3;
case "mental denial": return 3;
case "mental drain": return 2;
case "mental expansion": return 3;
case "mental balance": return 4;
case "mental scan": return 2;
case "mental view": return 2;
case "mental pocket": return 1;

case "shaldrin": return 10;
case "summon dragon": return 10;

case "identify vial": return 1;
case "create vial": return 2;
case "search herbs": return 5;
case "extract blood": return 4;
case "summon cauldron": return 1;
case "prepare potion": return 4;
case "herbalist knowledge": return 10;
case "make potion": return 5;
case "throw vial": return 5;
case "lubricate vial": return 6;
case "identify herb": return 2;
case "herbs knowledge": return 7;
case "speedcrafting": return 6;

//Archer things
case "craftmanship":return 1;
case "fletchery":return 1;
case "shooting":return 1;
case "faster shots":return 1;
case "markmanship":return 1;
case "aim":return 1;
case "critical shots":return 1;

}


 if(class == 1) { return 0; }
  switch(skill) {
  case "chaos bludgeons":return 3;
  case "chaos blades":return 6;
  case "chaos axes":return 9;
  case "punch":return 1;
  case "bare hands":return 1;
  case "bludgeons":return 2;
  case "blades":return 4;
  case "axes":return 7;
  case "pound":return 4;
  case "slash":return 6;
  case "cut":return 9;
  case "riposte":return 3;
  case "attack":return 2;
  case "shield parry":return 4;
  case "parry":return 4;
  case "dodge": return 5;
  case "critical":return 5;
  case "control animal":return 4;
  case "shield bash":return 5;
  case "weapon parry":return 6;
  case "stun":return 6;
  case "alertness":return 6;
  case "stomp":return 6;
  case "throw weight":return 6;
  case "two weapons combat":return 4;
  case "doublehit":return 7;
  case "ignore wrong strike": return 8;
  case "stunned maneuvers":return 8;
  case "inner strength":return 6;
  case "find weakness":return 8;
  case "foresee attack":return 8;
  case "tumble":return 8;
  case "deceived attack":return 9;
  case "enhance criticals":return 8;
  case "first strike":return 9;
  case "chaos strike": return 3;
  case "tremendous blow":return 8;
  case "kick":return 2;
  case "round blow":return 4;
  case "charge rush":return 6;
  case "strike":return 4;
  case "stab":return 8;
  case "double strike":return 6;
  case "battlecry":return 6;


//martial artists new things
case "martial arts": return 6;
case "advanced martial arts": return 7;
case "whirlwind": return 6;
case "focused sky strike": return 9;
case "focused shadow blow": return 5;
case "dragon blow": return 3;
case "claws storm": return 6;
case "sky strike": return 9;
case "shadow blow": return 4;


case "mental force": return 5;
case "overload brain": return 4;
case "simultaneous thought": return 3;
case "evading thought": return 5;
case "mental block": return 4;
case "mental strike": return 1;
case "mental disrupt": return 3;
case "mental light": return 1;
case "knowledge of mind": return 6;
}
  if(class == 2) { return 0; }
  switch(skill) {
  case "chanting":return 6;
  case "create scroll":return 3;
  case "clear scroll":return 1;
  case "literacy":return 7;
  case "scribble":return 6;
  case "mana control":return 6;
  case "channel":return 6;
  case "mastery of earth":return 4;
  case "knowledge of heat":return 5;
  case "lore of cold":return 5;
  case "lore of poison":return 6;
  case "theory of electricity":return 6;
  case "quick chant": return 9;
  case "quick spelling": return 10;
  case "elusive spellcasting":return 6;
  case "counter spell":return 8;
  case "reflect spell": return 9;
  case "power channeling": return 3;
  case "power focusing":return 5;
  case "power concentration":return 7;
  case "distract concentration": return 6;
  case "stunning blast":return 7;
  case "enhance blast":return 10;
  case "proximity blast":return 6;
  case "mastery of medicine":return 9;
  case "navigation mastery": return 10;
  case "mastery of commerce": return 8;
  case "invoke ethereal mana": return 10;
  case "mental unity": return 5;

  case "dark power": return 7;
  case "knowledge of animation": return 7;
  case "control corporeal": return 6;
  case "control ethereal": return 7;
  case "control dark magic": return 8;
  case "control greater undead": return 9;
  case "enhance weakness": return 10;
  case "mastery of protection": return 9;
  case "shielding mastery": return 8;
  case "abjuration": return 6;
//Warlock
  case "essence of chaos": return 8;
  case "knowledge of summoning": return 8;
  case "knowledge of chaos": return 6;
  case "soul channeling": return 7;
  case "remove purity": return 5;
  case "knowledge of mage": return 9;
  case "knowledge of fighter": return 10;
  case "knowledge of cleric": return 8;
  }
  if(class == 3) { return 0; }
  switch(skill) {
  case "cast information":return 4;
  case "cast teleport":return 6;
  case "cast locate":return 7;
  case "cast relocate":return 7;
  case "cast create":return 5;
  case "cast trade":return 6;
  case "cast identify":return 3;
  case "cast illusion":return 7;
  case "cast storm":return 6;
  case "cast earth":return 1;
  case "cast fire":return 3;
  case "cast ice":return 3;
  case "cast electric":return 4;
  case "cast essence":return 1;
  case "cast bolt":return 1;
  case "cast poison":return 3;
  case "cast force field":return 7;

  case "cast cure":return 4;
  case "cast transfer":return 1;
  case "cast heal":return 1;
  case "cast alignment":return 3;
  case "cast bless":return 5;
  case "cast soul":return 6;
  case "cast divine":return 1;
  case "cast minor":return 1;
  case "cast lesser":return 4;
  case "cast major":return 7;
  case "cast wide":return 8;
  case "cast satisfy": return 1;

  case "cast dark power":return 2;
  case "knowledge of animation": return 7;
  case "control corporeal": return 6;
  case "control ethereal": return 7;
  case "control dark magic": return 8;
  case "control greater undead": return 9;

  case "enhance weakness": return 10;
  case "mastery of protection": return 9;
  case "shielding mastery": return 8;
  case "abjuration": return 6;
//Warlock
  case "essence of chaos": return 8;
  case "knowledge of summoning": return 8;
  case "knowledge of chaos": return 6;
  case "soul channeling": return 7;
  case "remove purity": return 5;
  case "knowledge of mage": return 9;
  case "knowledge of fighter": return 10;
  case "knowledge of cleric": return 8;
  }
  if(class == 3) { return 0; }
  switch(skill) {
  case "cast information":return 4;
  case "cast teleport":return 6;
  case "cast locate":return 7;
  case "cast relocate":return 7;
  case "cast create":return 5;
  case "cast trade":return 6;
  case "cast identify":return 3;
  case "cast illusion":return 7;
  case "cast storm":return 6;
  case "cast earth":return 1;
  case "cast fire":return 3;
  case "cast ice":return 3;
  case "cast electric":return 4;
  case "cast essence":return 1;
  case "cast bolt":return 1;
  case "cast poison":return 3;
  case "cast force field":return 7;

  case "cast cure":return 4;
  case "cast transfer":return 1;
  case "cast heal":return 1;
  case "cast alignment":return 3;
  case "cast bless":return 5;
  case "cast soul":return 6;
  case "cast divine":return 1;
  case "cast minor":return 1;
  case "cast lesser":return 4;
  case "cast major":return 7;
  case "cast wide":return 8;
  case "cast satisfy": return 1;

  case "cast dark power":return 2;
  case "cast raise corporeal":return 2;
  case "cast raise ethereal": return 4;
  case "cast unholy arms":return 7;
  case "cast minor necromancy":return 2;
  case "cast major necromancy":return 5;

  case "cast supreme necromancy": return 9;
  case "cast focus dark power": return 2;
  case "cast unholy enchantment": return 6;
  case "cast raise soul": return 3;

  case "cast abjuration": return 2;
  case "cast alteration": return 4;
  case "cast protection": return 3;
  case "cast vulnerability": return 5;
  case "cast antimagic": return 6;
  case "cast sorcery": return 7;
  case "cast enchantment": return 7;
  case "cast holy alteration": return 8;
//warlock lappaa
  case "cast plane of chaos": return 3;
  case "cast beast control": return 5;
  case "cast warmth of chaos": return 6;
  case "cast aid of chaos": return 4;
  case "cast chaos sheltering": return 4;
  case "cast anvil of chaos": return 5;
  case "cast blessing of chaos": return 3;
  case "cast void travel": return 4;
  case "cast forge of chaos": return 5;
  case "cast ritual of chaos": return 9;
  case "cast lesser chaos": return 2;
  case "cast minor chaos": return 4;
  case "cast greater chaos": return 6;

  }
  if(class == 4) { return 0; }
}
/*
  if (skill == "massage") { exp = 50; }
  if (skill == "anatomy") { exp = 220; }
  if (skill == "meditation") { exp = 50; }
  if (skill == "knowledge of the way") { exp = 10; }
  if (skill == "knowledge of kata") { exp = 10; }
  if (skill == "sacrifice ritual") { exp (skill == "nerve mastery") { exp = 320; }
  if (skill == "hit combing") { exp = 350; }
  if (skill == "combined martial arts") { exp = 600; }
  if (skill == "ambidexterous attack") { exp = 300; }
  if (skill == "headbang") { exp = 300; }
  if (skill == "mental balance") { exp = 30; }
  if (skill == "breath control") { exp = 320; }
  if (skill == "sixth instinct") { exp = 270; }
  if (skill == "spinkick") { exp = 80; }
  if (skill == "cranekick") { exp = 230; }
  if (skill == "zutsu") { exp = 260; }
  if (skill == "hiodu") { exp = 130; }
  if (skill == "sly hands") { exp = 40; }
  if (skill == "sneaky hands") { exp = 50; }
  if (skill == "blazing speed") { exp = 50; }
  if (skill == "flying hands") { exp = 50; }
  if (skill == "feeding hands") { exp = 50; }
  if (skill == "sticky hands") { exp = 80; }
  if (skill == "thunderclap") { exp = 100; }
  if (skill == "moving rock") { exp = 100; }
  if (skill == "dragonclaws") { exp = 100; }
  if (skill == "hunting hands") { exp = 100; }
  if (skill == "slicing blade") { exp = 150; }
  if (skill == "sneaky wind") { exp = 200; }
  if (skill == "sharp lightning") { exp = 200; }
  if (skill == "invisible storm") { exp = 200; }
  if (skill == "bloodhunt") { exp = 200; }
  if (skill == "sweeping slit") { exp = 80; }
  if (skill == "deep thrust") { exp = 200; }
  if (skill == "slaughter slash") { exp = 350; }
  if (skill == "dancing edge") { exp = 225; }
*/

