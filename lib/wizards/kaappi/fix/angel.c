/* Paladin spell 'call angel'
   The angel has the same skills than the summoner.
   It tries to cast the spells that it knows.

        //Celtron
*/

#define MAX_LEVEL       30
inherit "/obj/monster";

object owner, angel_spell;
int toughness;                  //affects the angel activity
string *spellwords;

object query_owner() { return owner; }

string *query_spellwords() { return spellwords; }

void reset(int arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(30);
  set_exp(10000);
  set_name("angel");
  set_short("An angel");
  set_al(100);
  set_random_pick(0);
  set_race("angel");
  set_aggressive(0);
  set_special(105);
  call_out("angel_action", 10);
}

string get_adj(int hc) {
  switch(hc) {
  case 0..10 :  toughness = 1;  return "a tiny";
  case 11..30 : toughness = 2;  return "a small";
  case 31..50 : toughness = 3;  return "a fat";
  case 51..70 : toughness = 4;  return "a tall";
  case 71..90 : toughness = 5;  return "a white-winged";
  default     : toughness = 6;  return "an arch";
  }
  return 0;
}

// return 1 if angel can cast the spell
status evaluate_spell(string syllabes) {
  string one, two, three, skill, skill2;
  if(sscanf(syllabes, "%s %s %s", one, two, three) != 3) {
        return 0;
  }
  if(three == "min") skill = "cast minor";
  if(three == "les") skill = "cast lesser";
  if(three == "mar") skill = "cast major";

  /* Second syllabe check */
  if(two == "hea") skill2 = "cast heal";
  if(two == "nam") skill2 = "cast satisfy";
  if(two == "bls") skill2 = "cast bless";
  if(two == "alr") skill2 = "cast holy alteration";
  if(two == "num") skill2 = "cast cure";
  if(two == "xfr") skill2 = "cast transfer";

  /* Old skill evaluate   // Kaappi
  if(owner->query_skills(skill) > 20) return 1;
  else return 0;
  */

  if(owner->query_skills(skill) > 20) {
  if(owner->query_skills(skill2) > 20)  return 1;
  else return 0;
  }
  else return 0;
  }

// spell list at the end of the file
void generate_spellwords() {
  string *spells;
  int i;
  spells = ({ "chl hea mar","chl hea min","chl bls min",
                "chl bls les","chl bls mar","chl nam min","chl nam les",
                "chl nam mar","chl alr min","chl alr mar","chl num mar",
                "chl xfr les", });

  spellwords = ({ });
  for(i=0; i < sizeof(spells); i++) {
    if(evaluate_spell(spells[i])) {
      spellwords = spellwords + ({ spells[i], });
    }
  }

}

// spell_level = min 1, les 2, mar 3
void start_angel(object player, int spell_level) {
  int hc;
  owner = player;
  // fig + apprcleric = 30 levels. max angel (== arch) on level 121
  hc = owner->query_level() - 30;
  if(hc > MAX_LEVEL)
    set_level(MAX_LEVEL);
  else
    set_level(hc);
  set_exp(10000);
  this_object()->set_skill_map(owner->query_skill_map());
  set_short(capitalize(get_adj(hc))+" angel, following "+owner->query_name());
  generate_spellwords();
}

void angel_action() {
  object room, other_angel, myroom;
  int i;

  room = environment(owner);
  myroom = environment(this_object());

  if(!owner) {
    tell_room(myroom, "The masterless angel flies away.\n");
    move_object(this_object(), "/world/special/dump");
    destruct(this_object());
    return;
  }

  if(this_object()->query_attack()) {
    tell_room(myroom, "The angel flies away from harm's way.\n");
    move_object(this_object(), "/world/special/dump");
    destruct(this_object());
    return ;
  }

  other_angel = present("angel", myroom);

// Prevent players from having more than one angel.
  if(other_angel && other_angel != this_object() &&
        file_name(other_angel)[0..22] == "/guilds/spell_obj/angel") {
    tell_room(myroom, "The angels meet and take off together.\n");
    move_object(other_angel, "/world/special/dump");
    destruct(other_angel);
    move_object(this_object(), "/world/special/dump");
    destruct(this_object());
    return;
  }
  if(room != environment(this_object()) ) {
    if(angel_spell) {
      say(short()+" interrupts the spell and flies away.\n");
      destruct(angel_spell);
    }
    move_player("X", room);
  } else if(!angel_spell && !random(8 - toughness)) {

    // if owner is low on hp, cast heal spell

    /* Don't cast true heal if owner is in combat, use minor heal instead. //Kaappi
    if(owner->query_hp() < owner->query_max_hp() / 2) { i = 0; }
    */

    if(owner->query_hp() < owner->query_max_hp() / 2) {
       if(owner->query_attack() && spellwords[0] == "chl hea mar" )
       {i = 1;}
       else { i = 0;}
    }


    else { i = random(sizeof(spellwords)); }
    angel_spell = clone_object("/guilds/obj/spell");
    angel_spell->start_spell(spellwords[i] + " at "+lower_case(owner->query_name()));

  }

  // the angel cannot tolerate if paladin is going berserk
  if(owner->query_berserk()) {
    tell_room(myroom, short()+" senses much anger in "+owner->query_name()+" and flies away.\n");
    move_object(this_object(), "/world/special/dump");
    destruct(this_object());
    return;
  }

  call_out("angel_action", 4);
}

void special_move() {
  if(this_object()->query_attack()) {
    tell_room(environment(this_object()), "The angel flies away from harm's way.\n");
    move_object(this_object(), "/world/special/dump");
    destruct(this_object());
    return ;
  }
}

/*
Minor heal          | mi        | chl hea min | healing
Distant heal        | dh        | chl hea les | healing
Major heal          | ma        | chl hea mar | healing
Regeneration        | reg       | chl bls min | protection
Hitpoint bless      | hpb       | chl bls les | protection
Spellpoint bless    | spb       | chl bls mar | protection
Satisfy thirst      | sat       | chl nam min | neutral
Satisfy hunger      | sah       | chl nam les | neutral
Satisfy all         | saa       | chl nam mar | neutral
Stun resistance     | sr        | chl alr min | protection
Backfire            | bfire     | chl alr mar | protection
Transfer health     | th        | chl xfr les | healing
Remove scar         | rs        | chl num mar | neutra
*/


