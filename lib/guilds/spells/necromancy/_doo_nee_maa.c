#define MASTERY_D "/daemons/mastery_d"
#define DIR "/guilds/necro/obj/"

/* Mass raise skeletons */
resolve(bonus) {
  int i, val;
  object *obs;
  object horde;
  horde = present("horde", environment(this_player()));
  if(!horde) { write("There are no horde here.\n"); return 1; }
  val = 0;
  obs = all_inventory(environment(this_player()));
  for(i=0;i<sizeof(obs);i++) {
  if(obs[i]->query_corpse() && !obs[i]->query_animal()) {
  val += 1;
  destruct(obs[i]);
  }
}
  if(val == 0) {
  write("There are no corpses that you can convert to the horde!\n");
  return 1;
  }
  horde->add_skeletons(val);
  write("You add "+val+" animated skeletons to the horde.\n");

  MASTERY_D->mastery("Mastery of dark arts",this_player());

  return 1;
}
