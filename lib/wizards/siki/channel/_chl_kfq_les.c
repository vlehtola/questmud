/* Party heal //Celtron */

#define AREA_HEAL "/guilds/spells/channel/_chl_kfq_min"

status is_target(object ob) {
  object party_ob;

  party_ob = this_player()->query_party();
  if(!party_ob) return 0;

  return party_ob->is_member(ob);
}

resolve(int bonus, string target) {
  return AREA_HEAL->resolve(bonus, target, this_object());
}
