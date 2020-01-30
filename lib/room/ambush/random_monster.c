inherit "/obj/monster";
#define DIR "/room/ambush/monster_descs/"
#define ATTACK_DELAY	20 /*sec*/

start() {
  set_name("monster");
  set_short("Ambush monster");
  set_block_dir("leave");
}

set_ambush_race(string race, int oma_level) {
  int i, start, time;
  string file, *files;
  /* orc lienee lyhyin race name */
  files = get_dir(DIR+race[0..2]+"*");
  oma_level = oma_level /10;
  if(oma_level >= sizeof(files)) oma_level = sizeof(files)-1;
  file = files[oma_level];
  /* get the descs */
  set_name(race);
  set_alias("bandit");
  short_desc = read_file(DIR+file, start, start+1);
  if(sscanf(short_desc, "%s\n", short_desc) == 1) { }
  long_desc = read_file(DIR+file, start+1, start+5) +"\n";
  time = random(ATTACK_DELAY);
  call_out("ambush_delay", ATTACK_DELAY-time, time);
}

ambush_delay(int time) {
  if(!this_object()->query_attacker())
	say(short()+" seems to have hostile intentions.\n");
  call_out("ambush_attack", time);
}

ambush_attack() {
  object ob;
  int i;
  set_aggressive(1);
  environment(this_object())->allow_flee();
  if(this_object()->query_attacker()) return;

  ob = all_inventory(environment(this_object()));
  for(i=0; i < sizeof(ob); i++) {
    if(ob[i] && living(ob[i]) && !ob[i]->query_npc()) {
       tell_room(environment(this_object()), short()+" assaults "+ob[i]->query_name()+"!\n");
       this_object()->attack_object(ob[i]);
       return;
    }
  }
}
